@echo on

echo GSLInclude = %GSLInclude%
echo  %cd%
setx  GSLInclude "%cd%\..\GSL\include" 

echo BoostInclude = %BoostInclude%
echo  %cd%
setx  BoostInclude "%cd%\..\boost"

echo StlSoftInclude = %StlSoftInclude%
echo  %cd%
setx  StlSoftInclude "%cd%\..\stlsoft\include"

echo ACEInclude = %ACEInclude%
echo  %cd%
setx  ACEInclude "%cd%\..\ACE\ACE_wrappers"

echo OpenSSLInclude = %OpenSSLInclude%
echo  %cd%
setx  OpenSSLInclude "%cd%\..\openssl\X64\release\include"

echo MysqlInclude = %MysqlInclude%
echo  %cd%
setx  MysqlInclude "%cd%\..\mysql\include"

echo MysqlConnectorInclude = %MysqlConnectorInclude%
echo  %cd%
setx  MysqlConnectorInclude "%cd%\..\mysql-connector-c++\include"

echo MysqlConnectorMqsqlxInclude = %MysqlConnectorMqsqlxInclude%
echo  %cd%
setx  MysqlConnectorMqsqlxInclude "%cd%\..\mysql-connector-c++\BuildX64\include\mysqlx"

echo FreeglutInclude = %FreeglutInclude%
echo  %cd%
setx  FreeglutInclude "%cd%\..\FreeGLUT\include"

echo VisualLeakDetectorInclude = %VisualLeakDetectorInclude%
echo  %cd%
setx  VisualLeakDetectorInclude "%cd%\..\vld\src"

echo OpenALSoftInclude = %OpenALSoftInclude%
echo  %cd%
setx  OpenALSoftInclude "%cd%\..\openal-soft\include"

echo ZlibInclude = %ZlibInclude%
echo  %cd%
setx  ZlibInclude "%cd%\..\zlib"

echo FreetypeInclude = %FreetypeInclude%
echo  %cd%
setx  FreetypeInclude "%cd%\..\freetype\include"

echo LuaInclude = %LuaInclude%
echo  %cd%
setx  LuaInclude "%cd%\..\lua\src"

echo OpenglInclude = %OpenglInclude%
echo  %cd%
setx  OpenglInclude "%cd%\..\OpenGL-Registry\api"

echo OpengEGLlInclude = %OpengEGLlInclude%
echo  %cd%
setx  OpengEGLlInclude "%cd%\..\EGL-Registry\api"

echo OpenXLSXInclude = %OpenXLSXInclude%
echo  %cd%
setx  OpenXLSXInclude "%cd%\..\OpenXLSX\OpenXLSX" 

echo PugiXmlInclude = %PugiXmlInclude%
echo  %cd%
setx  PugiXmlInclude "%cd%\..\pugixml\src"  

echo MinizInclude = %MinizInclude%
echo  %cd%
setx  MinizInclude "%cd%\..\miniz"  

echo ProtobufInclude = %ProtobufInclude%
echo  %cd%
setx  ProtobufInclude "%cd%\..\protobuf\src"  

echo AbseilInclude = %AbseilInclude%
echo  %cd%
setx  AbseilInclude "%cd%\..\protobuf\third_party\abseil-cpp"  

echo ActiveMQInclude = %ActiveMQInclude%
echo  %cd%
setx  ActiveMQInclude "%cd%\..\activemq\src\main"  

echo LibsEnvironmentInclude = %LibsEnvironmentInclude%
echo %cd%
setx LibsEnvironmentInclude "%GSLInclude%;%BoostInclude%;%StlSoftInclude%;%ACEInclude%;%MysqlInclude%;%MysqlConnectorInclude%;%MysqlConnectorMqsqlxInclude%;%FreeglutInclude%;%VisualLeakDetectorInclude%;%OpenSSLInclude%;%OpenALSoftInclude%;%ZlibInclude%;%FreetypeInclude%;%LuaInclude%;%OpenglInclude%;%OpengEGLlInclude%;%OpenXLSXInclude%;%PugiXmlInclude%;%MinizInclude%;%ProtobufInclude%;%AbseilInclude%;%ActiveMQInclude%;" 

pause