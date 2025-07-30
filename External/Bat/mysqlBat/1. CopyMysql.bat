@echo on

rmdir /S /Q "../../../Libs/mysql"

xcopy "../../mysql/include/*" "../../../Libs/mysql/include/" /F /Y /E 
xcopy "../../mysql/BuildWin32/archive_output_directory/Debug/mysqlclient.lib" "../../../Libs/mysql/BuildWin32/archive_output_directory/Debug/" /F /Y /E 
xcopy "../../mysql/BuildWin32/archive_output_directory/Release/mysqlclient.lib" "../../../Libs/mysql/BuildWin32/archive_output_directory/Release/" /F /Y /E 
xcopy "../../mysql/BuildX64/archive_output_directory/Debug/mysqlclient.lib" "../../../Libs/mysql/BuildX64/archive_output_directory/Debug/" /F /Y /E 
xcopy "../../mysql/BuildX64/archive_output_directory/Release/mysqlclient.lib" "../../../Libs/mysql/BuildX64/archive_output_directory/Release/" /F /Y /E 

pause