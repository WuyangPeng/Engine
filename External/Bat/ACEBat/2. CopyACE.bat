@echo on

rmdir /S /Q "../../../Libs/ACE"

xcopy "../../ACE/ACE_wrappers/lib/Win32/*" "../../../Libs/ACE/ACE_wrappers/lib/Win32/" /F /Y
xcopy "../../ACE/ACE_wrappers/lib/X64/*" "../../../Libs/ACE/ACE_wrappers/lib/X64/" /F /Y
xcopy "../../ACE/ACE_wrappers/ace/*.h" "../../../Libs/ACE/ACE_wrappers/ace/" /F /Y /E 
xcopy "../../ACE/ACE_wrappers/ace/*.inl" "../../../Libs/ACE/ACE_wrappers/ace/" /F /Y /E 

pause