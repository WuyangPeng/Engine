@echo on

xcopy "../.clang-format" "%EngineTestingInclude%/../" /F /Y
xcopy "../.gitignore" "%EngineTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%EngineTestingInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%AssistInclude%/../" /F /Y
xcopy "../.gitignore" "%AssistInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%AssistInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%AssistTestingInclude%/../" /F /Y
xcopy "../.gitignore" "%AssistTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%AssistTestingInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%GameInclude%/../" /F /Y
xcopy "../.gitignore" "%GameInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%GameInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%GameTestingInclude%/../" /F /Y
xcopy "../.gitignore" "%GameTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%GameTestingInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%TheLastOverlordInclude%/../" /F /Y
xcopy "../.gitignore" "%TheLastOverlordInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%TheLastOverlordInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%TheLastOverlordTestingInclude%/../" /F /Y
xcopy "../.gitignore" "%TheLastOverlordTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%TheLastOverlordTestingInclude%/../Bat/" /F /Y

xcopy "../.clang-format" "%RiseOfHistoryInclude%/../" /F /Y
xcopy "../.gitignore" "%RiseOfHistoryInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%RiseOfHistoryInclude%/../Bat/" /F /Y 

xcopy "../.clang-format" "%RiseOfHistoryTestingInclude%/../" /F /Y
xcopy "../.gitignore" "%RiseOfHistoryTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%RiseOfHistoryTestingInclude%/../Bat/" /F /Y 

xcopy "../.clang-format" "%MillenniumHistoryInclude%/../" /F /Y
xcopy "../.gitignore" "%MillenniumHistoryInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%MillenniumHistoryInclude%/../Bat/" /F /Y 

xcopy "../.clang-format" "%MillenniumHistoryTestingInclude%/../" /F /Y
xcopy "../.gitignore" "%MillenniumHistoryTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%MillenniumHistoryTestingInclude%/../Bat/" /F /Y 

pause