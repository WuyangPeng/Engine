@echo on
echo 请检查当前路径是否正确。
pause 
cd ..
cd Win32
for /r %%f in (*.ilk *.lastcodeanalysissucceeded *.manifest *.pdb *.exe *.dll *.ipdb *.iobj *.lib *.exp) do del /s /q /f "%%f"
cd DebugWindows 
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..
cd ReleaseWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..
cd StaticDebugWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..
cd StaticReleaseWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..

cd ..
cd x64
for /r %%f in (*.ilk *.lastcodeanalysissucceeded *.manifest *.pdb *.exe *.dll *.ipdb *.iobj *.lib *.exp) do del /s /q /f "%%f"
cd DebugWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..
cd ReleaseWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..
cd StaticDebugWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..
cd StaticReleaseWindows
rmdir /s /q Log
rmdir /s /q Resource
mkdir Resource
cd ..

pause 