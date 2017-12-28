
이 포스팅은 한국어, 영어로 적혀 있습니다. 위 셀렉트 박스에서 언어 설정이 가능합니다. 형편없는 영어 실력 양해 바랍니다.  
This posting is written in both Korean and English. You can select language with 'select box', above this article. excuse my poor english.<br><br>

---

## 프로젝트 개요
이 프로젝트는 네이버 블로그의 포스팅을 html포맷으로 백업하는 크롤러를 만드는 것입니다. 포스팅에 포함된 글, 그리고 이미지도 저장하여 완전히 백업하는것이 목표입니다.

---

## 참고 및 사용 라이브러리  
1. [**Beautiful Soup**](https://www.crummy.com/software/BeautifulSoup/)  
파이썬의 크롤링 라이브러리입니다. 태그, 클래스 별 탐색 기능이 포함되어 있습니다.  

2. [**progress2**](https://github.com/WoLpH/python-progressbar)  
파이썬의 진행 막대 라이브러리입니다. 백업 상황을 보여주기 위해 사용했습니다.  

---

## Getting Started
[![PyPI version](https://badge.fury.io/py/NaverBlogBackup.svg)](https://badge.fury.io/py/NaverBlogBackup)

PyPI에 올라가 있습니다. `pip`으로 설치하실 수 있습니다.  

{% highlight bash %}
$ pip install NaverBlogBackup
$ pip3 install NaverBlogBackup
{% endhighlight %}

혹은 직접 tar [파일](https://pypi.python.org/packages/85/ef/87292ee65f9e01cc2b18b908758c8f88f28b3415de8b09558587f9d27eb9/NaverBlogBackup-0.1.3.tar.gz)을 받으신 후 설치하시면 됩니다.

{% highlight bash %}
$ pip install ./NaverBlogBackup-"lastest-version".tar.gz
$ pip3 install ./NaverBlogBackup-"lastest-version".tar.gz
{% endhighlight %}


---

## 사용법

아직 GUI나 콘솔에서 바로 실행 가능하지 않으므로 파이썬 스크립트를 만들어서 실행해주셔야 합니다.  

{% highlight python %}
from NaverBlogCrawler import NaverBlogCrawler as nblog

if __name__ == "__main__":
    crawler = nblog.NaverBlogCrawler("your_naver_ID")
    crawler.run()
{% endhighlight %}
다음과 같이 파이썬 스크립트를 만들어 실행하신다면 해당 디렉토리에 `post` 폴더를 만들어 백업이 될 것입니다.

---

## 실행 예

![](/img/NaverBlogBackup/usageScreenshot.png)
위와 같은 파이썬 스크립트를 실행하였을 때의 스크린샷입니다.  

![](/img/NaverBlogBackup/bakupDirScreenshot.png)
백업된 `post/` 내부입니다. 포스트 별로 디렉토리를 만들어줍니다.  

![](/img/NaverBlogBackup/postFolder.png)
포스트 별 폴더 내부입니다. 이미지는 따로 저장되고 html은 `post.html`로 저장됩니다.  

![](/img/NaverBlogBackup/backupedPost.png)
`post.html` 실행 예시입니다. 해당 포스트의 원본은 [이렇](https://blog.naver.com/1net1/221159842052)습니다. 거의 대부분 그대로 저장됩니다.   

![](/img/NaverBlogBackup/codeComponent.png)
위 포스트에 있는 Code Component입니다. 이는 네이버 블로그에 원래 있던 css파일의 코드 컴포넌트 부분을 가지고 왔습니다.  
