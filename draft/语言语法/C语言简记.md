# C语言简记  

C语言语法比较简单，可以选择《C程序设计语言》作为入门书籍。

## 一、基本数据类型  

1、常量和变量  

常量:  
`#define MY_AGE 10000`  
`const int MY_AGE = 10000:`  
变量:  
`int i = 0；`等等

2、整型数据  

`int`  
`long`  32位系统4个字节，64位系统8个字节  
`long long`  都为8个字节  

`unsigned int`  无符号类型  
long和long long用%ld输出  

0b  二进制数据  
0  八进制数据  
0x  十六进制数据  
  
C11后(在各平台通用)  

```c
int32_t  
int8_t  
uint8_t  
int64_t  
```

3、实型数据  

float  单精度，四个字节  用%f  
double   双精度，八个字节  
long double  长双精度，十六个字节 用%lf  
  
4.字符型数据  

转义字符  

```c
\a  响铃符  
\n  换行符  
\r  回车符  
\b  退格符  
\t  制表符  
\\    \  
\'    '  
\"    "  
```

字符型数据  

```c
char ch = 'A';  
printf("%c\n",ch);  
```

5.typedef自定义类型

`typedef  int64_t myint;`

定义在主函数前  
  
## 二.流程控制与循环  

1.if语句  

```C
if（）｛  
｝  
else if（）｛  
｝  
else｛  
｝  
```

2.switch语句  

```C

switch(ex){
    case ex1:  //此处为冒号  
    ...;  //如果ex为ex1，执行本语句  
    break;  //执行完跳出  
    case ex2:  
    ...;  
    break:  
    default:   //如果ex非ex1非ex2  
    ...:   //则执行本语句  
}
```

3.goto语句  

```C
label:  //标签  
...:  
...:  
...:  
goto lable: //跳转到标签  
```

4.for循环  

```C
for(i = 0;i<100;i++){  
for(){}   //嵌套循环  
if()｛  
goto end:  //跳出多重循环  
break;   //跳出本循环  
continue:  //跳出本次循环  
｝  
}  
end:  
```

5.while和do...while...  

```C
i=0;  
do｛    //先执行:再判断  
｝while();  
  
  
while(i<100){  //先判断，再执行  
if(i%2 ){  //可以挑奇数，即i%2== 1:true为1:error为0:  
  
}  
...;  
}  
```

## 三.常用运算符  

1.数学运算符  
\+ - * /   `乘除优先于加减`

数学函数  #include<math.h>  

2.逻辑运算符  

&&  逻辑与  
||  逻辑或  
！  非  

3.位运算符  

&  位与   有零为零，全一为一  
|  位或   有一为一，全零为零  
~  位反   零一互换  
^  异或   异一同零  
<<  左移   右边补零，类乘以二  
\>>  右移   类除以二  

## 四.输入与输出  

1.输出字符和字符串  
putchar(48);   //直接数字  
  
char ch = 'A';   //输出字符  
putchar(ch);  
  
puts();  //输出字符串  
  
char str[] ="Hello";  
puts(str);  

2.格式化输出  
printf();  

3.输入字符  
char inputchar = getchar();  

4.格式化输入  
scanf("%c",&c);  

## 五.数组  

1.一维数组  
int len[10] = {};  
2.二维数组  

```C
int arr[4][4]={  
{};  
{};  
{};  
{};  
};  
```

3.字符数组  

## 六.字符串操作  

1.字符串连接  

```C
char *str = "hello";  
char *str = "world";  
char dist[100];  
memset(dist,0,100);  
  
strcat(dist,str);  
strcat(dist," ");  
strcat(dist,str1);  
//strncat(dist,str1,3);   只取str1前3个  
```

2.格式化字符串  

3.类型转换  

atof   转浮点  
atoi   转整形  
...  
  
char *str ="100";  
int a;  
sscanf(str,"%d",&a);  
  
int a = 1000;  
char buf[100];  
sprintf(buf,"%d",a);  

4.比较  
5.截取  

## 七.函数(略)  

## 八.预处理  

1.预设常量  
`#define NUM 200`
可以在IDE配置  
2.条件预处理  

```C
#if  ....  
......:  
#elif ...  
......:  
#else  
......:  
  
```
  
3.防止引入头文件重复  

如果a.h引入b.h:b.h引入a.h  
在头文件中加入  

```C
#ifndef A_H_  
#define A_H_  
......:  
#endif  
```

4.宏函数  

```C
#define Loop(){  
.....  
}  
```

5.宏函数参数链接  

```C
void bts_a(){  
printf("a");  
};  
  
void bts_b(){  
printf("b");  
}  
  
#define link(name) bts_##name()  //  ##连接  
  
int main(){  
link(a);   //等价bts_a  
}  
```

6.宏函数可变参数  
`#define LOG_1(FORMAT,...)printf();printf(前缀，__VA_SRGS__);`
`#define LOG_2()`  
待深入...  

## 九.指针  

函数指针  

```C
hello(int a,char * b);
void(*fp)(int,char*) = &hello;  
fd(10,"A");  

typedef void(*bts)();  
bts fp = &hello;  
fp();  
```

无类型指针  
`void *data = "hello";`  
可以写任何类型  

## 十.共同体  

结构体  

```C
struct file{  
int a;  
char ch;  
};  
struct file bts;  
bts.a = 10;  
bts.ch = "A";  
// struct file bts = {...,...};  
  
typedef struct file bts  
  
typedef struct file{  //结构体名字  
int a;  
char ch;  
}bts;  //类型名字  
```

结构体指针  

```C
stu s1 = {...;...};  
stu * s2 = &1;  
s1.age = 20;  
```

共同体  

## 十一.文件操作  

写出文件  

```C
File * f = fopen("data.txt","w");  
if(f!=NULL){  
fpuc('A',f);  
fputs("helloworld",f);  
fclose(f);  
}else{  
puts();  
}  
```

读取文件  

```C
File *f = fopen("data.txt","r");  
if(f){  
char ch = fgetc(f);  
printf();  
char buf[100];  
fgets(buf,6,f);  
for(int = 0;i<100;i++){  
char ch = fgetc(f);  
if(ch != EOF){  
}  
}else{  
}  
fclose(f);  
}else{  
puts();  
}  
```

格式化写出和读取文件  
fprintf(f,"%d\n");  
fscanf(f,"%d\n",&a);
