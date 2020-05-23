# 《疯狂Java讲义》学习笔记

> java全部内容很多，这里主要记的是《疯狂Java讲义》的读书笔记，从面向对象开始记。  
> 写的不是很全面和仔细，仅当学习记录。

## 1.面向对象

### 1.类和对象

#### 类：事物的描述，某种概念

- 定义语法：

```java
  [修饰符] class 类名
    {
      //构造器...
      //成员变量...
      //成员方法...
    }
```

可以包括成员变量，方法，构造器，初始化块，内部类

#### 对象：该类事物的实例，在Java中通过new来创建

- 定义语法：

```java
  类名 对象名 = new 类名(参数);  
```

### 2.方法详解

#### 所属性

- 方法必须属于类或对象。必须在类中定义。  
- 如果使用`static`修饰，则这个方法属于它所在的类，否则属于这个类的实例。  

#### 形参可变

- 在最后形参后加 "..."，则表明该形参可以接收多个参数值，多个参数值被当作数组传入。  

#### 方法重载

- 同一个类中定义多个同名方法，但是形参不同的情况称为方法重载。  
- 对于返回值类型，修饰符等，与方法重载无关。  

### 3.成员变量和局部变量

#### 成员变量

1. 类变量（在类定义中使用了`static`修饰符）  
2. 实例变量（在类定义中没有使用`static`修饰符隐藏和封装）  

#### 局部变量

1. 形参（方法签名中定义的变量）
2. 方法局部变量（在方法中定义的变量）
3. 代码块局部变量（在代码块中定义的变量）

### 4.隐藏和封装

- 访问控制符

-`private`同类
-`default`同类 同包
-`protected`同类 同包 子类中
-`public`同类 同包 子类中 全局范围内

- 包管理  
`package`指定一个类放在指定的包里，在Java源程序第一个非注释行指定  
`import`导入指定包层次下的某个或所有类  
`import static`导入指定类的一个或所有静态成员变量

### 5.构造器

- 创建对象时执行初始化。
- 同一类中拥有多个构造器，但是形参不一样，则称之为构造器重载。
- 系统根据形参选择构造器进行初始化。

### 6.继承

- 特点

- 子类无法获取父类的构造器。
- 语法

```java
      修饰符 class 子类名 extends 父类名
      {
        //code
      }
```

- 重写

- 子类含有与父类同名的方法时，子类定义的方法会覆盖父类的方法，称之为方法重写。

- super限定

- 当子类发生了方法重写后，可以通过super来访问父类中被重写的方法。
- 调用父类构造器
- 在子类中，通过`super(形参)`；的形式调用父类构造器
- 子类会默认调用一次父类的构造器。父类构造器总会在子类构造器执行之前执行。

### 7.多态

```java
动物类
{
    吃方法（）
    {
        吃东西
    }
}

猫类 继承 动物类
{
    吃方法（）
    {
        吃鱼
    }
    抓鱼方法（）
    {

    }
}

狗类 继承 动物类
{
    吃方法（）
    {
        吃肉
    }
    看门方法（）{

    }
}

//调用
Cat c =new Cat();
c.eat();

//c1.eat(),c2.eat()...太繁琐。定义一个方法来调用
方法（猫对象）{
    对象.eat();
}

//狗也有eat（）方法，把对象设成动物类
方法（动物对象）{
    对象.eat();
}

//把猫对象，狗对象向上转型为动物类进行创建
动物类 a = new 猫类（）；
```

- 父类 对象  =new 子类();
- 左边是编译时类型，右边是运行时类型。
  - 变量：看编译时类中是否含有该变量
  - 函数：编译看编译时类是否含有该函数，运行时看运行时类中是否含有该函数，依赖于对象调用，故执行子类方法
  - 静态函数：用类来调用，如果非要用对象来调用，因其依赖于类调用，故执行父类方法
- 对象只能执行父类里的方法。限制了对子类的特有功能调用，称为`向上转型`
  - 如果想进行子类特有对象，可以`向下转型`：子类 对象 = 子类（对象）
- 成员方法具有多态性，而成员变量没有。

- 类型转换
- 语法：`(type)variable`
- 基本类型之间，只有数值类型可以相互转换，包括整数形，字符型，浮点型
- 引用类型之间，只能在具有继承关系的两个类型之间转换
- instanceof
- 继承父类的子类可能有多个，向下转型到具体子类之后，其他的子类没办法使用向下转型子类的特有方法，所以可以在使用前判断一下
-`操作数1 instanceof 操作数2`
- 用于判断前一个对象是否时后面的类，或者其子类，其实例，是/否   返truefalse

### 8.继承和组合

- 尽量不要在父类构造器中调用将被子类重写的方法。
- 通过继承来进行类的复用，往往可以通过组合来实现，及 在新类中定义一个久类的对象，如果用`private`修饰，则可以保证父类的封装性。

### 9.初始化块

- 语法

```java
    [修饰符] {
         //code
    }
```

- 修饰符只能是static，用static修饰的初始化块称之为静态初始化块，也称类初始化块。它在类初始化时执行，普通初始化块是在实例初始化时执行，所以类初始化块更先被执行。

### 10.包装类

- 为了解决基本类型数据不具备对象的特性，Java提供了相应的包装类。
- 1.`byte，short，int，long，char，float，double，boolean`---->Byte ,Short, Integer, Long, Charecter, Float, Double, Boolean

- 字符串类型值---> 基本类型值

- 1.`parseXxx(String s)`int i = Integer.parseInt("123");
- 2.`Xxx(String s)构造器`int i = new Integer("123");

- 基本类型值----> 字符类型值

- 1.`valueOf()`String s = valueOf(3.14);
- 2.`基本类型值 + " "`String s = 3.14 + " "

- 数值比较
- 静态的`compare(xxx val1,xxx val2)`true>false
- ...

### 11.处理对象

- 打印对象和toString()

- 1.打印对象其实是输出对象的toString()方法的返回值，toString()是Object对象实例方法，Java中所有对象皆为Object对象的子类，因此都具有toString()方法，默认出“类名+@+哈希值”，可以通过方法重写实现自身功能。
- ==和equal方法
- 基本类型变量的值相等则返回true，否则为false
- 引用类型变量指向同一对象时，返回true，否则为false。
- hashCode()方法
- 重写equal方法后一般要自定义哈希值
- getClass()方法
- JVM最先在内存中加载`字节码文件对象Class`，由其读取其他class文件

### 12.类成员

- 用`static`修饰的成员变量，方法，初始化块，内部类，称之为类成员，类成员属于类，而不属于实例。类成员无法访问实例成员。
- 单例类：一个类只能创建一个实例，则这个类被称之为单例类。

```java
    /*
    1.将构造器隐藏，使之无法new
    2.定义一个类方法，由类进行new，故需public
    */
    //饿汉式
    class 单例类名
    {
        private static 单例类名 val = new 单例类名();
        private 单例类名(){};                  //将构造器隐藏
        public static 单例类名 func（）{//定义类方法
            return val;
        }
    }
    //懒汉式
    class 单例类名
    {
          private static 单例类名 val；//val用来存放曾经创建的实例
          private 单例类名(){};                  //将构造器隐藏
          public static 单例类名 func（）{//定义类方法
              if(val == null)
               {
                       val = new 单例类名();
               }
               return val;
           }
    }
```

### 13.final修饰符

- 其修饰的类，方法，变量不可改变。
- 类：final修饰的类不可以有子类。
- 方法：final修饰的方法不可以被重写。但是可以重载。
- 变量：只能赋值一次。
- 不可变类...
- 缓存实例的不可变类...

### 14.抽象类

- 定义抽象类只需要在普通类上增加abstract修饰符即可
- 抽象类只能被继承，抽象方法必须在子类中被重写
-`final`，`private`和`abstract`永远不可能同时修饰某个方法

### 15.接口

- 定义方法

```java
    [修饰符] interface 接口名 extends 父接口1,父接口2...
    {
        //code...
        //定义而不实现.
    }
```

- 接口支持多继承
- 使用接口

```java
    [修饰符] class 类名 extends 父类 implements 接口1,接口2...
    {
       //code...
    }
```

- 面向接口编程
- 简单工厂模式
  
1. Computer类-> Printer方法    如果Printer改变，则需在Computer类中改
2. Computer类-> Output对象-> Printer方法
3. 。。。

- 命令模式
          1. ​    接口 定义 处理方法(参数)
          2. ​    类->方法(参数，处理方法)
          3. ​    主->创建实例时指定处理方法
          4. ​    定义 处理方法1，处理方法2

### 16.内部类

- 定义在其他类内部的类称之为内部类，包含内部类的类称之为外部类或宿主类。
- 不允许同一个包中的其他类访问该类。
- 内部类成员可以直接访问外部类的私有数据。
- 匿名内部类可以用来创建仅需使用一次的的类。
- 非静态内部类内不许定义静态成员。

```java
    外部类
    {
        //内部类{}//有名字
        外部方法（）//匿名内部类
        {
            new 父类or接口（）
            {
                内部类方法1；
            }.内部类方法（）；
        }
    }
    //如果有多个方法
     外部类
    {
        //内部类{}//有名字
        外部方法（）//匿名内部类
        {
            内部类 in = new 父类or接口（）
            {
                内部类方法1；
                内部类方法2；
            }；
        }
    }
    //使用时
    in.内部方法1();
    in.内部方法2();
```

### 17.Lambda表达式

- 支持将代码块作为方法参
- ES6里的箭头函数就是Lambda表达式

### 18.枚举类

- 格式：

```java
    [修饰符] enum 类名{
            实例1，实例2；
    }
```

- 使用时可通过`类名.实例1` 的形式。
-`类名.values()`代表了所有的实例。

### 19.对象和垃圾回收

- 可达状态：对象有引用
- 可恢复状态：对象没有引用，系统准备回收其空间前，执行`finalize`方法
- 不可达状态：调用了finalize方法后，没有将对象恢复成可达状态
- 强制回收：`System.gc( )`和`Runtime.getRuntime.gc( )`

### 20.修饰符的适用范围

### 21.使用jar文件

- jar cf 包名 路径
- cvf 显示过程  
- cvfM 不生成清单文件
- jar xf 包名 （解压）
- xfe 变成可执行的

---

## 2.异常

---

### 1.简介

- 定义：在运行时期发生的不正常情况。描述这种不正常情况的类，就叫做异常类。
- Throwable：
- Error          一般不可处理的,由JVM抛出的严重性问题；一般不针对新处理，直接修改程序
- Exception      可处理的；

### 2.异常处理机制

- 1.try...catch...finally...;(try 为必须,其他没有要求)
只能捕获一次异常,优先捕获小异常,再捕获大异常,可以更具体

```java
    try
    {
        //业务代码
    }
    catch(Exception e) //捕获异常
    {
        //(1)
    }
    finally
    {

    }
```

- 2.访问异常信息
在(1)处可调用以下方法
- getMessage()                         返回该异常对象的详细描述字符串
- printStackTrace()                    将该异常的跟踪栈信息输出到标准错误输出
- printStackTrace(PrintStream s)       将该异常的跟踪栈信息输出到指定输出流
- getStackTrace()                      返回该异常的输出栈信息

- 3.finally块
- 一定会被执行,可以在其中进行一些必要的操作,比如关闭一些系统资源

- 4.try()
- 在try后括号里可以声明初始化一个或多个资源,这些资源会在try语句结束后自动关闭

### 3.Checked异常和Runtime异常

- 1.分类:
- RuntimeException类及其子类下的所有异常称之为Runtime异常(运行时异常);编译时不被检测
- Exception类下的其他的异常统称为Checked异常,编译时被检测
- 2.使用throws抛出异常
-`方法(参数...) throws 异常类1,异常类2`
- 不知道如何处理的异常交由上级处理,main方法如果不知道处理方法,则抛给JVM处理,JVM会打印异常的跟踪栈信息,并终止程序运行
- 如果在函数内抛出异常，必须在函数上声明throws抛出,可同时声明抛出多个异常
- 如果某段代码声明了抛出Checked异常,则需要在try块中显式捕获该异常,要么在另一个声明了异常抛出的方法中调用

### 4.使用throw抛出异常

- 1.抛出异常
-`throw ExceptionInstance
- 由于业务不符而产生的异常,必须要程序员执行抛出
- throw抛出的不是异常,而是异常实例
- 如果抛出的时Checked异常,则需要在try块中显式捕获该异常,要么在另一个声明了异常抛出的方法中调用
- 2.自定义异常类
- 必须继承于Exception类
- 一般需提供两构造器:一无参,一有一字符串参数
- 3.catch和throw配合
- catch捕获后处理,再抛出,再由调用者捕获后处理
- 4.异常链

---

## 3.多线程

---

### 简介

- 优点:多线程程序并发性高
- 缺点:线程太多
  
### 线程的创建和启动

- 1.继承Thread类创建线程类
- 1.定义一个子类继承Thread类,重写该类的run()方法,该run方法就代表了线程需要完成的任务,所以run方法又称为 线程执行体
- 2.创建子类实例对象
- 3.调用子类start()方法来启动该线程

```java
        class T1 extends Thread
        {
            public void run()
            {
                //code...
                //1.线程类继承Thread类时,直接使用this即可获取当前线程
                //2.Thread对象的getName()方法返回当前线程的名字
                //3.Thread.currentThread()是Thread类的静态方法,总是返回正在执行的线程对象
            }
        }
        //调用时
        new T1().start();
```

- 2.实现Runnable接口创建线程类
- 1.定义Runnable接口的实现类,并重写该类的run()方法.
- 2.创建该实现类的实例,并以此实例作为Thread的target来创建Thread对象,该Thread才是真正的线程对象

```java
        class T2 implements Runnable
        {
            public void run()
            {
                //code...
                //只能通过Thread.currentThread()返回正在执行的线程对象
            }
        }
        //调用时
        T2 st = new T2();
        new Thread(st,"线程1").start();     //"线程1"是线程名
        new Thread(st,"线程2").start();
```

- 3.使用Callable和Future创建线程
- 1.创建Callable接口的实现类,实现call()方法,该方法有返回值,再创建该实现类的实例.
- 2.使用FutureTask类来包装Callable对象,该FutureTask对象还封装了该Callable对象的call()方法的返回值
- 3.使用FutureTask对象作为Thread对象的target创建并启动新线程.
- 4.调用FutureTask对象的get()方法来获得子线程执行结束后的返回值
  
```java
    //还有一些，等待整理...
```

### 线程的生命周期

- 1.新建和就绪状态
- new之后就是新建状态
- start之后就是就绪状态
- 2.运行和阻塞状态
- 开始执行run方法,则该进程处于运行状态
- 阻塞状态出现的情况
- 1.线程调用sleep()方法主动放弃所占用的处理器资源
- 2.线程调用阻塞式IO方法
- 3.线程试图获得一个同步监视器,但该监视器被其他线程持有
- 4.线程在等待某个通知
- 5.程序调用了线程的suspend()方法将线程挂起
- 3.线程死亡

### 控制线程

- 1.join线程
- 在某个线程中调用其他线程的join方法是,该线程会等到其他线程执行完在继续执行,如线程A中调用线程B.join()后,线程A被阻塞,等到线程B执行完,线程A再继续执行.
- join();等待被join的线程执行完成
- join(long millis);等待被join的线程最多millis毫秒,时间到了,不再等待
- join(long millis,int nanos);等待时间为millis毫秒+nanos毫微秒
- 2.后台线程
- 1.后台程序的任务是给其他线程提供服务,如果所有前台线程都结束了,后台线程也会自动结束.
- 2.调用Thread对象的setDaemon(true)方法,可以指定线程为后台线程.
- 3.Thread类还提供了一个isDaemon方法来判断一个线程是否为后台线程.
- 3.线程睡眠
- static void sleep(long millis):让当前执行的线程暂停millis毫秒
- static void sleep(long millis,int nanos):让当前执行的线程暂停millis毫秒+nanos毫微秒
- 4.线程让步
- yield()方法与sleep相似,但不会阻塞该线程,只是推到就绪状态,调用了yield()之后,只有优先级高于或等于该线程的线程才能获得执行机会.
- 5.改变线程优先级
- Thread类提供了setPriority(int newPriority),getPriority()方法来设置和返回指定线程的优先级.
- 优先级数组是1~10;有三个常量值
- MAX_PRIORITY     10
- MIN_PRIORITY     1
- NORM_PRIORITY    5

### 线程同步

- 1.同步代码块
- 写在线程执行体方法里,执行到这里锁住,不让其他线程执行体执行.
  
```java
    //obj是同步监视器,下面代码的意义:线程在开始执行同步代码块之前,必须先获得对同步监视器的锁定.其实就是锁住obj不然其他线程获得,执行完同步代码块之后再释放对obj的锁定.
    synchronized(obj)
    {
        //code
    }
```

- 2.同步方法
- 使用synchronized修饰的方法称之为同步方法
- 写在业务方法里面,每次只能由一个线程执行体执行
- 3.释放同步监视器的锁定
- 由JVM系统执行
- 4.同步锁
- 有多种Lock,在实现线程安全的时候常用ReentrantLock实现类

```java
        private final ReentrantLock l = new ReentrantLock();

        //加锁
        l.lock();
        try{
            //....
        }finally{
            //解锁,为了防止忘记解锁,放在finally块里
            l.unlock();
        }

```

- 5.死锁
- 两个进程相互都在等对方释放锁,就会发生死锁.

### 线程通信

- 1.传统的线程通信
- wait() 让当前线程等待
- notify() 唤醒在当前同步监视器等待的单一线程,有多线程是随机选择一个
- notifyAll() 唤醒在当前同步监视器等待的所有线程.
- 2.用condition控制线程通信
- 如果使用Lock进行锁定,则无法使用上面的函数
- Condition将同步监视器方法分解成不同的对象.
- 分别对应的方法是  await();   signal();  signalAll();

```java
    private final Lock lock = new ReentrantLock();
    private final Condition cond = lock.newCondition();

    //...

    lock.lock();

    cond.await();

    cond.signal();
```

- 3.使用阻塞队列控制线程通信
- BlockingQueue接口提供了两个支持阻塞的方法
- put(E e);    将e元素放到队列中,如果元素已满,则阻塞
- take();      从队列头部取出元素,如果头部元素已经为空,则阻塞
- 所以通过定义一个容量为1的容器对象,两个线程分别调用容器对象的put();take();方法来控制自己阻塞,实现线程通信

### 线程组和未处理的异常

- 线程组可以对组内线程进行统一管理,线程一旦加入某线程组,就不能改变所属线程组了,直到线程死亡为止.
- 1.为线程指定分组的构造器:
- Thread(ThreadGroup group,Runnable target);               以target的run方法为线程执行体
- Thread(ThreadGroup group,Runnable target,String name);
- Thread(ThreadGroup group,String name);                   以name为线程名
- 2.创建线程组
- ThreadGroup(String name);                                创建名为name的线程组
- ThreadGroup(ThreadGroup parent,String name)              创建parent线程组的子线程组name
- 3.ThreadGroup操控组内线程的方法
- int activeCount();                                       返回线程中中的活动线程数.
- interrupt();                                             中断线程组中所有线程
- isDaemon();                                              判断是否为后台线程组
- set'Daemon(boolean daemon)                               把该线程组设置成后台线程组
- setMaxPriority(int pri);                                 设置线程组的最高优先级
- 4.未处理的异常
- 线程组类中定义了一个uncaughtException(Thread t,Throwable e);方法,该方法可以处理线程组内所有线程所抛出的未处理的异常...

### 线程组

- 因为系统启动一个线程的成本较高,所以线程池在系统启动时就先创建好多个空闲线程.
- ...

### ForkJoinPool

- 为了充分利用多CPU,多核CPU,ForkJoinPool支持将一个任务拆分成多个小任务...

### 线程相关类

- ...

---

## 4.基础类库

---

### 创建String对象

```java
  String s0 = "abc";                 //在字符串变量池中创建了"abc"变量,将地址赋给s0
  String s1 = "abc";                 //将字符串变量池中"abc"变量的地址赋给s1
  String s2 = new String("abc");     //在堆中创建空间保存"abc"变量,将地址付给s1
```

特点:

- 其中s0会等于s1,都是相同对象的引用,而与s2不相等
- String类的构造方法...

#### 常用方法

获取:

- 1.获取长度             int length();
- 2.获取字符             char charAt(int index)
- 3.获取位置
- int indexOf(char ch);
- int indexOf(char ch,int fromIndex);
- int indexOf(String str);
- int lastIndexOf(String str,int fromIndex);
- int lastIndexOf(char ch);
- int lastIndexOf(char ch,int fromIndex);
- int lastIndexOf(String str);
- int lastIndexOf(String str,int fromIndex);
- ...
- 4.获取子串
- String substring(int beginIndex,int endIndex);
- String substring(int beginIndex);
    转换:
- 1.切割成 字符串/字符/字节 数组
- String[] split(String regex);
- char[] toCharArray();
- byte[] getBytes();
- 2.字母 大/小 写
- String toUpperCase();
- String toLowerCase();
- 3.替换
- String replace(char newCh,char oldCh);
- String replace(String newStr,String oldStr);
- 4.去除两边空格           String trim();
- 5.连接字符串             String contact(String Str);
    判断:
- 1.内容是否相同
- boolean equals(Object Obj);
- boolean equalsIgnoreCase(String Str);    //忽略字母大小写
- 2.是否包含
- boolean contains(String Str);
- 3.是否以指定字符串开头/结尾
- boolean startsWith(String Str);
- boolean endsWith(String Str);
- 4.比较字典顺序 abcd...   A>a
- int compareTo(String Str);
    intern方法:对字符串池进行操作
- 字符串池里没有则创建,有则返回其引用

### StringBuffer/StringBuilder

- 两个类功能相同
- 区别:StringBuffer线程同步,开销大,在单线程里优先使用StringBuilder
    添加  append(data)
    删除  
- delete(int start,int end);
- delete(int index);
    插入  insert(int Index,data)
    查找  和String相同
    修改
- replace(int start,int end,String Str);  //把start~end之间内容,替换成Str
- setCharAt(int Index,char ch);

---

## 5.集合框架

---
> 特点:  
> 1.用于存储对象的容器  
> 2.长度可变  
> 3.不可以存储基本类型值

### Collection和Iterator(内部类)接口

添加:

- boolean add(Object o);
- boolean addAll(Collection c);
删除:
- boolean remove(Object o);
- boolean removeAll(Collection c);
- boolean retainAll(Collection c);    //删除c里不包含的元素
- void clear();
判断:
- boolean contains(Object o);
- boolean containsAll(Collection c);
- boolean isEmpty();
获取:
- int size();
- Object[] toArray();
- Iterator iterator();  

### List 元素有序,可重复

> 特性:
> Iterator it = list.Iterator();  //唯一可在迭代中进行增删操作  
> 包含:  
> Vector        内部数据结构是数组,同步的,查询慢  
> ArrayList     内部数据结构是数组,不同步的,查询较快  
> LinkedList    内部数据结构是链表,不同步的,增删快  

- 添加  void add(index,element/Collection)
- 删除  Object remove(index)
- 修改  Object set(index,element)
- 获取
- Object get(index)
- int indexOf(Object)
- int lastIndexOf(Object)
- List subList(from,to)
  
- LinkedList特性:addFrist();addEnd();
  
### Set 元素无顺序,不可以重复

- HashSet
- LinkedHashSet`唯一且有序`
- TreeSet:可以对Set中元素指定排序,按自然顺序
- 方式一:实现Comparable接口的compareTo方法,指定按照对象的某一元素进行排序;compare中进行判断大小,返回正负数
- 方式二:定义类实现Comparable接口的compare方法,将该类对象传给TreeSet的构造器

### Map<K,V>一次添加一对

- keySet()    获取Map中所有key的Set集合,可以进行迭代
- entrySet()  Map.Entry   是他们键值对的映射关系类型,getKey/getValue 获取 键/值
- 子类:
- Hashtable 同步,不允许null作键
- Properties:用来存储键值对型的配置文件的信息
- HashMap   不同步,允许null作键
- TreeMap   不同步

### 泛型

- <>中必须是应用类型
- 是一种安全机制,对集合中对象类型的限定,在编译时检测,编译后会擦除
- 在类中操作的引用类型不确定时,可以用泛型
- 限定迭代器  Collection<? extends Person>上限  ? super Person下限

集合选择技巧:  
需要唯一吗?

- 需要:Set
  - 需要定制顺序吗?
    - 需要:TreeSet
    - 不需要:HashSet
  - 需要和存储相同顺序:LinkedHashSet
- 不需要:List
  - 需要频繁增删吗?
    - 需要:LinkedList
    - 不需要:ArrayList

---

## 7.输入/输出

---

### Files类

#### 访问文件和目录

- 1.访问 文件名 相关方法
- String getName();
- String getPath();
- File getAbsoluteFile();
- String getAbsolutePath();
- String getParent();
- boolean renameTo(File newName)
- 2.文件 检查 相关方法
- boolean exists();
- boolean canWrite();
- boolean canRead();
- boolean isFile();
- boolean isDirectory();
- boolean isAbsolute();
- 3.获取文件常规信息
- long lastModified();
- long length();
- 4.文件操作相关方法
- boolean createNewFile();
- boolean delete();              删除File对象所有
- static File createTempFile(String prefix,String suffix);   在临时文件夹中创建临时文件,给定前缀后缀
- static File createTempFile(String prefix,String suffix,File directory);   在指定文件夹中创建临时文件,给定前缀后缀
- void deleteOnExit();   注册一个删除钩子,当JVM退出时,删除文件
- 5.目录操作相关方法
- boolean mkdir();     试图创建File对象所对应的目录
- String[] list();     列出File对象所有的之文件名和路径名
- Files[] listFiles(); 列出File对象所有的之文件名和路径名,返回File数组
- static File[] listRoots();   列出系统所有的根目录

#### 文件过滤器

### 字节流/字符流

> 使用技巧  
> 1，明确源和目的(汇)  
> 源：InputStream  Reader  
> 目的：OutputStream  Writer  
> 2，明确数据是否是纯文本数据。  
> 源：是纯文本：Reader  
> 否：InputStream  
> 目的：是纯文本 Writer  
> 否：OutputStream  
> 到这里，就可以明确需求中具体要使用哪个体系。  
> 3，明确具体的设备。  
> 源设备：  
> 硬盘：File  
> 键盘：System.in  
> 内存：数组  
> 网络：Socket流  
> 目的设备：  
> 硬盘：File  
> 控制台：System.out  
> 内存：数组  
> 网络：Socket流  
> 4，是否需要其他额外功能。  
> 1，是否需要高效(缓冲区);  
> 是，就加上buffer.  
> 2，转换。  
> 需求1：复制一个文本文件。  
> 1,明确源和目的。  
> 源：InputStream Reader  
> 目的：OutputStream  Writer  
> 2,是否是纯文本？  
> 是！  
> 源：Reader  
> 目的：Writer  
> 3,明确具体设备。  
> 源：  
> 硬盘：File  
> 目的：  
> 硬盘：File  
> FileReader fr = new FileReader("a.txt");  
> FileWriter fw = new FileWriter("b.txt");  
> 4,需要额外功能吗？  
> 需要，需要高效。  
> BufferedReader bufr = new BufferedReader(new FileReader("a.txt"));  
> BufferedWriter bufw = new BufferedWriter(new FileWriter("b.txt"));

#### InputStream和Reader

- InputStream
- int read();    从输入流中读取单个字节,返回字节数据(转化为int)
- int read(byte[] b)   从输入流中读取最多b.length个字节的数据,储存在b[]中,返回实际字节数  
- int read(byte[] b,int off,int len)     最多读len个字节,从b[]中off出开始储存,返回实际字节数
- Reader
- int read();    从输入流中读取单个字符,返回字符数据(转化为int)
- int read(char[] b)   从输入流中读取最多b.length个字符的数据,储存在b[]中,返回实际字符数  
- int read(char[] b,int off,int len)     最多读len个字符,从b[]中off处开始储存,返回实际字符数
- 移动记录指针
- void mark(int readAheadLimit)    在记录指针当前位置记录一个标记(mark)
- boolean markSupported()          判断此输入流是否支持mark()操作
- void reset()                     记录指针位置回到上次标记位
- long skip(long n)                记录指针向前移动n个字节/字符

#### OutputStream和Write

- OutputStream和Write共有
- void write(int c);            将字节/字符输出到输出流中,c代表的可以是字节,也可以是字符
- void write(byte[]/char[] b)   将字节数组/字符数组输出到指定输出流中
- void write(byte[]/char[] b,int off,int len)     将字节数组/字符数组中off处开始长度为len的字节/字符输出到输出流中
- Write自有
- void write(String Str)
- void write(String Str,int off,int len);

### 处理流

  只要流的构造器参数不是物理节点即可,如

```java
    FileOutputStream fos = new FileOutputStream("1.txt"); //物理节点
    PrintStream ps = new Print Stream(fos); //处理流
```

### 转换流

  用于将字节流转换成字符流,
  InputStreamReader
  OutputStreamWrite

### 推回输入流

  PushbackInputStream/PushbackReader

  原始输入流---[调用unread()]---> 推回缓冲区-----[调用read()]----->程序

  只有 读完了缓冲区, read所需要的还没满,才会从原始输入流 读取

  方法和InputStream/Reader相同.

### 重定向标准输入/输出

  Java的标准输入/输出(System.in/System.out)设备是键盘/鼠标,通过重定向可以自己指定
  System类里提供了三个重定向标准输入/输出方法
  static void setErr(PrintStream err)           重定向标准错误流
  static void setIn(InputStream in)             重定向标准输入流
  static void setOut(PrintStream out)           重定向标准输出流

---

### Java虚拟机读取其他进程的数据

  InputStream getErrorStream()      获取子进程的错误流
  InputStream getInputStream()      获取子进程的输入流
  OutputStream getOutputStream()    获取子进程的输出流

### RandomAccessFile类

  特点:

- 允许只有定位文件记录指针
- 可以不从开始地方开始输入
- 可以向已存在的文件后追加内容
- 只能读写文件
    操作记录指针:
- long getFilePointer()  返回当前文件的记录指针位置
- void seek(long pos)    将指针定位到pos处
    创建
- 有两个构造器,(String FileName/File F,String mode),在于指定文件的不同(String/File)
- mode有四种模式
- "r"      只读,文件不在,报错
- "rw"     读写,文件不在,创建
- "rwd"    "rw"+文件内容的更新同步写入底层存储设备
- "rws"    "rwd"+文件元数据的更新同写入底层存储设备

### 对象序列化

1.使用对象流实现序列化

- 如果需要将一个对象保存到磁盘或通过网络传输,这个类应该实现Serializable接口或Externalizable接口,实现可序列化
- 通过处理流ObjectOutputStream对象,调用`writeObject(Cla)`方法,把实现了序列化的对象Cla输出到二进制流中
- 如果需要从二进制流中取出对象,则需要反序列化
- 通过处理ObjectInputStream对象,调用`readObject()`方法读取Object对象,如果知道对象类名,可以直接转化
2.对象引用序列化
- 如果一个类持有另一个类的引用,那么持有的类必须是可序列化,此类才可以序列化.
- 如果两个类持有相同的类的引用,相同类仅序列化一次,每个序列化对象都有一个序列化编号
3.自定义序列化
- 在不想被序列化的成员前使用`transient`关键字修饰
- 重写writeObject/readObject方法
- ANY-ACCESS-MODIFIER Object writeReplace() throws ObjectStreamException;    序列化是找其他对象替换不想被序列化的对象
- ANY-ACCESS-MODIFIER Object readResolve() throws ObjectStreamException;
4.另一种序列化机制
- 实现Externallizable接口,自定义序列化
- void readExternal(Object in)
- void writeExternal(Object out)
5.版本
- 为序列化类设置private static final类型的serialVersionUID;

### NIO (New IO)

#### Buffer

- Buffer是一个抽象类,可以保存多个类型相同的数据,基本类型除了boolean外,都有相应的Buffer子类:ByteBuffer,CharBuffer...
- static XxxBuffer allocate(int capacity)    创建一个容量为capacity的XxxBuffer对象.(普通Buffer)
- static XxxBuffer allocateDirect(int capacity)    (直接Buffer):创建成本高,读取效率高
  `CharBuffer CB = CharBuffer.allocate(8);`
- 0 <= mark <= position <= limit <= capacity
- mark是指针位置标记  
- position是可读写区的开始位置
- limit是可读写区的末位置
- capacity是缓冲区容量
- 两个重要方法:开始时Buffer的position为0,limit为capacity,程序可以通过put()向Buffer放入数据,position向后移动,取出数据用get();
- flip()     limit = position; position = 0;      为输出数据做准备
- clear()    position = 0;  limit = capacity;     为输入数据做准备
- 其他常用方法:
- int capacity();            返回buffer的capacity大小
- boolean hasRemaining();    判断position和limit之间是否还有元素可提供处理
- int limit();               返回limit的位置
- Buffer limit(int newLt);   设置新的limit位置
- buffer mark();             设置mark位置
- int position();            返回Buffer的position位置
- Buffer position(int newPs);设置新的position位置
- int remaining();           返回position和limit之间的元素个数
- Buffer reset();            position = mark
- Buffer rewind();           position = 0; mark = NULL

#### Channel接口

- Channel可以将指定文件部分或全部映射成Buffer,程序不能直接与Channel进行交互,而要通过Buffer.
- Channel要通过传统的节点InputStream,OutputStream的getChannel()来返回对应的Channel,FileInputStream返回的是Channel,PipedInputStream和PipedOutputStream()返回的是Pipe.SinkChannel和Pipe.SourceChannel.
...

---

## 8.网络编程

---

### Java的基本网络支持

#### InetAddress类(子类:Inet4Address,Inet6Address)

- getByName(String host)     根据主机(域名)获取对象
- getByAddress(byte[] addr)  根据地址(IP)获取对象
- String getCanonicalHostAddress();    获取此IP的全限定域名
- String getHostAddress();             返回实例的IP地址
- String getHostName();                获取提供此IP的主机名

- getLocalHost()   获取本机IP地址对应的InetAddress对象
- isReachable()    测试是否可以到达该地址

#### URLDecoder和URLEncoder

```java
  String Word = URLDecoder.decode("%E7%96%AF","utf-8");
  String Str = URLEncoder.encode("呵呵","GBK");
```

#### URL,URLConnection和URLPermission

- URL类
- String getFile();  获取该URL的资源名
- String getHost();  获取该URL的主机名
- String getPath();  获取该URL的路径部分
- int getPort();     获取该URL的端口号
- String getProtocol();  获取该URL的协议名
- String getQuery();     获取该URL的查询字符串部分
- URLConnection openConnection();    返回一个URLConnection对象,该对象代表了与URL所引用的远程对象的连接
- InputStream openStream();          打开与此URL的连接,并返回一个用于读取该URL资源的InputStream.
- URLPermission工具类:客户端:请求头<----->响应头:服务器端
- 用于管理HttpURLConnection的权限问题
- setAllowUserInteraction();         设置该URLConnection对象的allowUserInteraction请求头字段的值
- setDoInput();                      设置该URLConnection对象的doInput请求头字段的值
- setDoOutput();                     设置该URLConnection对象的doOutput请求头字段的值
- setIfModifiedSince();              设置该URLConnection对象的ifModifiedSince请求头字段的值
- setUseCaches();                    设置该URLConnection对象的useCaches请求头字段的值
- setRequestProperty(String key,String values);              设置该URLConnection对象的key请求头字段的值为values
- addRequestProperty(String key,String values);              增加该URLConnection对象的key请求头字段的值为values

- Object getContent();                 获取该URLConnection的内容
- String getHeaderField(String name);  获取指定响应头字段的值
- getContentEncoding();
- getContentLength();
- getContentType();
- getDate();
- getExpiration();
- getLastModified();
- getInputStream();                    返回该URLConnection对应的输入流,用于获取URLConnection响应的内容
- getOutputStream();                   返回该URLConnection对应的输出流,用于向URLConnection发送请求的参数

### 基于TCP协议的网络编程

#### 服务器端

- Socket accept();         接收客户端Socket连接请求,返回对应的Socket
- ServerSocket(int port,)                                    指定端口创建ServerSocket,0~65535
- ServerSocket(int port,int backlog)                         改变连接队列长度的参数backlog
- ServerSocket(int port,int backlog,InetAddress localAddr);  指定绑定的IP地址
- close();       关闭ServerSocket

#### 客户端

- Socket(InetAddr/String remoteAddress,int port)             创建连接到指定远程主机的端口号;
- Socket(InetAddr/String remoteAddress,int port,InetAddress localAddr,int localPort);        指定本地主机的IP端口
- InputStream getInputStream();        返回Socket对象的输入流,程序通过该输入流从Socket中取出数据
- OutputStream getOutputStream();      返回Socket对象的输出流,程序通过该输入流向Socket中输出数据

#### 加入多线程

#### 记录客户端用户信息

#### 半关闭的Socket

- shutdownInput();     关闭该Socket的输入流
- shutdownOutput();    关闭该Socket的输出流

#### 使用NIO实现非阻塞

- Selector:是SelectableChannel对象的多路复用器,通过此类的静态open()创建Selector实例.
- 一个Selector实例有三个SelectionKey集合:所有/被选择/被取消的Channel,前两者可以通过keys()/selectedKey()方法返回该集合

- int select()               监控所有注册的Channel,当Channel中有需要处理的IO操作时,该方法将其加入被选择的SelectionKey集合
- int select(long timeout)   设置超过时长的select操作
- int selectNow()            执行一个立即返回的select()操作
- Selector wakeup()          使一个未返回的select()方法立即返回

- SelectableChannel:代表了可以支持非阻塞IO操作的Channel对象,它可被注册到Selector上
- SelectableChannel configureBlocking(boolean block);      设置是否采用阻塞模式
- boolean isBlocking();        返回是否是阻塞模式;
- int vaildOps();              返回一个整数值,代表这个Channel所支持的所有操作.读1写4连接8接收16,多个权限则按位或,(相加,如5是读写)
- boolean isRegistered();      返回是否已经注册
- SelectionKey keyFor(Selector sel);     返回与sel的注册关系

- SelectionKey:该对象代表了SelectableChannel与Selector之间的关系
- ServerSocketChannel:支持非阻塞操作...你妹的,这么多内容!

### UDP

- Datagram

## 反射机制

> 用于动态获取类中信息,用Class类实现.
> 一个应用例子:软件读取配置信息,根据信息,通过反射机制获取对应类的信息,放到软件中从处理.这个时候我们写一个类,并将信息写到配置文件中,软件就会执行加载我们写的类去处理了,不需要我们去软件源代码中操作

### 获取字节码对象的方法

- 用getClass()方法
- 用.class属性
- 用Class.forName(class)方法

```java
  String name = "cn.xu.pack";
  Class clazz = Class.forName(name);

  //构造函数
  Object o = clazz.newInstance();   //1.无参

  Constructor constructor = clazz.getContructor(int.class,double.class);  //2.有参
  Object O = constructor.newInstance(10,11.3);

  //字段
  
  Field field = clazz.getField(n);           //获取类中的n变量(public),如果无参数,则获取所有变量,返回数组
  Field[] field = clazz.getDeclaredField();   //私有变量的也可以获取

  //方法
  Method method = clazz.getMethod("fun",null); //获取空参数函数fun,有参数则把null替换掉
  
  method.invoke(o,null);    //有参数则把null替换掉
```

## 正则表达式

> 用于操作字符串数据

```java
String str = "helloworld";
boolean b = str.matchs(regux)
```

> 范围用[]  如[13],[a-z],[a-[d-g]]
> 数量用{}  
> 组用()

- 匹配
- 切割
- 替换
- 获取
