// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.3.0.1 (2020/05/30 22:55)

#include "MainFunctionHelperBaseTesting.h"
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/FileManager/Directory.h"

Framework::MainFunctionHelperBaseTesting
	::MainFunctionHelperBaseTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MainFunctionHelperBaseTesting)

void Framework::MainFunctionHelperBaseTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MainFunctionHelperBaseTesting
	::MainTest()
{
	// �����MainFunctionHelperBaseʹ�ù�������ã��޷��������е�Ԫ���ԡ� 

	CoreTools::Directory directory{ System::GetEngineeringDirectory() };

	ASSERT_NOT_THROW_EXCEPTION_0(MainFunctionHelperBase1Test);
}

void Framework::MainFunctionHelperBaseTesting
	::MainFunctionHelperBase1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MainFunctionHelperBase1")));
}

