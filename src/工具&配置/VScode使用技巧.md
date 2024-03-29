# VScode使用技巧

使用VScode需要注意的特点：

1. 跨平台：支持`Linux`、`Windows`、`Mac`，不同系统平台可能存在一些差异。这里主要以`Linux`为例。
2. 多版本：有标准版本，预发布版（insider），纯开源版（VSCodium不包含微软网络服务）。
3. 与Git/Github的集成操作。
4. 其他一些基本信息，用途等，自行了解。

## 1. 基本功能

默认安装后，具有的功能。

### 1.1 快捷键

下面VScode默认的几个常用快捷键。不同系统可能会有差异，建议有需求就搜索并记起来，熟能生巧。

1. `F2`：重命名符号

2. `Ctrl + /`：添加/删除注释

3. `Alt + 上/下`：移动代码行

4. `Ctrl+Shift+上/下`      选择多行

5. 。。。等等。

也可以通过安装插件，来更改快捷键。比较流行的有`VIM`方案。

### 1.2 用户代码段

设置-->用户代码段-->选择匹配的语言

```json
// Example(在ts.json中):
 "Print to console": {
  "prefix": "log",
  "body": [
   "console.log('$1');",
   "$2"
 ],
 "description": "Log output to console"
 }
```

上面的例子中，定义了ts文件中可以触发的代码填充，输入`log`然后按`tab`，就会输出`console.log('');`光标默认在`$1`的位置，按``tab`则会跳转到下一个位置。

## 2. 扩展（或者叫插件）

上面了解了vscode的基本功能后，我们知道VScode有默认的一些配置方案，比如快捷键，外观等，我们自己可以进行一些设置，增强功能，比如用户代码段。

同时VScode还支持扩展功能，安装扩展后，扩展会改变一些设置，和提供增强的功能。主要扩展类型有：

1. VScode优化类扩展：语言扩展包，文件图标主题，翻译，高级Git操作等。
2. 开发增强类扩展：比如语言、框架等。
3. 其他类型：五花八门，听歌，看图，改Word等。

## 3. 开发环境配置

了解了基本功能和扩展后，通过安装合适的扩展就可以搭建我们的开发环境了。

但是如果你需要为多种语言配置开发环境，安装太多扩展后则可能影响VScode的使用效率。比如开发`Java`时，我们希望不启用`Python/C++/...`的扩展，我们希望能为不同环境使用不同的VScode配置。

我们很容易看到扩展有禁用，和工作区禁用两种选项，因此我们可以通过工作区设置来配置不同的开发环境。但是我们很快发现不足，比如新安装的扩展，会默认应用到所有的工作区（因为没有禁用）。还有工作区不能使用VScode进行同步。

好在后来VScode出了配置文件功能，可以将所有的设置都进行了隔离，这才是正确的多环境配置方式。配置文件也可以进行同步。

### 3.1 配置文件

设置-->配置文件-->新建配置文件

官方甚至提供了一些默认的配置模板,比如 `Python/Java Spring/...`，也就是说，安装完VScode，选择一下官方的配置方案后,就可以进行开发了。

因此使用方式为，为一种开发环境创建一个配置文件，配置文件会保存外观，插件等信息，当需要另外一种环境的时候，创建另外的配置文件。