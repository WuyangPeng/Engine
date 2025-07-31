@echo on

rmdir /S /Q "../../../Libs/vld"

xcopy "../../vld/src/*.h" "../../../Libs/vld/src/" /F /Y /E  
xcopy "../../vld/src/*.manifest" "../../../Libs/vld/src/" /F /Y /E  
xcopy "../../vld/src/*.dll" "../../../Libs/vld/src/" /F /Y /E  
xcopy "../../vld/src/*.lib" "../../../Libs/vld/src/" /F /Y /E  

pause