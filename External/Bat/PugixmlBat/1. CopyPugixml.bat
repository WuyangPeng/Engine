@echo on

rmdir /S /Q "../../../Libs/pugixml"

xcopy "../../pugixml/src/*" "../../../Libs/pugixml/src/" /F /Y /E

pause