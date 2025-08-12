@echo on

rmdir /S /Q "../../../Libs/boost"

xcopy "../../boost/boost/*.h" "../../../Libs/boost/boost/" /F /Y /E 
xcopy "../../boost/boost/*.hpp" "../../../Libs/boost/boost/" /F /Y /E 
xcopy "../../boost/boost/*.ipp" "../../../Libs/boost/boost/" /F /Y /E 

xcopy "../../boost/stage/lib/*chrono*" "../../../Libs/boost/stage/lib/" /F /Y  
xcopy "../../boost/stage/lib/*time*" "../../../Libs/boost/stage/lib/" /F /Y 
xcopy "../../boost/stage/lib/*thread*" "../../../Libs/boost/stage/lib/" /F /Y 
xcopy "../../boost/stage/lib/*charconv*" "../../../Libs/boost/stage/lib/" /F /Y 

pause