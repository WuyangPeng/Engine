@echo on

rmdir /S /Q "../../../Libs/activemq"

xcopy "../../activemq/*.h" "../../../Libs/activemq/" /F /Y /E   

xcopy "../../activemq/*.lib" "../../../Libs/activemq/" /F /Y /E 
xcopy "../../activemq/*.dll" "../../../Libs/activemq/" /F /Y /E 

pause