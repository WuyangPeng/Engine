// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎测试版本：0.3.0.2 (2020/06/03 15:35)

#include "WindowInstanceParameterTesting.h"
#include "Framework/WindowCreate/WindowInstanceParameter.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/Contract/Noexcept.h"

Framework::WindowInstanceParameterTesting
	::WindowInstanceParameterTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowInstanceParameterTesting)

void Framework::WindowInstanceParameterTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowInstanceParameterTesting
	::MainTest()
{
	// 测试在FrameworkWindowTesting中，需要窗口环境。

	CoreTools::DisableNoexcept();
}

