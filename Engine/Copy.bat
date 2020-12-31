@echo on

xcopy ".clang-format" "%EngineTestingInclude%/../" /F /Y
xcopy ".gitignore" "%EngineTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%EngineTestingInclude%/../" /F /Y

xcopy ".clang-format" "%AssistInclude%/../" /F /Y
xcopy ".gitignore" "%AssistInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%AssistInclude%/../" /F /Y

xcopy ".clang-format" "%AssistTestingInclude%/../" /F /Y
xcopy ".gitignore" "%AssistTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%AssistTestingInclude%/../" /F /Y

xcopy ".clang-format" "%GameInclude%/../" /F /Y
xcopy ".gitignore" "%GameInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%GameInclude%/../" /F /Y

xcopy ".clang-format" "%GameTestingInclude%/../" /F /Y
xcopy ".gitignore" "%GameTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%GameTestingInclude%/../" /F /Y

xcopy ".clang-format" "%TheLastOverlordInclude%/../" /F /Y
xcopy ".gitignore" "%TheLastOverlordInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%TheLastOverlordInclude%/../" /F /Y

xcopy ".clang-format" "%TheLastOverlordTestingInclude%/../" /F /Y
xcopy ".gitignore" "%TheLastOverlordTestingInclude%/../" /F /Y
xcopy "DelDoxygenFile.bat" "%TheLastOverlordTestingInclude%/../" /F /Y

pause