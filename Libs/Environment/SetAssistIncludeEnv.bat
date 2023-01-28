@echo on

echo DXSDK_DIR = %DXSDK_DIR%
echo %cd%
setx DXSDK_DIR "%cd%\..\Microsoft DirectX SDK (June 2010)" 

echo ZThreadInclude = %ZThreadInclude%
echo  %cd%
setx  ZThreadInclude "%cd%\..\ZThread\include"

echo OgreInclude = %OgreInclude%
echo  %cd%
setx  OgreInclude "%cd%\..\ogre\OgreMain\include" 

echo OgreBuildInclude = %OgreBuildInclude%
echo  %cd%
setx  OgreBuildInclude "%cd%\..\ogre\BuildX64\include"  

echo OgreALInclude = %OgreALInclude%
echo  %cd%
setx  OgreALInclude "%cd%\..\OgreAL\include" 

echo OisInclude = %OisInclude%
echo  %cd%
setx  OisInclude "%cd%\..\ois\includes" 

echo FreealutInclude = %FreealutInclude%
echo  %cd%
setx  FreealutInclude "%cd%\..\freealut\include" 

echo OggInclude = %OggInclude%
echo  %cd%
setx  OggInclude "%cd%\..\libogg\include" 

echo BvorbisInclude = %BvorbisInclude%
echo  %cd%
setx  BvorbisInclude "%cd%\..\libvorbis\include" 

echo FltkInclude = %FltkInclude%
echo  %cd%
setx  FltkInclude "%cd%\..\fltk" 

echo FltkBuildInclude = %FltkBuildInclude%
echo  %cd%
setx  FltkBuildInclude "%cd%\..\fltk\BuildX64" 

echo WxWidgetsInclude = %WxWidgetsInclude%
echo  %cd%
setx  WxWidgetsInclude "%cd%\..\wxWidgets\include"

echo WxWidgetsMsvcInclude = %WxWidgetsMsvcInclude%
echo  %cd%
setx  WxWidgetsMsvcInclude "%cd%\..\wxWidgets\include\msvc"

echo DirectXInclude = %DirectXInclude%
echo %cd%
setx DirectXInclude "%cd%\..\Microsoft DirectX SDK (June 2010)" 

echo GoogleTestInclude = %GoogleTestInclude%
echo %cd%
setx GoogleTestInclude "%cd%\..\googletest\googletest\include" 

echo CppunitInclude = %CppunitInclude%
echo %cd%
setx CppunitInclude "%cd%\..\cppunit\include\cppunit" 

pause