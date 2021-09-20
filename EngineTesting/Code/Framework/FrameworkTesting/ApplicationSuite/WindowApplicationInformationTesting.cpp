// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.2 (2020/06/14 0:58)

#include "WindowApplicationInformationTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  

Framework::WindowApplicationInformationTesting
	::WindowApplicationInformationTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowApplicationInformationTesting)

void Framework::WindowApplicationInformationTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowApplicationInformationTesting
	::MainTest()
{
	// 测试在FrameworkWindowTesting中，需要窗口环境。

	CoreTools::DisableNoexcept();
}

 


