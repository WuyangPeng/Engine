@echo on 

call RunWinMainEntryPoint1.bat  
call RunWinMainEntryPoint2.bat  
call RunMainEntryPoint1.bat
call RunGlutMainEntryPoint1.bat
call RunAndroidMainEntryPoint1.bat

call RunWinMainEntryPoint3.bat  
call RunWinMainEntryPoint4.bat  
call RunMainEntryPoint2.bat
call RunGlutMainEntryPoint2.bat
call RunAndroidMainEntryPoint2.bat

call RunMainFunctionHelperBase1.bat

call RunConsoleMainFunctionHelperBase1.bat

call RunConsoleMainFunctionHelper1.bat

call RunWindowMainFunctionHelper1.bat

call RunOpenGLGlutMainFunctionHelper1.bat

call RunAndroidMainFunctionHelper1.bat

call RunMacintoshMainFunctionHelper1.bat

call RunWindowMessageLoop1.bat

pause