@echo on

rmdir /S /Q "../../../Libs/miniz"

xcopy "../../miniz/*.h" "../../../Libs/miniz/" /F /Y /E  
xcopy "../../miniz/BuildX64/miniz_export.h" "../../../Libs/miniz/" /F /Y /E  

xcopy "../../miniz/BuildWin32/Debug/*.lib" "../../../Libs/miniz/BuildWin32/Debug/" /F /Y /E 
xcopy "../../miniz/BuildWin32/Release/*.lib" "../../../Libs/miniz/BuildWin32/Release/" /F /Y /E   

xcopy "../../miniz/BuildX64/Debug/*.lib" "../../../Libs/miniz/BuildX64/Debug/" /F /Y /E 
xcopy "../../miniz/BuildX64/Release/*.lib" "../../../Libs/miniz/BuildX64/Release/" /F /Y /E

pause