@echo on
cd Doxygen
echo ���鵱ǰ·���Ƿ���ȷ��
pause 
rmdir /s /q html
for /r %%f in (*.*) do del /s /q /f "%%f"
pause 