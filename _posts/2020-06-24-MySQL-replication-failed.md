---
layout:       post
title:        "[MySQL] Replication 실패 트러블 슈팅(작성중)"
date:         2020-06-24
author :      "Lenir"
catalog:      true
header-img:   "img/Java/header.jpg"
header-mask:  0.7
multilingual: false
mathjax:      true
tags:
- Study
- MySQL
- Replication
- Troubleshooting

comments: true
---

## Intro
최근에 서비스 운영 중 Replication이 걸려 있는 MySQL DB 서버 간 데이터 싱크가 맞지 않아 이슈가 발생한 적이 있습니다.<br>
이번 글에서는 어떤 이유로 싱크가 맞지 않았는지, 그리고 MySQL Replication에 대해 간단하게 알아보겠습니다.<br>
<br>
## Replication?
Replication은 복제 대상 MySQL DB 서버(이하 Master)의 데이터를 다른 DB 서버(Slave)에 복제할 수 있도록 지원하는 기능입니다.<br>
MySQL은 두가지 Replication 형식을 지원합니다. Statement-Based Replication과 Row-Based Replication이 바로 그것들입니다.<br>
일단 각 두가지 방법들에 대해 간략하게 설명하겠습니다.<br>
<br>
### Statement-Based Replication?
복제 대상 DB(Master)에서 실행된 SQL문을 기록하여 Slave DB에서 실행하는 방식으로 복제하는 Replication입니다.(이하 SBR)<br>
예를 들어 Master DB에 'Insert A / Insert B / Update A / Delete B' 가 실행되었다면, Slave DB에서도 마찬가지로 'Insert A / Insert B / Update A / Delete B' 가 실행되는 것이 SBR입니다.<br>
SBR의 장점 및 단점에 대해 아래에 간략하게 소개해 보겠습니다.<br>
<br>
#### Pros
- 검증된 기술임('Proven technology')<br>
- 로그 파일에 쓰는 데이터가 적음.<br>
 - 특히나 update/delete가 많은 row에 영향을 미친다면, 특히 데이터를 더 적게 사용함<br>
 - 예를 들어, 다음과 같은 SQL 문에서는 하나의 Statement로 많은 row에 영향을 줄 수 있을 겁니다.<br>
 - {% highlight Sql %}
 Update someDB.someTable SET SomeColumn = 'SomeValue' where SomeColumn = 'SomethingElseValue';
 {% endhighlight %}<br>
- 로그 파일에 변경이 일어난 모든 SQL 문이 저장되므로 DB 감사(audit)에 사용 가능함.<br>
<br>
#### Cons
- SQL 문을 복제하여 Slave DB에서 실행시키는 방식으로, 실행 시 마다 Output이 달라질 수 있는 함수를 사용한다면, 데이터의 Sync를 보장하지 못함. (중요)<br>
 - 예를 들어, rand() 같은 경우 실행 시 마다 다른 값이 나오므로 해당 값이 들어가는 SQL 문의 경우 데이터의 Sync를 보장하지 못함.<br>
 - 이렇게 사용 불가능한 함수들은 MySQL Manual의 'Replication and System Functions' 에 명시되어 있음.<br>
- Insert-Select 문 등을 모두 실행하므로 row lock이 비교적 많이 걸림.<br>
<br>
### Row-Based Replication?
Master에서 변경된 row의 데이터를 기록하여 Slave DB에 반영하는 방식의 Replication입니다.(이하 RBR)<br>
<br><br>
#### Pros
- 모든 변화가 데이터 기반으로 복제되므로 가장 안전한 Replication. ('This is the safest form of replication')<br>
- Insert-Select 문 등으로 일어난 변화에서 row lock이 비교적 적게 걸림.<br>
<br>
#### Cons
- 모든 데이터의 변화를 기록하므로 로그 파일에 쓰는 데이터가 많음.<br>
 - SBR과 반대로 update/delete가 많은 row에 영향을 미친다면, 데이터를 더 많이 기록함.<br>
<br>

## 이슈 발생 및 Troubleshooting
위에서 Replication에 대해 간략하게 알아봤습니다. 그러면 발생한 이슈에 대해 알아봅시다.<br>
이슈 증상은 간단합니다. 데이터의 싱크가 맞지 않았습니다.<br>
일단 데이터의 싱크가 맞지않은 걸로 보아 row-based replication은 아닌 것으로 보입니다.<br>
그리고 MySQL Reference Manual의 'Replication slave options and Variables'를 보면 다음과 옵션이 있습니다.<br>
> **--replicate-do-db=db_name**<br>
Creates a replication filter using the name of a database.

즉, 해당 옵션으로서 DB이름을 준다면 replication을 할 때 해당 이름의 DB라는 조건이 추가됩니다.<br>
이 옵션에서 statement-based replication의 경우 다음과 같이 동작한다고 적혀있습니다.<br>
![](/img/MySQL-replication-failed/mysql-replication-do-db-SBR.PNG)<br>
'기본 DB, 즉 `USE`로 선택된 DB가 `db_name`인 SQL문을 복제하도록 조건을 걸며, 여러 DB에 대한 조건을 걸 시 한번에 하나씩 명시함. 단, 이 경우에도 cross-database statement의 복제는 지원하지 않는다.'<br>
예를 들면 replication 옵션으로 `--replicate-do-db=CONFIG, --replicate-do-db=LOG` 가 잡혀 있고, 다음과 같은 SQL문이 있다고 합시다.<br>
{% highlight Sql %}
use LOG;
Insert into CONFIG.SOMETABLE (A, B, C) values ('a', 'b', 'c');
{% endhighlight %}<br>
위의 Insert statement는 cross-database statement이므로 LOG와 CONFIG DB 모두에 replicate 옵션이 걸려 있음에도 불구하고 해당 statement는 복제되지 않을 것입니다.<br>
정확한 이슈 발생 사유는 DB의 replication 옵션을 확인해야 알 수 있겠지만 현재로서 가장 유력한 원인은 다음과 같을것입니다.<br>
>Statement-based replication을 사용하며 replicate-do-db 조건을 건 상태에서 cross-database 문을 사용하여 Insert/Update 문이 실행되었음.<br>

<br>
## 이슈 해결
일단 유력한 이슈 원인을 찾았으니 이에 대한 해결 방안을 생각해봅시다.<br>
이에 대해 다음과 같이 해결할 수 있을 겁니다.<br>
- Cross-database statement를 사용하지 않음.<br>
하지만 이 경우는 인적 에러가 발생할 수 있을 것으로 보입니다. (만약 사용하게 된다면 똑같은 이슈 발생)<br>
또 다른 방법으로는 MySQL의 reference manual에 나와 있는 다음과 같은 옵션이 있습니다.<br>
> **--replicate-wild-do-table=db_name.tbl_name**<br>
Creates a replication filter by telling the slave thread to restrict replication to statements where any of the updated tables match the specified database and table name patterns.

즉, name pattern을 이용하여 해당 pattern에 맞는 table에 대해 replication 조건을 거는 것인데, 이 옵션의 설명 중에 다음과 같은 항목이 있습니다.

> .... To specify more than one table, use this option multiple times, once for each table. **This works for cross-database updates.**  

즉 위에서 언급한 `--replicate-do-db=db_name` 옵션과 하는 일은 비슷하나 database 이름 및 table 이름에 wild character를 사용 가능한 것 그리고 여러 조건을 나열하였을 때 **cross-database update가 먹힌다는 것** 이 다릅니다. <br>
그래서 또 다른 해결방법은, 다음과 같습니다.<br>
- `replicate-do-db` 대신 `replicate-wild-do-db` 옵션을 사용하여 replicate 대상 db 지정<br>
