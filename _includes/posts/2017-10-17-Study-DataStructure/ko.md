# 리스트 (List)
가장 기본이 되는 자료구조인 List입니다. 보통 순서가 있으며, 일렬로 쭉 늘어선 모양을 하고 있습니다. 보통 중복을 허용합니다. 중복을 허용하지 않는 것은 set이라고 따로 부르기도 합니다. Python에서는 set과 list가 기본적으로 구현되어 있습니다.<br><br>
## 배열 (Array)
![](/img/dataStructure/array.jpg)
가장 대표적인 리스트인 배열입니다. array[index]로 표시됩니다. index로 random access가 가능하나 Linked List에 비해 삽입, 삭제가 느립니다. 보통 연속된 메모리 공간에 할당(in C, C++ et cetera) 이를 이용한 것이 C, C++의 포인터로 다음과 같은것이 가능합니다.
{% highlight c++ %}
  //int matrix[10][10] is ((0,1,2....9),(10,11,..19)...(..99)) initialized//

  int* pointer;
  pointer = (int*)(&matrix + (sizeof(int)*10)*5 + sizeof(int)*5); // == matrix[5][5]

  printf(*pointer); // 55
{% endhighlight %}
 코드가 문법에 맞는지는 잘 기억이 나질 않네요. <br><br>

## 링크드 리스트 (Linked List)
![](/img/dataStructure/linkedList.png)
값과 다음 노드의 주소로 이루어진 '노드'의 연결로 이루어진 구조입니다. 보통 첫 노드인 `head`를 선언한 뒤 뒤에 노드를 이어 붙이는 형식으로 삽입하며, 삭제시엔 삭제할 노드의 앞의 `next`노드를 삭제할 노드의 `next`노드로 둔 뒤 삭제합니다. Python으로 구현시 다음과 같습니다.
{% highlight python %}
  class Node:
      def __init__(self, data, next=None):
          self.data = data
          self.next = next

  class LinkedList:
      def __init__(self, data):
          self.head = Node(data)

      def insert(self, data):
          if self.next == None:
              self.next = Node(data)
          else:
              self.next.insert(data)

      def delete(self, data):
          if next.data == data:
              temp = self.next.next
              self.next = temp
              del next
          else:
              self.next.delete(data)
{% endhighlight %}
정도가 되지 않을까 합니다. 돌려보진 않았지만 대략 맞을거 같네요. 역시 파이썬 코드는 깔끔해서 보기 좋아요!<br>
이 링크드 리스트를 응용하여 앞뒤로 연결한 더블 링크드 리스트도 있고, 마지막과 첫 노드를 연결한 서큘러 링크드 리스트도(서큘러 버퍼와 비슷) 있는데, 대동소이합니다.<br><br>

---
# 그래프 (Graph)
![](/img/dataStructure/graph.png)
매우 중요한 그래프입니다. 수학에서 말하는 그 그래프(plot)말고 자료구조 그래프입니다.<br>
버텍스(정점;Vertex)와 그 안의 data, 그리고 해당 버텍스와 다른 노드를 연결하는 엣지(간선;edge)로 이루어 진 자료구조입니다. 여러가지로 구현이 가능합니다만 다음과 같이 딕셔너리로 구현할 수도 있습니다.
{% highlight python %}
  class Graph:
      def __init__(self, vertex, linkedVertex=[]):
          self.vertexes = {}
          self.vertexes.append(vertex:linkedVertex)

      def insertVetex(self, vertex, linkedVertex=[]):
          self.vertexes.append(vertex:linkedVertex)

     # Data like {'A':['B', 'C', 'D'] , 'B':['A', 'D'], 'C':['A'], 'D':['B', 'C']}


{% endhighlight %}

edge를 양쪽 다 추가하지 않으니 directed 그래프가 되겠네요.<br><br>


## 트리 (Tree)
![](/img/dataStructure/tree.png)
undirected Graph의 일종인 트리입니다. undirected Graph이며 Cycle이 없는 Graph를 Tree라고 합니다. 더 쉽게 말하자면, 무조건 Root에서 leaf로 내려가기만 하고 빙글빙글 도는 사이클이 없으면 되죠. Python으로 간단히 다음과 같이 표현 가능합니다.
{% highlight python %}
  class Node:
      def __init__(self, data):
          self.data = data
          self.children = []
  class Tree:
      def __init__(self, data):
          self.root = Node(data)

      def addChildren(self, children=[]):
          self.children = children

{% endhighlight %}
<br><br>

### 이진 트리 (Binary Tree)
![]()
트리중에서도 중요한 트리 중 하나인 바이너리 트리입니다. 트리이면서 자식 노드가 최대 2개인 트리를 바이너리트리라고 합니다. 바이너리 트리는 보통 이진 탐색(Binary Search)를 하기 위한 바이너리 서치 트리의 형태로 사용합니다. 트리만 갖춰져 있다면 O(log n)의 탐색 시간을 가지는 자료구조입니다. 바이너리 트리를 Python으로 다음과 같이 표현할 수 있습니다.
{% highlight python %}
  class Node:
      def __init__(self, data):
          self.data = data
          self.left = None
          self.right = None

  class BinaryTree:
      def __init__(self, data):
          self.root = Node(data)

      def addLeft(self, data):
          self.left = Node(data)

      def addRight(self, data):
          self.right = Node(data)

{% endhighlight %}
<br><br>

#### 이진 탐색 트리 (Binary Search Tree)
![](/img/dataStructure/BST.png)
바이너리 서치를 할 수 있는 트리입니다. 바이너리 서치라고 한다면 숫자로 UP / DOWN을 하는 게임을 할 때 구상 가능한 대표적인 전략을 생각하시면 됩니다. Parent Node의 Left에는 Parent Node보다 작은 값, Right에는 Parent Node보다 큰 값을 넣어 만든 트리가 이진 탐색 트리입니다. 예를들어 위 그림의 트리에서 6을 찾는다면, Root(8 > target) -> Left(3 < target) -> Right(6 == target) 순으로 찾게 되는겁니다. BST는 Python으로 다음과 같이 표현 가능 할 것입니다.
{% highlight python %}
  class Node:
      def __init__(self, value):
          self.value = data
          self.left = None
          self.right = None
  class BST:
      def __init__(self):
          self.root = Node(None)

      def insert(self, value):
          if self.value == None:
              self.value = value
          elif self.value > value:
              self.left.insert(value)
          elif self.value < value:
              self.right.insert(value)
          else: # Same value exists
              print("Cannot insert Same value!")

      def binarySearch(self, value):
          if self.value == None:
              print("Tree is empty")
          elif self.value > value:
              self.left.binarySearch(value)
          elif self.value < value:
              self.right.binarySearch(value)
          elif self.value == value:
              return self

{% endhighlight %}
<br><br>
