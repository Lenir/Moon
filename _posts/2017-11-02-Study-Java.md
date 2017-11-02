---
layout:       post
title:        "[Study] Java Programming"
date:         2017-11-02
author :      "Lenir"
catalog:      true
header-img:   "img/Java/header.jpg"
header-mask:  0.7
multilingual: false
mathjax:      true
tags:
- Study
- Java
- JCF

comments: true
---

## JCF
JCF, Java Collection Framework. C++의 STL과 비슷한 위치의 프레임워크입니다. STL처럼 여러가지 컬렉션을 제공합니다.<br><br>
### JCF Collections
JCF가 제공하는 콜렉션의 종류는 다음과 같습니다. `List`, `Set`, `Map`.<br>
`List`는 C++에서 많이 써 보던 그 배열입니다. 순서가 있는 리스트입니다. JCF에서는 `Vector`, `ArrayList`로 제공합니다. 정확한 차이점은 모르겠지만 알아본 바로는 `Vector`의 경우 내부에 `Synchronized`로 구현되어 있다고 합니다. <br>
`Set`는 `List`와 비슷하지만 중복된 값을 넣을 수 없습니다. `Set`으로 지원합니다.<br>
`Map`은 튜플입니다. `(Key, item)`의 형태로 이루어져 있습니다. 대표적으로 `HashMap`으로 지원합니다.<br>
#### ArrayList
![](/img/CPP/vector.gif)
첫번째로 살펴볼 컬렉션은 ArrayList입니다. C++의 배열같이 쓰시면 됩니다. 내부 구현은 충분한 양의 메모리 공간을 잡아둔 뒤 부족해질 거 같으면 늘리는 식이라고 합니다. 코드로 예를 들어봅시다.
{% highlight Java %}
ArrayList<Integer> intArray = new ArrayList<Integer>();
intArray.add(1);
intArray.add(2);
intArray.add(3);
System.out.println(intArray);
{% endhighlight %}
C++의 Vector와 상당히 비슷합니다. 위 코드를 실행하면 콘솔에 [1, 2, 3]라고 찍혀 나올 겁니다. 이제 ArrayList의 메소드를 살펴봅시다.

##### ArrayList::add();
ArrayList에 새 요소를 집어넣습니다. 즉, C++에서의 push_back()과 같습니다. 위에서 쓴 코드를 다시 써봅시다.
{% highlight Java %}
ArrayList<String> strArray = new ArrayList<String>();
strArray.add("Alpha");
strArray.add("Beta");
strArray.add("Gamma");
System.out.println(strArray);
{% endhighlight %}
다음과 같이 사용합니다. 결과는 ["Alpha", "Beta", "Gamma"] 로 나오겠군요.

<br><br>
