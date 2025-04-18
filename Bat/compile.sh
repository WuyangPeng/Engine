set curDir=%cd%/..

cd %curDir%/Libs/Bat
sh create_lib.sh

cd %curDir%/Engine/Bat
sh complie.sh

cd %curDir%/Assist/Bat
sh complie.sh

cd %curDir%/EngineTesting/Bat
sh complie.sh

cd %curDir%/AssistTesting/Bat
sh complie.sh