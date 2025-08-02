@echo on

rmdir /S /Q "../../../Libs/hiredis"

xcopy "../../hiredis/*.h" "../../../Libs/hiredis/" /F /Y /E   

xcopy "../../hiredis/*.lib" "../../../Libs/hiredis/" /F /Y /E 
xcopy "../../hiredis/*.dll" "../../../Libs/hiredis/" /F /Y /E 

pause