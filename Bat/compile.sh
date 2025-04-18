curDir=$(pwd)/..

cd "$curDir"/Libs/Bat
sh create_lib.sh

cd "$curDir"/Engine/Bat
./compile.sh

cd "$curDir"/Assist/Bat
./compile.sh

cd "$curDir"/EngineTesting/Bat
./compile.sh

cd "$curDir"/AssistTesting/Bat
./compile.sh