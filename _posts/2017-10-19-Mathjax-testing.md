---
layout:       post
title:        "Mathjax 문법 포스팅"
date:         2017-10-17
author :      "Lenir"
catalog:      true
multilingual: false
mathjax:      true
tags:
- Mathjax
- 문법
comments: true
---
## 인라인 렌더링, 블록 렌더링, 문단 렌더링
~~~
인라인 렌더링 은 다음과 같으며 \\( 1/x^{2} \\), 블록 렌더링은 다음과 같습니다.:
\\[ \frac{1}{n^{2}} \\]
문단 렌더링은 다음과 같습니다.<br><br>
$$
\left( x , y \right)\left( \begin{array}{cc}
      1 & 2 \\
      3 & 4 \\
    \end{array} \right) = \left( x + 3y, 2x + 4y \right)
$$
~~~

인라인 렌더링 은 다음과 같으며 \\( 1/x^{2} \\), 블록 렌더링은 다음과 같습니다.:
\\[ \frac{1}{n^{2}} \\]
문단 렌더링은 다음과 같습니다.<br><br>
$$
\left( x , y \right)\left( \begin{array}{cc}
      1 & 2 \\
      3 & 4 \\
    \end{array} \right) = \left( x + 3y, 2x + 4y \right)
$$
<br><br>

## Mathjax 구성 요소들
#### 괄호
~~~
좌, 우 괄호는 다음과 같습니다. \\[ \left( , \right) \\]
~~~
좌, 우 괄호는 다음과 같습니다. \\[ \left( , \right) \\]

#### 그리스 문자
~~~
그리스 문자들은 다음과 같이 사용합니다. \\[ \alpha, \beta, \gamma, \delta \\]
~~~
그리스 문자들은 다음과 같이 사용합니다. \\[ \alpha, \beta, \gamma, \delta \\]

#### 시그마 함수
~~~
시그마 함수는 다음과 같이 사용합니다. \\[ \sum_{i=0}^n i \\]
~~~
시그마 함수는 다음과 같이 사용합니다. \\[ \sum_{i=0}^n i \\]

#### 행렬
~~~
매트릭스는 다음과 같이 사용합니다.<br><br>
$$
\left( \begin{array}{ccc}
      1 & 2 & 3 \\
      4 & 5 & 6 \\
      7 & 8 & 9 \\
    \end{array} \right)
$$
~~~
매트릭스는 다음과 같이 사용합니다.<br><br>
$$
\left( \begin{array}{ccc}
      1 & 2 & 3 \\
      4 & 5 & 6 \\
      7 & 8 & 9 \\
    \end{array} \right)
$$
<br><br>

### 고급 예시
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
