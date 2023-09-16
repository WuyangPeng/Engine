@ingroup group_Assist_Documentation

----------------------------
学习库

----------------------------
ogre（C++大学教程）

1. 版本：1.12.7。
2. 官方网站：https://www.ogre3d.org/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. 将imgui代码复制到Components\Overlay\src\imgui下。
5. 工程OgreXMLConverter和Plugin_DotScene的debug版本的运行库改成多线程 DLL (/MD)。

----------------------------
imgui（ogre关联）

1. 版本：1.77。
2. 官方网站：https://github.com/ocornut/imgui。
3. git地址：https://github.com/ocornut/imgui.git。

----------------------------
ogre-next（引擎不关联）

1. 版本：2.3。
2. 官方网站：https://github.com/OGRECave/ogre-next 。
3. 编译依赖库，git地址：https://github.com/OGRECave/ogre-next-deps.git 。
4. 依赖库编译方式：CMake。x64版本建立在BuildX64下。
5. 编译依赖库，并将ogre-next-deps\BuildX64\ogredeps下的文件复制到ogre-next\Dependencies下。
6. ogre-next编译方式：CMake。x64版本建立在BuildX64下。

----------------------------
ZThread（C++编程思想） 

1.  版本：2.3.2。
2.  官方网站：http://zthread.sourceforge.net/。
3.  在Build下新建ZThread静态库工程，包含include下的头文件和src下根目录下的所有文件。
	修改输出目录为$(SolutionDir)$(Platform)\$(Configuration)\，中间目录为$(Platform)\$(Configuration)\。
	附加包含目录..\..\..\include;
	SDL检查设置为否。
4.  文件Guard.h：
	在223行，去掉参数l1。
    在431行，extract改为this->extract。
    在494行，isDisabled()改为this->isDisabled()。
5.  文件ThreadLocal.h：
    在304行，增加return *this;
6.  文件GuardedClass.h：
	在57行，去掉参数l。
7.  MutexImpl.h第156行，改成this->ownerAcquired(self);
	第167行改成this->waiterArrived(self);
	第176行改成this->waiterDeparted(self);
	第195行改成this->ownerAcquired(self);
	第239行改成this->ownerAcquired(self);
	第256行改成this->waiterArrived(self);
	第265行改成this->waiterDeparted(self);
	第287行改成this->ownerAcquired(self);
	第329行改成this->ownerReleased(impl);
8.  ThreadOps.cxx第55行改成 HINSTANCE hInst = ::GetModuleHandleA("Kernel32.dll");
9.	复制工程到ZThreadDll，配置类型改成动态库。预处理器定义增加ZTHREAD_EXPORTS;。

----------------------------	
OIS（C++大学教程）

1. 版本：1.3。
2. 官方网站：http://wiki.ogre3d.org/OIS。
3. Debug和OIS_DebugDll版本设置目标文件名$(ProjectName)_d。
4. Demo_Console的输出文件名改成$(OutDir)Demo_Console.exe。
5. Demo_FFTest的输出文件名改成$(OutDir)Demo_FFTest.exe。
6. 直接复制x64工程。
7. 修改输出目录为$(SolutionDir)$(Platform)\$(Configuration)\，中间目录为$(Platform)\$(Configuration)\。
   附加库目录增加$(SolutionDir)$(Platform)\$(Configuration)\。
8. 文件OISConsole.cpp：
   第15行插入#include <algorithm>。 

----------------------------
freealut（OgreAL相关联） 

1. 版本：1.1.0。
2. 官方网站：https://github.com/vancegroup/freealut。
3. git地址：https://github.com/vancegroup/freealut.git。
4. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
5. 定义正确的OPENAL_INCLUDE_DIR到($openal-soft)/include/AL。 
6. 定义正确的OPENAL_LIBRARY到($openal-soft)/BuildX64/Release/OpenAL32.lib和($openal-soft)/BuildWin32/Release/OpenAL32.lib

----------------------------
OgreAL（C++大学教程） 

1. 版本：0.2。
2. 官方网站：http://wiki.ogre3d.org/tiki-index.php?page=OgreAL。
             https://sourceforge.net/projects/ogreal/。
3. 设置正确的附加包含目录到$(OgreInclude)、$(OgreBuildInclude)、$(OpenALSoftInclude)\AL。
4. 设置正确的附加包含目录到../../libogg/include，../../libvorbis/include和../../freealut/include。
5. Debug版本设置目标文件名$(ProjectName)_d。
6. 设置正确的附加库目录到$(OpenALSoftWin32DebugLib)和$(OpenALSoftWin32ReleaseLib)。
7. 设置正确的附加库目录到$(OgreWin32DebugLib)和$(OgreWin32ReleaseLib)。
8. 设置正确的附加库目录到../../freealut/BuildWin32/src/$(Configuration)。
9. 设置正确的附加库目录到../../libogg/BuildWin32/$(Configuration)
                         ../../libvorbis/BuildWin32/lib/$(Configuration)。					 
10.设置正确的附加依赖项vorbis.lib、vorbisfile.lib和ogg.lib。
11.生成后事件命令行第2条改成xcopy "../../freealut/BuildWin32/src/$(Configuration)/alut.dll" "$(SolutionDir)Demos/bin/$(Configuration)"  /F /Y。
12.四个Demo无法通过编译。
13.文件OgreALPrereqs.h：
   注释第13行，在第18行后插入
   typedef ALenum (*EAXGetBufferMode)(ALuint buffer, ALint *pReserved);
   typedef ALboolean (*EAXSetBufferMode)(ALsizei n, ALuint *buffers, ALint value);
14.文件OgreALSoundManager.cpp：
   第3行、第147行、第152行，ms_Singleton改成msSingleton。
15.文件OgreALSound.h：
   第226行插入virtual void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false) { }
16.文件OgreALListener.h：
   第95行插入virtual void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false) { }
17.文件OgreALListener.cpp：
   第3行、第36行、第41行，ms_Singleton改成msSingleton。
18.复制x64工程，设置正确的附加库目录到$(OpenALSoftX64DebugLib)、$(OpenALSoftX64ReleaseLib)、$(OgreX64DebugLib)、$(OgreX64ReleaseLib)、
   ../../freealut/BuildX64/src/$(Configuration)、../../libogg/BuildX64/$(Configuration)、
   ../../libvorbis/BuildX64/lib/$(Configuration)。
 
----------------------------
DirectX（引擎不关联）

1. 版本：9.29.1962。

----------------------------
Wild Magic（引擎不关联）

1. 版本：5.17。
2. 官方网站：https://www.geometrictools.com/index.html。
3. 设置正确的环境变量DXSDK_DIR指向正确的Microsoft DirectX SDK路径。
4. 一些文件另存为ANSI编码，以通过编译。

----------------------------
Geometric Tools（引擎不关联）
                  
1. 版本：5.10。
2. 官方网站：https://www.geometrictools.com/index.html。
3. 一些文件另存为ANSI编码，以通过编译。

----------------------------
irrlicht（引擎不关联）

1. 版本：1.8.4。
2. 官方网站：http://irrlicht.sourceforge.net/
3. 设置附加包含目录$(DXSDK_DIR)\Include;

----------------------------
glew（引擎不关联）

1. 版本：2.2.0。
2. 官方网站：http://glew.sourceforge.net/。
3. 使用https://sourceforge.net/projects/glew/files/glew/2.2.0/下的才有源代码。
4. 工程在build\vc15。

----------------------------
loki（引擎不关联）

1. 版本：0.1.7。
2. 官方网站：http://loki-lib.sourceforge.net/。 
3. SmallObj.cpp第1132行改成throw std::bad_alloc();。
4. SafeFormat.h
   117行增加
   #if (defined(_WIN64))
        LOKI_PRINTF_STATE_FORWARD(unsigned int)
   #endif
5. FunctionTest.cpp第757行改成catch(std::bad_function_call)。
6. LevelMutex工程增加预处理器定义_ALLOW_RTCc_IN_STL;WINDOWS_IGNORE_PACKING_MISMATCH。
7. SmartPtr.h第1189行改成{ auto ptr = GetImplRef(rhs);GetImplRef(*this) = OP::Clone(ptr); }。
8. AssocVectorTest.h第162、163、165行去掉TestAllocator模板参数。
9. 直接复制x64工程。

----------------------------
TIFF（引擎不关联）

1. 版本：4.1.0。
2. 官方网站：http://www.libtiff.org/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
shwild（引擎不关联）

1. 版本：0.9.20。
2. 官方网站：http://www.shwild.org/。
3. 修改build\vc9和build\vc9_x64下makefile文件，
   第26行改成COMP_TAG = vc16。
   第45行改成PROJ_LIB_DIR = $(PROJ_BASE_DIR)\Win32\lib和PROJ_LIB_DIR = $(PROJ_BASE_DIR)\X64\lib。
   注释掉第153行和158行（-WX警告视为错误）。
   16行增加STLSOFT = ($stlsoft)。    
4. 运行VS，并打开命令提示符，定位至build\vc9和build\vc9_x64录，执行nmake。
7. 编译X64，转到目录Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build下运行vcvars64.bat。
8. 不要执行nmake clean。

----------------------------
cppunit（引擎不关联）

1. 版本：1.12.1。
2. 官方网站：https://sourceforge.net/projects/cppunit/。

----------------------------
libpng（引擎不关联）

1. 版本：1.6.37。
2. 官方网站：http://www.libpng.org/pub/png/libpng.html。

----------------------------
libxml++（引擎不关联）

1. 版本：4.9.1。
2. 官方网站：http://libxmlplusplus.sourceforge.net/。

----------------------------
mysql++（引擎不关联）

1. 版本：3.2.5。
2. 官方网站：https://tangentsoft.com/mysqlpp/home。

----------------------------
SDL2（引擎不关联）

1. 版本：2.0.12。
2. 官方网站：http://www.libsdl.org/。

----------------------------
perl 

1. 版本：5.36.0。
2. 官方网站：https://www.perl.org/
3. 修改win32下的Makefile文件，112行去除注释。
4. 修改win32下的Makefile文件，22行的INST_DRV设置成($perl)。
5. 运行VS，并打开命令提示符，定位至 ($perl)/Win32目录
6. 编译Win32的debug版，修改win32下的Makefile文件，29行、143行去除注释，23行设置成$(INST_DRV)\BuildWin32\Debug。
7. 编译Win32的release版，修改win32下的Makefile文件，29行去除注释，143行注释，23行设置成$(INST_DRV)\BuildWin32\Release。
8. 编译X64，转到目录Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build下运行vcvars64.bat。
9. 编译X64的debug版，修改win32下的Makefile文件，143行去除注释，29行注释，23行设置成$(INST_DRV)\BuildX64\Debug。
10.编译X64的release版，修改win32下的Makefile文件，29行、143行注释，23行设置成$(INST_DRV)\BuildX64\Release。
11.在Win32目录层级下执行命令nmake。
12.编译四个版本中需要执行nmake clean，然后再执行nmake、nmake install。
13.编译Win32和X64版本中需要重新使用原版的perl编译。

----------------------------
Pantheios 

1. 版本：1.0.1。
2. 官方网站：http://www.pantheios.org/
3. 修改build\vc16.x64和build\vc16下makefile文件，
   第77行改成PROJ_LIB_DIR =	$(PROJ_BASE_DIR)\X64\lib和PROJ_LIB_DIR = $(PROJ_BASE_DIR)\Win32\lib。
   注释掉第687行和700行（-WX警告视为错误）。
   23行下增加
   STLSOFT = ($stlsoft)
   ACE = ($ACE)
4. 注释pantheios.h第196行，因为无法下载到1.10.1 beta 20版本的stlsoft。
5. test\component\test.component.bec.fprintf下的文件test.component.bec.fprintf.cpp注释掉第182行。
6. 运行VS，并打开命令提示符，定位至build\vc16.x64和build\vc16目录，执行nmake。
7. 编译X64，转到目录Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build下运行vcvars64.bat。
8. 不要执行nmake clean。

----------------------------
Openrj 

1. 版本：1.6.4。
2. 官方网站：http://www.openrj.org/
3. 修改build\vc8下makefile文件，
   第26行改成COMP_TAG = vc16。
   第44行改成PROJ_LIB_DIR = $(PROJ_BASE_DIR)\Win32\lib和PROJ_LIB_DIR = $(PROJ_BASE_DIR)\X64\lib。
   注释掉第110行和115行（-WX警告视为错误）。
   25行增加STLSOFT = ($stlsoft)。
   编译X64，27行下增加
   LD_ARGS = -machine:x64
   ARCH_TAG = .x64。
4. 运行VS，并打开命令提示符，定位至build\vc8目录，执行nmake。
5. 不要执行nmake clean。

----------------------------
chipmunk2D physics

1. 版本：7.0.3。
2. 官方网站：http://chipmunk-physics.net/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. chipmunk_demos的C++语言标准改成：std:c++latest。
5. ChipmunkDebugDraw.c
   第44行的(RGBA8)改成RGBA8。
   注释第63行到150行。 
   第170行到175行，第183行到186行，206行到213行，267行到270行的(Vertex)改成Vertex。
   第171行和182行改成
   Index index[] = { 0, 1, 2, 0, 2, 3 };
   Vertex *vertexes = push_vertexes(4, index, 6);
6. ChipmunkDemo.c   
   第353行到第355行改成
   sg_pass_action action{};
   action.colors[0] = {.action = SG_ACTION_CLEAR, .val = {0x07/255.0f, 0x36/255.0f, 0x42/255.0f}};
   第629行到第638行改成
   return sapp_desc{
			.init_cb = Init,
			.frame_cb = Display,
			.cleanup_cb = Cleanup,
			.event_cb = Event,			
			.width = 1024,
			.height = 768,
			.high_dpi = true,
			.window_title = "Chipmunk2D",
		};
7. ChipmunkDemoTextSupport.c
   注释第69行到165行。
   第206行到209行的(Vertex)改成Vertex。

----------------------------