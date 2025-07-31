@echo on

rmdir /S /Q "../../../Libs/OpenXLSX"

xcopy "../../OpenXLSX/OpenXLSX/*.hpp" "../../../Libs/OpenXLSX/OpenXLSX/" /F /Y /E  

xcopy "../../OpenXLSX/BuildWin32/*.lib" "../../../Libs/OpenXLSX/BuildWin32/" /F /Y /E 
xcopy "../../OpenXLSX/BuildWin32/*.dll" "../../../Libs/OpenXLSX/BuildWin32/" /F /Y /E   

xcopy "../../OpenXLSX/BuildX64/*.lib" "../../../Libs/OpenXLSX/BuildX64/" /F /Y /E   
xcopy "../../OpenXLSX/BuildX64/*.dll" "../../../Libs/OpenXLSX/BuildX64/" /F /Y /E   

pause