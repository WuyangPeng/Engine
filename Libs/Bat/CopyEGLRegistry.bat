@echo on

xcopy "%OpengEGLlInclude%/KHR/*.h" "../EGL-Registry/api/KHR" /F /Y  
xcopy "%OpengEGLlInclude%/EGL/*.h" "../EGL-Registry/api/EGL" /F /Y  
xcopy "%OpengEGLlInclude%/1.0/*.h" "../EGL-Registry/api/1.0" /F /Y  
xcopy "%OpengEGLlInclude%/1.0/EGL/*.h" "../EGL-Registry/api/1.0/EGL" /F /Y  
xcopy "%OpengEGLlInclude%/1.1/*.h" "../EGL-Registry/api/1.1" /F /Y  
xcopy "%OpengEGLlInclude%/1.1/EGL/*.h" "../EGL-Registry/api/1.1/EGL" /F /Y  
xcopy "%OpengEGLlInclude%/1.2/*.h" "../EGL-Registry/api/1.2" /F /Y  
xcopy "%OpengEGLlInclude%/1.2/EGL/*.h" "../EGL-Registry/api/1.2/EGL" /F /Y  

pause