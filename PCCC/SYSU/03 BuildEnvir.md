# 在win10下搭建汇编语言开发环境

## DOSBox

### 下载安装DOSBox

[工具官网：http://www.dosbox.com/](http://www.dosbox.com/)

[项目主页：http://sourceforge.net/projects/dosbox/](http://sourceforge.net/projects/dosbox/)

[下载链接：https://nchc.dl.sourceforge.net/project/dosbox/dosbox/0.74-3/DOSBox0.74-3-win32-installer.exe](https://nchc.dl.sourceforge.net/project/dosbox/dosbox/0.74-3/DOSBox0.74-3-win32-installer.exe)

运行DOSBox0.74-3-win32-installer.exe，全程默认选项即可。

### 配置DOSBox

创建一个用于保存汇编工具（如MASM、Link、DEBUG等工具）和汇编文件（*.asm）的工作目录。如C:\DOSBOX</br>
打开DOSBox的安装根目录(默认安装路径：C:\Program Files (x86)\DOSBox-0.74)。</br>
双击文件DOSBox 0.74 Options.bat，运行该批处理文件后系统会用文本文档Notepad打开配置文件dosbox-0.74.conf。</br>
定位到dosbox-0.74.conf文件的[autoexec]节点（一般在该文件末尾），在文件中添加以下内容：

```conf
MOUNT C C:\DOSBOX                  # 将目录C:\DOSBOX挂载为DOSBOX下的C:
C:
```

## 汇编工具MASM32

(官方工具包并不方便，可直接网络上搜寻下载汇编工具压缩包)</br>

[工具官网：http://www.masm32.com/](http://www.masm32.com/)

[下载链接：http://117.128.6.17/cache/www.masm32.com/download/masm32v11r.zip?ich_args2=530-25085014063598_8715635fd9b3c204d046e7b9dc4f0fba_10001002_9c896225d4c4f3d7973a518939a83798_a77d6e061f56ff5f6a185ae79a2f9018](http://117.128.6.17/cache/www.masm32.com/download/masm32v11r.zip?ich_args2=530-25085014063598_8715635fd9b3c204d046e7b9dc4f0fba_10001002_9c896225d4c4f3d7973a518939a83798_a77d6e061f56ff5f6a185ae79a2f9018)

解压masm32v11r.zip，运行install.exe</br>
在C:\masm32中寻找汇编工具debug.exe, edit.com, link.exe, masm.exe</br>
将寻找到的汇编工具复制粘贴至开始时创建的工作目录</br>

## 编译程序

打开DOSBox程序 ，会出现如图所示的两个界面，我们只需关注较小的窗口；另外一个界面无需关注， 可以最小化但是不能关闭它。以下命令的拼写忽略大小写。

### EDIT

(推荐使用其他软件编辑，如UE、VIM)</br>
EDIT 文件名.asm，启动EDIT.EXE进入代码编辑状态,当进入DOSBOX编辑界面，随意可以按Windows键退出DOSBOX编辑界面。

### MASM

MASM 文件名.asm，生成目标文件文件名.OBJ（生成过程中可以修改目标文件名，直接回车可保持默认目标文件名）</br>
注意：此时可能生成三个文件：*.obj、*.lst和*.crf文件。其中，列表文件*.lst和交叉引用文件非必选，前者是汇编语言汇编的机器语言与汇编语言对照表，可用于调试；后者给出了用户定义的所有符号和对每个符号定义、引用的行号。

### LINK

LINK 文件名.OBJ，链接生成可执行文件文件名.EXE

### DEBUG

DEBUG 文件名.EXE，在DEBUG的命令提示符“-”出现后开始调试

## DEBUG命令

### R

R 查看程序运行前的寄存器组初始值

### U

U 查看程序反汇编代码。从反汇编代码中可看出，变量会被汇编为直接寻址方式，使用变量在数据段内的有效地址表示

### T

T 单步调试

### D

D 观察内存变化（D后不带地址或范围，默认显示上一个D命令之后的80字节内容）

### G

G 地址，程序从当前位置直接运行到指定地址处停下

### E

E 地址修改内存中的内容，如：E DS:0100，输入空格可逐个字节修改，回车停止修改

## 参考资料

[博客园](https://www.cnblogs.com/zyever/p/7919007.html)
[CSDN](https://blog.csdn.net/doniexun/article/details/45438457)
