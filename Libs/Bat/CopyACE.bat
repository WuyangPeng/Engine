@echo on

xcopy "%ACEInclude%/lib/Win32/*" "../ACE/ACE_wrappers/lib/Win32" /F /Y
xcopy "%ACEInclude%/lib/X64/*" "../ACE/ACE_wrappers/lib/X64" /F /Y
xcopy "%ACEInclude%/ace/*.h" "../ACE/ACE_wrappers/ace/" /F /Y
xcopy "%ACEInclude%/ace/*.inl" "../ACE/ACE_wrappers/ace/" /F /Y

pause