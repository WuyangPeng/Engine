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

echo FreeglutInclude = %FreeglutInclude%
echo  %cd%
setx  FreeglutInclude "%cd%\..\freeglut\include"

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
setx  OpenXLSXInclude "%cd%\..\OpenXLSX\library" 

echo PugiXmlInclude = %PugiXmlInclude%
echo  %cd%
setx  PugiXmlInclude "%cd%\..\pugixml\src"  

echo MinizInclude = %MinizInclude%
echo  %cd%
setx  MinizInclude "%cd%\..\miniz"  

echo LibsEnvironmentInclude = %LibsEnvironmentInclude%
echo %cd%
setx LibsEnvironmentInclude "%GSLInclude%;%BoostInclude%;%StlSoftInclude%;%ACEInclude%;%MysqlInclude%;%MysqlConnectorInclude%;%FreeglutInclude%;%VisualLeakDetectorInclude%;%OpenSSLInclude%;%OpenALSoftInclude%;%ZlibInclude%;%FreetypeInclude%;%LuaInclude%;%OpenglInclude%;%OpengEGLlInclude%;%OpenXLSXInclude%;%PugiXmlInclude%;%MinizInclude%" 

pause