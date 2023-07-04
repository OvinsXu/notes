# autotools使用流程

## 0.简介

`autotools`是系列工具，首先要确认系统是否装了以下工具（可以用which命令进行查看）。

`aclocal`、`autoscan`、`autoconf`、`autoheader`、`automake`

使用`autotools`主要就是利用各个工具的脚本文件以生成最后的Makefile。其总体流程是这样的：

1. 使用aclocal生成一个“aclocal.m4”文件，该文件主要处理本地的宏定义；

2. 改写“configure.scan”文件，并将其重命名为“configure.in”，并使用autoconf文件生成configure文件。

接下来，将通过一个简单的hello.c例子来熟悉`autotools`生成`makefile`的过程.

## 1.autoscan

它会在给定目录及其子目录树中检查源文件，若没有给出目录，就在当前目录及其子目录树中进行检查。它会搜索源文件以寻找一般的移植性问题并创建一个文件`“configure.scan”`，该文件就是接下来`autoconf`要用到的`“configure.in”`原型。如下所示：

```shell
$ autoscan

autom4te: configure.ac: no such file or directory

autoscan: /usr/bin/autom4te failed with exit status: 1

$ ls 

autoscan.log configure.scan hello.c
```

如上所示，autoscan首先会尝试去读入`“configure.ac”`文件，此时还没有创建该配置文件，于是它会自动生成一个`“configure.in”`的原型文件`“configure.scan”`。

## 2.autoconf

configure.in是autoconf的脚本配置文件，它的原型文件“configure.scan”如下所示：

```shell
# Autoconf 

# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)

#The next one is modified by sunq

#AC_INIT(FULL-PACKAGE-NAME,VERSION,BUG-REPORT-ADDRESS)

AC_INIT(hello,1.0)

# The next one is added by sunq

AM_INIT_AUTOMAKE(hello,1.0)

AC_CONFIG_SRCDIR([hello.c])

AC_CONFIG_HEADER([config.h])

# Checks for programs.

AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile])

AC_OUTPUT

```
下面对这个脚本文件进行解释：

- 以“#”号开始的行为注释。
- `AC_PREREQ`宏声明本文件要求的autoconf版本，如本例使用的版本2.59。
- `AC_INIT`宏用来定义软件的名称和版本等信息，在本例中省略了BUG-REPORT-ADDRESS，一般为作者的e-mail。
- `AM_INIT_AUTOMAKE`是另加的，是automake所必备的宏，也同前面一样，PACKAGE是所要产生软件套件的名称，VERSION是版本编号。
- `AC_CONFIG_SRCDIR`宏用来侦测所指定的源码文件是否存在，来确定源码目录的有效性。在此处为当前目录下的hello.c。
- `AC_CONFIG_HEADER`宏用于生成config.h文件，以便autoheader使用。
- `AC_CONFIG_FILES`宏用于生成相应的Makefile文件。
- 中间的注释间可以添加分别用户测试程序、测试函数库、测试头文件等宏定义。

接下来首先运行`aclocal`，生成一个`“aclocal.m4”`文件，该文件主要处理本地的宏定义。如下所示：

```shell
$ aclocal    #再接着运行autoconf，生成“configure”可执行文件。如下所示：
$ autoconf
$ ls
aclocal.m4 autom4te.cache autoscan.log configure configure.in hello.c
```

## 3.autoheader

接着使用autoheader命令，它负责生成config.h.in文件。该工具通常会从“acconfig.h”文件中复制用户附加的符号定义，因此此处没有附加符号定义，所以不需要创建“acconfig.h”文件。如下所示：

```shell
$ autoheader
```

## 4.automake

这一步是创建Makefile很重要的一步，`automake`要用的脚本配置文件是Makefile.am，用户需要自己创建这个文件。之后，`automake`工具将其转换成Makefile.in。

在该例中，创建的文件为Makefile.am如下所示：

```shell
AUTOMAKE_OPTIONS=foreign

bin_PROGRAMS= hello

hello_SOURCES= hello.c hello.h
```

下面对该脚本文件的对应项进行解释。

- 其中的AUTOMAKE_OPTIONS为设置automake的选项。由于GNU对自己发布的软件有严格的规范，比如必须附带许可证声明文件COPYING等，否则automake执行时会报错。automake提供了三种软件等级：foreign、gnu和gnits，让用户选择采用，默认等级为gnu。在本例使用foreign等级，它只检测必须的文件。

- bin_PROGRAMS定义要产生的执行文件名。如果要产生多个执行文件，每个文件名用空格隔开。

- hello_SOURCES定义“hello”这个执行程序所需要的原始文件。如果”hello”这个程序是由多个原始文件所产生的，则必须把它所用到的所有原始文件都列出来，并用空格隔开。例如：若目标体“hello”需要“hello.c”、“sunq.c”、“hello.h”三个依赖文件，则定义hello_SOURCES=hello.c sunq.c hello.h。

接下来可以使用automake对其生成`“configure.in”`文件，在这里使用选项`“—adding-missing”`可以让automake自动添加有一些必需的脚本文件。如下所示：

```shell
$ automake --add-missing
configure.in: installing './install-sh'
configure.in: installing './missing'
Makefile.am: installing 'depcomp'

$ ls
aclocal.m4   autoscan.log configure.in hello.c   Makefile.am missing
autom4te.cache configure   depcomp  install-sh Makefile.in config.h.in
```

可以看到，在automake之后就可以生成configure.in文件。

## 5.运行configure

在这一步中，通过运行自动配置设置文件configure，把Makefile.in变成了最终的Makefile。如下所示：

```shell
$ ./configure

checking for a BSD-compatible install... /usr/bin/install -c

checking whether build enVironment is sane... yes

checking for gawk... gawk

# ...
```

可以看到，在运行configure时收集了系统的信息，用户可以在configure命令中对其进行方便地配置.

在`./configure`的自定义参数有两种，一种是开关式（--enable-XXX或--disable-XXX），另一种是开放式，即后面要填入一串字符（--with-XXX=yyyy）参数。读者可以自行尝试其使用方法。另外，可以查看同一目录下的”config.log”文件，以方便调试之用。

到此为止，makefile就可以自动生成了。回忆整个步骤，用户不再需要定制不同的规则，而只需要输入简单的文件及目录名即可，这样就大大方便了用户的使用。

## 6.生成的Makefile

`autotools`生成的Makefile除具有普通的编译功能外，还具有以下主要功能:

1．make

键入make默认执行”make all”命令，即目标体为all，此时在本目录下就生成了可执行文件“hello”，运行“./hello”能出现正常结果

2．make install

此时，会把该程序安装到系统目录中去，若直接运行hello，也能出现正确结果。

3．make clean

此时，make会清除之前所编译的可执行文件及目标文件（object file, *.o）

4．make dist

此时，make将程序和相关的文档打包为一个压缩文档以供发布，该命令生成了`tar.gz`的压缩文件。
