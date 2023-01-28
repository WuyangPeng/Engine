@echo on
 
echo ZThreadWin32DebugLib = %ZThreadWin32DebugLib%
echo  %cd%
setx  ZThreadWin32DebugLib "%cd%\..\ZThread\build\MicrosoftZThread\Win32\Debug" 
 
echo ZThreadWin32ReleaseLib = %ZThreadWin32ReleaseLib%
echo  %cd%
setx  ZThreadWin32ReleaseLib "%cd%\..\ZThread\build\MicrosoftZThread\Win32\Release" 

echo ZThreadX64DebugLib = %ZThreadX64DebugLib%
echo  %cd%
setx  ZThreadX64DebugLib "%cd%\..\ZThread\build\MicrosoftZThread\x64\Debug" 

echo ZThreadX64ReleaseLib = %ZThreadX64ReleaseLib%
echo  %cd%
setx  ZThreadX64ReleaseLib "%cd%\..\ZThread\build\MicrosoftZThread\x64\Release" 

echo OgreWin32DebugLib = %OgreWin32DebugLib%
echo  %cd%
setx  OgreWin32DebugLib "%cd%\..\ogre\BuildWin32\lib\debug" 

echo OgreWin32ReleaseLib = %OgreWin32ReleaseLib%
echo  %cd%
setx  OgreWin32ReleaseLib "%cd%\..\ogre\BuildWin32\lib\Release" 

echo OgreX64DebugLib = %OgreX64DebugLib%
echo  %cd%
setx  OgreX64DebugLib "%cd%\..\ogre\BuildX64\lib\debug" 

echo OgreX64ReleaseLib = %OgreX64ReleaseLib%
echo  %cd%
setx  OgreX64ReleaseLib "%cd%\..\ogre\BuildX64\lib\Release" 

echo OgreALWin32DebugLib = %OgreALWin32DebugLib%
echo  %cd%
setx  OgreALWin32DebugLib "%cd%\..\OgreAL\lib\debug" 

echo OgreALWin32ReleaseLib = %OgreALWin32ReleaseLib%
echo  %cd%
setx  OgreALWin32ReleaseLib "%cd%\..\OgreAL\lib\Release" 

echo OgreALX64DebugLib = %OgreALX64DebugLib%
echo  %cd%
setx  OgreALX64DebugLib "%cd%\..\OgreAL\x64\debug" 

echo  OgreALX64ReleaseLib = %OgreALX64ReleaseLib%
echo  %cd%
setx  OgreALX64ReleaseLib "%cd%\..\OgreAL\x64\Release" 

echo OisWin32DebugLib = %OisWin32DebugLib%
echo  %cd%
setx  OisWin32DebugLib "%cd%\..\ois\lib" 

echo OisWin32ReleaseLib = %OisWin32ReleaseLib%
echo  %cd%
setx  OisWin32ReleaseLib "%cd%\..\ois\lib" 

echo OisX64DebugLib = %OisX64DebugLib%
echo  %cd%
setx  OisX64DebugLib "%cd%\..\ois\lib64" 

echo  OisX64ReleaseLib = %OisX64ReleaseLib%
echo  %cd%
setx  OisX64ReleaseLib "%cd%\..\ois\lib64" 

echo FltkWin32DebugLib = %FltkWin32DebugLib%
echo  %cd%
setx  FltkWin32DebugLib "%cd%\..\fltk\BuildWin32\lib\Debug" 

echo FltkWin32ReleaseLib = %FltkWin32ReleaseLib%
echo  %cd%
setx  FltkWin32ReleaseLib "%cd%\..\fltk\BuildWin32\lib\Release" 

echo FltkX64DebugLib = %FltkX64DebugLib%
echo  %cd%
setx  FltkX64DebugLib "%cd%\..\fltk\BuildX64\lib\Debug" 

echo  FltkX64ReleaseLib = %FltkX64ReleaseLib%
echo  %cd%
setx  FltkX64ReleaseLib "%cd%\..\fltk\BuildX64\lib\Release" 

echo  WxWidgetsX64Lib = %WxWidgetsX64Lib%
echo  %cd%
setx  WxWidgetsX64Lib "%cd%\..\wxWidgets\lib\vc_x64_lib" 

echo  WxWidgetsWin32Lib = %WxWidgetsWin32Lib%
echo  %cd%
setx  WxWidgetsWin32Lib "%cd%\..\wxWidgets\lib\vc_lib" 

echo DirectXX64Lib = %DirectXX64Lib%
echo %cd%
setx DirectXX64Lib "%cd%\..\Microsoft DirectX SDK (June 2010)\Lib\x64" 

echo DirectXWin32Lib = %DirectXWin32Lib%
echo %cd%
setx DirectXWin32Lib "%cd%\..\Microsoft DirectX SDK (June 2010)\Lib\x86" 

echo GoogleTestWin32DebugLib = %GoogleTestWin32DebugLib%
echo  %cd%
setx  GoogleTestWin32DebugLib "%cd%\..\googletest\BuildWin32\lib\Debug" 

echo GoogleTestWin32ReleaseLib = %GoogleTestWin32ReleaseLib%
echo  %cd%
setx  GoogleTestWin32ReleaseLib "%cd%\..\googletest\BuildWin32\lib\Release" 

echo GoogleTestX64DebugLib = %GoogleTestX64DebugLib%
echo  %cd%
setx  GoogleTestX64DebugLib "%cd%\..\googletest\BuildX64\lib\Debug" 

echo  GoogleTestX64ReleaseLib = %GoogleTestX64ReleaseLib%
echo  %cd%
setx  GoogleTestX64ReleaseLib "%cd%\..\googletest\BuildX64\lib\Release" 

pause