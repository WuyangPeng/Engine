@echo on

rmdir /S /Q "../../../Libs/mongo-cxx-driver"

xcopy "../../mongo-cxx-driver/*.hpp" "../../../Libs/mongo-cxx-driver/" /F /Y /E   

xcopy "../../mongo-cxx-driver/*.lib" "../../../Libs/mongo-cxx-driver/" /F /Y /E 
xcopy "../../mongo-cxx-driver/*.dll" "../../../Libs/mongo-cxx-driver/" /F /Y /E 

pause