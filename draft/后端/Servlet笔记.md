## 0 环境
Servlet = **server applet：**可以理解为运行在服务器上的Java程序，需要运行在web服务器软件上（Tomcat）所以需要先安装Tomcat。

**部署项目的方式：**

1.  直接将项目放到webapps目录下即可。
- /hello：项目的访问路径-->虚拟目录
-  简化部署：将项目打成一个war包，再将war包放置到webapps目录下。
-  war包会自动解压缩
2.  配置conf/server.xml文件，在<Host>标签体中配置

<Context docBase="D:\hello" path="/hehe" />

-  docBase:项目存放的路径
-  path：虚拟目录
3.   在conf\Catalina\localhost创建任意名称的xml文件。在文件中编写

 <Context docBase="D:\hello" />

-  虚拟目录：xml文件的名称

## 1 Servlet类
### 1.1 快速入门：

1.  创建JavaEE项目
2.  定义一个类，实现Servlet接口
-  public class tryServlet implements Servlet
3.  实现接口中的抽象方法
4.  配置Servlet
- **在web.xml中配置：**
```xml
<!--配置Servlet -->
     <servlet>
         <servlet-name>demo1</servlet-name><!-- demo1指向tryServlet -->
         <servlet-class>tryServlet</servlet-class>
     </servlet>
 
     <servlet-mapping>
         <servlet-name>demo1</servlet-name>
         <url-pattern>/d1</url-pattern> <!-- 由url的/d1去找demo1 -->
     </servlet-mapping>
```

- Servlet3.0以上之后,可以不写web.xml了,直接在类前面写@WebServlet("资源路径")

@WebServlet({"/d4","/dd4","/ddd4"})
  	2. 路径定义规则：

   1.  /xxx：路径匹配
   2.  /xxx/xxx:多层路径，目录结构
   3.  *.do：扩展名匹配
### 1.2 生命周期

1. 被创建：执行init方法，只执行一次
   -  默认情况下，第一次被访问时，Servlet被创建
   -  可以配置执行Servlet的创建时机。
      -  在<servlet>标签下配置
      1.  第一次被访问时，创建
         -  <load-on-startup>的值为负数
      2.  在服务器启动时，创建
         -  <load-on-startup>的值为0或正整数
2.   提供服务：执行service方法，执行多次
   -  每次访问Servlet时，Service方法都会被调用一次。
3.  被销毁：执行destroy方法，只执行一次
   -  Servlet被销毁时执行。服务器关闭时，Servlet被销毁
   -  只有服务器正常关闭时，才会执行destroy方法。
   -  destroy方法在Servlet被销毁之前执行，一般用于释放资源
### 1.3 Servlet的体系结构  
  Servlet -- 接口
  	|
  GenericServlet -- 抽象类
  	|
  HttpServlet  -- 抽象类
 

-  GenericServlet：将Servlet接口中其他的方法做了默认空实现，只将service()方法作为抽象，将来定义Servlet类时，可以继承GenericServlet，实现service()方法即可
- HttpServlet：对http协议的一种封装，简化操作
   -  定义类继承HttpServlet
   -  复写doGet/doPost方法
## 2 Request类
### 2.1 HTTP请求
请求消息数据格式

1.  请求行

  	请求方式 请求url 请求协议/版本
  	GET /login.html	HTTP/1.1
 

-  请求方式： HTTP协议有7中请求方式，常用的有2种
   -  GET：

              1. 请求参数在请求行中，在url后。
              2. 请求的url长度有限制的
              3. 不太安全

   -  POST：

              1. 请求参数在请求体中
              2. 请求的url长度没有限制的
              3. 相对安全

2.  请求头：客户端浏览器告诉服务器一些信息

  	请求头名称: 请求头值

   -  常见的请求头：

            1. User-Agent：浏览器告诉服务器，我访问你使用的浏览器版本信息
    	                * 可以在服务器端获取该头的信息，解决浏览器的兼容性问题
 
            2. Referer：http://localhost/login.html
    	                * 告诉服务器，我(当前请求)从哪里来？
                        * 作用：
      	1. 防盗链：
      	                     2. 统计工作：
  3. 请求空行
  	空行，就是用于分割POST请求的请求头，和请求体的。
  4. 请求体(正文)：
  	* 封装POST请求消息的请求参数的
* 字符串格式：
```xml
POST /login.html	HTTP/1.1
Host: localhost
User-Agent: Mozilla/5.0 (Windows NT 6.1; Win64; x64; rv:60.0) Gecko/20100101 Firefox/60.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2
Accept-Encoding: gzip, deflate
Referer: http://localhost/login.html
Connection: keep-alive
Upgrade-Insecure-Requests: 1
username=zhangsan
```

	* 响应消息数据格式
### 2.2 request对象  
  ServletRequest             --接口
  	|	继承
  HttpServletRequest	-- 接口
  	|	实现
  org.apache.catalina.connector.RequestFacade 类(tomcat)


### 2.3 功能

1.  获取请求行数据

GET /day14/demo1?name=zhangsan HTTP/1.1

-  方法：

    	    1. 获取请求方式 ：String getMethod()                        GET    
     2. 获取虚拟目录：String getContextPath()                  /day14
    	    3. 获取Servlet路径: String getServletPath()                  /demo1
     4. 获取get方式请求参数：  String getQueryString()    name=zhangsan
    	    5. (*)获取请求URI：
       String getRequestURI():                          /day14/demo1
       StringBuffer getRequestURL()  :             http://localhost/day14/demo1    	
    	    6. 获取协议及版本：String getProtocol()     HTTP/1.1
    7. 获取客户机的IP地址：String getRemoteAddr()

2.  获取请求头数据
- 方法：
   -  String getHeader(String name):通过请求头的名称获取请求头的值
   -  Enumeration<String> getHeaderNames():获取所有的请求头名称
3.  获取请求体数据:
-  请求体：只有POST请求方式，才有请求体，封装了POST请求的请求参数
-  步骤：

    	1. 获取流对象
           BufferedReader getReader()：获取字符输入流，只能操作字符数据
           ServletInputStream getInputStream()：获取字节输入流,可以操作所有类型数据
    	2. 再从流对象中拿数据
### 2.4 其他功能

1.  获取请求参数通用方式：不论get还是post请求方式都可以使用下列方法来获取请求参数

        1. String getParameter(String name):根据参数名称获取参数值                       
        2. String[] getParameterValues(String name):根据参数名称获取参数值的数组 
        3. Enumeration<String> getParameterNames():获取所有请求的参数名称
        4. Map<String,String[]> getParameterMap():获取所有参数的map集合
**post方式：会乱码**

-   解决：在获取参数前，设置request的编码

request.setCharacterEncoding("utf-8");
## 3 Response类
### 3.1 HTTP响应
 数据格式：
            1. 响应行
                1. 组成：协议/版本 响应状态码 状态码描述
                2. 响应状态码：服务器告诉客户端浏览器本次请求和响应的一个状态。
                    1. 状态码都是3位数字 
                    2. 分类：
                        1. 1xx：服务器就收客户端消息，但没有接受完成，等待一段时间后，发送1xx多状态码
                        2. 2xx：成功。代表：200
                        3. 3xx：重定向。代表：302(重定向)，304(访问缓存)
                        4. 4xx：客户端错误。
                            * 代表：
                                * 404（请求路径没有对应的资源） 
                                * 405：请求方式没有对应的doXxx方法
                        5. 5xx：服务器端错误。代表：500(服务器内部出现异常)
            2. 响应头：
                1. 格式：头名称： 值
                2. 常见的响应头：
                    1. Content-Type：服务器告诉客户端本次响应体数据格式以及编码格式
                    2. Content-disposition：服务器告诉客户端以什么格式打开响应体数据
                        * 值：
                            * in-line:默认值,在当前页面内打开
                            * attachment;filename=xxx：以附件形式打开响应体。文件下载
            3. 响应空行
            4. 响应体:传输的数据
```xml
HTTP/1.1 200 OK
Content-Type: text/html;charset=UTF-8
Content-Length: 101
Date: Wed, 06 Jun 2018 07:08:42 GMT
<html>
	<head>
		<title>$Title$</title>
	</head>
	<body>
		hello , response
	</body>
</html>
```
### 3.2 **Response对象**
    * 功能：设置响应消息
        1. 设置响应行
            1. 格式：HTTP/1.1 200 ok
            2. 设置状态码：setStatus(int sc) 
        2. 设置响应头：setHeader(String name, String value) 
            
        3. 设置响应体：
            * 使用步骤：
                1. 获取输出流
                    * 字符输出流：PrintWriter getWriter()
                    * 字节输出流：ServletOutputStream getOutputStream()
                2. 使用输出流，将数据输出到客户端浏览器
### 3.3 重定向&转发

-  重定向的特点:redirect

                1. 地址栏发生变化
                2. 重定向可以访问其他站点(服务器)的资源
                3. 重定向是两次请求。不能使用request对象来共享数据

-  转发的特点：forward

                1. 转发地址栏路径不变
                2. 转发只能访问当前服务器下的资源
                3. 转发是一次请求，可以使用request对象来共享数据
### 3.4 ServletContext

1.  概念：代表整个web应用，可以和程序的容器(服务器)来通信
2.  获取：

        1. 通过request对象获取
            request.getServletContext();
        2. 通过HttpServlet获取
            this.getServletContext();

3.  功能：

        1. 获取MIME类型：
            * MIME类型:在互联网通信过程中定义的一种文件数据类型
                * 格式： 大类型/小类型   text/html       image/jpeg

            * 获取：String getMimeType(String file)  
        2. 域对象：共享数据
            1. setAttribute(String name,Object value)
            2. getAttribute(String name)
            3. removeAttribute(String name)

            * ServletContext对象范围：所有用户所有请求的数据
        3. 获取文件的真实(服务器)路径
            1. 方法：String getRealPath(String path)  
                 String b = context.getRealPath("/b.txt");//web目录下资源访问
                 System.out.println(b);
        
                String c = context.getRealPath("/WEB-INF/c.txt");//WEB-INF目录下的资源访问
                System.out.println(c);
        
                String a = context.getRealPath("/WEB-INF/classes/a.txt");//src目录下的资源访问
                System.out.println(a);
## Cookie

1.  概念：客户端会话技术，将数据保存到客户端

2.  快速入门：

        * 使用步骤：
            1. 创建Cookie对象，绑定数据
                * new Cookie(String name, String value) 
            2. 发送Cookie对象
                * response.addCookie(Cookie cookie) 
            3. 获取Cookie，拿到数据
                * Cookie[]  request.getCookies()  

3.  实现原理

        * 基于响应头set-cookie和请求头cookie实现

