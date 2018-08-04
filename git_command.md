
# git安装及使用
	   ---

## 1 ssh建立连接
      安装git命令   sudo apt-get install git 
      在linux终端使用命令生成ssh key
      ssh-keygen -t rsa -C [github邮箱]
      复制公钥.pub结尾的文件内容，粘贴到github网页端设置>ssh中
      ssh -T git@github.com 测试是否可以与github进行通信

## 2 本地上传文件到github:
      × 进入要上传文件的目录，初始化为git仓库  git init
      × 创建本地仓库 git remote add origin git@github.com:[github用户名]/[github仓库].git
      其中：origin是远程仓库默认的用户名，可以在.git/config中进行修改
      * touch readme.txt
      * vim readme.txt  输入需要的内容
      × git add readme.txt
      * git commit -m "提交注释" 
      * git push -u origin master

## 3 修改本地文件，更新至远程仓库
	  git commit -m -a "提交注释" 
      git push

##  4 在本地添加分支，并同步到远程仓库 这种方法创建的分支是和master同一级的分支
     git branch git   在本地添加分支
     git branch -r
     git checkout git  切换上传文件的分支
     git add readme.txt     同步修改后的文件
     git commit -m -a ""
     git push
     //   git push --set-upstream origin git 
	  也可以利用命令在远程直接创建分支：
	  git push origin master:git
	  删除远程分支：
	  git push origin:git

## 5 删除远程库中的文件
     git checkout 所在分支
     git rm xxx.txt
     git push

## 6 删除远程分支
	 git push origin --delete <分支名>

## 7 git branch
	 git branch --all  打印所有分支结构
	 git branch -vv    打印分支名和其他信息
	 git branch --lis  只打印分支名
