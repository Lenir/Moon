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
C++의 Vector와 상당히 비슷합니다. 선언할 때 제네릭을 이용해서 리스트의 타입을 정해주는 것도 똑같습니다. 위 코드를 실행하면 콘솔에 `[1, 2, 3]`라고 찍혀 나올 겁니다.<br>
이렇게 하나하나 원소를 집어 넣는것이 답답하다면 리스트를 이용한 초기화도 지원합니다. 코드를 볼까요.
{% highlight Java %}
ArrayList<Integer> intArray = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5));
System.out.println(intArray);
{% endhighlight %}
이렇게 하면 됩니다! 이제 ArrayList의 메소드를 살펴봅시다.<br><br>

##### ArrayList.add(E element);
ArrayList에 새 요소를 집어넣습니다. 즉, C++에서의 push_back()과 같습니다. 위에서 쓴 코드를 다시 써봅시다.
{% highlight Java %}
ArrayList<String> strArray = new ArrayList<String>();
strArray.add("Alpha");
strArray.add("Beta");
strArray.add("Gamma");
System.out.println(strArray);
{% endhighlight %}
다음과 같이 사용합니다. 결과는 `["Alpha", "Beta", "Gamma"]` 로 나오겠군요.<br><br>

##### ArrayList.addAll(ArrayList<E> array);
ArrayList에 ArrayList를 더할 때 사용합니다. 즉, ArrayList를 합칩니다. 코드의 예를 들어 봅시다.
{% highlight Java %}
ArrayList<String> strArray1 = new ArrayList<String>();
ArrayList<String> strArray2 = new ArrayList<String>();
strArray1.add("Alpha");
strArray1.add("Beta");
strArray2.add("Gamma");
strArray2.add("Delta");
strArray1.addAll(strArray2);
System.out.println(strArray1);
{% endhighlight %}
이렇게 `strArray1`에 `strArray2`의 요소를 다 더해줍니다. 결과는 `["Alpha", "Beta", "Gamma", "Delta"]` 이렇게 나올 겁니다. <br><br>

##### ArrayList.remove(int index | Object o);
이 메소드는 원소를 삭제합니다. 그런데 이 함수는 두가지로 오버로딩됩니다. `remove(int index)`와 `remove(Object o)` 두가지 입니다. ArrayList 클래스의 문서를 봅시다.<br>
> **public E remove(int index)**<br>
 Removes the element at the specified position in this list. Shifts any subsequent elements to the left (subtracts one from their indices).

위에 적힌 대로 remove(int index)는 index를 입력받아 해당 위치의 원소를 삭제하고 삭제한 값을 리턴하는 메소드입니다.

> **public boolean remove(Object o)**<br>
Removes the first occurrence of the specified element from this list, if it is present.  If the list does not contain the element, it is unchanged.  More formally, removes the element with the lowest index

이 remove(Object o)는 인자로 받은 o와 처음으로 일치하는 원소를 삭제합니다. 만약 삭제에 성공했다면 `true`, 실패했다면 `false`를 리턴합니다. <br><br>

##### ArrayList.get(int index);
이 메소드는 인덱스를 이용해서 해당 위치의 원소를 리턴합니다. 즉 배열에서의 []연산자와 같습니다. <br><br>

##### ArrayList.set(int index, E element);
이 메소드는 인덱스와 원소를 이용해서 해당 인덱스 위치에 있는 값을 인자의 원소 값으로 바꾸고 이전 값을 반환합니다. 예를 들어 봅시다.
{% highlight Java %}
ArrayList<Integer> intArray = new ArrayList<Integer>(Arrays.asList(1, 2, 3, 4, 5));
int old = intArray.set(1, 22);
System.out.println(intArray);
System.out.println("Replaced : ", old);
{% endhighlight %}
1번째 원소인 2가 22로 바뀝니다. 콘솔에는 `[1, 22, 3, 4, 5] \n Replaced : 2` 가 나올 것입니다.<br><br>

##### ArrayList.contains(Object o);
이 메소드는 인자로 받은 오브젝트가 리스트에 있는지 체크합니다. 만약 리스트에 있다면 `true`, 없다면 `false`를 리턴합니다.<br><br>

##### ArrayList.sort(Comparator c);
이 메소드는 리스트를 정렬합니다. 보통 `Collections.sort(list l)`을 많이 사용합니다. 뭐가 다른 걸까요? Collections.sort()의 내부를 봅시다.
{% highlight Java %}
@SuppressWarnings("unchecked")
    public static <T extends Comparable<? super T>> void sort(List<T> list) {
        list.sort(null);
    }
@SuppressWarnings({"unchecked", "rawtypes"})
    public static <T> void sort(List<T> list, Comparator<? super T> c) {
        list.sort(c);
    }
{% endhighlight %}
리스트를 인자로 받아서 해당 리스트의 sort를 콜해줍니다. 그렇습니다, `Collections.sort(myList)`나 `myList.sort(null)`이나 똑같습니다. <br>
그냥 int형 리스트나 String형 리스트를 정렬할 때엔 특별한 comparator가 필요하진 않습니다만 HashMap으로 만든 리스트를 Value로 정렬하거나 하는 등의 경우엔 comparator를 만들어 같이 넣어주어야 합니다. 예를 들어 봅시다.
{% highlight Java %}
HashMap<Integer, String> students = new HashMap<Integer, String>();
students.put(1, "Beta");
students.put(2, "Delta");
students.put(3, "Alpha");
students.put(4, "Gammma");
// students = {1=Beta, 2=Delta, 3=Alpha, 4=Gammma}
ArrayList<HashMap.Entry<Integer, String>> stuBook = new ArrayList<HashMap.Entry<Integer, String>>(students.entrySet());
// ArrayList that lists HashMap's Entry.
// stuBook = [1=Beta, 2=Delta, 3=Alpha, 4=Gammma]
Comparator<HashMap.Entry<Integer, String>> nameComparator = new Comparator<HashMap.Entry<Integer, String>>(){
			@Override
			public int compare(Entry<Integer, String> o1, Entry<Integer, String> o2) {
				// TODO Auto-generated method stub
				return o1.getValue().compareTo(o2.getValue());
			}
		};
Collections.sort(stuBook, nameComparator);
// stuBook = [3=Alpha, 1=Beta, 2=Delta, 4=Gammma]
{% endhighlight %}
위와 같이 HashMap의 엔트리를 넣는 리스트를 Value를 이용하여 정렬하기 위해서는 새로운 Comparator인 nameComparator를 만들어 compare 메소드를 오버라이드 해 주었습니다.  <br><br>

##### ArrayList.iterator();
해당 리스트의 이터레이터를 반환합니다. `ArrayList`클래스 내부의 `Iterator`클래스를 생성해서 반환해주는 식으로 구현되어있습니다. 리스트 검색 시 사용합니다. 코드를 예시로 들어보겠습니다.
{% highlight Java %}
ArrayList<String> strArray = new ArrayList<String>();
Iterator<String> strIter = strArray.iterator();
strArray.add("Alpha");
strArray.add("Beta");
strArray.add("Gamma");
while(strIter.hasNext()){
  System.out.println(strIter.next());
}
{% endhighlight %}
이렇게 하면 이터레이터가 리스트를 쭉 돌며 원소를 하나 하나씩 출력하고 넘어갑니다. 콘솔 출력에는 `"Alpha"\n "Beta"\n "Gamma"\n`이 찍힙니다.<br><br>
