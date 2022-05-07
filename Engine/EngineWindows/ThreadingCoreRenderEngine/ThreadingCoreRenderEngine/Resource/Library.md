@ingroup group_Engine_Documentation

----------------------------
��

----------------------------
GSL������ֱ�ӹ�����

1. �ٷ���վ��https://github.com/microsoft/GSL��
2. git��ַ��https://github.com/microsoft/GSL.git��

----------------------------
CppCoreGuidelines������ֱ�ӹ�����

1. �ٷ���վ��https://github.com/isocpp/CppCoreGuidelines��
2. git��ַ��https://github.com/isocpp/CppCoreGuidelines.git��

----------------------------
OpenGL������ֱ�ӹ�����

1. �汾��4.6��
2. �ٷ���վ��http://www.opengl.org/registry/��
3. git��ַ��https://github.com/KhronosGroup/OpenGL-Registry.git��

----------------------------
EGL������ֱ�ӹ�����

1. �汾��1.5��
2. �ٷ���վ��https://www.khronos.org/registry/EGL/��
3. git��ַ��https://github.com/KhronosGroup/EGL-Registry.git��

----------------------------
boost������ֱ�ӹ�����

1. �汾��1.78.0��
2. �ٷ���վ��http://www.boost.org/��
3. ����ָ�
  ��1������bootstrap��
  ��2������b2 --toolset=msvc-10.0���ض��汾��
           b2�����°汾��	
  ��3����������context����Ҫ��ʹ��ѡ��asmflags=\safeseh��

----------------------------
stlsoft������ֱ�ӹ�����

1. �汾��1.10.1-beta33��
2. git��ַ��https://github.com/synesissoftware/STLSoft-1.10
3. ��stlsoft.h��778������
	# elif (_MSC_VER < 2000)
	#   define STLSOFT_COMPILER_VERSION_STRING      "Visual C++ 16.x"

----------------------------
ACE������ͨ����NETWORK_USE_ACE������

1. �汾��7.0.0��
2. �ٷ���վ��http://download.dre.vanderbilt.edu/�� http://www.dre.vanderbilt.edu/~schmidt/ACE.html��
3. ��aceĿ¼�������ļ�config.h������ȷ��config�ļ���
   #ifndef ACE_CONFIG_H
   #define ACE_CONFIG_H

       #include "config-win32.h"

   #endif /* ACE_CONFIG_H */
   ��ʹ��ACE�µ��������ļ�CopyACEConfigִ�С�
4. �����x64�汾���ֶ���ACE\ACE_wrappers\lib���ļ����Ƶ�ACE\ACE_wrappers\lib\X64��
   Ȼ���ٱ���Win32�汾���ֶ���ACE\ACE_wrappers\lib���ļ����Ƶ�ACE\ACE_wrappers\lib\Win32��
   ��ʹ��ACE�µ��������ļ�CopyACEWin32��CopyACEX64ִ�С�
5. ����release��Win32�汾��x64�汾ʱ����Ҫ��ִ����һ���汾�Ĺ���������

----------------------------
openssl������ͨ����NETWORK_USE_OPENSSL������

1. �汾��1.1.1j��
2. �ٷ���վ��https://www.openssl.org/��
3. ���ز���װ ActivePerl�����ص�ַ��http://www.activestate.com/activeperl/downloads 
4. ��������ʾ������λ�� ($Perl64)\eg Ŀ¼��ִ�� perl example.pl��
   ����ʾ Hello from ActivePerl! ��˵�� Perl ��װ�ɹ���
5. ���ز���װ Nasm �����������($NASM)\Ŀ¼���ӵ�ϵͳ�������� Path �С�
   ���ص�ַ��http://www.nasm.us/ ��
6. ͨ������Ա��������VS������������ʾ������λ�� ($openssl)Ŀ¼
7. ����perl Configure VC-WIN32 --debug --prefix=($openssl)\Win32\Debug������debug�棩��
   perl Configure VC-WIN32 --prefix=($openssl)\Win32\Release������release�汾����    
   ����ִ��󣬿ɺ��ԡ�
8. ����X64��ת��Ŀ¼Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build������vcvars64.bat��
   Ȼ������ perl Configure VC-WIN64A --debug --prefix=($openssl)\X64\Debug������debug�棩��
   perl Configure VC-WIN64A --prefix=($openssl)\X64\Release������release�棩��    
9. �����ĸ��汾����Ҫִ�� nmake clean��������perl��䡣Ȼ��
   ִ�� nmake��nmake test��nmake install��

----------------------------

mysql ������ͨ����DATABASE_USE_MYSQL_C_API������
1.  �汾��8.0.23��
2.  �ٷ���վ��https://www.mysql.com/��
3.  ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4.  Win32�汾����WITHOUT_SERVER��
5.  ������ȷ��BOOST_INCLUDE_DIR��($boost)��
6.  boost.cmake 41�С�303�С�305�С�313�иĳɵ�ǰʹ�õ�boost��汾��
7.  ������ȷ��OPENSSL_ROOT_DIR��($openssl)����Ҫ���Ӷ�Ӧ�汾��openssl�� 
8.  Win32�汾��mysqld.vcxproj�����ļ�x64�ĳ�x86��
9.  sql_locale.cc��test_string_service_charset.cc��sql_commands_help_data.h����ΪANSI���롣
10. �ļ�crc32.cc����storage\innobase\ut�£�
    ��227�п�ʼ�ĳ�
	#if defined(_M_X64)  
		crc_64bit = _mm_crc32_u64(crc_64bit, data);   
	#else // !_M_X64 
		ulint len = 8;  
		const byte* buf = reinterpret_cast<byte*>(&data);
		while (len > 0 && (reinterpret_cast<uintptr_t>(buf) & 7) != 0) {   
			ut_crc32_8_hw(&crc_64bit, &buf, &len); 
		}
	#endif /* defined (_M_X64) */
11. �ļ�tables_contained_in.h����include�£�
    ��67�п�ʼ�ĳ�
    #if defined(_M_X64)  
		_BitScanForward64(&idx, m_bits_left);  
	#else // !_M_X64 
		_BitScanForward(&idx, m_bits_left);
	#endif /* defined (_M_X64) */
11. ��Ŀ¼include\boost_1_V_0�е�V�ĳ�Ŀǰ��boost��汾��
12. ����boost��汾��һ�£����±��벻��ʱ��ʹ��mysqlָ����boost�汾��
	��Ҫ�ɰ汾��boostͷ�ļ����Ƶ�include\boost_1_V_0�£�Ȼ����include\boost_1_V_0ԭ�����ļ����и��ǡ�

----------------------------
mysql connector c++������ͨ����DATABASE_USE_MYSQL_CPP_CONNECTOR������
1. �汾��8.0.23��
2. �ٷ���վ��https://www.mysql.com/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. ������ȷ��WITH_SSL��ԭΪsystem��ָ���Ӧ�汾��($openssl)����������x64�汾����Ҫָ��x64��openssl��

----------------------------  
protobuf������ͨ����NETWORK_USE_PROTOBUF������
1. �汾��3.15.5��
2. �ٷ���վ��https://github.com/protocolbuffers/protobuf��
3. git��ַ��https://github.com/protocolbuffers/protobuf.git��
4. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
freeglut������ͨ����SYSTEM_USE_GLUT������

1. �汾��3.2.1��
2. �ٷ���վ��http://freeglut.sourceforge.net/��
3. git��ַ��https://github.com/dcnieho/FreeGLUT��
4. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
wxWidgets������ͨ����USER_INTERFACE_USE_WX_WIDGETS������

1. �汾��3.1.3��
2. �ٷ���վ��http://www.wxwidgets.org/��

----------------------------
opencv������ͨ����IMAGICS_USE_OPENCV������

1. �汾��4.3.0��
2. �ٷ���վ��https://opencv.org/
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
Visual Leak Detector������Debug�汾ֱ�ӹ�����

1. �汾��2.7.0��
2. git��ַ��https://github.com/oneiric/vld��
3. Allocs.cpp��39�У�testsuite.cpp��78������ 
   #elif _MSC_VER > 1927	// VS 2019
   #define CRTDLLNAME   _T("ucrtbased.dll")
4. Allocs.cpp��67�У�testsuite.cpp��105������ 
   #elif _MSC_VER > 1927	// VS 2019
   #define CRTDLLNAME   _T("ucrtbase.dll") 
5. src\tests��Common.props��18�иĳ�v142��

----------------------------
OpenAL Soft������ͨ����SOUND_EFFECT_USE_OPENAL������

1. �汾��1.20.1��
2. �ٷ���վ��https://www.openal-soft.org/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
zlib������ֱ�ӹ�����

1. �汾��1.2.11��
2. �ٷ���վ��http://www.zlib.net/
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
freetype������ֱ�ӹ�����

1. �汾��2.10.2��
2. �ٷ���վ��https://www.freetype.org/
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
lua������ͨ����SCRIPT_USE_LUA������

1. �汾��5.4.0��
2. �ٷ���վ��http://www.lua.org/
3. ��build�½���VS���̣�lua����̬�⡣���������ļ���lapi.c lcode.c lctype.c ldebug.c ldo.c ldump.c 
   lfunc.c lgc.c llex.c lmem.c lobject.c lopcodes.c lparser.c lstate.c lstring.c ltable.c ltm.c 
   lundump.c lvm.c lzio.c lauxlib.c lbaselib.c lbitlib.c lcorolib.c ldblib.c liolib.c lmathlib.c 
   loslib.c lstrlib.c ltablib.c lutf8lib.c loadlib.c linit.c������ȥluac.c��lua.c�������ļ�����
   ���Ŀ¼�ĳɣ�$(SolutionDir)$(Platform)\$(Configuration)\��
4. ����VS���̣�����interpreter������lua.c����compiler������luac.c����
   ���Ŀ¼�ĳɣ�$(SolutionDir)$(Platform)\$(Configuration)\��
   ���Ӹ��ӿ�Ŀ¼��$(SolutionDir)$(Platform)\$(Configuration)\���������������ӣ�lua.lib��

----------------------------  
OpenXLSX ������ͨ����CORE_TOOLS_USE_OPENXLSX������

1. �ٷ���վ��https://github.com/troldal/OpenXLSX��
2. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
3. ִ��OpenXLSX�µ��������ļ���

----------------------------
pugixml������ֱ�ӹ�����

1. �汾��1.11.4��
2. �ٷ���վ��https://github.com/zeux/pugixml��
3. pugiconfig.hpp��47�У������PUGIXML_HEADER_ONLY��

----------------------------

miniz������ֱ�ӹ�����

1. �汾��2.2.0��
2. �ٷ���վ��https://github.com/richgel999/miniz��
3. ʹ��releases pageҳ�İ汾���뾲̬�⣬��Ϊminiz��

----------------------------
perl������ͨ����SCRIPT_USE_PERL������

1. �汾��5.32.0��
2. �ٷ���վ��https://www.perl.org/
3. �޸�win32�µ�Makefile�ļ���134��ȥ��ע�͡�
4. �޸�win32�µ�Makefile�ļ���23�е�INST_DRV���ó�($perl)��
5. ����VS������������ʾ������λ�� ($perl)/Win32Ŀ¼
6. ����Win32��debug�棬�޸�win32�µ�Makefile�ļ���30�С�163��ȥ��ע�ͣ�24�����ó�$(INST_DRV)\BuildWin32\Debug��
7. ����Win32��release�棬�޸�win32�µ�Makefile�ļ���30��ȥ��ע�ͣ�163��ע�ͣ�24�����ó�$(INST_DRV)\BuildWin32\Release��
8. ����X64��ת��Ŀ¼Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build������vcvars64.bat��
9. ����X64��debug�棬�޸�win32�µ�Makefile�ļ���163��ȥ��ע�ͣ�30��ע�ͣ�24�����ó�$(INST_DRV)\BuildX64\Debug��
10.����X64��release�棬�޸�win32�µ�Makefile�ļ���30�С�163��ע�ͣ�24�����ó�$(INST_DRV)\BuildX64\Release��
11.��Win32Ŀ¼�㼶��ִ������nmake��
12.�����ĸ��汾����Ҫִ��nmake clean��Ȼ����ִ��nmake��nmake install��
13.����Win32��X64�汾����Ҫ����ʹ��ԭ���perl���롣

----------------------------
Pantheios������ͨ����CORE_TOOLS_USE_PANTHEIOS������

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
Openrj������ͨ����CORE_TOOLS_USE_OPENRJ������

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
ogg������ͨ����SOUND_EFFECT_USE_OGG������

1. �汾��1.3.4��
2. �ٷ���վ��https://www.xiph.org/downloads/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
vorbis������ͨ����SOUND_EFFECT_USE_VORBIS������

1. �汾��1.3.7��
2. �ٷ���վ��https://www.xiph.org/downloads/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. ������ȷ��OGG_INCLUDE_DIR��($ogg)/include�� 
5. ������ȷ��OGG_LIBRARY��($ogg)/BuildX64/Release/ogg.lib��($ogg)/BuildWin32/Release/ogg.lib��  

----------------------------
FLTK������ͨ����USER_INTERFACE_USE_FLTK������

1. �汾��1.3.5
2. �ٷ���վ��https://www.fltk.org/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. �ļ�Fl_Device.cxx��
   ��84�иĳ�
   static
   #if defined(__APPLE__)
		Fl_Quartz_Graphics_Driver
   #elif defined(WIN32)
		Fl_GDI_Graphics_Driver
   #else
		Fl_Xlib_Graphics_Driver
   #endif
		driver;
   static Fl_Display_Device display(&driver);
   return &display;
   �������ȴ�й¶�� 
 
----------------------------
chipmunk2D physics������ͨ����PHYSICS_USE_CHIPMUNK2D������

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