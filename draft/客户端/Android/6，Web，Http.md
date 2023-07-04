1.HTML相关知识（省略）
2.Tomcat:把要发布的页面放到Tomcat安装目录下的webapps目录中(也可以用.war压缩文件自动解压)
比较理论>不做太多笔记,详细百度

| 序号 | 方法 | 描述 |
| :--- | :--- | :--- |
| 1 | GET | 发送请求来获得服务器上的资源，请求体中不会包含请求数据，请求数据放在协议头中。另外get支持快取、缓存
、可保留书签等。幂等 |
| 2 | POST | 和get一样很常见，向服务器提交资源让服务器处理，比如提交表单、上传文件等，可能导致建立新的资源或者对
原有资源的修改。提交的资源放在请求体中。不支持快取。非幂等 |
| 3 | HEAD | 本质和get一样，但是响应中没有呈现数据，而是http的头信息，主要用来检查资源或超链接的有效性或是否可以可达、检
查网页是否被串改或更新，获取头信息等，特别适用在有限的速度和带宽下。 |
| 4 | PUT | 和post类似，html表单不支持，发送资源与服务器，并存储在服务器指定位置，要求客户端事先知
道该位置；比如post是在一个集合上（/province），而put是具体某一个资源上（/province/123）。所以put是安全的，
无论请求多少次，都是在123上更改，而post可能请求几次创建了几次资源。幂等 |
| 5 | DELETE | 请求服务器删除某资源。和put都具有破坏性，可能被防火墙拦截。如果是https协议，则无需担心。幂等 |
| 6 | CONNECT | HTTP/1.1协议中预留给能够将连接改为管道方式的代理服务器。就是把服务器作为跳板，去访问其他网页
然后把数据返回回来，连接成功后，就可以正常的get、post了。 |
| 7 | OPTIONS | 获取http服务器支持的http请求方法，允许客户端查看服务器的性能，比如ajax跨域时的预检等。 |
| 8 | TRACE | 回显服务器收到的请求，主要用于测试或诊断。一般禁用，防止被恶意攻击或盗取信息。 |

**GET 和 POST 比较**

|   | GET | POST |
| :--- | :--- | :--- |
| 点击返回/刷新按钮 | 没有影响 | 数据会重新提交 |
| 缓存/添加书签 | 可以 | 不可以 |
| 历史记录 | 有 | 没有 |
| 编码类型 | application/x-www-form-urlencoded | application/x-www-form-urlencoded 
或 multipart/form-data。为二进制数据使用
多重编码 |
| 是否幂等 | 幂等 | 非幂等 |
| 长度限制 | http协议没有限制，但是实际浏览器或服务
器有(最大2048) | 理论上没有，可能会收到服务器配置或内存限制 |
| 数据类型限制 | 只能ASCII，非ascii都要编码传输 | 没有限制，允许二进制数据 |
| 安全性 | 数据全部展示在url中，不安全 | 相比get，通过request body传递数据，比较安全 |
| 可见效 | 可见 | 不可见 |

![image.jpeg](https://cdn.nlark.com/yuque/0/2021/jpeg/21546446/1621102412592-2feee41f-e088-4124-8d82-cb121966f755.jpeg#align=left&display=inline&height=337&originHeight=337&originWidth=601&size=196432&status=done&style=none&width=601)
![image.jpeg](https://cdn.nlark.com/yuque/0/2021/jpeg/21546446/1621102398879-557b96b6-7ec4-497e-96c7-89947dceff6c.jpeg#align=left&display=inline&height=119&originHeight=119&originWidth=388&size=56623&status=done&style=none&width=388)
![image.jpeg](https://cdn.nlark.com/yuque/0/2021/jpeg/21546446/1621102412301-736b34b0-88d9-4b3a-8458-f90f7671ac84.jpeg#align=left&display=inline&height=286&originHeight=286&originWidth=785&size=188518&status=done&style=none&width=785)
![image.jpeg](https://cdn.nlark.com/yuque/0/2021/jpeg/21546446/1621102411593-e27f49c8-06a4-4631-bddc-74c018eccc37.jpeg#align=left&display=inline&height=349&originHeight=349&originWidth=684&size=175554&status=done&style=none&width=684)
