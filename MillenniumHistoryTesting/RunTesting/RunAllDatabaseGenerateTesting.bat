@echo on
 
call RunDatabaseGenerateTesting.bat 

call RunDatabaseGenerateCoreTesting.bat 

call RunDatabaseGenerateMiddleLayerTesting.bat

pause