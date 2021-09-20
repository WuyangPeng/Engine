// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.2 (2020/06/12 21:19)

#include "FontInformationTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"   

Framework::FontInformationTesting
	::FontInformationTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, FontInformationTesting)

void Framework::FontInformationTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::FontInformationTesting
	::MainTest()
{
	// 测试在FrameworkWindowTesting中，需要窗口环境。

	CoreTools::DisableNoexcept();
}


