@echo on
 
call RunMailServerTesting.bat 

call RunMailServerCoreTesting.bat 

call RunMailServerMiddleLayerTesting.bat

pause