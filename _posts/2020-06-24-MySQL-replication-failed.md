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
- Mysql
- Replication

comments: true
---

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
