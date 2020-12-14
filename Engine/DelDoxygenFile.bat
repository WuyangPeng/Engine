@echo on
cd Doxygen
echo 请检查当前路径是否正确。
pause 
rmdir /s /q html
for /r %%f in (*.*) do del /s /q /f "%%f"
pause 