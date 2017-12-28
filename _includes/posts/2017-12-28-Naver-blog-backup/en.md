
이 포스팅은 한국어, 영어로 적혀 있습니다. 위 셀렉트 박스에서 언어 설정이 가능합니다. 형편없는 영어 실력 양해 바랍니다.  
This posting is written in both Korean and English. You can select language with 'select box', above this article. excuse my poor english.<br><br>

---

## Project Summary
This Project is making Crawler that backups Naver Blog's posting in html format. Goal is completely backup postings include its image.  

---

## Library Used
1. [**Beautiful Soup**](https://www.crummy.com/software/BeautifulSoup/)  
Python's Crawling lib. Can find page's source in tag, class' name.  

2. [**progress2**](https://github.com/WoLpH/python-progressbar)  
Python's Progress bar lib. I used it for showing backup progress status.  

---

## Getting Started
[![PyPI version](https://badge.fury.io/py/NaverBlogBackup.svg)](https://badge.fury.io/py/NaverBlogBackup)

This project uploaded on PyPI. You can install with `pip` easily!  

{% highlight bash %}
$ pip install NaverBlogBackup
$ pip3 install NaverBlogBackup
{% endhighlight %}

Or you can install with tar [file](https://pypi.python.org/packages/85/ef/87292ee65f9e01cc2b18b908758c8f88f28b3415de8b09558587f9d27eb9/NaverBlogBackup-0.1.3.tar.gz) on hard way.

{% highlight bash %}
$ pip install ./NaverBlogBackup-"lastest-version".tar.gz
$ pip3 install ./NaverBlogBackup-"lastest-version".tar.gz
{% endhighlight %}


---

## Usage

I didn't implement it with running directly on console neither GUI. You have to write python script and run it.  

{% highlight python %}
from NaverBlogCrawler import NaverBlogCrawler as nblog

if __name__ == "__main__":
    crawler = nblog.NaverBlogCrawler("your_naver_ID")
    crawler.run()
{% endhighlight %}
When you run script like above code area, it'll backups your postings on `post` directory.

---

## Examples

![](/img/NaverBlogBackup/usageScreenshot.png)
This is screenshot when run above python script.  

![](/img/NaverBlogBackup/bakupDirScreenshot.png)
Inside of  `post/` directory. It makes directory for each posting backups.  

![](/img/NaverBlogBackup/postFolder.png)
Inside of posting directory. Html backup saved in `post.html` and image also saved with it.  

![](/img/NaverBlogBackup/backupedPost.png)
This is capture of `post.html`. This backup's original page is like [this](https://blog.naver.com/1net1/221159842052). It looks pretty same.   

![](/img/NaverBlogBackup/codeComponent.png)  
Code Component in above posting. I use css file's code component part on Naver Blog's page code.  
