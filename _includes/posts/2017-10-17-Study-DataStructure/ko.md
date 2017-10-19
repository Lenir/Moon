## 리스트 (List)
가장 기본이 되는 자료구조인 List입니다. 보통 순서가 있으며, 일렬로 쭉 늘어선 모양을 하고 있습니다. 보통 중복을 허용합니다. 중복을 허용하지 않는 것은 set이라고 따로 부르기도 합니다. Python에서는 set과 list가 기본적으로 구현되어 있습니다.<br><br>
### 배열 (Array)
![](/img/dataStructure/array.jpg)
가장 대표적인 리스트인 배열입니다. array[index]로 표시됩니다. index로 random access가 가능하나 Linked List에 비해 삽입, 삭제가 느립니다. 보통 연속된 메모리 공간에 할당(in C, C++ et cetera) 이를 이용한 것이 C, C++의 포인터로 다음과 같은것이 가능합니다.
{% highlight c++ %}
  //int matrix[10][10] is ((0,1,2....9),(10,11,..19)...(..99)) initialized//

  int* pointer;
  pointer = (int*)(&matrix + (sizeof(int)*10)*5 + sizeof(int)*5); // == matrix[5][5]

  printf(*pointer); // 55
{% endhighlight %}
 코드가 문법에 맞는지는 잘 기억이 나질 않네요*.* <br><br>

### 링크드 리스트 (Linked List)
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
## 그래프 (Graph)
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


### 트리 (Tree)
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

#### 이진 트리 (Binary Tree)
![](/img/dataStructure/binaryTree.png)
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

##### 이진 탐색 트리 (Binary Search Tree)
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
          if self == None:
              self = Node(value)
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

###### AVL 트리
![](/img/dataStructure/AVL.png)
기존 BST는 삽입/삭제를 할 수록 한쪽으로 치우쳐 거의 배열과 비슷한 수준이 되어버리는 경우가 있었습니다. 그래서 나온 것이 자동으로 균형을 맞추는 AVL 트리 입니다. 이 트리는 Python으로 표현하면 다음과 같습니다.
{% highlight python %}
  balanceNum = 0
  class Node:
      def __init__(self, value):
          self.value = data
          self.left = None
          self.right = None

  class AVL-Tree:
      def __init__(self):
          self.root = Node(None)

      def avlInsert(self, value):
          if self == None:
              self = Node(value)
          elif self.value > value:
              self.left.avlInsert(value)
              self.balance()
          elif self.value < value:
              self.right.avlInsert(value)
              self.balance()
          else: # Same value exists
              print("Cannot insert Same value!")

      def balance(self):
          global balanceNum
          balanceNum = self.getBalanceNum()
          if balanceNum > 1: # viased to Left
              if self.left.getBalanceNum() > 0: # left child not has right child
                  self.rotateLL()
              else: # left child has right child
                  self.rotateLR()
          if balanceNum < -1: # viased to Right
              if self.right.getBalanceNum() <0: # right child not has left child
                  self.rotateRR()
              else: # right child has left child
                  self.rotateRL()
          return self

      def getBalanceNum(self):
          global balanceNum
          if self == None:
              balanceNum = 0
          else:
              return (getBalanceNum(self.left) - getBalanceNum(self.right))

      def rotateLL(self):
          child = self.left
          self.left = child.right
          child.right = self
          return child

      def rotateRR(self):
          child = self.right
          self.right = child.left
          child.left = self
          return child

      def rotateRL(self):
          child = self.right
          self.right = child.rotateLL()
          return self.rotateRR()

      def rotateLR(self):
          child = self.left
          self.left = child.rotateRR()
          return self.rotateLL()

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
코드가 위에서 보던 다른 구조들에 비해 상당히 복잡합니다. 코드에서 보다시피 값을 넣거나 뺄 때 마다 밸런스를 맞춰줍니다. 균형은 매우 잘 맞으나, 노드 삽입/삭제의 속도가 후술할 Red-Black Tree보다 조금 떨어집니다.<br><br>

###### Red-Black 트리
![](/img/dataStructure/RBT.png)
위에서 본 AVL 트리와 비슷하게 자동으로 균형을 맞춰주는 트리입니다. 하지만 이 트리는 노드 삽입/삭제, 탐색이 모두 O(log n)의 시간이 걸립니다. 실제로 많이 쓰이는 트리구조이기도 합니다. B 트리 중 2-3-4 트리와 동치관계입니다.<br>
레드블랙 트리는 다음과 같은 성질을 가집니다.
1. 모든 노드는 레드 노드 혹은 블랙 노드이다.
2. 루트 노드는 블랙 노드이다.
3. 모든 리프 노드(leaf Node)는 블랙 노드이다.
4. 레드 노드의 자식은 모두 블랙 노드이다.
5. 특정 노드로부터 리프 노드까지의 블랙 노드의 갯수는 모두 같다.
AVL트리의 균형이 경로 차가 1이상 나지 않는 정도까지 맞춰준다면, 레드블랙 트리는 가장 짧은 경로와 가장 긴 경로의 차이가 2배 이상 나지 않는 정도로 균형을 맞춰줍니다. 이를 Python으로 표현하면 다음과 같습니다.
{% highlight python %}
  class Node:
      def __init__(self, value):
          self.value = value
          self.color = None
          self.left = None
          self.right = None
          self.parent = None

  class RedBlackTree:
      def __init__(self, value):
          self.root = Node(data)

      def getGrandpa(self):
          if self.parent != None:
              if self.parent.parent != None:
                  return self.parent.parent
          else:
              return None

      def getUncle(self):
          granpa = self.getGrandpa()
          if granpa != None:
              if granpa.left == self.parent:
                  return granpa.right
              else:
                  return granpa.left
          else:
              return None
      def getSibling(self):
          if self.parent.right == self:
              return self.parent.left
          elif self.parent.left == self:
              return self.parent.right
          return None
{% endhighlight %}
####### RBT - Insert Cases
삽입은 키 검색 후 새 노드를 해당 자리에 삽입 후 레드 노드로 지정한 후 시작.
1. 새 노드가 루트 노드일떄 : <br>
  루트 노드는 블랙 노드. 색 변환.
2. 블랙 노드의 자식으로서 노드 추가시 : 조건 만족.
3. 새 노드의 부모와 삼촌 노드가 모두 레드 노드 : <br>
  부모와 삼촌 노드를 블랙 노드로, 할아버지 노드를 레드 노드로 색 변환. <br>
  이후 할아버지 노드에 대해 1 ~ 3의 케이스를 다시 적용.
4. 부모 노드는 레드, 삼촌 노드는 블랙일때:
   1. 부모 노드가 할아버지 노드의 왼쪽, 새 노드가 부모 노드의 오른쪽 자식일때 :<br>
    부모 노드-자식 노드에 대해 rotateLeft 한 뒤 케이스 5로 처리
   2. 부모 노드가 할아버지 노드의 오른쪽, 새 노드가 부모 노드의 왼쪽 자식일때 : <br>
    부모 노드-자식 노드에 대해 rotateRight 한 뒤 케이스 5로 처리
5. 부모 노드는 레드, 삼촌 노드는 블랙일떄:
   1. 새 노드가 왼쪽 자식일때 : <br>
    할아버지 노드에 대해 rotateRight.
   2. 새 노드가 오른쪽 자식일때 : <br>
    할아버지 노드에 대해 rotateLeft.
{% highlight python %}
      def insertCase1(self):
          if self.parent == None:
              self.color = "BLACK"
          else:
              self.insertCase2() # case 2

      def insertCase2(self):
          if self.parent.color == "BLACK":
              pass
          else:
              self.insertCase3() # case 3

      def insertCase3(self):
          if self.parent.color == "RED" && self.getUncle().color == "RED":
              self.parent.color = "BLACK"
              self.getUncle().color = "BLACK"
              self.getGrandpa().insertCase1() # recursive case apply!
          else:
              self.insertCase4() # case 4

      def insertCase4(self):
          grandpa = self.getGrandpa()
          uncle = self.getUncle()
          if self.parent.color == "RED" && uncle.color == "BLACK":
              if self.parent.right == self && grandpa.left == self.parent :
                  self.parent.rotateLeft()
              elif self.parent.left == self && grandpa.right == self.parent:
                  self.parent.rotateRight()
              self.insertCase5() # case 5

      def insertCase5(self):
          if self.parent.left == self:
              self.getGrandpa().rotateRight()
          elif self.parent.right == self:
              self.getGrandpa().rotateLeft()


      def rotateLeft(self):
          succeeder = self.right
          parent = self.parent
          if succeeder.left != None:
              succeeder.parent = self
          else: #succeeder.left == None
              pass
          self.right = succeeder.left
          self.parent = succeeder
          succeeder.left = self
          succeeder.parent = parent

          if parent != None:
              if parent.left == self:
                  parent.left = succeeder
              else:
                  parent.right = succeeder

      def rotateRight(self):
          succeeder = self.left
          parent = self.parent
          if succeeder.right != None:
              succeeder.parent = self
          else: #succeeder.right == None
              pass
          self.left = succeeder.right
          self.parent = succeeder
          succeeder.right = self
          succeeder.parent = parent

          if parent != None:
              if parent.right == self:
                  parent.right = succeeder
              else:
                  parent.left = succeeder

{% endhighlight %}
####### RBT - Delete Cases
삭제는 키 검색 후 해당 노드를 루트 노드로 하는 서브트리에서 왼쪽 서브트리의 최댓값, 혹은 오른쪽 서브트리의 최솟값을(즉, 삭제 예정 노드와 제일 근처값) 해당 노드의 자리에 옮긴 후 삭제 예정 노드를 삭제한다.
{% highlight python %}
    def replaceNode(self, target):
        self.color, target.color = target.color, self.color
        self.value, target.value = target.value, self.value

    def deleteOne(self):

        if self.right == None:
            child = self.left
        elif self.left == None:
            child = self.right
        else:
            return false

        self.replaceNode(child)

        if self.color == "BLACK":
            if child.color == "RED":
                child.color = "BLACK"
            else:
                self.deleteCase1()
        del self
{% endhighlight %}
삭제시 가능한 케이스들은 다음과 같다.
1. 바꾼 노드가 새 루트 노드일떄 : <br>
  조건 만족.
2. 형제 노드가 레드 노드일 경우 : <br>
부모 노드와 형제 노드의 색을 바꾼 뒤,
    1. 삭제할 노드가 왼쪽 노드일 경우 : <br>
  부모 노드에 대해 rotateLeft()
    2. 삭제할 노드가 오른쪽 노드일 경우 : <br>
  부모 노드에 대해 rotateRight()
3. 부모, 형제, 그리고 형제의 자식 노드가 모두 블랙 노드일 경우 : <br>
  형제 노드를 레드 노드로 색 변환. <br>
  이후 부모 노드에 대해 1 케이스를 다시 적용.
4. 부모 노드는 레드, 형제 노드와 형제 노드의 자식 노드가 블랙 노드 인 경우 : <br>
  형제 노드와 부모 노드의 색을 바꾼다.
5. 형제 노드가 검정 :
    1. 삭제 노드가 부모 노드의 왼쪽 자식일 때 : <br>
      1. 형제 노드의 왼쪽이 레드, 오른쪽이 블랙 노드인 경우 : <br>
        형제 노드를 레드 노드로, 형제 노드의 왼쪽 자식을 블랙 노드로 바꾸고 형제 노드에 대해 rotateRight()
    2. 삭제 노드가 부모 노드의 오른쪽 자식일 때 : <br>
      1. 형제 노드의 왼쪽이 레드, 오른쪽이 블랙 노드인 경우:<br>
        형제 노드를 레드 노드로, 형제 노드의 오른쪽 자식을 블랙 노드로 바꾸고 형제 노드에 대해 rotateLeft()
6. 형제 노드가 블랙, 형제 노드의 오른쪽/왼쪽 자식 노드가 레드 노드일 경우 : <br>
    1. 삭제 노드가 부모 노드의 왼쪽 자식일 때 : <br>
    형제 노드의 오른쪽 자식 노드를 블랙 노드로 색 변환, 그리고 부모 노드에 대해 rotateLeft()
    2. 삭제 노드가 부모 노드의 오른쪽 자식일 때 : <br>
    형제 노드의 왼쪽 자식 노드를 블랙 노드로 색 변환, 그리고 부모 노드에 대해 rotateRight()
{% highlight python %}
    def deleteCase1(self):
        if self.parent == None:
            pass
        else:
            self.deleteCase2()

    def deleteCase2(self):
        sibling = self.getSibling()
        if sibling.color == "RED":
            sibling.color, self.parent.color = self.parent.color, sibling.color
            if self.parent.left == self:
                self.parent.rotateLeft()
            else:
                self.parent.rotateRight()
        self.deleteCase3()

    def deleteCase3(self):
        sibling = self.getSibling()
        if self.parent.color == "BLACK" and sibling.color == "BLACK" and sibling.left.color == "BLACK" and sibling.right.color == "BLACK":
            sibling.color = "RED"
            self.parent.deleteCase1()
        else:
            self.deleteCase4()

    def deleteCase4(self):
        sibling = self.getSibling()
        if self.parent.color == "RED" and sibling.color == "BLACK" and sibling.left.color == "BLACK" and sibling.right.color == "BLACK":
            sibling.color, self.parent.color = self.parent.color, sibling.color
        else:
            self.deleteCase5()

    def deleteCase5(self):
        sibling = self.getSibling()
        if self.parent.left == self:
            if sibling.left.color == "RED" and sibling.right.color == "BLACK":
                sibling.color = "RED"
                sibling.left.color = "BLACK"
                sibling.rotateRight()
        else:
            if sibling.left.color == "RED" and sibling.right.color == "BLACK":
                sibling.color = "RED"
                sibling.right.color = "BLACK"
                sibling.rotateLeft()
        self.deleteCase6()

    def deleteCase6(self):
        sibling = self.getSibling()
{% endhighlight %}
상당히 복잡한 구조입니다. 대신 그만큼 성능도 좋아 많이 쓰이는 트리라 알고 있는게 좋겠죠.<br><br>

#### B-트리 (B-Tree)
![](/img/dataStructure/b-tree.png)
이진 트리의 확장형인 B-트리 입니다. B-Tree order of N으로 부르며, 이 때 노드는 최대 N개의 값을 가질 수 있습니다. 그리고 그 자식 노드는 그림에서 보시다시피 부모 노드의 값 사이에 N+1만큼 가질 수 있죠.<br><br>

##### 2-3-4 트리 (2-3-4 Tree)
![](/img/dataStructure/2-3-4tree.png)
B-트리 중 B-Tree order of 4로, 레드-블랙 트리의 동치형인 트리입니다. 레드-블랙 트리에서 블랙 노드의 자식 노드 중 레드 노드를 블랙 노드의 좌-우로 정렬시키면 2-3-4 트리가 됩니다. <br>
![](/img/dataStructure/2-3-4andRBT.png)
위의 그림처럼요. <br><br>

#### 트라이 (trie)
![](/img/dataStructure/trie.png)
트리 중 문자열 검색 알고리즘 중 가장 유명한 알고리즘인 아호코라식 알고리즘(Aho-Corasick Algorithm)에 사용되는 트라이입니다. 알고리즘에 사용 가능한 문자 갯수(eg. 알파벳만 사용시 26) 만큼의 child를 가질 수 있습니다. 위 그림에서 예를 들어 봅시다. 문서 중 tea를 찾으려고 합니다. 그러면 (root) -t-> (t) -e-> (te) -a-> (tea : 3) 으로, index 3에 tea가 있다는걸 알 수 있습니다. 이렇게 trie는 공간을 매우 많이 잡아먹지만(word case : O(n^l), l은 최장 단어 길이 수)

~~~
Here is an example MathJax inline rendering \\( 1/x^{2} \\), and here is a block rendering:
\\[ \frac{1}{n^{2}} \\]
~~~

Here is an example MathJax inline rendering \\( 1/x^{2} \\), and here is a block rendering:
\\[ \frac{1}{n^{2}} \\]

The only thing to look out for is the escaping of the backslash when using markdown, so the delimiters become `\\[ ... \\]` and `\\( ... \\)` for inline and block maths respectively.


$$
\begin{align*}
  & \phi(x,y) = \phi \left(\sum_{i=1}^n x_ie_i, \sum_{j=1}^n y_je_j \right)
  = \sum_{i=1}^n \sum_{j=1}^n x_i y_j \phi(e_i, e_j) = \\
  & (x_1, \ldots, x_n) \left( \begin{array}{ccc}
      \phi(e_1, e_1) & \cdots & \phi(e_1, e_n) \\
      \vdots & \ddots & \vdots \\
      \phi(e_n, e_1) & \cdots & \phi(e_n, e_n)
    \end{array} \right)
  \left( \begin{array}{c}
      y_1 \\
      \vdots \\
      y_n
    \end{array} \right)
\end{align*}
$$

<br><br>
