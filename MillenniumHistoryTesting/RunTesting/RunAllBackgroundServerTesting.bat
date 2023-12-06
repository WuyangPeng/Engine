@echo on
 
call RunBackgroundServerTesting.bat 

call RunBackgroundServerCoreTesting.bat 

call RunBackgroundServerMiddleLayerTesting.bat

pause