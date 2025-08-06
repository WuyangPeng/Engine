@echo on

rmdir /S /Q "../../../Libs/mongo-cxx-driver"

xcopy "../../mongo-cxx-driver/*.hpp" "../../../Libs/mongo-cxx-driver/" /F /Y /E   

xcopy "../../mongo-cxx-driver/*.lib" "../../../Libs/mongo-cxx-driver/" /F /Y /E 
xcopy "../../mongo-cxx-driver/*.dll" "../../../Libs/mongo-cxx-driver/" /F /Y /E 

move /y "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\mongocxx\Debug\mongocxx-v_noabi-dhi-x64-v143-mdd.lib" "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\mongocxx\Debug\mongocxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\mongocxx\Release\mongocxx-v_noabi-rhi-x64-v143-md.lib" "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\mongocxx\Release\mongocxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\mongocxx\Debug\mongocxx-v_noabi-dhi-win32-v143-mdd.lib" "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\mongocxx\Debug\mongocxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\mongocxx\Release\mongocxx-v_noabi-rhi-win32-v143-md.lib" "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\mongocxx\Release\mongocxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\bsoncxx\Debug\bsoncxx-v_noabi-dhi-x64-v143-mdd.lib" "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\bsoncxx\Debug\bsoncxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\bsoncxx\Release\bsoncxx-v_noabi-rhi-x64-v143-md.lib" "..\..\..\Libs\mongo-cxx-driver\BuildX64\src\bsoncxx\Release\bsoncxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\bsoncxx\Debug\bsoncxx-v_noabi-dhi-win32-v143-mdd.lib" "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\bsoncxx\Debug\bsoncxx.lib"

move /y "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\bsoncxx\Release\bsoncxx-v_noabi-rhi-win32-v143-md.lib" "..\..\..\Libs\mongo-cxx-driver\BuildWin32\src\bsoncxx\Release\bsoncxx.lib"

pause