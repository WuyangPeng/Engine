@echo on
 
call RunGatewayServerTesting.bat 

call RunGatewayServerCoreTesting.bat 

call RunGatewayServerMiddleLayerTesting.bat

pause