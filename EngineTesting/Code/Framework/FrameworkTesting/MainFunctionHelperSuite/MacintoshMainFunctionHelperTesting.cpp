// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.3.0.2 (2020/06/02 15:46)

#include "MacintoshMainFunctionHelperTesting.h"  
#include "System/Threading/Process.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/FileManager/Directory.h"  

Framework::MacintoshMainFunctionHelperTesting
	::MacintoshMainFunctionHelperTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, MacintoshMainFunctionHelperTesting)

void Framework::MacintoshMainFunctionHelperTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::MacintoshMainFunctionHelperTesting
	::MainTest()
{
	// 框架类MacintoshdMainFunctionHelper1使用工具箱调用，无法单独运行单元测试。 

	CoreTools::Directory directory{ System::GetEngineeringDirectory() };

	ASSERT_NOT_THROW_EXCEPTION_0(MacintoshMainFunctionHelper1Test);
}

void Framework::MacintoshMainFunctionHelperTesting
	::MacintoshMainFunctionHelper1Test()
{
	ASSERT_TRUE(System::CreateSystemProcess(SYSTEM_TEXT("MacintoshMainFunctionHelper1")));
}

