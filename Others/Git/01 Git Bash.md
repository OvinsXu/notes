># 1.  基本操作
>>## 1.1  创建版本库
>>>### 1.1.1  通过命令行,转到目的文件夹.(使用pwd命令可查看当前目录)
>>>### 1.1.2  通过 git init 把当前目录变成git可以管理的库
>>>### 1.1.3  通过 git add filename    添加文件到暂存区
>>>### 1.1.4  通过 git commit    将文件提交到仓库
>>>>####  后面加-m添加注释,如: -m '这是提交的注释'
>>>#### 1.1.5  通过  git status 查看是否有文件未提交
>>>### 1.1.6  通过  git diff  filename      查看文件修改部分
>>>### 1.1.7  通过  git rm filename     删除文件
>>## 1.2  版本切换
>>> ### 1.2.1  通过 git log 查看项目日志
>>>>#### git log file  查看文件日志
>>>>#### git log .   查看本目录日志
>>>>#### git log --pretty=oneline  单行显示日志
>>> ### 1.2.2 回退
>>>> #### 1.2.2.1  通过  git reset  --hard HEAD^  回退一版本,HEAD^^回退两版本
>>>> #### 1.2.2.2 通过  git reset  --hard HEAD~nums  回退nums个版本
>>> ### 1.2.3  通过  cat filename  查看文件
>>>### 1.2.4   git reset --hard 版本号  //切换到指定版本
>>>### 1.2.5   git reflog   版本切换日志
>>## 1.3 分支管理
>>>### 1.3.1 添加分支  git branch 分支名
>>>### 1.3.2 查看分支  git branch
>>>### 1.3.3 切换分支  git checkout 分支名
>>>### 1.3.4 合并分支  git merge 分支名
>>>### 1.3.5 删除分支  git branch -d 分支名
># 二：远程操作
>>## 1.1  推送到远程服务器
>>>### 1.1.1  git URL master    //URL  远程地址链接
>>>### 1.1.2  git remote add BTS URL    //为远程地址URL设置别名BTS
>>## 1.2  团队合作
>>>### 1.2.1  通过 git clone URL   克隆远端服务器内容到本地
>>>### 1.2.2  通过 git pull URL master 更新服务器数据到本地