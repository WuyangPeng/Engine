@echo on
 
call RunDatabaseServerTesting.bat 

call RunDatabaseServerCoreTesting.bat 

call RunDatabaseServerMiddleLayerTesting.bat

pause