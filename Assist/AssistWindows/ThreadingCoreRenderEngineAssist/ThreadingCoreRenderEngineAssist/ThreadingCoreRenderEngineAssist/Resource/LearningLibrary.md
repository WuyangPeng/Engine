@ingroup group_Assist_Documentation

----------------------------
ѧϰ��

----------------------------
ogre��C++��ѧ�̳̣�

1. �汾��1.12.7��
2. �ٷ���վ��https://www.ogre3d.org/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. ��imgui���븴�Ƶ�Components\Overlay\src\imgui�¡�
5. ����OgreXMLConverter��Plugin_DotScene��debug�汾�����п�ĳɶ��߳� DLL (/MD)��

----------------------------
imgui��ogre������

1. �汾��1.77��
2. �ٷ���վ��https://github.com/ocornut/imgui��
3. git��ַ��https://github.com/ocornut/imgui.git��

----------------------------
ogre-next�����治������

1. �汾��2.3��
2. �ٷ���վ��https://github.com/OGRECave/ogre-next ��
3. ���������⣬git��ַ��https://github.com/OGRECave/ogre-next-deps.git ��
4. ��������뷽ʽ��CMake��x64�汾������BuildX64�¡�
5. ���������⣬����ogre-next-deps\BuildX64\ogredeps�µ��ļ����Ƶ�ogre-next\Dependencies�¡�
6. ogre-next���뷽ʽ��CMake��x64�汾������BuildX64�¡�

----------------------------
ZThread��C++���˼�룩 

1.  �汾��2.3.2��
2.  �ٷ���վ��http://zthread.sourceforge.net/��
3.  ��Build���½�ZThread��̬�⹤�̣�����include�µ�ͷ�ļ���src�¸�Ŀ¼�µ������ļ���
	�޸����Ŀ¼Ϊ$(SolutionDir)$(Platform)\$(Configuration)\���м�Ŀ¼Ϊ$(Platform)\$(Configuration)\��
	���Ӱ���Ŀ¼..\..\..\include;
	SDL�������Ϊ��
4.  �ļ�Guard.h��
	��223�У�ȥ������l1��
    ��431�У�extract��Ϊthis->extract��
    ��494�У�isDisabled()��Ϊthis->isDisabled()��
5.  �ļ�ThreadLocal.h��
    ��304�У�����return *this;
6.  �ļ�GuardedClass.h��
	��57�У�ȥ������l��
7.  MutexImpl.h��156�У��ĳ�this->ownerAcquired(self);
	��167�иĳ�this->waiterArrived(self);
	��176�иĳ�this->waiterDeparted(self);
	��195�иĳ�this->ownerAcquired(self);
	��239�иĳ�this->ownerAcquired(self);
	��256�иĳ�this->waiterArrived(self);
	��265�иĳ�this->waiterDeparted(self);
	��287�иĳ�this->ownerAcquired(self);
	��329�иĳ�this->ownerReleased(impl);
8.  ThreadOps.cxx��55�иĳ� HINSTANCE hInst = ::GetModuleHandleA("Kernel32.dll");
9.	���ƹ��̵�ZThreadDll���������͸ĳɶ�̬�⡣Ԥ��������������ZTHREAD_EXPORTS;��

----------------------------	
OIS��C++��ѧ�̳̣�

1. �汾��1.3��
2. �ٷ���վ��http://wiki.ogre3d.org/OIS��
3. Debug��OIS_DebugDll�汾����Ŀ���ļ���$(ProjectName)_d��
4. Demo_Console������ļ����ĳ�$(OutDir)Demo_Console.exe��
5. Demo_FFTest������ļ����ĳ�$(OutDir)Demo_FFTest.exe��
6. ֱ�Ӹ���x64���̡�
7. �޸����Ŀ¼Ϊ$(SolutionDir)$(Platform)\$(Configuration)\���м�Ŀ¼Ϊ$(Platform)\$(Configuration)\��
   ���ӿ�Ŀ¼����$(SolutionDir)$(Platform)\$(Configuration)\��
8. �ļ�OISConsole.cpp��
   ��15�в���#include <algorithm>�� 

----------------------------
freealut��OgreAL������� 

1. �汾��1.1.0��
2. �ٷ���վ��https://github.com/vancegroup/freealut��
3. git��ַ��https://github.com/vancegroup/freealut.git��
4. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
5. ������ȷ��OPENAL_INCLUDE_DIR��($openal-soft)/include/AL�� 
6. ������ȷ��OPENAL_LIBRARY��($openal-soft)/BuildX64/Release/OpenAL32.lib��($openal-soft)/BuildWin32/Release/OpenAL32.lib

----------------------------
OgreAL��C++��ѧ�̳̣� 

1. �汾��0.2��
2. �ٷ���վ��http://wiki.ogre3d.org/tiki-index.php?page=OgreAL��
             https://sourceforge.net/projects/ogreal/��
3. ������ȷ�ĸ��Ӱ���Ŀ¼��$(OgreInclude)��$(OgreBuildInclude)��$(OpenALSoftInclude)\AL��
4. ������ȷ�ĸ��Ӱ���Ŀ¼��../../libogg/include��../../libvorbis/include��../../freealut/include��
5. Debug�汾����Ŀ���ļ���$(ProjectName)_d��
6. ������ȷ�ĸ��ӿ�Ŀ¼��$(OpenALSoftWin32DebugLib)��$(OpenALSoftWin32ReleaseLib)��
7. ������ȷ�ĸ��ӿ�Ŀ¼��$(OgreWin32DebugLib)��$(OgreWin32ReleaseLib)��
8. ������ȷ�ĸ��ӿ�Ŀ¼��../../freealut/BuildWin32/src/$(Configuration)��
9. ������ȷ�ĸ��ӿ�Ŀ¼��../../libogg/BuildWin32/$(Configuration)
                         ../../libvorbis/BuildWin32/lib/$(Configuration)��					 
10.������ȷ�ĸ���������vorbis.lib��vorbisfile.lib��ogg.lib��
11.���ɺ��¼������е�2���ĳ�xcopy "../../freealut/BuildWin32/src/$(Configuration)/alut.dll" "$(SolutionDir)Demos/bin/$(Configuration)"  /F /Y��
12.�ĸ�Demo�޷�ͨ�����롣
13.�ļ�OgreALPrereqs.h��
   ע�͵�13�У��ڵ�18�к����
   typedef ALenum (*EAXGetBufferMode)(ALuint buffer, ALint *pReserved);
   typedef ALboolean (*EAXSetBufferMode)(ALsizei n, ALuint *buffers, ALint value);
14.�ļ�OgreALSoundManager.cpp��
   ��3�С���147�С���152�У�ms_Singleton�ĳ�msSingleton��
15.�ļ�OgreALSound.h��
   ��226�в���virtual void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false) { }
16.�ļ�OgreALListener.h��
   ��95�в���virtual void visitRenderables(Ogre::Renderable::Visitor* visitor, bool debugRenderables = false) { }
17.�ļ�OgreALListener.cpp��
   ��3�С���36�С���41�У�ms_Singleton�ĳ�msSingleton��
18.����x64���̣�������ȷ�ĸ��ӿ�Ŀ¼��$(OpenALSoftX64DebugLib)��$(OpenALSoftX64ReleaseLib)��$(OgreX64DebugLib)��$(OgreX64ReleaseLib)��
   ../../freealut/BuildX64/src/$(Configuration)��../../libogg/BuildX64/$(Configuration)��
   ../../libvorbis/BuildX64/lib/$(Configuration)��
 
----------------------------
DirectX�����治������

1. �汾��9.29.1962��

----------------------------
Wild Magic�����治������

1. �汾��5.17��
2. �ٷ���վ��https://www.geometrictools.com/index.html��
3. ������ȷ�Ļ�������DXSDK_DIRָ����ȷ��Microsoft DirectX SDK·����
4. һЩ�ļ����ΪANSI���룬��ͨ�����롣

----------------------------
Geometric Tools�����治������
                  
1. �汾��5.10��
2. �ٷ���վ��https://www.geometrictools.com/index.html��
3. һЩ�ļ����ΪANSI���룬��ͨ�����롣

----------------------------
irrlicht�����治������

1. �汾��1.8.4��
2. �ٷ���վ��http://irrlicht.sourceforge.net/
3. ���ø��Ӱ���Ŀ¼$(DXSDK_DIR)\Include;

----------------------------
glew�����治������

1. �汾��2.2.0��
2. �ٷ���վ��http://glew.sourceforge.net/��
3. ʹ��https://sourceforge.net/projects/glew/files/glew/2.2.0/�µĲ���Դ���롣
4. ������build\vc15��

----------------------------
loki�����治������

1. �汾��0.1.7��
2. �ٷ���վ��http://loki-lib.sourceforge.net/�� 
3. SmallObj.cpp��1132�иĳ�throw std::bad_alloc();��
4. SafeFormat.h
   117������
   #if (defined(_WIN64))
        LOKI_PRINTF_STATE_FORWARD(unsigned int)
   #endif
5. FunctionTest.cpp��757�иĳ�catch(std::bad_function_call)��
6. LevelMutex��������Ԥ����������_ALLOW_RTCc_IN_STL;WINDOWS_IGNORE_PACKING_MISMATCH��
7. SmartPtr.h��1189�иĳ�{ auto ptr = GetImplRef(rhs);GetImplRef(*this) = OP::Clone(ptr); }��
8. AssocVectorTest.h��162��163��165��ȥ��TestAllocatorģ�������
9. ֱ�Ӹ���x64���̡�

----------------------------
TIFF�����治������

1. �汾��4.1.0��
2. �ٷ���վ��http://www.libtiff.org/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
shwild�����治������

1. �汾��0.9.20��
2. �ٷ���վ��http://www.shwild.org/��
3. �޸�build\vc9��build\vc9_x64��makefile�ļ���
   ��26�иĳ�COMP_TAG = vc16��
   ��45�иĳ�PROJ_LIB_DIR = $(PROJ_BASE_DIR)\Win32\lib��PROJ_LIB_DIR = $(PROJ_BASE_DIR)\X64\lib��
   ע�͵���153�к�158�У�-WX������Ϊ���󣩡�
   16������STLSOFT = ($stlsoft)��    
4. ����VS������������ʾ������λ��build\vc9��build\vc9_x64¼��ִ��nmake��
7. ����X64��ת��Ŀ¼Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build������vcvars64.bat��
8. ��Ҫִ��nmake clean��

----------------------------
cppunit�����治������

1. �汾��1.12.1��
2. �ٷ���վ��https://sourceforge.net/projects/cppunit/��

----------------------------
libpng�����治������

1. �汾��1.6.37��
2. �ٷ���վ��http://www.libpng.org/pub/png/libpng.html��

----------------------------
libxml++�����治������

1. �汾��4.9.1��
2. �ٷ���վ��http://libxmlplusplus.sourceforge.net/��

----------------------------
mysql++�����治������

1. �汾��3.2.5��
2. �ٷ���վ��https://tangentsoft.com/mysqlpp/home��

----------------------------
SDL2�����治������

1. �汾��2.0.12��
2. �ٷ���վ��http://www.libsdl.org/��

----------------------------
perl 

1. �汾��5.36.0��
2. �ٷ���վ��https://www.perl.org/
3. �޸�win32�µ�Makefile�ļ���112��ȥ��ע�͡�
4. �޸�win32�µ�Makefile�ļ���22�е�INST_DRV���ó�($perl)��
5. ����VS������������ʾ������λ�� ($perl)/Win32Ŀ¼
6. ����Win32��debug�棬�޸�win32�µ�Makefile�ļ���29�С�143��ȥ��ע�ͣ�23�����ó�$(INST_DRV)\BuildWin32\Debug��
7. ����Win32��release�棬�޸�win32�µ�Makefile�ļ���29��ȥ��ע�ͣ�143��ע�ͣ�23�����ó�$(INST_DRV)\BuildWin32\Release��
8. ����X64��ת��Ŀ¼Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build������vcvars64.bat��
9. ����X64��debug�棬�޸�win32�µ�Makefile�ļ���143��ȥ��ע�ͣ�29��ע�ͣ�23�����ó�$(INST_DRV)\BuildX64\Debug��
10.����X64��release�棬�޸�win32�µ�Makefile�ļ���29�С�143��ע�ͣ�23�����ó�$(INST_DRV)\BuildX64\Release��
11.��Win32Ŀ¼�㼶��ִ������nmake��
12.�����ĸ��汾����Ҫִ��nmake clean��Ȼ����ִ��nmake��nmake install��
13.����Win32��X64�汾����Ҫ����ʹ��ԭ���perl���롣

----------------------------
Pantheios 

1. �汾��1.0.1��
2. �ٷ���վ��http://www.pantheios.org/
3. �޸�build\vc16.x64��build\vc16��makefile�ļ���
   ��77�иĳ�PROJ_LIB_DIR =	$(PROJ_BASE_DIR)\X64\lib��PROJ_LIB_DIR = $(PROJ_BASE_DIR)\Win32\lib��
   ע�͵���687�к�700�У�-WX������Ϊ���󣩡�
   23��������
   STLSOFT = ($stlsoft)
   ACE = ($ACE)
4. ע��pantheios.h��196�У���Ϊ�޷����ص�1.10.1 beta 20�汾��stlsoft��
5. test\component\test.component.bec.fprintf�µ��ļ�test.component.bec.fprintf.cppע�͵���182�С�
6. ����VS������������ʾ������λ��build\vc16.x64��build\vc16Ŀ¼��ִ��nmake��
7. ����X64��ת��Ŀ¼Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build������vcvars64.bat��
8. ��Ҫִ��nmake clean��

----------------------------
Openrj 

1. �汾��1.6.4��
2. �ٷ���վ��http://www.openrj.org/
3. �޸�build\vc8��makefile�ļ���
   ��26�иĳ�COMP_TAG = vc16��
   ��44�иĳ�PROJ_LIB_DIR = $(PROJ_BASE_DIR)\Win32\lib��PROJ_LIB_DIR = $(PROJ_BASE_DIR)\X64\lib��
   ע�͵���110�к�115�У�-WX������Ϊ���󣩡�
   25������STLSOFT = ($stlsoft)��
   ����X64��27��������
   LD_ARGS = -machine:x64
   ARCH_TAG = .x64��
4. ����VS������������ʾ������λ��build\vc8Ŀ¼��ִ��nmake��
5. ��Ҫִ��nmake clean��

----------------------------
chipmunk2D physics

1. �汾��7.0.3��
2. �ٷ���վ��http://chipmunk-physics.net/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. chipmunk_demos��C++���Ա�׼�ĳɣ�std:c++latest��
5. ChipmunkDebugDraw.c
   ��44�е�(RGBA8)�ĳ�RGBA8��
   ע�͵�63�е�150�С� 
   ��170�е�175�У���183�е�186�У�206�е�213�У�267�е�270�е�(Vertex)�ĳ�Vertex��
   ��171�к�182�иĳ�
   Index index[] = { 0, 1, 2, 0, 2, 3 };
   Vertex *vertexes = push_vertexes(4, index, 6);
6. ChipmunkDemo.c   
   ��353�е���355�иĳ�
   sg_pass_action action{};
   action.colors[0] = {.action = SG_ACTION_CLEAR, .val = {0x07/255.0f, 0x36/255.0f, 0x42/255.0f}};
   ��629�е���638�иĳ�
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
   ע�͵�69�е�165�С�
   ��206�е�209�е�(Vertex)�ĳ�Vertex��

----------------------------