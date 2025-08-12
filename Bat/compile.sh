curDir=$(pwd)/..

cd "$curDir"/External/Bat
sh create_lib.sh

cd "$curDir"/Engine/Bat
sh compile.sh

cd "$curDir"/Assist/Bat
sh compile.sh

cd "$curDir"/EngineTesting/Bat
sh compile.sh

cd "$curDir"/AssistTesting/Bat
sh compile.sh