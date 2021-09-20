// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.3.0.2 (2020/06/05 22:11)

#include "WindowMessageUnitTestSuiteTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"  
#include "CoreTools/Contract/Noexcept.h"

Framework::WindowMessageUnitTestSuiteTesting
	::WindowMessageUnitTestSuiteTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMessageUnitTestSuiteTesting)

void Framework::WindowMessageUnitTestSuiteTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowMessageUnitTestSuiteTesting
	::MainTest()
{
	// 测试在WindowMessageUnitTestSuiteTesting中，需要一个单独的测试。 

	CoreTools::DisableNoexcept();
}



