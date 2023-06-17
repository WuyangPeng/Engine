///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/13 19:49)

#include "WindowMessageUnitTestSuiteTesting.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

Framework::WindowMessageUnitTestSuiteTesting::WindowMessageUnitTestSuiteTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, WindowMessageUnitTestSuiteTesting)

void Framework::WindowMessageUnitTestSuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::WindowMessageUnitTestSuiteTesting::MainTest() noexcept
{
    // 测试在WindowMessageUnitTestSuiteTesting中，需要一个单独的测试。
}
