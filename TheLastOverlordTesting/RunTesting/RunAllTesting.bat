@echo on

call RunAllGameClientTesting.bat
call RunAllRobotClientTesting.bat
call RunAllMessageClientTesting.bat
call RunAllBackgroundClientTesting.bat

call RunAllGatewayServerTesting.bat
call RunAllLoginServerTesting.bat
call RunAllGameServerTesting.bat
call RunAllFightingServerTesting.bat
call RunAllWorldServerTesting.bat
call RunAllOfflineServerTesting.bat
call RunAllLeaderboardServerTesting.bat
call RunAllRechargeServerTesting.bat
call RunAllLogServerTesting.bat
call RunAllGameMasterServerTesting.bat
call RunAllServerManagerTesting.bat
call RunAllBackgroundServerTesting.bat
call RunAllUpdateServerTesting.bat

call RunTheLastOverlordTestingTesting.bat

pause