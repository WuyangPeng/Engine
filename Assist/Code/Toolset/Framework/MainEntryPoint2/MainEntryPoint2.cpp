// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.3.0.1 (2020/05/26 14:36)

#include "MainEntryPoint2.h" 
#include "System/Time/DeltaTime.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h" 

#include <iostream>

using std::cout;

Framework::MainEntryPoint2
	::MainEntryPoint2(int argc, char** argv, const String& consoleTitle, const EnvironmentDirectory& environmentDirectory)
	:ParentType{ argc,argv,consoleTitle,environmentDirectory }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainEntryPoint2)

int Framework::MainEntryPoint2
	::DoRun()
{
	cout << "����MainEntryPoint��ڵ㺯��\n";

	System::SystemPause();

	return 0;
}






