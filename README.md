# notes

## 简介

个人学习笔记,托管于`Github Pages`,使用`mdbook`进行构建。[点击访问](https://ovinsxu.github.io/notes/)

1. 安装rust
2. 安装mdbook
3. 创建项目
4. 书写博客
5. 上传github，设置自动构建

`mdbook`编写指南：[点击查看](https://hellowac.github.io/mdbook-doc-zh/zh-cn/index.html)

## 编写方式

将`markdown`笔记保存到对应文件夹后,在SUMMARY文件中记录。

## 文件夹说明

- src ： mdbook的生成源，里面存放`md`文件，会自动生成静态网页。
- src/SUMMARY.md ： 网页侧边的文章导航，需要在这里登记。
- stages ：草稿暂存区。 