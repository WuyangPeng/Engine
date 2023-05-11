@echo on

xcopy "%AprWin32DebugLib%/*.lib" "../apr/BuildWin32/Debug" /F /Y 
xcopy "%AprWin32DebugLib%/*.dll" "../apr/BuildWin32/Debug" /F /Y 
xcopy "%AprWin32DebugLib%/*.pdb" "../apr/BuildWin32/Debug" /F /Y 

xcopy "%AprWin32ReleaseLib%/*.lib" "../apr/BuildWin32/Release" /F /Y 
xcopy "%AprWin32ReleaseLib%/*.dll" "../apr/BuildWin32/Release" /F /Y 
xcopy "%AprWin32ReleaseLib%/*.pdb" "../apr/BuildWin32/Release" /F /Y 

xcopy "%AprX64DebugLib%/*.lib" "../apr/BuildX64/Debug" /F /Y 
xcopy "%AprX64DebugLib%/*.dll" "../apr/BuildX64/Debug" /F /Y 
xcopy "%AprX64DebugLib%/*.pdb" "../apr/BuildX64/Debug" /F /Y 

xcopy "%AprX64ReleaseLib%/*.lib" "../apr/BuildX64/Release" /F /Y 
xcopy "%AprX64ReleaseLib%/*.dll" "../apr/BuildX64/Release" /F /Y 
xcopy "%AprX64ReleaseLib%/*.pdb" "../apr/BuildX64/Release" /F /Y 

pause