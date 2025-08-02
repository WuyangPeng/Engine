# Threading Core Render Engine（线程核心渲染引擎）

Engine is an open-source 3D rendering engine written in C++ and using OpenGL,OpenGLES,DirectX and Vulkan as graphic API.
It can be used for activities such as:
  - Gaming
  - Scientific computation and visualization
  
引擎是一个开源的三维绘制引擎，用C++编写，使用OpenGL、OpenGLES、DirectX、Vulkan作为图形API。
它可用于以下活动：
  - 游戏
  - 科学计算和可视化

### Supported Platforms（支持平台）:
- windows
- linux
- android
- macintosh

## Setup（安装程序）:
- Before building, make sure your setup is correct : 
- 在构建之前，请确保您的设置正确：

### Setup Window machine（设置Window机器）:
- Install Visual Studio 2022 Community or Professional, make sure to add "Desktop development with C++".
- 安装Visual Studio 2022社区版或专业版，确保添加“使用C++进行桌面开发”。

### Compile（编译）：

### Windows平台

- Libs目录下为依赖库，如果出现依赖库错误，根据Engine\EngineWindows\ThreadingCoreRenderEngine\ThreadingCoreRenderEngine\Resource下的Library.md进行修正。
	
- 编译Engine工程。
	
- 编译Assist工程。
	
- 编译Game工程。
	
- 编译MillenniumHistory（千年史策）、RiseOfHistory（历史的崛起）和TheLastOverlord（最后的霸王）工程。
	
- 编译各工程的单元测试（EngineTesting依赖于Assist）。

### linux平台 

- 下载代理
	cd /data  
	tar -zxvf clashpremium-release-linux-amd64.tar.gz  
	mv CrashCore clash  
	wget -O config.yaml "https://bergv.no-mad-world.club/link/KWK9VOvamb7MfR10?clash=3"  
	chmod +x clash  
	nohup ./clash -d . &  

- 安装 git  
	sudo yum install git  
	git config --global http.https://github.com.proxy http://127.0.0.1:7890  

- 下载仓库

	git clone https://github.com/WuyangPeng/Engine.git /data/coding  
	cd /data/coding  
	git checkout develop  
	git pull origin develop  
	git submodule update --init --recursive  

- 安装 cmake

	sudo yum install cmake

- 安装c++ 编译器

	sudo dnf install gcc-c++

- 升级 gcc

	tar -zxvf gcc-14.2.0.tar.gz  
	cd gcc-14.2.0  

	./contrib/download_prerequisites  
	mkdir build  
	cd build  
	../configure -enable-checking=release -enable-languages=c,c++ -disable-multilib  
	make -j1  
	make install  

-  复制文件
	cp /usr/local/lib64/libstdc++.so.6.0.33 /usr/lib64/  
	cd /usr/lib64/  
	ll libstdc*  
	rm -f libstdc++.so.6  
	ln -s libstdc++.so.6.0.33 libstdc++.so.6  
	ll libstdc*  

	cd /usr/local/bin  
	mv g++ g++_old  
	ln -s x86_64-pc-linux-gnu-g++ g++  

	cd /usr/bin  
	ll *g++*  
	mv g++ g++_old  
	ln -s x86_64-pc-linux-gnu-g++ g++  
	ll *gcc*  
	mv  gcc gcc_old  
	ln -s x86_64-pc-linux-gnu-gcc gcc  

-  安装 openssl

	sudo yum install openssl-devel

-  安装 autoconf

	sudo yum install autoconf  
	sudo yum install autoconf automake libtool  
	sudo yum install apr-devel apr-util-devel  

-  安装opengl

	sudo yum install mesa-libGL-devel freeglut-devel
	
-  安装python

	sudo dnf install python3-devel
	
- 编译工程
	
	cd /data/coding/Bat  

	sh compile.sh  

	如果出现依赖库错误，根据Engine\EngineWindows\ThreadingCoreRenderEngine\ThreadingCoreRenderEngine\Resource下的Library.md进行修正。

