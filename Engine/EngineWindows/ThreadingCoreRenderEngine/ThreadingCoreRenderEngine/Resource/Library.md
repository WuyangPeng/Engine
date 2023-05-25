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

1. �汾��1.82.0��
2. �ٷ���վ��http://www.boost.org/��
3. ����ָ�
  ��1������bootstrap��
  ��2������b2�����°汾��
		   b2 --toolset=msvc-14.2���ض��汾��           	
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

1. �汾��7.1.0��
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

----------------------------
openssl������ͨ����NETWORK_USE_OPENSSL������

1. �汾��3.0.5��
2. �ٷ���վ��https://www.openssl.org/��
3. ���ز���װ ActivePerl�����ص�ַ��http://www.activestate.com/activeperl/downloads 
4. ��������ʾ������λ�� ($Perl64)\eg Ŀ¼��ִ�� perl example.pl��
   ����ʾ Hello from ActivePerl! ��˵�� Perl ��װ�ɹ���
5. ���ز���װ Nasm �����������($NASM)\Ŀ¼��ӵ�ϵͳ�������� Path �С�
   ���ص�ַ��http://www.nasm.us/ ��
6. ͨ������Ա�������VS������������ʾ������λ�� ($openssl)Ŀ¼
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
1.  �汾��8.0.33��
2.  �ٷ���վ��https://www.mysql.com/��
3.  ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4.  ����WITHOUT_SERVER��
5.  ������ȷ��BOOST_INCLUDE_DIR��($boost)��
6.  boost.cmake 41�С�304�С�306�С�314�иĳɵ�ǰʹ�õ�boost��汾��
7.  ������ȷ��OPENSSL_ROOT_DIR��($openssl)����Ҫ���Ӷ�Ӧ�汾��openssl��

�����Ҫ�������������������Ҫ������޸ģ�û�ж���WITHOUT_SERVER��Win32�汾���ٱ�֧�֣��� 
1.  my_alloc.h��strings_strnxfrm-t.cc��strings_valid_check-t.cc��strings_utf8-t.cc��
	sql_locale.cc��test_string_service_charset.cc��sql_commands_help_data.h��mem_root_deque.h���ΪANSI���롣
2.  �ļ�crc32.cc����storage\innobase\ut�£�
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
3.  �ļ�tables_contained_in.h����include�£�
    ��67�п�ʼ�ĳ�
    #if defined(_M_X64)  
		_BitScanForward64(&idx, m_bits_left);  
	#else // !_M_X64 
		_BitScanForward(&idx, m_bits_left);
	#endif /* defined (_M_X64) */
4.  ��Ŀ¼include\boost_1_V_0�е�V�ĳ�Ŀǰ��boost��汾��
5.  ����boost��汾��һ�£����±��벻��ʱ��ʹ��mysqlָ����boost�汾��
	��Ҫ�ɰ汾��boostͷ�ļ����Ƶ�include\boost_1_V_0�£�Ȼ����include\boost_1_V_0ԭ�����ļ����и��ǡ�

----------------------------
mysql connector c++������ͨ����DATABASE_USE_MYSQL_CPP_CONNECTOR������
1. �汾��8.0.33��
2. �ٷ���վ��https://www.mysql.com/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. ������ȷ��WITH_SSL��ԭΪsystem��ָ���Ӧ�汾��($openssl)����������x64�汾����Ҫָ��x64��openssl��
5. WIN32�汾����޷����룬ʹ��CMake�����������¹��̣�
   $(MysqlConnectorCpp)\cdk\extra\zlib������Ŀ¼��$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\zlib
   $(MysqlConnectorCpp)\cdk\extra\zstd ����Ŀ¼��$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\zstd
   $(MysqlConnectorCpp)\cdk\extra\lz4 ����Ŀ¼��$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\lz4
   $(MysqlConnectorCpp)\cdk\extra\protobuf ����Ŀ¼��$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\protobuf
   
----------------------------  
protobuf������ͨ����NETWORK_USE_PROTOBUF������
1. �汾��21.12��
2. �ٷ���վ��https://github.com/protocolbuffers/protobuf��
3. git��ַ��https://github.com/protocolbuffers/protobuf.git��
4. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
5. port_def.incβ������
   #include "System/Helper/PragmaWarning/ProtoBuf.h"

----------------------------
freeglut������ͨ����SYSTEM_USE_GLUT������

1. �汾��3.2.2��
2. �ٷ���վ��http://freeglut.sourceforge.net/��
3. git��ַ��https://github.com/dcnieho/FreeGLUT��
4. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
wxWidgets������ͨ����USER_INTERFACE_USE_WX_WIDGETS������

1. �汾��3.2.0��
2. �ٷ���վ��http://www.wxwidgets.org/��

----------------------------
opencv������ͨ����IMAGICS_USE_OPENCV������

1. �汾��4.6.0��
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

1. �汾��1.22.2��
2. �ٷ���վ��https://www.openal-soft.org/��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
zlib������ֱ�ӹ�����

1. �汾��1.2.12��
2. �ٷ���վ��http://www.zlib.net/
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
freetype������ֱ�ӹ�����

1. �汾��2.12.1��
2. �ٷ���վ��https://www.freetype.org/
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------
lua������ͨ����SCRIPT_USE_LUA������

1. �汾��5.4.4��
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

1. �汾��0.4.1��
2. �ٷ���վ��https://github.com/troldal/OpenXLSX��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. OPENXLSX_LIBRARY_TYPEֵ�޸ĳ�SHARED��

----------------------------
pugixml������ֱ�ӹ�����

1. �汾��1.12.1��
2. �ٷ���վ��https://github.com/zeux/pugixml��
3. pugiconfig.hpp��47�У������PUGIXML_HEADER_ONLY��

----------------------------
miniz������ֱ�ӹ�����

1. �汾��2.2.0��
2. �ٷ���վ��https://github.com/richgel999/miniz��
3. ʹ��releases pageҳ�İ汾���뾲̬�⣬��Ϊminiz��

----------------------------
ogg������ͨ����SOUND_EFFECT_USE_OGG������

1. �汾��1.3.5��
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

1. �汾��1.3.8
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
Apr������ͨ����NETWORK_USE_ACTIVE_MQ������

1. �ٷ���վ��https://github.com/apache/apr ��
2. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------

ActiveMQ������ͨ����NETWORK_USE_ACTIVE_MQ������

1. �汾��5.18.1
2. �ٷ���վ��https://activemq.apache.org/components/cms/download/ ��

----------------------------

Mongo-c-driver��Mongo-cxx-driver������

1. �汾��1.23.4
2. �ٷ���վ��https://github.com/mongodb/mongo-c-driver ��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. �����x64�汾��ִ��Release�汾��INSTALL���ֶ���C:/Program Files (x86)/mongo-c-driver���ļ����Ƶ�mongo-cxx-driver/BuildX64/mongo-c-driver�£�
   Ȼ���ٱ���Win32�汾��ִ��Release�汾��INSTALL���ֶ���C:/Program Files (x86)/mongo-c-driver���ļ����Ƶ�mongo-cxx-driver/BuildWin32/mongo-c-driver�£�
   ��ʹ��Mongo�µ��������ļ�CopyMongoWin32��CopyMongoX64ִ�С�
   
----------------------------

Mongo-cxx-driver������ͨ����DATABASE_USE_MONGO������

1. �汾��3.7.1
2. �ٷ���վ��https://github.com/mongodb/mongo-cxx-driver ��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�
4. ����libbson-1.0_DIR��mongo-c-driver��BuildX64\src\libbson��
5. ����BSON_LIBRARY��mongo-cxx-driver��BuildX64\mongo-c-driver\lib\bson-1.0.lib��
6. ������ȷ��Boost_INCLUDE_DIR��
7. ����libmongoc-1.0_DIR��mongo-c-driver��BuildX64\src\libmongoc��
8. ����MONGOC_LIBRARY��mongo-cxx-driver��BuildX64\mongo-c-driver\lib\mongoc-1.0.lib��

----------------------------

hiredis������ͨ����DATABASE_USE_REDIS������

1. �汾��1.1.0
2. �ٷ���վ��https://github.com/redis/hiredis ��
3. ���뷽ʽ��CMake��Win32�汾������BuildWin32�£�x64�汾������BuildX64�¡�

----------------------------