@echo on

xcopy "%FreeglutInclude%/GL/*.h" "../freeglut/include/GL" /F /Y   

xcopy "%FreeglutWin32DebugLib%/*.lib" "../freeglut/BuildWin32/lib/Debug" /F /Y   
xcopy "%FreeglutWin32DebugLib%/*.pdb" "../freeglut/BuildWin32/lib/Debug" /F /Y   

xcopy "%FreeglutWin32ReleaseLib%/*.lib" "../freeglut/BuildWin32/lib/Release" /F /Y   
xcopy "%FreeglutWin32ReleaseLib%/*.pdb" "../freeglut/BuildWin32/lib/Release" /F /Y   

xcopy "%FreeglutX64DebugLib%/*.lib" "../freeglut/BuildX64/lib/Debug" /F /Y   
xcopy "%FreeglutX64DebugLib%/*.pdb" "../freeglut/BuildX64/lib/Debug" /F /Y   

xcopy "%FreeglutX64ReleaseLib%/*.lib" "../freeglut/BuildX64/lib/Release" /F /Y   
xcopy "%FreeglutX64ReleaseLib%/*.pdb" "../freeglut/BuildX64/lib/Release" /F /Y   

xcopy "%FreeglutWin32DebugBin%/*.dll" "../freeglut/BuildWin32/bin/Debug" /F /Y    

xcopy "%FreeglutWin32ReleaseBin%/*.dll" "../freeglut/BuildWin32/bin/Release" /F /Y   

xcopy "%FreeglutX64DebugBin%/*.dll" "../freeglut/BuildX64/bin/Debug" /F /Y    

xcopy "%FreeglutX64ReleaseBin%/*.dll" "../freeglut/BuildX64/bin/Release" /F /Y   

pause