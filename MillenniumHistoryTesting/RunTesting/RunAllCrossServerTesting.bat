@echo on
 
call RunCrossServerTesting.bat 

call RunCrossServerCoreTesting.bat 

call RunCrossServerMiddleLayerTesting.bat

pause