@echo on

rmdir /S /Q "../../../Libs/mysql-connector-c++"

xcopy "../../mysql-connector-c++/include/*.h" "../../../Libs/mysql-connector-c++/include/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildX64/include/mysqlx/version_info.h" "../../../Libs/mysql-connector-c++/include/" /F /Y /E 

xcopy "../../mysql-connector-c++/BuildWin32/include/mysqlx/version_info.h" "../../../Libs/mysql-connector-c++/BuildWin32/include/mysqlx/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildWin32/Debug/*.lib" "../../../Libs/mysql-connector-c++/BuildWin32/Debug/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildWin32/Debug/*.dll" "../../../Libs/mysql-connector-c++/BuildWin32/Debug/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildWin32/Release/*.lib" "../../../Libs/mysql-connector-c++/BuildWin32/Release/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildWin32/Release/*.dll" "../../../Libs/mysql-connector-c++/BuildWin32/Release/" /F /Y /E 

xcopy "../../mysql-connector-c++/BuildX64/include/mysqlx/version_info.h" "../../../Libs/mysql-connector-c++/BuildX64/include/mysqlx/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildX64/Debug/*.lib" "../../../Libs/mysql-connector-c++/BuildX64/Debug/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildX64/Debug/*.dll" "../../../Libs/mysql-connector-c++/BuildX64/Debug/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildX64/Release/*.lib" "../../../Libs/mysql-connector-c++/BuildX64/Release/" /F /Y /E 
xcopy "../../mysql-connector-c++/BuildX64/Release/*.dll" "../../../Libs/mysql-connector-c++/BuildX64/Release/" /F /Y /E 

pause