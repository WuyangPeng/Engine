@echo on

rmdir /S /Q "../../../Libs/openssl"

xcopy "../../openssl/Win32/Debug/bin/*.dll" "../../../Libs/openssl/Win32/Debug/bin/" /F /Y /E 
xcopy "../../openssl/Win32/Debug/bin/*.exe" "../../../Libs/openssl/Win32/Debug/bin/" /F /Y /E 
xcopy "../../openssl/Win32/Debug/include/openssl/*" "../../../Libs/openssl/Win32/Debug/include/openssl/" /F /Y /E 
xcopy "../../openssl/Win32/Debug/lib/*.lib" "../../../Libs/openssl/Win32/Debug/lib/" /F /Y /E 
xcopy "../../openssl/Win32/Debug/lib/ossl-modules/*.dll" "../../../Libs/openssl/Win32/Debug/lib/ossl-modules/" /F /Y /E 
xcopy "../../openssl/Win32/Debug/lib/engines-3/*.dll" "../../../Libs/openssl/Win32/Debug/lib/engines-3/" /F /Y /E 

xcopy "../../openssl/Win32/Release/bin/*.dll" "../../../Libs/openssl/Win32/Release/bin/" /F /Y /E 
xcopy "../../openssl/Win32/Release/bin/*.exe" "../../../Libs/openssl/Win32/Release/bin/" /F /Y /E 
xcopy "../../openssl/Win32/Release/include/openssl/*" "../../../Libs/openssl/Win32/Release/include/openssl/" /F /Y /E 
xcopy "../../openssl/Win32/Release/lib/*.lib" "../../../Libs/openssl/Win32/Release/lib/" /F /Y /E 
xcopy "../../openssl/Win32/Release/lib/ossl-modules/*.dll" "../../../Libs/openssl/Win32/Release/lib/ossl-modules/" /F /Y /E 
xcopy "../../openssl/Win32/Release/lib/engines-3/*.dll" "../../../Libs/openssl/Win32/Release/lib/engines-3/" /F /Y /E 

xcopy "../../openssl/x64/Debug/bin/*.dll" "../../../Libs/openssl/x64/Debug/bin/" /F /Y /E 
xcopy "../../openssl/x64/Debug/bin/*.exe" "../../../Libs/openssl/x64/Debug/bin/" /F /Y /E 
xcopy "../../openssl/x64/Debug/include/openssl/*" "../../../Libs/openssl/x64/Debug/include/openssl/" /F /Y /E 
xcopy "../../openssl/x64/Debug/lib/*.lib" "../../../Libs/openssl/x64/Debug/lib/" /F /Y /E 
xcopy "../../openssl/x64/Debug/lib/ossl-modules/*.dll" "../../../Libs/openssl/x64/Debug/lib/ossl-modules/" /F /Y /E 
xcopy "../../openssl/x64/Debug/lib/engines-3/*.dll" "../../../Libs/openssl/x64/Debug/lib/engines-3/" /F /Y /E 

xcopy "../../openssl/x64/Release/bin/*.dll" "../../../Libs/openssl/x64/Release/bin/" /F /Y /E 
xcopy "../../openssl/x64/Release/bin/*.exe" "../../../Libs/openssl/x64/Release/bin/" /F /Y /E 
xcopy "../../openssl/x64/Release/include/openssl/*" "../../../Libs/openssl/x64/Release/include/openssl/" /F /Y /E 
xcopy "../../openssl/x64/Release/lib/*.lib" "../../../Libs/openssl/x64/Release/lib/" /F /Y /E 
xcopy "../../openssl/x64/Release/lib/ossl-modules/*.dll" "../../../Libs/openssl/x64/Release/lib/ossl-modules/" /F /Y /E 
xcopy "../../openssl/x64/Release/lib/engines-3/*.dll" "../../../Libs/openssl/x64/Release/lib/engines-3/" /F /Y /E 

pause