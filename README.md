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
- Android
- Macintosh

## Setup（安装程序）:
- Before building, make sure your setup is correct : 
- 在构建之前，请确保您的设置正确：

### Setup Window machine（设置Window机器）:
- Install Visual Studio 2022 Community or Professional, make sure to add "Desktop development with C++".
- 安装Visual Studio 2022社区版或专业版，确保添加“使用C++进行桌面开发”。

### Compile（编译）：

	1. Windows平台

		(1) Libs目录下为依赖库，如果出现依赖库错误，
			根据Engine\EngineWindows\ThreadingCoreRenderEngine\ThreadingCoreRenderEngine\Resource下的Library.md进行修正。
	
		(2) 执行Environment下的批处理文件SetIncludeEnv.bat和SetLibEnv.bat各两次
			（LibsEnvironmentBaseInclude等变量需要使用其他的环境变量，所以需要执行两次）。
	
		(3) 执行MillenniumHistory、RiseOfHistory和TheLastOverlord工程$$Windows目录下的SetAllEnvironment.bat。
	
		(4) 编译Engine工程。
	
		(5) 编译Assist工程。
	
		(6) 编译Game工程。
	
		(7) 编译MillenniumHistory（千年史策）、RiseOfHistory（历史的崛起）和TheLastOverlord（最后的霸王）工程。
	
		(8) 编译各工程的单元测试（EngineTesting依赖于Assist）。

	2. linux平台 

		(1) 将Libs文件复制到/data/github/下。
	
		(2) 执行cd /data/github/Libs/Bat。
	
		(3) 执行sh create_lib。如果出现依赖库错误，
			根据Engine\EngineWindows\ThreadingCoreRenderEngine\ThreadingCoreRenderEngine\Resource下的Library.md进行修正。
