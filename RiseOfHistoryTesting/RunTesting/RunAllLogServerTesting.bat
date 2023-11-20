@echo on
 
call RunLogServerTesting.bat 

call RunLogServerCoreTesting.bat 

call RunLogServerMiddleLayerTesting.bat

pause