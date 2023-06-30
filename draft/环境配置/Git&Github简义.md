# Git&Github学习



## 1.基本操作

---

### 1  创建版本库

- 1.通过命令行,转到目的文件夹.(使用pwd命令可查看当前目录)
- 2.通过 git init 把当前目录变成git可以管理的库
- 3.通过 git add filename添加文件到暂存区
- 4.通过 git commit将文件提交到仓库,后面加-m添加注释,如:-m '这是提交的注释'
- 5.通过  git status 查看是否有文件未提交
- 6.通过  git diff  filename  查看文件修改部分
- 7.通过  git rm filename 删除文件

### 2  版本切换

- 通过 git log 查看项目日志
  - git log file  查看文件日志
  - git log . 查看本目录日志
  - git log--pretty=oneline  单行显示日志
- 回退
  - 通过  git reset --hard HEAD^  回退一版本,HEAD^^回退两版本
  - 通过  git reset --hard HEAD~nums  回退nums个版本
- 通过  cat filename  查看文件
- git reset--hard 版本号  //切换到指定版本
- git reflog   版本切换日志
  
#### 3 分支管理

- 添加分支  git branch 分支名
- 查看分支  git branch
- 切换分支  git checkout 分支名
- 合并分支  git merge 分支名
- 删除分支  git branch-d 分支名
  
---

## 二.远程操作

---

### 1.推送到远程服务器

- git URL master//URL  远程地址链接
- git remote add BTS URL//为远程地址URL设置别名BTS

### 2  团队合作

- 1.通过 git clone URL   克隆远端服务器内容到本地
- 2.通过 git pull URL master 更新服务器数据到本地

### 3.其他

- 生成密钥  `ssh-keygen -t rsa -C "ovins@outlook.com" `
- 设置名称  `git config --global user.name "ovins"`
- 设置邮箱  `git config --global user.email "ovins@outlook.com"`

生成一份公私钥后,我们把公钥添加到github上,私钥则保存在`用户目录/.ssh/`下.
		假如我们有多台主机,可以直接拷贝该文件夹。不用再去生成公私钥。但是需要使用`ssh-add`添加一下。并且把权限设置为`700`

---

## 一些 GitHub 的基本概念

---

### Repository

> 仓库的意思，即你的项目，你想在 GitHub 上开源一个项目，那就必须要新建一个 Repository ，如果你开源的项目多了，你就拥有了多个 Repositories 。

### Issue

> 问题的意思，举个例子，就是你开源了一个项目，别人发现你的项目中有bug，或者哪些地方做的不够好，他就可以给你提个 Issue ，即问题，提的问题多了，也就是 Issues ，然后你看到了这些问题就可以去逐个修复，修复ok了就可以一个个的 Close 掉。

### Star

> 这个好理解，就是给项目点赞，但是在 GitHub 上的点赞远比微博、知乎点赞难的多，如果你有一个项目获得100个star都算很不容易了！

### Fork

> 这个不好翻译，如果实在要翻译我把他翻译成分叉，什么意思呢？你开源了一个项目，别人想在你这个项目的基础上做些改进，然后应用到自己的项目中，这个时候他就可以 Fork 你的项目，这个时候他的 GitHub 主页上就多了一个项目，只不过这个项目是基于你的项目基础（本质上是在原有项目的基础上新建了一个分支，分支的概念后面会在讲解Git的时候说到），他就可以随心所欲的去改进，但是丝毫不会影响原有项目的代码与结构。

### Pull Request

> 发起请求，这个其实是基于 Fork 的，还是上面那个例子，如果别人在你基础上做了改进，后来觉得改进的很不错，应该要把这些改进让更多的人收益，于是就想把自己的改进合并到原有项目里，这个时候他就可以发起一个 Pull Request（简称PR） ，原有项目创建人就可以收到这个请求，这个时候他会仔细review你的代码，并且测试觉得OK了，就会接受你的PR，这个时候你做的改进原有项目就会拥有了。

### Watch

> 这个也好理解就是观察，如果你 Watch 了某个项目，那么以后只要这个项目有任何更新，你都会第一时间收到关于这个项目的通知提醒。

### Gist

> 有些时候你没有项目可以开源，只是单纯的想分享一些代码片段，那这个时候 Gist 就派上用场了！
