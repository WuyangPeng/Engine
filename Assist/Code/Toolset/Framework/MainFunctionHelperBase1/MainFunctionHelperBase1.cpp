// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/30 15:42)

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
	COUT << SYSTEM_TEXT("���氲װĿ¼Ϊ��Ϊ�ձ�ʾ����ǰ·������") 
		 << GetEngineInstallationDirectory()
		 << SYSTEM_TEXT('\n')
	     << SYSTEM_TEXT("����IsDestroy����ֵӦ��Ϊfalse��")
		 << std::boolalpha 
	     << IsDestroy()
		 << std::noboolalpha 
		 << SYSTEM_TEXT("��\n");

	System::SystemPause();

	return 0;
}

