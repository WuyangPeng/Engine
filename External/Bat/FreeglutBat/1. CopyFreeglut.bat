@echo on

rmdir /S /Q "../../../Libs/freeglut"

xcopy "../../freeglut/include/GL/*.h" "../../../Libs/freeglut/include/GL/" /F /Y /E  

xcopy "../../freeglut/BuildWin32/lib/*.lib" "../../../Libs/freeglut/BuildWin32/lib/" /F /Y /E 
xcopy "../../freeglut/BuildWin32/bin/*.dll" "../../../Libs/freeglut/BuildWin32/bin/" /F /Y /E   

xcopy "../../freeglut/BuildX64/lib/*.lib" "../../../Libs/freeglut/BuildX64/lib/" /F /Y /E   
xcopy "../../freeglut/BuildX64/bin/*.dll" "../../../Libs/freeglut/BuildX64/bin/" /F /Y /E   

pause