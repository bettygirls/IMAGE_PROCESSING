  
# init 是所有linux 进程的父进程，进程号为1，是内核引导运行的，是系统中的第一个进程
-b :不执行相关脚本而直接进入单用户模式
-s :切换到单用户模式

查看系统进程命令 ：ps -ef | head  


查看init的配置文件 ： more /etc/inittab  


查看系统当前运行的级别： runlevel  



### /etc/inittab 中有0——6运行级别
#0  停机（千万不能把initdefault 设置为0）  


#1  单用户模式  


#2  多用户，没有 NFS(和级别3相似，会停止部分服务)
#3  完全多用户模式
#4  没有用到
#5  x11(Xwindow)   图形界面启动  或者 startx
#6  重新启动（千万不要把initdefault 设置为6）
 
