@echo on

call RunConsoleSystemTesting.bat
call RunGlutMainLoopTesting.bat
call RunSystemAndroidTesting.bat
call RunSystemOpenGLTesting.bat
call RunSystemWindowsTesting.bat
call RunSystemTesting.bat 

pause