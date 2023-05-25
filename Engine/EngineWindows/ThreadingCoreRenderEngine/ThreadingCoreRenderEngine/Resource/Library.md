@ingroup group_Engine_Documentation

----------------------------
库

----------------------------
GSL（引擎直接关联）

1. 官方网站：https://github.com/microsoft/GSL。
2. git地址：https://github.com/microsoft/GSL.git。

----------------------------
CppCoreGuidelines（引擎直接关联）

1. 官方网站：https://github.com/isocpp/CppCoreGuidelines。
2. git地址：https://github.com/isocpp/CppCoreGuidelines.git。

----------------------------
OpenGL（引擎直接关联）

1. 版本：4.6。
2. 官方网站：http://www.opengl.org/registry/。
3. git地址：https://github.com/KhronosGroup/OpenGL-Registry.git。

----------------------------
EGL（引擎直接关联）

1. 版本：1.5。
2. 官方网站：https://www.khronos.org/registry/EGL/。
3. git地址：https://github.com/KhronosGroup/EGL-Registry.git。

----------------------------
boost（引擎直接关联）

1. 版本：1.82.0。
2. 官方网站：http://www.boost.org/。
3. 编译指令：
  （1）运行bootstrap。
  （2）运行b2（最新版本）
		   b2 --toolset=msvc-14.2（特定版本）           	
  （3）由于链接context库需要，使用选项asmflags=\safeseh。

----------------------------
stlsoft（引擎直接关联）

1. 版本：1.10.1-beta33。
2. git地址：https://github.com/synesissoftware/STLSoft-1.10
3. 在stlsoft.h第778行增加
	# elif (_MSC_VER < 2000)
	#   define STLSOFT_COMPILER_VERSION_STRING      "Visual C++ 16.x"

----------------------------
ACE（引擎通过宏NETWORK_USE_ACE关联）

1. 版本：7.1.0。
2. 官方网站：http://download.dre.vanderbilt.edu/、 http://www.dre.vanderbilt.edu/~schmidt/ACE.html。
3. 在ace目录下增加文件config.h包含正确的config文件。
   #ifndef ACE_CONFIG_H
   #define ACE_CONFIG_H

       #include "config-win32.h"

   #endif /* ACE_CONFIG_H */
   可使用ACE下的批处理文件CopyACEConfig执行。
4. 编译好x64版本后，手动将ACE\ACE_wrappers\lib下文件复制到ACE\ACE_wrappers\lib\X64，
   然后再编译Win32版本，手动将ACE\ACE_wrappers\lib下文件复制到ACE\ACE_wrappers\lib\Win32。
   可使用ACE下的批处理文件CopyACEWin32和CopyACEX64执行。

----------------------------
openssl（引擎通过宏NETWORK_USE_OPENSSL关联）

1. 版本：3.0.5。
2. 官方网站：https://www.openssl.org/。
3. 下载并安装 ActivePerl。下载地址：http://www.activestate.com/activeperl/downloads 
4. 打开命令提示符，定位到 ($Perl64)\eg 目录，执行 perl example.pl，
   若提示 Hello from ActivePerl! 则说明 Perl 安装成功。
5. 下载并安装 Nasm 汇编器，并将($NASM)\目录添加到系统环境变量 Path 中。
   下载地址：http://www.nasm.us/ 。
6. 通过管理员身份运行VS，并打开命令提示符，定位至 ($openssl)目录
7. 输入perl Configure VC-WIN32 --debug --prefix=($openssl)\Win32\Debug（编译debug版），
   perl Configure VC-WIN32 --prefix=($openssl)\Win32\Release（编译release版本），    
   会出现错误，可忽略。
8. 编译X64，转到目录Microsoft Visual Studio\2019\Enterprise\VC\Auxiliary\Build下运行vcvars64.bat，
   然后输入 perl Configure VC-WIN64A --debug --prefix=($openssl)\X64\Debug（编译debug版）。
   perl Configure VC-WIN64A --prefix=($openssl)\X64\Release（编译release版）。    
9. 编译四个版本中需要执行 nmake clean，再输入perl语句。然后
   执行 nmake、nmake test、nmake install。

----------------------------

mysql （引擎通过宏DATABASE_USE_MYSQL_C_API关联）
1.  版本：8.0.33。
2.  官方网站：https://www.mysql.com/。
3.  编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4.  定义WITHOUT_SERVER。
5.  定义正确的BOOST_INCLUDE_DIR到($boost)。
6.  boost.cmake 41行、304行、306行、314行改成当前使用的boost库版本。
7.  定义正确的OPENSSL_ROOT_DIR到($openssl)，需要链接对应版本的openssl。

如果需要编译服务器，还可能需要下面的修改（没有定义WITHOUT_SERVER，Win32版本不再被支持）： 
1.  my_alloc.h、strings_strnxfrm-t.cc、strings_valid_check-t.cc、strings_utf8-t.cc、
	sql_locale.cc、test_string_service_charset.cc、sql_commands_help_data.h、mem_root_deque.h另存为ANSI编码。
2.  文件crc32.cc（在storage\innobase\ut下）
    第227行开始改成
	#if defined(_M_X64)  
		crc_64bit = _mm_crc32_u64(crc_64bit, data);   
	#else // !_M_X64 
		ulint len = 8;  
		const byte* buf = reinterpret_cast<byte*>(&data);
		while (len > 0 && (reinterpret_cast<uintptr_t>(buf) & 7) != 0) {   
			ut_crc32_8_hw(&crc_64bit, &buf, &len); 
		}
	#endif /* defined (_M_X64) */
3.  文件tables_contained_in.h（在include下）
    第67行开始改成
    #if defined(_M_X64)  
		_BitScanForward64(&idx, m_bits_left);  
	#else // !_M_X64 
		_BitScanForward(&idx, m_bits_left);
	#endif /* defined (_M_X64) */
4.  将目录include\boost_1_V_0中的V改成目前的boost库版本。
5.  由于boost库版本不一致，导致编译不过时，使用mysql指定的boost版本，
	需要旧版本的boost头文件复制到include\boost_1_V_0下，然后用include\boost_1_V_0原来的文件进行覆盖。

----------------------------
mysql connector c++（引擎通过宏DATABASE_USE_MYSQL_CPP_CONNECTOR关联）
1. 版本：8.0.33。
2. 官方网站：https://www.mysql.com/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. 设置正确的WITH_SSL（原为system）指向对应版本的($openssl)，如编译的是x64版本，需要指向x64的openssl。
5. WIN32版本如果无法编译，使用CMake重新生成以下工程：
   $(MysqlConnectorCpp)\cdk\extra\zlib，生成目录：$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\zlib
   $(MysqlConnectorCpp)\cdk\extra\zstd 生成目录：$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\zstd
   $(MysqlConnectorCpp)\cdk\extra\lz4 生成目录：$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\lz4
   $(MysqlConnectorCpp)\cdk\extra\protobuf 生成目录：$(MysqlConnectorCpp)\BuildWin32\cdk\protocol\mysqlx\protobuf
   
----------------------------  
protobuf（引擎通过宏NETWORK_USE_PROTOBUF关联）
1. 版本：21.12。
2. 官方网站：https://github.com/protocolbuffers/protobuf。
3. git地址：https://github.com/protocolbuffers/protobuf.git。
4. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
5. port_def.inc尾部增加
   #include "System/Helper/PragmaWarning/ProtoBuf.h"

----------------------------
freeglut（引擎通过宏SYSTEM_USE_GLUT关联）

1. 版本：3.2.2。
2. 官方网站：http://freeglut.sourceforge.net/。
3. git地址：https://github.com/dcnieho/FreeGLUT。
4. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
wxWidgets（引擎通过宏USER_INTERFACE_USE_WX_WIDGETS关联）

1. 版本：3.2.0。
2. 官方网站：http://www.wxwidgets.org/。

----------------------------
opencv（引擎通过宏IMAGICS_USE_OPENCV关联）

1. 版本：4.6.0。
2. 官方网站：https://opencv.org/
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
Visual Leak Detector（引擎Debug版本直接关联）

1. 版本：2.7.0。
2. git地址：https://github.com/oneiric/vld。
3. Allocs.cpp第39行，testsuite.cpp第78行增加 
   #elif _MSC_VER > 1927	// VS 2019
   #define CRTDLLNAME   _T("ucrtbased.dll")
4. Allocs.cpp第67行，testsuite.cpp第105行增加 
   #elif _MSC_VER > 1927	// VS 2019
   #define CRTDLLNAME   _T("ucrtbase.dll") 
5. src\tests下Common.props第18行改成v142。

----------------------------
OpenAL Soft（引擎通过宏SOUND_EFFECT_USE_OPENAL关联）

1. 版本：1.22.2。
2. 官方网站：https://www.openal-soft.org/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
zlib（引擎直接关联）

1. 版本：1.2.12。
2. 官方网站：http://www.zlib.net/
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
freetype（引擎直接关联）

1. 版本：2.12.1。
2. 官方网站：https://www.freetype.org/
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
lua（引擎通过宏SCRIPT_USE_LUA关联）

1. 版本：5.4.4。
2. 官方网站：http://www.lua.org/
3. 在build下建立VS工程，lua，静态库。包含以下文件：lapi.c lcode.c lctype.c ldebug.c ldo.c ldump.c 
   lfunc.c lgc.c llex.c lmem.c lobject.c lopcodes.c lparser.c lstate.c lstring.c ltable.c ltm.c 
   lundump.c lvm.c lzio.c lauxlib.c lbaselib.c lbitlib.c lcorolib.c ldblib.c liolib.c lmathlib.c 
   loslib.c lstrlib.c ltablib.c lutf8lib.c loadlib.c linit.c。（除去luac.c和lua.c的所有文件）。
   输出目录改成：$(SolutionDir)$(Platform)\$(Configuration)\。
4. 建立VS工程，程序interpreter（包含lua.c）和compiler（包含luac.c）。
   输出目录改成：$(SolutionDir)$(Platform)\$(Configuration)\。
   增加附加库目录：$(SolutionDir)$(Platform)\$(Configuration)\。附加依赖项增加：lua.lib。

----------------------------  
OpenXLSX （引擎通过宏CORE_TOOLS_USE_OPENXLSX关联）

1. 版本：0.4.1。
2. 官方网站：https://github.com/troldal/OpenXLSX。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. OPENXLSX_LIBRARY_TYPE值修改成SHARED。

----------------------------
pugixml（引擎直接关联）

1. 版本：1.12.1。
2. 官方网站：https://github.com/zeux/pugixml。
3. pugiconfig.hpp第47行，定义宏PUGIXML_HEADER_ONLY。

----------------------------
miniz（引擎直接关联）

1. 版本：2.2.0。
2. 官方网站：https://github.com/richgel999/miniz。
3. 使用releases page页的版本编译静态库，名为miniz。

----------------------------
ogg（引擎通过宏SOUND_EFFECT_USE_OGG关联）

1. 版本：1.3.5。
2. 官方网站：https://www.xiph.org/downloads/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------
vorbis（引擎通过宏SOUND_EFFECT_USE_VORBIS关联）

1. 版本：1.3.7。
2. 官方网站：https://www.xiph.org/downloads/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. 定义正确的OGG_INCLUDE_DIR到($ogg)/include。 
5. 定义正确的OGG_LIBRARY到($ogg)/BuildX64/Release/ogg.lib和($ogg)/BuildWin32/Release/ogg.lib。  

----------------------------
FLTK（引擎通过宏USER_INTERFACE_USE_FLTK关联）

1. 版本：1.3.8
2. 官方网站：https://www.fltk.org/。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. 文件Fl_Device.cxx：
   第84行改成
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
   以消除內存泄露。 
 
----------------------------
Apr（引擎通过宏NETWORK_USE_ACTIVE_MQ关联）

1. 官方网站：https://github.com/apache/apr 。
2. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------

ActiveMQ（引擎通过宏NETWORK_USE_ACTIVE_MQ关联）

1. 版本：5.18.1
2. 官方网站：https://activemq.apache.org/components/cms/download/ 。

----------------------------

Mongo-c-driver（Mongo-cxx-driver关联）

1. 版本：1.23.4
2. 官方网站：https://github.com/mongodb/mongo-c-driver 。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. 编译好x64版本后，执行Release版本的INSTALL。手动将C:/Program Files (x86)/mongo-c-driver下文件复制到mongo-cxx-driver/BuildX64/mongo-c-driver下，
   然后再编译Win32版本，执行Release版本的INSTALL。手动将C:/Program Files (x86)/mongo-c-driver下文件复制到mongo-cxx-driver/BuildWin32/mongo-c-driver下，
   可使用Mongo下的批处理文件CopyMongoWin32和CopyMongoX64执行。
   
----------------------------

Mongo-cxx-driver（引擎通过宏DATABASE_USE_MONGO关联）

1. 版本：3.7.1
2. 官方网站：https://github.com/mongodb/mongo-cxx-driver 。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。
4. 设置libbson-1.0_DIR到mongo-c-driver下BuildX64\src\libbson。
5. 设置BSON_LIBRARY到mongo-cxx-driver下BuildX64\mongo-c-driver\lib\bson-1.0.lib。
6. 设置正确的Boost_INCLUDE_DIR。
7. 设置libmongoc-1.0_DIR到mongo-c-driver下BuildX64\src\libmongoc。
8. 设置MONGOC_LIBRARY到mongo-cxx-driver下BuildX64\mongo-c-driver\lib\mongoc-1.0.lib。

----------------------------

hiredis（引擎通过宏DATABASE_USE_REDIS关联）

1. 版本：1.1.0
2. 官方网站：https://github.com/redis/hiredis 。
3. 编译方式：CMake。Win32版本建立在BuildWin32下，x64版本建立在BuildX64下。

----------------------------