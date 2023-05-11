@echo on

xcopy "%ActiveMQInclude%/cms/*.h" "../activemq/src/main/cms" /F /Y 
xcopy "%ActiveMQInclude%/activemq/cmsutil/*.h" "../activemq/src/main/activemq/cmsutil" /F /Y 
xcopy "%ActiveMQInclude%/activemq/commands/*.h" "../activemq/src/main/activemq/commands" /F /Y 
xcopy "%ActiveMQInclude%/activemq/core/*.h" "../activemq/src/main/activemq/core" /F /Y 
xcopy "%ActiveMQInclude%/activemq/exceptions/*.h" "../activemq/src/main/activemq/exceptions" /F /Y 
xcopy "%ActiveMQInclude%/activemq/io/*.h" "../activemq/src/main/activemq/io" /F /Y 
xcopy "%ActiveMQInclude%/activemq/library/*.h" "../activemq/src/main/activemq/library" /F /Y 
xcopy "%ActiveMQInclude%/activemq/state/*.h" "../activemq/src/main/activemq/state" /F /Y 
xcopy "%ActiveMQInclude%/activemq/threads/*.h" "../activemq/src/main/activemq/threads" /F /Y 
xcopy "%ActiveMQInclude%/activemq/transport/*.h" "../activemq/src/main/activemq/transport" /F /Y 
xcopy "%ActiveMQInclude%/activemq/util/*.h" "../activemq/src/main/activemq/util" /F /Y 
xcopy "%ActiveMQInclude%/activemq/wireformat/*.h" "../activemq/src/main/activemq/wireformat" /F /Y 

pause