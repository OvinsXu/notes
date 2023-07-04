在博客园找到了很好的教程，将链接放在下面，大家可点击查看。同时转载备份。
# Spring

> 来源----[我没有三颗心脏](https://www.cnblogs.com/wmyskxz/)


[1.Spring学习(1)——快速入门](https://www.cnblogs.com/wmyskxz/p/8820371.html)
[2.Spring学习(2)——Spring IoC 详解](https://www.cnblogs.com/wmyskxz/p/8824597.html)
[3.Spring学习(3)——装配 Spring Bean 详解](https://www.cnblogs.com/wmyskxz/p/8830632.html)
[4.Spring(4)——面向切面编程（AOP模块）](https://www.cnblogs.com/wmyskxz/p/8835243.html)
[5.Spring(5)——Spring 和数据库编程](https://www.cnblogs.com/wmyskxz/p/8845799.html)

# Spring MVC

> 来源----[我没有三颗心脏](https://www.cnblogs.com/wmyskxz/)


[Spring MVC【入门】就这一篇！](https://www.cnblogs.com/wmyskxz/p/8848461.html)

# MyBatis

> 来源----[我没有三颗心脏](https://www.cnblogs.com/wmyskxz/)


[MyBatis(1)——快速入门](https://www.cnblogs.com/wmyskxz/p/8853461.html)

好东西要备份：
# [Spring学习(1)——快速入门](https://www.cnblogs.com/wmyskxz/p/8820371.html)
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121133-d8ebf4e1-758b-43fe-aad8-2152a610359b.png#align=left&display=inline&height=303&originHeight=303&originWidth=773&size=0&status=done&style=none&width=773)
## 认识 Spring 框架
Spring 框架是 Java 应用最广的框架，它的**成功来源于理念，而不是技术本身**，它的理念包括 **IoC (Inversion of Control，控制反转)** 和 **AOP(Aspect Oriented Programming，面向切面编程)**。
#### 什么是 Spring：

1. Spring 是一个**轻量级的 DI / IoC 和 AOP 容器的开源框架**，来源于 Rod Johnson 在其著作**《Expert one on one J2EE design and development》**中阐述的部分理念和原型衍生而来。
2. Spring 提倡以**“最少侵入”**的方式来管理应用中的代码，这意味着我们可以随时安装或者卸载 Spring
- **适用范围：任何 Java 应用**
- **Spring 的根本使命：简化 Java 开发**
> 尽管 J2EE 能够赶上 Spring 的步伐，**但 Spring 并没有停止前进，** Spring 继续在其他领域发展，而 J2EE 则刚刚开始涉及这些领域，或者还没有完全开始在这些领域的创新。**移动开发、社交 API 集成、NoSQL 数据库、云计算以及大数据**都是 Spring 正在涉足和创新的领域。Spring 的前景依然会很美好。

#### Spring 中常用术语：

- **框架：**是能**完成一定功能**的**半成品**。
框架能够帮助我们完成的是：**项目的整体框架、一些基础功能、规定了类和对象如何创建，如何协作等**，当我们开发一个项目时，框架帮助我们完成了一部分功能，我们自己再完成一部分，那这个项目就完成了。
- **非侵入式设计：**
从框架的角度可以理解为：**无需继承框架提供的任何类**
这样我们在更换框架时，之前写过的代码几乎可以继续使用。
- **轻量级和重量级：**
轻量级是相对于重量级而言的，**轻量级一般就是非入侵性的、所依赖的东西非常少、资源占用非常少、部署简单等等**，其实就是**比较容易使用**，而**重量级正好相反**。
- **JavaBean：**
即**符合 JavaBean 规范**的 Java 类
- **POJO：**即 **Plain Old Java Objects，简单老式 Java 对象**
它可以包含业务逻辑或持久化逻辑，但**不担当任何特殊角色**且**不继承或不实现任何其它Java框架的类或接口。**

_注意：bean 的各种名称——虽然 Spring 用 bean 或者 JavaBean 来表示应用组件，但并不意味着 Spring 组件必须遵循 JavaBean 规范，一个 Spring 组件可以是任意形式的 POJO。_

- **容器：**
在日常生活中容器就是一种盛放东西的器具，从程序设计角度看就是**装对象的的对象**，因为存在**放入、拿出等**操作，所以容器还要**管理对象的生命周期**。
#### Spring 的优势

- **低侵入 / 低耦合** （降低组件之间的耦合度，实现软件各层之间的解耦）
- **声明式事务管理**（基于切面和惯例）
- **方便集成其他框架**（如MyBatis、Hibernate）
- **降低 Java 开发难度**
- Spring 框架中包括了 J2EE 三层的每一层的解决方案（一站式）
#### Spring 能帮我们做什么
**①.Spring** 能帮我们根据配置文件**创建及组装对象之间的依赖关系**。
**②.Spring 面向切面编程**能帮助我们**无耦合的实现日志记录，性能统计，安全控制。**
**③.Spring** 能**非常简单的帮我们管理数据库事务**。
**④.Spring** 还**提供了与第三方数据访问框架（如Hibernate、JPA）无缝集成**，而且自己也提供了一套**JDBC访问模板**来方便数据库访问。
**⑤.Spring** 还提供与**第三方Web（如Struts1/2、JSF）框架无缝集成**，而且自己也提供了一套**Spring MVC**框架，来方便web层搭建。
**⑥.Spring** 能**方便的与Java EE（如Java Mail、任务调度）整合**，与**更多技术整合（比如缓存框架）**。
#### Spring 的框架结构
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121142-1839fe39-6908-4136-a663-f6c958f02430.png#align=left&display=inline&height=452&originHeight=452&originWidth=525&size=0&status=done&style=none&width=525)

- **Data Access/Integration层**包含有JDBC、ORM、OXM、JMS和Transaction模块。
- **Web层**包含了Web、Web-Servlet、WebSocket、Web-Porlet模块。
- **AOP模块**提供了一个符合AOP联盟标准的面向切面编程的实现。
- **Core Container(核心容器)：**包含有Beans、Core、Context和SpEL模块。
- **Test模块**支持使用JUnit和TestNG对Spring组件进行测试。

---

## Spring IoC 和 DI 简介
#### IoC：Inverse of Control（控制反转）

- 读作**“反转控制”**，更好理解，不是什么技术，而是一种**设计思想**，就是**将原本在程序中手动创建对象的控制权，交由Spring框架来管理。**
- **正控：**若要使用某个对象，需要**自己去负责对象的创建**
- **反控：**若要使用某个对象，只需要**从 Spring 容器中获取需要使用的对象，不关心对象的创建过程**，也就是把**创建对象的控制权反转给了Spring框架**
- **好莱坞法则：**Don’t call me ,I’ll call you
#### 一个例子
控制反转显然是一个抽象的概念，我们举一个鲜明的例子来说明。
在现实生活中，人们要用到一样东西的时候，第一反应就是去找到这件东西，比如想喝新鲜橙汁，在没有饮品店的日子里，最直观的做法就是：买果汁机、买橙子，然后准备开水。值得注意的是：这些都是你自己**“主动”创造**的过程，也就是说一杯橙汁需要你自己创造。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121138-30ab9c76-b1aa-45a9-8564-5772909c9fc5.png#align=left&display=inline&height=280&originHeight=280&originWidth=705&size=0&status=done&style=none&width=705)
然而到了今时今日，由于饮品店的盛行，当我们想喝橙汁时，第一想法就转换成了找到饮品店的联系方式，通过电话等渠道描述你的需要、地址、联系方式等，下订单等待，过一会儿就会有人送来橙汁了。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121189-eac251f7-982f-4be6-96ae-6d75f94a2643.png#align=left&display=inline&height=214&originHeight=214&originWidth=709&size=0&status=done&style=none&width=709)
**请注意你并没有“主动”去创造橙汁**，橙汁是由饮品店创造的，而不是你，然而也完全达到了你的要求，甚至比你创造的要好上那么一些。
#### 编写第一个 Spring 程序

1. 新建一个空的 Java 项目，命名为【spring】
2. 新建一个名为【lib】的目录，并添加进必要的 jar 包，导入项目

![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121196-7dbe29f6-539c-42cc-a02f-fd84e04810f5.png#align=left&display=inline&height=228&originHeight=228&originWidth=290&size=0&status=done&style=none&width=290)

3. 在 Packge【pojo】下新建一个【Source】类：
```
package pojo;
public class Source {  
    private String fruit;   // 类型
    private String sugar;   // 糖分描述
    private String size;    // 大小杯    
    /* setter and getter */
}
```

4. 在 【src】 目录下新建一个 【applicationContext.xml】 文件，通过 xml 文件配置的方式装配我们的 bean
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">
    <bean name="source" class="pojo.Source">
        <property name="fruit" value="橙子"/>
        <property name="sugar" value="多糖"/>
        <property name="size" value="超大杯"/>
    </bean>
</beans>
```

5. 在 Packge【test】下新建一个【TestSpring】类：
```
package test;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.Source;
public class TestSpring {
    @Test
    public void test(){
        ApplicationContext context = new ClassPathXmlApplicationContext(
                new String[]{"applicationContext.xml"}
        );
        Source source = (Source) context.getBean("source");
        System.out.println(source.getFruit());
        System.out.println(source.getSugar());
        System.out.println(source.getSize());
    }
}
```

6. 运行测试代码，可以正常拿到 xml 配置的 bean

![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121185-1fc3d122-3a7a-42c1-bb2e-b542694a310e.png#align=left&display=inline&height=192&originHeight=192&originWidth=579&size=0&status=done&style=none&width=579)

- **总结：**
- **传统的方式：**
通过new 关键字主动创建一个对象
- **IOC方式：**
对象的生命周期由Spring来管理，直接从Spring那里去获取一个对象。 IOC是反转控制 (Inversion Of Control)的缩写，就像控制权从本来在自己手里，交给了Spring。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121187-8be44136-1565-42ee-aec7-e2d6077ae591.png#align=left&display=inline&height=233&originHeight=233&originWidth=503&size=0&status=done&style=none&width=503)
> 参考地址：[这里](http://how2j.cn/k/spring/spring-ioc-di/87.html#nowhere)

#### DI：Dependency Injection（依赖注入）

- 指 Spring 创建对象的过程中，**将对象依赖属性（简单值，集合，对象）通过配置设值给该对象**
#### 继续上面的例子

1. 在 Packge【pojo】下新建一个【JuiceMaker】类：
```
package pojo;
public class JuiceMaker {
    // 唯一关联了一个 Source 对象
    private Source source = null;
    /* setter and getter */
    public String makeJuice(){
        String juice = "xxx用户点了一杯" + source.getFruit() + source.getSugar() + source.getSize();
        return juice;
    }
}
```

2. 在 xml 文件中配置 JuiceMaker 对象：
- **注意：**这里要使用 ref 来**注入**另一个对象
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">
    <bean name="source" class="pojo.Source">
        <property name="fruit" value="橙子"/>
        <property name="sugar" value="多糖"/>
        <property name="size" value="超大杯"/>
    </bean>
    <bean name="juickMaker" class="pojo.JuiceMaker">
        <property name="source" ref="source" />
    </bean>
</beans>
```

3. 在 【TestSpring】 中添加如下代码：
```
package test;
import org.junit.Test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.JuiceMaker;
import pojo.Source;
public class TestSpring {
    @Test
    public void test(){
        ApplicationContext context = new ClassPathXmlApplicationContext(
                new String[]{"applicationContext.xml"}
        );
        Source source = (Source) context.getBean("source");
        System.out.println(source.getFruit());
        System.out.println(source.getSugar());
        System.out.println(source.getSize());
        JuiceMaker juiceMaker = (JuiceMaker) context.getBean("juickMaker");
        System.out.println(juiceMaker.makeJuice());
    }
}
```

4. 运行测试代码：

![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121193-6f450343-6b23-49db-bce5-3914ea2ac302.png#align=left&display=inline&height=197&originHeight=197&originWidth=593&size=0&status=done&style=none&width=593)
**总结：**IoC 和 DI 其实是同一个概念的不同角度描述，DI 相对 IoC 而言，**明确描述了“被注入对象依赖 IoC 容器配置依赖对象”**
#### IoC 如何实现的
最后我们简单说说IoC是如何实现的。想象一下如果我们自己来实现这个依赖注入的功能，我们怎么来做？ 无外乎：

1. 读取标注或者配置文件，看看JuiceMaker依赖的是哪个Source，拿到类名
2. 使用反射的API，基于类名实例化对应的对象实例
3. 将对象实例，通过构造函数或者 setter，传递给 JuiceMaker

我们发现其实自己来实现也不是很难，Spring实际也就是这么做的。这么看的话其实IoC就是一个工厂模式的升级版！当然要做一个成熟的IoC框架，还是非常多细致的工作要做，Spring不仅提供了一个已经成为业界标准的Java IoC框架，还提供了更多强大的功能，所以大家就别去造轮子啦！希望了解IoC更多实现细节不妨通过学习Spring的源码来加深理解！
> 引用地址：[这里](https://www.tianmaying.com/tutorial/spring-ioc)


---

## Spring AOP 简介
如果说 IoC 是 Spring 的核心，那么面向切面编程就是 Spring 最为重要的功能之一了，在数据库事务中切面编程被广泛使用。
#### AOP 即 Aspect Oriented Program 面向切面编程
首先，在面向切面编程的思想里面，把功能分为核心业务功能，和周边功能。

- **所谓的核心业务**，比如登陆，增加数据，删除数据都叫核心业务
- **所谓的周边功能**，比如性能统计，日志，事务管理等等

周边功能在 Spring 的面向切面编程AOP思想里，即被定义为切面
在面向切面编程AOP的思想里面，核心业务功能和切面功能分别独立进行开发，然后把切面功能和核心业务功能 "编织" 在一起，这就叫AOP
#### AOP 的目的
AOP能够将那些与业务无关，**却为业务模块所共同调用的逻辑或责任（例如事务处理、日志管理、权限控制等）封装起来**，便于**减少系统的重复代码**，**降低模块间的耦合度**，并**有利于未来的可拓展性和可维护性**。
#### AOP 当中的概念：

- 切入点（Pointcut）
在哪些类，哪些方法上切入（**where**）
- 通知（Advice）
在方法执行的什么实际（**when:**方法前/方法后/方法前后）做什么（**what:**增强的功能）
- 切面（Aspect）
切面 = 切入点 + 通知，通俗点就是：**在什么时机，什么地方，做什么增强！**
- 织入（Weaving）
把切面加入到对象，并创建出代理对象的过程。（由 Spring 来完成）
#### AOP 编程

1. 在 Packge【service】下创建 【ProductService】类：
```
package service;
public class ProductService {
    public void doSomeService(){
        System.out.println("doSomeService");
    }
}
```

2. 在 xml 文件中装配该 bean：
```
<bean name="productService" class="service.ProductService" />
```

3. 在【TestSpring】中编写测试代码，运行：

![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121199-4cde8b8a-3799-4f8f-8e61-b460e6c97931.png#align=left&display=inline&height=500&originHeight=500&originWidth=959&size=0&status=done&style=none&width=959)

4. 在 Packge【aspect】下准备日志切面 【LoggerAspect】类：
```
package aspect;
import org.aspectj.lang.ProceedingJoinPoint;
public class LoggerAspect {
    
    public Object log(ProceedingJoinPoint joinPoint) throws Throwable {
        System.out.println("start log:" + joinPoint.getSignature().getName());
        Object object = joinPoint.proceed();
        System.out.println("end log:" + joinPoint.getSignature().getName());
        return object;
    }
}
```

5. 在 xml 文件中声明业务对象和日志切面：
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:aop="http://www.springframework.org/schema/aop"
       xmlns:tx="http://www.springframework.org/schema/tx"
       xmlns:context="http://www.springframework.org/schema/context"
       xsi:schemaLocation="
   http://www.springframework.org/schema/beans
   http://www.springframework.org/schema/beans/spring-beans-3.0.xsd
   http://www.springframework.org/schema/aop
   http://www.springframework.org/schema/aop/spring-aop-3.0.xsd
   http://www.springframework.org/schema/tx
   http://www.springframework.org/schema/tx/spring-tx-3.0.xsd
   http://www.springframework.org/schema/context
   http://www.springframework.org/schema/context/spring-context-3.0.xsd">
    <bean name="productService" class="service.ProductService" />
    <bean id="loggerAspect" class="aspect.LoggerAspect"/>
    <!-- 配置AOP -->
    <aop:config>
        <!-- where：在哪些地方（包.类.方法）做增加 -->
        <aop:pointcut id="loggerCutpoint"
                      expression="execution(* service.ProductService.*(..)) "/>
        <!-- what:做什么增强 -->
        <aop:aspect id="logAspect" ref="loggerAspect">
            <!-- when:在什么时机（方法前/后/前后） -->
            <aop:around pointcut-ref="loggerCutpoint" method="log"/>
        </aop:aspect>
    </aop:config>
</beans>
```

6. 再次运行 TestSpring 中的测试代码，代码并没有改变，但是在业务方法运行之前和运行之后，都分别输出了日志信息：

![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100121174-d635a041-4992-4078-9eb8-828b5abade0a.png#align=left&display=inline&height=543&originHeight=543&originWidth=953&size=0&status=done&style=none&width=953)
# [Spring(2)——Spring IoC 详解](https://www.cnblogs.com/wmyskxz/p/8824597.html)
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100187972-52d057b0-8b1e-451b-bcf6-9c2895a6dcc6.png#align=left&display=inline&height=303&originHeight=303&originWidth=773&size=0&status=done&style=none&width=773)
## Spring IoC 概述
#### IoC：Inverse of Control（控制反转）

- 读作**“反转控制”**，更好理解，不是什么技术，而是一种**设计思想**，就是**将原本在程序中手动创建对象的控制权，交由Spring框架来管理。**
- **正控：**若要使用某个对象，需要**自己去负责对象的创建**
- **反控：**若要使用某个对象，只需要**从 Spring 容器中获取需要使用的对象，不关心对象的创建过程**，也就是把**创建对象的控制权反转给了Spring框架**
- **好莱坞法则：**Don’t call me ,I’ll call you
#### 一个例子
控制反转显然是一个抽象的概念，我们举一个鲜明的例子来说明。
在现实生活中，人们要用到一样东西的时候，第一反应就是去找到这件东西，比如想喝新鲜橙汁，在没有饮品店的日子里，最直观的做法就是：买果汁机、买橙子，然后准备开水。值得注意的是：这些都是你自己**“主动”创造**的过程，也就是说一杯橙汁需要你自己创造。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100187988-a7474ba8-0c9c-441f-876e-a6843eaee622.png#align=left&display=inline&height=280&originHeight=280&originWidth=705&size=0&status=done&style=none&width=705)
然而到了今时今日，由于饮品店的盛行，当我们想喝橙汁时，第一想法就转换成了找到饮品店的联系方式，通过电话等渠道描述你的需要、地址、联系方式等，下订单等待，过一会儿就会有人送来橙汁了。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100188005-71340475-e0ab-4fa5-b7b7-6d627219b8a0.png#align=left&display=inline&height=214&originHeight=214&originWidth=709&size=0&status=done&style=none&width=709)
**请注意你并没有“主动”去创造橙汁**，橙汁是由饮品店创造的，而不是你，然而也完全达到了你的要求，甚至比你创造的要好上那么一些。
#### Spring IoC 阐述
这就是一种控制反转的理念，上述的例子已经很好的说明了问题，我们再来描述一下控制反转的概念：**控制反转是一种通过描述（在 Java 中可以是 XML 或者注解）并通过第三方（Spring）去产生或获取特定对象的方式。**

- **好处：**
降低对象之间的耦合
我们不需要理解一个类的具体实现，只需要知道它有什么用就好了（直接向 IoC 容器拿）

主动创建的模式中，责任归于开发者，而在被动的模式下，责任归于 IoC 容器，**基于这样的被动形式，我们就说对象被控制反转了。（也可以说是反转了控制）**

---

## Spring IoC 容器
Spring 会提供 **IoC 容器**来管理和容纳我们所开发的各种各样的 Bean，并且我们可以从中获取各种发布在 Spring IoC 容器里的 Bean，并且**通过描述**可以得到它。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100188002-c09ef82e-f95e-45b1-aabb-aa54458aea67.png#align=left&display=inline&height=463&originHeight=463&originWidth=917&size=0&status=done&style=none&width=917)
#### Spring IoC 容器的设计
Spring IoC 容器的设计主要是基于以下两个接口：

- **BeanFactory**
- **ApplicationContext**

其中 ApplicationContext 是 BeanFactory 的子接口之一，换句话说：**BeanFactory 是 Spring IoC 容器所定义的最底层接口，**而 ApplicationContext 是其最高级接口之一，并对 BeanFactory 功能做了许多的扩展，所以在**绝大部分的工作场景下**，都会使用 ApplicationContext 作为 Spring IoC 容器。
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100188016-20e4adaa-cbf6-4407-aeb7-c53d52960f01.png#align=left&display=inline&height=260&originHeight=260&originWidth=1189&size=0&status=done&style=none&width=1189)
#### BeanFactory
从上图中我们可以几乎看到， BeanFactory 位于设计的最底层，它提供了 Spring IoC 最底层的设计，为此，我们先来看看该类中提供了哪些方法：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100188032-f63f88e6-af9a-4eb9-bcec-fad33c4ab44c.png#align=left&display=inline&height=305&originHeight=305&originWidth=333&size=0&status=done&style=none&width=333)
由于这个接口的重要性，所以有必要在这里作一下简短的说明：

- 【getBean】 对应了多个方法来获取配置给 Spring IoC 容器的 Bean。
① 按照类型拿 bean：
`bean = (Bean) factory.getBean(Bean.class);`
**注意：**要求在 Spring 中只配置了一个这种类型的实例，否则报错。（如果有多个那 Spring 就懵了，不知道该获取哪一个）
② 按照 bean 的名字拿 bean:
`bean = (Bean) factory.getBean("beanName");`
**注意：**这种方法不太安全，IDE 不会检查其安全性（关联性）
③ 按照名字和类型拿 bean：**（推荐）**
`bean = (Bean) factory.getBean("beanName", Bean.class);`
- 【isSingleton】 用于判断是否单例，如果判断为真，其意思是该 Bean 在容器中是作为一个唯一单例存在的。而【isPrototype】则相反，如果判断为真，意思是当你从容器中获取 Bean，容器就为你生成一个新的实例。
**注意：**在默认情况下，【isSingleton】为 ture，而【isPrototype】为 false
- 关于 type 的匹配，这是一个按 Java 类型匹配的方式
- 【getAliases】方法是获取别名的方法

这就是 Spring IoC 最底层的设计，所有关于 Spring IoC 的容器将会遵守它所定义的方法。
#### ApplicationContext
根据 ApplicationContext 的类继承关系图，可以看到 ApplicationContext 接口扩展了许许多多的接口，因此它的功能十分强大，所以在实际应用中常常会使用到的是 ApplicationContext 接口，因为 BeanFactory 的方法和功能较少，而 ApplicationContext 的方法和功能较多。
通过[上一篇 IoC 的例子](https://www.jianshu.com/p/1af66a499f49)，我们来认识一个 ApplicationContext 的子类——ClassPathXmlApplicationContext。

1. 先在【src】目录下创建一个 【bean.xml】 文件：
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">
    <!-- 通过 xml 方式装配 bean -->
    <bean name="source" class="pojo.Source">
        <property name="fruit" value="橙子"/>
        <property name="sugar" value="多糖"/>
        <property name="size" value="超大杯"/>
    </bean>
</beans>
```

2. 这里定义了一个 bean ，这样 Spring IoC 容器在初始化的时候就能找到它们，然后使用 ClassPathXmlApplicationContext 容器就可以将其初始化：
```
ApplicationContext context = new ClassPathXmlApplicationContext("bean.xml");
Source source = (Source) context.getBean("source", Source.class);
System.out.println(source.getFruit());
System.out.println(source.getSugar());
System.out.println(source.getSize());
```
这样就会使用 Application 的实现类 ClassPathXmlApplicationContext 去初始化 Spring IoC 容器，然后开发者就可以通过 IoC 容器来获取资源了啦！
> 关于 Spring Bean 的装配以及一些细节，会在下一篇文章中讲到

#### ApplicationContext 常见实现类：
1.**ClassPathXmlApplicationContext：**
读取classpath中的资源
```
ApplicationContext ctx = new ClassPathXmlApplicationContext("applicationContext.xml");
```
2:**FileSystemXmlApplicationContext:-**
读取指定路径的资源
```
ApplicationContext ac = new FileSystemXmlApplicationContext("c:/applicationContext.xml");
```
3.**XmlWebApplicationContext:**
需要在Web的环境下才可以运行
```
XmlWebApplicationContext ac = new XmlWebApplicationContext(); // 这时并没有初始化容器
ac.setServletContext(servletContext); // 需要指定ServletContext对象
ac.setConfigLocation("/WEB-INF/applicationContext.xml"); // 指定配置文件路径，开头的斜线表示Web应用的根目录
ac.refresh(); // 初始化容器
```
#### BeanFactory 和 ApplicationContext 的区别：

- **BeanFactory：**是Spring中最底层的接口，只提供了最简单的IoC功能,负责配置，创建和管理bean。
在应用中，一般不使用 BeanFactory，而推荐使用ApplicationContext（应用上下文），原因如下。
- **ApplicationContext：**
1.继承了 BeanFactory，拥有了基本的 IoC 功能；
2.除此之外，ApplicationContext 还提供了以下功能：
① 支持国际化；
② 支持消息机制；
③ 支持统一的资源加载；
④ 支持AOP功能；

---

## Spring IoC 的容器的初始化和依赖注入
虽然 Spring IoC 容器的生成十分的复杂，但是大体了解一下 Spring IoC 初始化的过程还是必要的。这对于理解 Spring 的一系列行为是很有帮助的。
**注意：**Bean 的定义和初始化在 Spring IoC 容器是两大步骤，它是先定义，然后初始化和依赖注入的。

- **Bean 的定义分为 3 步：**
1.Resource 定位
Spring IoC 容器先根据开发者的配置，进行资源的定位，在 Spring 的开发中，通过 XML 或者注解都是十分常见的方式，定位的内容是由开发者提供的。
2.BeanDefinition 的载入
这个时候只是将 Resource 定位到的信息，保存到 Bean 定义（BeanDefinition）中，此时并不会创建 Bean 的实例
3.BeanDefinition 的注册
这个过程就是将 BeanDefinition 的信息发布到 Spring IoC 容器中
**注意：**此时仍然没有对应的 Bean 的实例。

做完了以上 3 步，Bean 就在 Spring IoC 容器中被定义了，而没有被初始化，更没有完成依赖注入，也就是没有注入其配置的资源给 Bean，那么它还不能完全使用。
对于初始化和依赖注入，Spring Bean 还有一个配置选项——**【lazy-init】**，其含义就是**是否初始化 Spring Bean**。在没有任何配置的情况下，它的默认值为 default，实际值为 false，也就是 **Spring IoC 默认会自动初始化 Bean**。如果将其设置为 true，那么只有当我们使用 Spring IoC 容器的 getBean 方法获取它时，它才会进行 Bean 的初始化，完成依赖注入。

---

## IoC 是如何实现的
最后我们简单说说IoC是如何实现的。想象一下如果我们自己来实现这个依赖注入的功能，我们怎么来做？ 无外乎：

1. 读取标注或者配置文件，看看JuiceMaker依赖的是哪个Source，拿到类名
2. 使用反射的API，基于类名实例化对应的对象实例
3. 将对象实例，通过构造函数或者 setter，传递给 JuiceMaker

我们发现其实自己来实现也不是很难，Spring实际也就是这么做的。这么看的话其实IoC就是一个工厂模式的升级版！当然要做一个成熟的IoC框架，还是非常多细致的工作要做，Spring不仅提供了一个已经成为业界标准的Java IoC框架，还提供了更多强大的功能，所以大家就别去造轮子啦！希望了解IoC更多实现细节不妨通过学习Spring的源码来加深理解！
> 引用地址：[这里](https://link.jianshu.com/?t=https%3A%2F%2Fwww.tianmaying.com%2Ftutorial%2Fspring-ioc)
> 【参考资料】:《Java EE 互联网轻量级框架整合开发》、《Spring 实战（第四版）》
> 【好文推荐】：[①Spring 的本质系列(1) -- 依赖注入](https://mp.weixin.qq.com/s?__biz=MzAxOTc0NzExNg==&mid=2665513179&idx=1&sn=772226a5be436a0d08197c335ddb52b8&scene=21#wechat_redirect)、 [②Spring的IoC原理](https://www.tianmaying.com/tutorial/spring-ioc)

# [Spring(3)——装配 Spring Bean 详解](https://www.cnblogs.com/wmyskxz/p/8830632.html)
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241731-efd4ec4f-e187-420b-baff-0f1c7ddb00a0.png#align=left&display=inline&height=303&originHeight=303&originWidth=773&size=0&status=done&style=none&width=773)
## 装配 Bean 的概述
前面已经介绍了 Spring IoC 的理念和设计，这一篇文章将介绍的是如何将自己开发的 Bean 装配到 Spring IoC 容器中。
大部分场景下，我们都会使用 ApplicationContext 的具体实现类，因为对应的 Spring IoC 容器功能相对强大。
而在 Spring 中提供了 3 种方法进行配置：

- 在 XML 文件中显式配置
- 在 Java 的接口和类中实现配置
- 隐式 Bean 的发现机制和自动装配原则
#### 方式选择的原则
在现实的工作中，这 3 种方式都会被用到，并且在学习和工作之中常常混合使用，所以这里给出一些关于这 3 种优先级的建议：
1.**最优先：通过隐式 Bean 的发现机制和自动装配的原则。**
基于约定由于配置的原则，这种方式应该是最优先的

- **好处：**减少程序开发者的决定权，简单又不失灵活。

2.**其次：Java 接口和类中配置实现配置**
在没有办法使用自动装配原则的情况下应该优先考虑此类方法

- **好处：**避免 XML 配置的泛滥，也更为容易。
- **典型场景：**一个父类有多个子类，比如学生类有两个子类，一个男学生类和女学生类，通过 IoC 容器初始化一个学生类，容器将无法知道使用哪个子类去初始化，这个时候可以使用 Java 的注解配置去指定。

3.**最后：XML 方式配置**
在上述方法都无法使用的情况下，那么也只能选择 XML 配置的方式。

- **好处：**简单易懂（当然，特别是对于初学者）
- **典型场景：**当使用第三方类的时候，有些类并不是我们开发的，我们无法修改里面的代码，这个时候就通过 XML 的方式配置使用了。

---

## 通过 XML 配置装配 Bean
使用 XML 装配 Bean 需要定义对应的 XML，这里需要引入对应的 XML 模式（XSD）文件，这些文件会定义配置 Spring Bean 的一些元素，当我们在 IDEA 中创建 XML 文件时，会有友好的提示：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241766-a1a1cad4-7df3-48d2-9402-44fea381e0de.png#align=left&display=inline&height=166&originHeight=166&originWidth=476&size=0&status=done&style=none&width=476)
一个简单的 XML 配置文件如下：
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xsi:schemaLocation="http://www.springframework.org/schema/beans http://www.springframework.org/schema/beans/spring-beans.xsd">
</beans>
```
这就只是一个格式文件，引入了一个 beans 的定义，引入了 xsd 文件，它是一个根元素，这样它所定义的元素将可以定义对应的 Spring Bean
#### 装配简易值
先来一个最简单的装配：
```
<bean id="c" class="pojo.Category">
    <property name="name" value="测试" />
</bean>
```
简单解释一下：

- `id` 属性是 Spring 能找到当前 Bean 的一个依赖的编号，**遵守 XML 语法的 ID 唯一性约束。必须以字母开头，**可以使用_字母、数字、连字符、下划线、句号、冒号_，**不能以 `/` 开头**。
不过 `id` 属性**不是一个必需的属性**，`name` 属性也可以定义 bean 元素的名称，能以逗号或空格隔开**起多个别名**，并且可以**使用很多的特殊字符**，比如在 Spring 和 Spring MVC 的整合中，就得使用 `name` 属性来定义 bean 的名称，并且使用 `/` 开头。
**注意：** 从 Spring 3.1 开始，`id` 属性也可以是 String 类型了，也就是说 `id` 属性也可以使用 `/` 开头，而 bean 元素的 id 的唯一性由容器负责检查。
如果 `id` 和 `name` 属性都没有声明的话，那么 Spring 将会采用 **“全限定名#{number}”** 的格式生成编号。 例如这里，如果没有声明 “`id="c"`” 的话，那么 Spring 为其生成的编号就是 “`pojo.Category#0`”，当它第二次声明没有 `id` 属性的 Bean 时，编号就是 “`pojo.Category#1`”，以此类推。
- `class` 属性显然就是一个类的全限定名
- `property` 元素是定义类的属性，其中的 `name` 属性定义的是属性的名称，而 `value` 是它的值。

这样的定义很简单，但是有时候需要注入一些自定义的类，比如之前饮品店的例子，JuickMaker 需要用户提供原料信息才能完成 juice 的制作：
```
<!-- 配置 srouce 原料 -->
<bean name="source" class="pojo.Source">
    <property name="fruit" value="橙子"/>
    <property name="sugar" value="多糖"/>
    <property name="size" value="超大杯"/>
</bean>
<bean name="juickMaker" class="pojo.JuiceMaker">
    <!-- 注入上面配置的id为srouce的Srouce对象 -->
    <property name="source" ref="source"/>
</bean>
```
这里先定义了一个 `name` 为 source 的 Bean，然后再制造器中**通过 `ref` 属性**去引用对应的 Bean，而 source 正是之前定义的 Bean 的 `name` ，这样就可以相互引用了。

- **注入对象：**使用 `ref` 属性
#### 装配集合
有些时候我们需要装配一些复杂的东西，比如 Set、Map、List、Array 和 Properties 等，为此我们在 Packge【pojo】下新建一个 ComplexAssembly 类：
```
package pojo;
import java.util.List;
import java.util.Map;
import java.util.Properties;
import java.util.Set;
public class ComplexAssembly {
	
	private Long id;
	private List<String> list;
	private Map<String, String> map;
	private Properties properties;
	private Set<String> set;
	private String[] array;
    /* setter and getter */
}
```
这个 Bean 没有任何的实际意义，知识为了介绍如何装配这些常用的集合类：
```
<bean id="complexAssembly" class="pojo.ComplexAssembly">
    <!-- 装配Long类型的id -->
    <property name="id" value="1"/>
    
    <!-- 装配List类型的list -->
    <property name="list">
        <list>
            <value>value-list-1</value>
            <value>value-list-2</value>
            <value>value-list-3</value>
        </list>
    </property>
    
    <!-- 装配Map类型的map -->
    <property name="map">
        <map>
            <entry key="key1" value="value-key-1"/>
            <entry key="key2" value="value-key-2"/>
            <entry key="key3" value="value-key-2"/>
        </map>
    </property>
    
    <!-- 装配Properties类型的properties -->
    <property name="properties">
        <props>
            <prop key="prop1">value-prop-1</prop>
            <prop key="prop2">value-prop-2</prop>
            <prop key="prop3">value-prop-3</prop>
        </props>
    </property>
    
    <!-- 装配Set类型的set -->
    <property name="set">
        <set>
            <value>value-set-1</value>
            <value>value-set-2</value>
            <value>value-set-3</value>
        </set>
    </property>
    
    <!-- 装配String[]类型的array -->
    <property name="array">
        <array>
            <value>value-array-1</value>
            <value>value-array-2</value>
            <value>value-array-3</value>
        </array>
    </property>
</bean>
```

- **总结：**
- List 属性为对应的 `<list>` 元素进行装配，然后通过多个 `<value>` 元素设值
- Map 属性为对应的 `<map>` 元素进行装配，然后通过多个 `<entry>` 元素设值，只是 `entry` 包含一个键值对(key-value)的设置
- Properties 属性为对应的 `<properties>` 元素进行装配，通过多个 `<property>` 元素设值，只是 `properties` 元素有一个必填属性 `key` ，然后可以设置值
- Set 属性为对应的 `<set>` 元素进行装配，然后通过多个 `<value>` 元素设值
- 对于数组而言，可以使用 `<array>` 设置值，然后通过多个 `<value>` 元素设值。

上面看到了对简单 String 类型的各个集合的装载，但是有些时候可能需要更为复杂的装载，比如一个 List 可以是一个系列类的对象，为此需要定义注入的相关信息，其实跟上面的配置没什么两样，只不过加入了 `ref` 这一个属性而已：

- **集合注入总结：**
- List 属性使用 `<list>` 元素定义注入，使用多个 `<ref>` 元素的 Bean 属性去引用之前定义好的 Bean
```
<property name="list">
    <list>
        <ref bean="bean1"/>
        <ref bean="bean2"/>
    </list>
</property>
```

- Map 属性使用 `<map>` 元素定义注入，使用多个 `<entry>` 元素的 `key-ref` 属性去引用之前定义好的 Bean 作为键，而用 `value-ref` 属性引用之前定义好的 Bean 作为值
```
<property name="map">
    <map>
        <entry key-ref="keyBean" value-ref="valueBean"/>
    </map>
</property>
```

- Set 属性使用 `<set>` 元素定义注入，使用多个 `<ref>` 元素的 `bean` 去引用之前定义好的 Bean
```
<property name="set">
    <set>
        <ref bean="bean"/>
    </set>
</property>
```
#### 命名空间装配
除了上述的配置之外， Spring 还提供了对应的命名空间的定义，只是在使用命名空间的时候要先引入对应的命名空间和 XML 模式（XSD）文件。
##### ——【① c-命名空间】——
c-命名空间是在 Spring 3.0 中引入的，它是在 XML 中更为简洁地描述构造器参数的方式，要使用它的话，必须要在 XML 的顶部声明其模式：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241852-67ac1f51-c60f-4ffb-af4b-87dbb9592690.png#align=left&display=inline&height=120&originHeight=120&originWidth=726&size=0&status=done&style=none&width=726)

- **注意：是通过构造器参数的方式**

现在假设我们现在有这么一个类：
```
package pojo;
public class Student {
	int id;
	String name;
	public Student(int id, String name) {
		this.id = id;
		this.name = name;
	}
    // setter and getter
}
```
在 c-命名空间和模式声明之后，我们就可以使用它来声明构造器参数了：
```
<!-- 引入 c-命名空间之前 -->
<bean name="student1" class="pojo.Student">
    <constructor-arg name="id" value="1" />
    <constructor-arg name="name" value="学生1"/>
</bean>
<!-- 引入 c-命名空间之后 -->
<bean name="student2" class="pojo.Student"
      c:id="2" c:name="学生2"/>
```
c-命名空间属性名**以 “`c:`” 开头**，也就是命名空间的前缀。接下来就是**要装配的构造器参数名**，在此之后如果需要注入对象的话则要跟上 `-ref`（如`c:card-ref="idCard1"`，则对 card 这个构造器参数注入之前配置的名为 idCard1 的 bean）
很显然，使用 c-命名空间属性要比使用 `<constructor-arg>` 元素精简，并且会直接引用构造器之中参数的名称，这有利于我们使用的安全性。
我们有另外一种替代方式：
```
<bean name="student2" class="pojo.Student"
      c:_0="3" c:_1="学生3"/>
```
我们将参数的名称替换成了 “0” 和 “1” ，也就是参数的索引。因为在 XML 中不允许数字作为属性的第一个字符，因此必须要添加一个下划线来作为前缀。
##### ——【② p-命名空间】——
c-命名空间通过构造器注入的方式来配置 bean，p-命名空间则是用setter的注入方式来配置 bean ，同样的，我们需要引入声明：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241807-12c5f605-6aae-4787-8860-102192aaf40b.png#align=left&display=inline&height=145&originHeight=145&originWidth=729&size=0&status=done&style=none&width=729)
然后我们就可以通过 p-命名空间来设置属性：
```
<!-- 引入p-命名空间之前 -->
<bean name="student1" class="pojo.Student">
    <property name="id" value="1" />
    <property name="name" value="学生1"/>
</bean>
<!-- 引入p-命名空间之后 -->
<bean name="student2" class="pojo.Student" 
      p:id="2" p:name="学生2"/>
```
我们需要先删掉 Student 类中的构造函数，不然 XML 约束会提示我们配置 `<constructor-arg>` 元素。
同样的，如果属性需要注入其他 Bean 的话也可以在后面跟上 `-ref`：
```
<bean name="student2" class="pojo.Student"
          p:id="2" p:name="学生2" p:cdCard-ref="cdCard1"/>
```
##### ——【③ util-命名空间】——
工具类的命名空间，可以简化集合类元素的配置，同样的我们需要引入其声明（无需担心怎么声明的问题，IDEA会有很友好的提示）：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241804-94662468-96a7-4c16-824b-8e8b946d853e.png#align=left&display=inline&height=161&originHeight=161&originWidth=720&size=0&status=done&style=none&width=720)
我们来看看引入前后的变化：
```
<!-- 引入util-命名空间之前 -->
<property name="list">
    <list>
        <ref bean="bean1"/>
        <ref bean="bean2"/>
    </list>
</property>
<!-- 引入util-命名空间之后 -->
<util:list id="list">
    <ref bean="bean1"/>
    <ref bean="bean2"/>
</util:list>
```
`<util:list>` 只是 util-命名空间中的多个元素之一，下表提供了 util-命名空间提供的所有元素：

| 元素 | 描述 |
| :--- | :--- |
| `<util:constant>` | 引用某个类型的 `public static` 域，并将其暴露为 bean |
| `<util:list>` | 创建一个 `java.util.List` 类型的 bean，其中包含值或引用 |
| `<util:map>` | 创建一个 `java.util.map` 类型的 bean，其中包含值或引用 |
| `<util:properties>` | 创建一个 `java.util.Properties` 类型的 bean |
| `<util:property-path>` | 引用一个 bean 的属性（或内嵌属性），并将其暴露为 bean |
| `<util:set>` | 创建一个 `java.util.Set` 类型的 bean，其中包含值或引用 |

#### 引入其他配置文件
在实际开发中，随着应用程序规模的增加，系统中 `<bean>` 元素配置的数量也会大大增加，导致 applicationContext.xml 配置文件变得非常臃肿难以维护。

- **解决方案：**让 applicationContext.xml 文件包含其他配置文件即可
使用 `<import>` 元素引入其他配置文件

1.在【src】文件下新建一个 bean.xml 文件，写好基础的约束，把 applicationContext.xml 文件中配置的 `<bean>` 元素复制进去
2.在 applicationContext.xml 文件中写入：
```
<import resource="bean.xml" />
```
3.运行测试代码，仍然能正确获取到 bean:
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241818-5d80eb0d-aaf3-4c4f-8ba5-88001d673895.png#align=left&display=inline&height=180&originHeight=180&originWidth=517&size=0&status=done&style=none&width=517)

---

## 通过注解装配 Bean
上面，我们已经了解了如何使用 XML 的方式去装配 Bean，但是更多的时候已经不再推荐使用 XML 的方式去装配 Bean，更多的时候回考虑使用注解（annotation） 的方式去装配 Bean。

- **优势：**
1.可以减少 XML 的配置，当配置项多的时候，臃肿难以维护
2.功能更加强大，既能实现 XML 的功能，也提供了自动装配的功能，采用了自动装配后，程序猿所需要做的决断就少了，更加有利于对程序的开发，这就是“约定由于配置”的开发原则

在 Spring 中，它提供了两种方式来让 Spring IoC 容器发现 bean：

- **组件扫描：**通过定义资源的方式，让 Spring IoC 容器扫描对应的包，从而把 bean 装配进来。
- **自动装配：**通过注解定义，使得一些依赖关系可以通过注解完成。
### 使用@Compoent 装配 Bean
我们把之前创建的 Student 类改一下：
```
package pojo;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
@Component(value = "student1")
public class Student {
	@Value("1")
	int id;
	@Value("student_name_1")
	String name;
    // getter and setter
}
```
解释一下：

- **@Component注解：**
表示 Spring IoC 会把这个类扫描成一个 bean 实例，而其中的 `value` 属性代表这个类在 Spring 中的 `id`，这就相当于在 XML 中定义的 Bean 的 id：`<bean id="student1" class="pojo.Student" />`，也可以简写成 `@Component("student1")`，甚至直接写成 `@Component` ，对于不写的，Spring IoC 容器就默认以类名来命名作为 `id`，只不过首字母小写，配置到容器中。
- **@Value注解：**
表示值的注入，跟在 XML 中写 `value` 属性是一样的。

这样我们就声明好了我们要创建的一个 Bean，就像在 XML 中写下了这样一句话：
```
<bean name="student1" class="pojo.Student">
    <property name="id" value="1" />
    <property name="name" value="student_name_1"/>
</bean>
```
但是现在我们声明了这个类，并不能进行任何的测试，因为 Spring IoC 并不知道这个 Bean 的存在，这个时候我们可以使用一个 StudentConfig 类去告诉 Spring IoC ：
```
package pojo;
import org.springframework.context.annotation.ComponentScan;
@ComponentScan
public class StudentConfig {
}
```
这个类十分简单，没有任何逻辑，但是需要说明两点：

- **该类和 Student 类位于同一包名下**
- **@ComponentScan注解：**
代表进行扫描，**默认是扫描当前包的路径**，扫描所有带有 `@Component` 注解的 POJO。

这样一来，我们就可以通过 Spring 定义好的 Spring IoC 容器的实现类——AnnotationConfigApplicationContext 去生成 IoC 容器了：
```
ApplicationContext context = new AnnotationConfigApplicationContext(StudentConfig.class);
Student student = (Student) context.getBean("student1", Student.class);
student.printInformation();
```
这里可以看到使用了 AnnotationConfigApplicationContext 类去初始化 Spring IoC 容器，它的配置项是 StudentConfig 类，这样 Spring IoC 就会根据注解的配置去解析对应的资源，来生成 IoC 容器了。

- **明显的弊端：**
- 对于 `@ComponentScan` 注解，它只是扫描所在包的 Java 类，但是更多的时候我们希望的是可以扫描我们指定的类
- 上面的例子只是注入了一些简单的值，测试发现，通过 `@Value` 注解并不能注入对象

`@Component` 注解存在着两个配置项：

- **basePackages：**它是由 base 和 package 两个单词组成的，而 package 还是用了复数，意味着**它可以配置一个 Java 包的数组**，Spring 会根据它的配置扫描对应的包和子包，将配置好的 Bean 装配进来
- **basePackageClasses**：它由 base、package 和 class 三个单词组成，采用复数，意味着它可以配置多个类， Spring 会根据配置的类所在的包，为包和子包进行扫描装配对应配置的 Bean

我们来试着重构之前写的 StudentConfig 类来验证上面两个配置项：
```
package pojo;
import org.springframework.context.annotation.ComponentScan;
@ComponentScan(basePackages = "pojo")
public class StudentConfig {
}
//  —————————————————— 【 宇宙超级无敌分割线】—————————————————— 
package pojo;
import org.springframework.context.annotation.ComponentScan;
@ComponentScan(basePackageClasses = pojo.Student.class)
public class StudentConfig {
}
```
验证都能通过，bingo！

- 对于 【basePackages】 和 【basePackageClasses】 的选择问题：
【basePackages】 的可读性会更好一些，所以在项目中会优先选择使用它，但是在需要大量重构的工程中，尽量不要使用【basePackages】，因为很多时候重构修改包名需要反复地配置，而 IDE 不会给你任何的提示，而采用【basePackageClasses】会有错误提示。
### 自动装配——@Autowired
上面提到的两个弊端之一就是没有办法注入对象，通过自动装配我们将解决这个问题。
所谓自动装配技术是一种**由 Spring 自己发现对应的 Bean，自动完成装配工作的方式，**它会应用到一个十分常用的注解 `@Autowired` 上，这个时候 **Spring 会根据类型去寻找定义的 Bean 然后将其注入**，听起来很神奇，让我们实际来看一看：
1.先在 Package【service】下创建一个 StudentService 接口：
```
package service;
public interface StudentService {
	public void printStudentInfo();
}
```
使用接口是 Spring 推荐的方式，这样可以更为灵活，可以将定义和实现分离
2.为上面的接口创建一个 StudentServiceImp 实现类：
```
package service;
import org.springframework.beans.factory.annotation.Autowired;
import pojo.Student;
@Component("studentService")
public class StudentServiceImp implements StudentService {
	@Autowired
	private Student student = null;
     // getter and setter
	public void printStudentInfo() {
		System.out.println("学生的 id 为：" + student.getName());
		System.out.println("学生的 name 为：" + student.getName());
	}
}
```
该实现类实现了接口的 printStudentInfo() 方法，打印出成员对象 student 的相关信息，这里的 `@Autowired` 注解，表示**在 Spring IoC 定位所有的 Bean 后，这个字段需要按类型注入**，这样 IoC 容器就会**寻找资源**，然后将其注入。
3.编写测试类：
```
// 第一步：修改 StudentConfig 类，告诉 Spring IoC 在哪里去扫描它：
package pojo;
import org.springframework.context.annotation.ComponentScan;
@ComponentScan(basePackages = {"pojo", "service"})
public class StudentConfig {
}
// 或者也可以在 XML 文件中声明去哪里做扫描
<context:component-scan base-package="pojo" />
<context:component-scan base-package="service" />
// 第二步：编写测试类：
package test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import pojo.StudentConfig;
import service.StudentService;
import service.StudentServiceImp;
public class TestSpring {
	public static void main(String[] args) {
		// 通过注解的方式初始化 Spring IoC 容器
		ApplicationContext context = new AnnotationConfigApplicationContext(StudentConfig.class);
		StudentService studentService = context.getBean("studentService", StudentServiceImp.class);
		studentService.printStudentInfo();
	}
}
```
运行代码：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100241833-0ad0175e-2813-45a9-875a-bbb469e55513.png#align=left&display=inline&height=145&originHeight=145&originWidth=516&size=0&status=done&style=none&width=516)

- **再次理解：** `@Autowired` 注解表示在 Spring IoC 定位所有的 Bean 后，再根据类型寻找资源，然后将其注入。
- **过程：** 定义 Bean ——》 初始化 Bean（扫描） ——》 根据属性需要从 Spring IoC 容器中搜寻满足要求的 Bean ——》 满足要求则注入
- **问题：** IoC 容器可能会寻找失败，此时会抛出异常（默认情况下，Spring IoC 容器会认为一定要找到对应的 Bean 来注入到这个字段，但有些时候并不是一定需要，比如日志）
- **解决：** 通过配置项 `required` 来改变，比如 `@Autowired(required = false)`

`@Autowired` 注解不仅仅能配置在属性之上，还允许方法配置，常见的 Bean 的 setter 方法也可以使用它来完成注入，总之一切需要 Spring IoC 去寻找 Bean 资源的地方都可以用到，例如：
```
/* 包名和import */
public class JuiceMaker {
    ......
    @Autowired
    public void setSource(Source source) {
        this.source = source;
    }
}
```
在大部分的配置中都推荐使用这样的自动注入来完成，这是 Spring IoC 帮助我们自动装配完成的，这样使得配置大幅度减少，满足约定优于配置的原则，增强程序的健壮性。
#### 自动装配的歧义性（@Primary和@Qualifier）
在上面的例子中我们使用 `@Autowired` 注解来自动注入一个 Source 类型的 Bean 资源，但如果我们现在有两个 Srouce 类型的资源，Spring IoC 就会不知所措，不知道究竟该引入哪一个 Bean：
```
<bean name="source1" class="pojo.Source">
    <property name="fruit" value="橙子"/>
    <property name="sugar" value="多糖"/>
    <property name="size" value="超大杯"/>
</bean>
<bean name="source2" class="pojo.Source">
    <property name="fruit" value="橙子"/>
    <property name="sugar" value="少糖"/>
    <property name="size" value="小杯"/>
</bean>
```
我们可以会想到 Spring IoC 最底层的容器接口——BeanFactory 的定义，它存在一个按照类型获取 Bean 的方法，显然通过 Source.class 作为参数**无法判断使用哪个类实例进行返回**，这就是自动装配的歧义性。
为了消除歧义性，Spring 提供了两个注解：

- **@Primary 注解：**
代表首要的，当 Spring IoC 检测到有多个相同类型的 Bean 资源的时候，会优先注入使用该注解的类。
- **问题：**该注解只是解决了首要的问题，但是并没有选择性的问题
- **@Qualifier 注解：**
上面所谈及的歧义性，一个重要的原因是 Spring 在寻找依赖注入的时候是按照类型注入引起的。除了按类型查找 Bean，Spring IoC 容器最底层的接口 BeanFactory 还提供了按名字查找的方法，如果按照名字来查找和注入不就能消除歧义性了吗？
- **使用方法：** 指定注入名称为 "source1" 的 Bean 资源
```
/* 包名和import */
public class JuiceMaker {
    ......
    @Autowired
    @Qualifier("source1")
    public void setSource(Source source) {
        this.source = source;
    }
}
```
#### 使用@Bean 装配 Bean

- **问题：** 以上都是通过 `@Component` 注解来装配 Bean ，并且只能注解在类上，当你需要引用第三方包的（jar 文件），而且往往并没有这些包的源码，这时候将无法为这些包的类加入 `@Component` 注解，让它们变成开发环境中的 Bean 资源。
- **解决方案：**
1.自己创建一个新的类来扩展包里的类，然后再新类上使用 `@Component` 注解，**但这样很 low**
2.**使用 `@Bean` 注解，注解到方法之上**，使其成为 Spring 中返回对象为 Spring 的 Bean 资源。

我们在 Package【pojo】 下新建一个用来测试 `@Bean` 注解的类：
```
package pojo;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
@Configuration
public class BeanTester {
    @Bean(name = "testBean")
    public String test() {
        String str = "测试@Bean注解";
        return str;
    }
}
```

- **注意：** `@Configuration` 注解相当于 XML 文件的根元素，**必须要**，有了才能解析其中的 `@Bean` 注解

然后我们在测试类中编写代码，从 Spring IoC 容器中获取到这个 Bean ：
```
// 在 pojo 包下扫描
ApplicationContext context = new AnnotationConfigApplicationContext("pojo");
// 因为这里获取到的 Bean 就是 String 类型所以直接输出
System.out.println(context.getBean("testBean"));
```
`@Bean` 的配置项中包含 4 个配置项：

- **name：** 是一个字符串数组，允许配置多个 BeanName
- **autowire：** 标志是否是一个引用的 Bean 对象，默认值是 Autowire.NO
- **initMethod：** 自定义初始化方法
- **destroyMethod：** 自定义销毁方法

使用 `@Bean` 注解的好处就是能够动态获取一个 Bean 对象，能够根据环境不同得到不同的 Bean 对象。或者说将 Spring 和其他组件分离（其他组件不依赖 Spring，但是又想 Spring 管理生成的 Bean）
#### Bean 的作用域
**在默认的情况下，Spring IoC 容器只会对一个 Bean 创建一个实例**，但有时候，我们希望能够通过 Spring IoC 容器获取多个实例，我们可以通过 `@Scope` 注解或者 `<bean>` 元素中的 `scope` 属性来设置，例如：
```
// XML 中设置作用域
<bean id="" class="" scope="prototype" />
// 使用注解设置作用域
@Scope(ConfigurableBeanFactory.SCOPE_PROTOTYPE)
```
Spring 提供了 5 种作用域，它会根据情况来决定是否生成新的对象：

| 作用域类别 | 描述 |
| :--- | :--- |
| singleton(单例) | 在Spring IoC容器中仅存在一个Bean实例 （默认的scope） |
| prototype(多例) | 每次从容器中调用Bean时，都返回一个新的实例，即每次调用getBean()时 ，相当于执行new XxxBean()：不会在容器启动时创建对象 |
| request(请求) | 用于web开发，将Bean放入request范围 ，request.setAttribute("xxx") ， 在同一个request 获得同一个Bean |
| session(会话) | 用于web开发，将Bean 放入Session范围，在同一个Session 获得同一个Bean |
| globalSession(全局会话) | 一般用于 Porlet 应用环境 , 分布式系统存在全局 session 概念（单点登录），如果不是 porlet 环境，globalSession 等同于 Session |

在开发中主要使用 `scope="singleton"`、`scope="prototype"`，**对于MVC中的Action使用prototype类型，其他使用singleton**，Spring容器会管理 Action 对象的创建,此时把 Action 的作用域设置为 prototype.
> 扩展阅读：[@Profile 注解](https://blog.csdn.net/u013803262/article/details/62416880) 、 [条件化装配 Bean](https://blog.csdn.net/tinydolphin/article/details/76253771)

#### Spring 表达式语言简要说明
Spring 还提供了更灵活的注入方式，那就是 Spring 表达式，实际上 Spring EL 远比以上注入方式都要强大，它拥有很多功能：

- 使用 Bean 的 id 来引用 Bean
- 调用指定对象的方法和访问对象的属性
- 进行运算
- 提供正则表达式进行匹配
- 集合配置

我们来看一个简单的使用 Spring 表达式的例子：
```
package pojo;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.stereotype.Component;
@Component("elBean")
public class ElBean {
    // 通过 beanName 获取 bean，然后注入 
    @Value("#{role}")
    private Role role;
    
    // 获取 bean 的属性 id
    @Value("#{role.id}")
    private Long id;
    
    // 调用 bean 的 getNote 方法
    @Value("#{role.getNote().toString()}")
    private String note;
    /* getter and setter */
}
```
与属性文件中读取使用的 “`$`” 不同，在 Spring EL 中则使用 “`#`”
> 扩展阅读： [Spring 表达式语言](https://www.cnblogs.com/best/p/5748105.html)

#### 参考资料：

- 《Java EE 互联网轻量级框架整合开发》
- 《Java 实战（第四版）》
- 万能的百度 and 万能的大脑
# [Spring(4)——面向切面编程（AOP模块）](https://www.cnblogs.com/wmyskxz/p/8835243.html)
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100277500-2bf96987-ad0b-46fe-a5f3-e219f094f5a4.png#align=left&display=inline&height=303&originHeight=303&originWidth=773&size=0&status=done&style=none&width=773)
## Spring AOP 简介
如果说 IoC 是 Spring 的核心，那么面向切面编程就是 Spring 最为重要的功能之一了，在数据库事务中切面编程被广泛使用。
#### AOP 即 Aspect Oriented Program 面向切面编程
首先，在面向切面编程的思想里面，把功能分为核心业务功能，和周边功能。

- **所谓的核心业务**，比如登陆，增加数据，删除数据都叫核心业务
- **所谓的周边功能**，比如性能统计，日志，事务管理等等

周边功能在 Spring 的面向切面编程AOP思想里，即被定义为切面
在面向切面编程AOP的思想里面，核心业务功能和切面功能分别独立进行开发，然后把切面功能和核心业务功能 "编织" 在一起，这就叫AOP
#### AOP 的目的
AOP能够将那些与业务无关，**却为业务模块所共同调用的逻辑或责任（例如事务处理、日志管理、权限控制等）封装起来**，便于**减少系统的重复代码**，**降低模块间的耦合度**，并**有利于未来的可拓展性和可维护性**。
#### AOP 当中的概念：

- 切入点（Pointcut）
在哪些类，哪些方法上切入（**where**）
- 通知（Advice）
在方法执行的什么实际（**when:**方法前/方法后/方法前后）做什么（**what:**增强的功能）
- 切面（Aspect）
切面 = 切入点 + 通知，通俗点就是：**在什么时机，什么地方，做什么增强！**
- 织入（Weaving）
把切面加入到对象，并创建出代理对象的过程。（由 Spring 来完成）
#### 一个例子
为了更好的说明 AOP 的概念，我们来举一个实际中的例子来说明：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100277544-d7d54157-22b4-49c7-ae03-10b9922eb2be.png#align=left&display=inline&height=461&originHeight=461&originWidth=440&size=0&status=done&style=none&width=440)
在上面的例子中，包租婆的核心业务就是签合同，收房租，那么这就够了，灰色框起来的部分都是重复且边缘的事，交给中介商就好了，这就是 **AOP 的一个思想：让关注点代码与业务代码分离！**
#### 实际的代码
我们来实际的用代码感受一下
1.在 Package【pojo】下新建一个【Landlord】类（我百度翻译的包租婆的英文）：
```
package pojo;
import org.springframework.stereotype.Component;
@Component("landlord")
public class Landlord {
	public void service() {
        // 仅仅只是实现了核心的业务功能
		System.out.println("签合同");
		System.out.println("收房租");
	}
}
```
2.在 Package【aspect】下新建一个中介商【Broker】类（我还是用的翻译...）：
```
package aspect;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.stereotype.Component;
@Component
@Aspect
class Broker {
	@Before("execution(* pojo.Landlord.service())")
	public void before(){
		System.out.println("带租客看房");
		System.out.println("谈价格");
	}
	@After("execution(* pojo.Landlord.service())")
	public void after(){
		System.out.println("交钥匙");
	}
}
```
3.在 applicationContext.xml 中配置自动注入，并告诉 Spring IoC 容器去哪里扫描这两个 Bean：
```
<?xml version="1.0" encoding="UTF-8"?>
<beans xmlns="http://www.springframework.org/schema/beans"
       xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
       xmlns:context="http://www.springframework.org/schema/context"
       xmlns:aop="http://www.springframework.org/schema/aop"
       xsi:schemaLocation="http://www.springframework.org/schema/beans
       http://www.springframework.org/schema/beans/spring-beans.xsd http://www.springframework.org/schema/context http://www.springframework.org/schema/context/spring-context.xsd http://www.springframework.org/schema/aop http://www.springframework.org/schema/aop/spring-aop.xsd">
    <context:component-scan base-package="aspect" />
    <context:component-scan base-package="pojo" />
    <aop:aspectj-autoproxy/>
</beans>
```
4.在 Package【test】下编写测试代码：
```
package test;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;
import pojo.Landlord;
public class TestSpring {
	public static void main(String[] args) {
		ApplicationContext context =
				new ClassPathXmlApplicationContext("applicationContext.xml");
		Landlord landlord = (Landlord) context.getBean("landlord", Landlord.class);
		landlord.service();
	}
}
```
5.执行看到效果：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100277525-48e558e4-5346-4db9-95bc-1eefc71d39a8.png#align=left&display=inline&height=201&originHeight=201&originWidth=537&size=0&status=done&style=none&width=537)
这个例子使用了一些注解，现在看不懂没有关系，但我们可以从上面可以看到，我们在 Landlord 的 service() 方法中仅仅实现了核心的业务代码，其余的关注点功能是根据我们设置的切面**自动补全**的。

---

## 使用注解来开发 Spring AOP
使用注解的方式已经逐渐成为了主流，所以我们利用上面的例子来说明如何用注解来开发 Spring AOP
#### 第一步：选择连接点
Spring 是方法级别的 AOP 框架，我们主要也是以某个类额某个方法作为连接点，另一种说法就是：**选择哪一个类的哪一方法用以增强功能。**
```
....
    public void service() {
        // 仅仅只是实现了核心的业务功能
        System.out.println("签合同");
        System.out.println("收房租");
    }
    ....
```
我们在这里就选择上述 Landlord 类中的 service() 方法作为连接点。
#### 第二步：创建切面
选择好了连接点就可以创建切面了，我们可以把切面理解为一个拦截器，当程序运行到连接点的时候，被拦截下来，在开头加入了初始化的方法，在结尾也加入了销毁的方法而已，在 Spring 中只要使用 `@Aspect` 注解一个类，那么 Spring IoC 容器就会认为这是一个切面了：
```
package aspect;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.stereotype.Component;
@Component
@Aspect
class Broker {
    @Before("execution(* pojo.Landlord.service())")
    public void before(){
        System.out.println("带租客看房");
        System.out.println("谈价格");
    }
    @After("execution(* pojo.Landlord.service())")
    public void after(){
        System.out.println("交钥匙");
    }
}
```

- **注意：** 被定义为切面的类仍然是一个 Bean ，需要 `@Component` 注解标注

代码部分中在方法上面的注解看名字也能猜出个大概，下面来列举一下 Spring 中的 AspectJ 注解：

| 注解 | 说明 |
| :--- | :--- |
| `@Before` | 前置通知，在连接点方法前调用 |
| `@Around` | 环绕通知，它将覆盖原有方法，但是允许你通过反射调用原有方法，后面会讲 |
| `@After` | 后置通知，在连接点方法后调用 |
| `@AfterReturning` | 返回通知，在连接点方法执行并正常返回后调用，要求连接点方法在执行过程中没有发生异常 |
| `@AfterThrowing` | 异常通知，当连接点方法异常时调用 |

有了上表，我们就知道 before() 方法是连接点方法调用前调用的方法，而 after() 方法则相反，这些注解中间使用了定义切点的正则式，也就是告诉 Spring AOP 需要拦截什么对象的什么方法，下面讲到。
#### 第三步：定义切点
在上面的注解中定义了 execution 的正则表达式，Spring 通过这个正则表达式判断具体要拦截的是哪一个类的哪一个方法：
```
execution(* pojo.Landlord.service())
```
依次对这个表达式作出分析：

- execution：代表执行方法的时候会触发
- `*` ：代表任意返回类型的方法
- pojo.Landlord：代表类的全限定名
- service()：被拦截的方法名称

通过上面的表达式，Spring 就会知道应该拦截 pojo.Lnadlord 类下的 service() 方法。上面的演示类还好，如果多出都需要写这样的表达式难免会有些复杂，我们可以通过使用 `@Pointcut` 注解来定义一个切点来避免这样的麻烦：
```
package aspect;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.aspectj.lang.annotation.Pointcut;
import org.springframework.stereotype.Component;
@Component
@Aspect
class Broker {
	@Pointcut("execution(* pojo.Landlord.service())")
	public void lService() {
	}
	@Before("lService()")
	public void before() {
		System.out.println("带租客看房");
		System.out.println("谈价格");
	}
	@After("lService()")
	public void after() {
		System.out.println("交钥匙");
	}
}
```
#### 第四步：测试 AOP
编写测试代码，但是我这里因为 JDK 版本不兼容出现了 BUG....（尴尬...）
这就告诉我们：环境配置很重要...不然莫名其妙的 BUG 让你崩溃...
#### 环绕通知
我们来探讨一下环绕通知，这是 Spring AOP 中最强大的通知，因为它集成了前置通知和后置通知，它保留了连接点原有的方法的功能，所以它及强大又灵活，让我们来看看：
```
package aspect;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.springframework.stereotype.Component;
@Component
@Aspect
class Broker {
//  注释掉之前的 @Before 和 @After 注解以及对应的方法
//	@Before("execution(* pojo.Landlord.service())")
//	public void before() {
//		System.out.println("带租客看房");
//		System.out.println("谈价格");
//	}
//
//	@After("execution(* pojo.Landlord.service())")
//	public void after() {
//		System.out.println("交钥匙");
//	}
    //  使用 @Around 注解来同时完成前置和后置通知
	@Around("execution(* pojo.Landlord.service())")
	public void around(ProceedingJoinPoint joinPoint) {
		System.out.println("带租客看房");
		System.out.println("谈价格");
		try {
			joinPoint.proceed();
		} catch (Throwable throwable) {
			throwable.printStackTrace();
		}
		System.out.println("交钥匙");
	}
}
```
运行测试代码，结果仍然正确：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100277557-99d3d549-243b-4de0-8ae6-a861d9146316.png#align=left&display=inline&height=190&originHeight=190&originWidth=460&size=0&status=done&style=none&width=460)

---

## 使用 XML 配置开发 Spring AOP
注解是很强大的东西，但基于 XML 的开发我们仍然需要了解，我们先来了解一下 AOP 中可以配置的元素：

| AOP 配置元素 | 用途 | 备注 |
| :--- | :--- | :--- |
| `aop:advisor` | 定义 AOP 的通知其 | 一种很古老的方式，很少使用 |
| `aop:aspect` | 定义一个切面 | —— |
| `aop:before` | 定义前置通知 | —— |
| `aop:after` | 定义后置通知 | —— |
| `aop:around` | 定义环绕通知 | —— |
| `aop:after-returning` | 定义返回通知 | —— |
| `aop:after-throwing` | 定义异常通知 | —— |
| `aop:config` | 顶层的 AOP 配置元素 | AOP 的配置是以它为开始的 |
| `aop:declare-parents` | 给通知引入新的额外接口，增强功能 | —— |
| `aop:pointcut` | 定义切点 | —— |

有了之前通过注解来编写的经验，并且有了上面的表，我们将上面的例子改写成 XML 配置很容易（去掉所有的注解）：
```
<!-- 装配 Bean-->
<bean name="landlord" class="pojo.Landlord"/>
<bean id="broker" class="aspect.Broker"/>
<!-- 配置AOP -->
<aop:config>
    <!-- where：在哪些地方（包.类.方法）做增加 -->
    <aop:pointcut id="landlordPoint"
                  expression="execution(* pojo.Landlord.service())"/>
    <!-- what:做什么增强 -->
    <aop:aspect id="logAspect" ref="broker">
        <!-- when:在什么时机（方法前/后/前后） -->
        <aop:around pointcut-ref="landlordPoint" method="around"/>
    </aop:aspect>
</aop:config>
```
运行测试程序，看到正确结果：
![](https://cdn.nlark.com/yuque/0/2021/png/21546446/1621100277581-786ee3a3-c2d3-4d26-9367-40aca3784473.png#align=left&display=inline&height=190&originHeight=190&originWidth=460&size=0&status=done&style=none&width=460)
> 扩展阅读：[Spring【AOP模块】就这么简单](https://mp.weixin.qq.com/s?__biz=MzI4Njg5MDA5NA==&mid=2247483954&idx=1&sn=b34e385ed716edf6f58998ec329f9867&chksm=ebd74333dca0ca257a77c02ab458300ef982adff3cf37eb6d8d2f985f11df5cc07ef17f659d4#rd) 、 [关于 Spring AOP(AspectJ)你该知晓的一切（慎独读，有些深度...）](https://zhuanlan.zhihu.com/p/25522841)

#### 参考资料：

- 《Java EE 互联网轻量级框架整合开发》
- 《Java 实战（第四版）》
- 万能的百度 and 万能的大脑
