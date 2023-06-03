# 记笔记环境配置

**有道云笔记**进行同步速记,有空再进行整理。  

**VScode** 用于编写并整理出规范的代码和笔记，并同步GitHub。  
**Quicker** 进行图片自动上传到sm.ms图床。  
**Git**在这里用于推送到GitHub。  

**GitHub和博客园**用于分享代码和笔记。  

## VScode配置

vscode [下载链接](https://code.visualstudio.com/Download)  
插件:  
`markdownlint`:检查语法是否规范  
`Markdown All in One`:以GitHub样式预览  

配置同步到Github

- 通过`SSH协议`进行安全连接,附[`SSH原理`](https://www.cnblogs.com/diffx/p/9553587.html)
- 在git>下执行`ssh-keygen -t rsa -C "你的email"`生成公私钥
- 将公钥保存在GitHub上,私钥保存在本地  

## 图片自动上传到图床

用Quicker自己写了个动作上传到[sm.ms](https://sm.ms/)  

## 附:Markdown语法规范

[Markdown中文文档](https://markdown-zh.readthedocs.io/en/latest/)  
