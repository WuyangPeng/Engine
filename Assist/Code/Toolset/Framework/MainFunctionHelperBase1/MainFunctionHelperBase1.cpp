// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.1 (2020/05/30 15:42)

#include "MainFunctionHelperBase1.h"
#include "System/Time/DeltaTime.h"

#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/MainFunctionHelper/EnvironmentDirectory.h"

#include <iostream>

Framework::MainFunctionHelperBase1 ::MainFunctionHelperBase1([[maybe_unused]] int argc, [[maybe_unused]] char** argv, [[maybe_unused]] const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
    : ParentType{ environmentDirectory }
{
 

	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}  

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionHelperBase1)

int Framework::MainFunctionHelperBase1
	::DoRun()
{ 
	COUT << SYSTEM_TEXT("引擎安装目录为（为空表示程序当前路径）：") 
		 << GetEngineInstallationDirectory()
		 << SYSTEM_TEXT('\n')
	     << SYSTEM_TEXT("函数IsDestroy返回值应该为false：")
		 << std::boolalpha 
	     << IsDestroy()
		 << std::noboolalpha 
		 << SYSTEM_TEXT("。\n");

	System::SystemPause();

	return 0;
}

