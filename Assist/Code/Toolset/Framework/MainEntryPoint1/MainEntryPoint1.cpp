// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎辅助版本：0.3.0.1 (2020/05/25 11:37)

#include "MainEntryPoint1.h" 
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

#include <iostream>

using std::cout;

Framework::MainEntryPoint1
	::MainEntryPoint1(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,consoleTitle,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainEntryPoint1)

int Framework::MainEntryPoint1
	::DoRun()
{
	cout << "运行MainEntryPoint入口点函数\n";

	System::SystemPause();

	return 0;
}






