@echo on

rmdir /S /Q "../../../Libs/protobuf"

xcopy "../../protobuf/src/*.h" "../../../Libs/protobuf/src/" /F /Y /E  
xcopy "../../protobuf/src/*.inc" "../../../Libs/protobuf/src/" /F /Y /E  
xcopy "../../protobuf/BuildX64/_deps/absl-src/*.h" "../../../Libs/protobuf/src/" /F /Y /E  
xcopy "../../protobuf/BuildX64/_deps/absl-src/*.inc" "../../../Libs/protobuf/src/" /F /Y /E  

xcopy "../../protobuf/BuildWin32/bin/Release/*.lib" "../../../Libs/protobuf/BuildWin32/bin/Debug/" /F /Y /E  
xcopy "../../protobuf/BuildWin32/bin/Release/*.dll" "../../../Libs/protobuf/BuildWin32/bin/Debug/" /F /Y /E  
xcopy "../../protobuf/BuildWin32/bin/Release/*.exe" "../../../Libs/protobuf/BuildWin32/bin/Debug/" /F /Y /E  

xcopy "../../protobuf/BuildWin32/bin/Release/*.lib" "../../../Libs/protobuf/BuildWin32/bin/Release/" /F /Y /E  
xcopy "../../protobuf/BuildWin32/bin/Release/*.dll" "../../../Libs/protobuf/BuildWin32/bin/Release/" /F /Y /E  
xcopy "../../protobuf/BuildWin32/bin/Release/*.exe" "../../../Libs/protobuf/BuildWin32/bin/Release/" /F /Y /E  

xcopy "../../protobuf/BuildX64/bin/Release/*.lib" "../../../Libs/protobuf/BuildX64/bin/Debug/" /F /Y /E  
xcopy "../../protobuf/BuildX64/bin/Release/*.dll" "../../../Libs/protobuf/BuildX64/bin/Debug/" /F /Y /E 
xcopy "../../protobuf/BuildX64/bin/Release/*.exe" "../../../Libs/protobuf/BuildX64/bin/Debug/" /F /Y /E   

xcopy "../../protobuf/BuildX64/bin/Release/*.lib" "../../../Libs/protobuf/BuildX64/bin/Release/" /F /Y /E  
xcopy "../../protobuf/BuildX64/bin/Release/*.dll" "../../../Libs/protobuf/BuildX64/bin/Release/" /F /Y /E  
xcopy "../../protobuf/BuildX64/bin/Release/*.exe" "../../../Libs/protobuf/BuildX64/bin/Release/" /F /Y /E  

pause