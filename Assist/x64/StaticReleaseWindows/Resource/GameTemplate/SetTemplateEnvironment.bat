@echo on

echo ToolsetGameTestingTemplateInclude = %ToolsetGameTestingTemplateInclude%
echo %cd%
setx ToolsetGameTestingTemplateInclude "%cd%\..\ExportTesting\Code" 

pause