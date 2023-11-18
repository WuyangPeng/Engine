@echo on

echo ToolInclude = %ToolInclude%
echo  %cd%
setx  ToolInclude "%cd%\.." 

pause