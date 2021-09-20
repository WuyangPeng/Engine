// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.1 (2020/05/31 23:26)

#include "ConsoleMainFunctionHelperBaseTesting.h"  
#include "System/Threading/Process.h"
#include "System/Window/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/FileManager/Directory.h"

Framework::ConsoleMainFunctionHelperBaseTesting
	::ConsoleMainFunctionHelperBaseTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, ConsoleMainFunctionHelperBaseTesting)

void Framework::ConsoleMainFunctionHelperBaseTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::ConsoleMainFunctionHelperBaseTesting
	::MainTest()
{
	// 框架类ConsoleMainFunctionHelperBase使用工具箱调用，无法单独运行单元测试。 

	CoreTools::Directory directory{ System::GetEngineeringDirectory() };

	ASSERT_NOT_THROW_EXCEPTION_0(ConsoleMainFunctionHelperBase1Test);
}

void Framework::ConsoleMainFunctionHelperBaseTesting
	::ConsoleMainFunctionHelperBase1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("ConsoleMainFunctionHelperBase1")));
}

