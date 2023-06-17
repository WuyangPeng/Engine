///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2022/06/24 14:00)

#include "AndroidCallBackUnitTestSuiteTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"
#include "Framework/AndroidFrame/AndroidCallBackUnitTestSuite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
Framework::AndroidCallBackUnitTestSuiteTesting::AndroidCallBackUnitTestSuiteTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    FRAMEWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Framework, AndroidCallBackUnitTestSuiteTesting)

void Framework::AndroidCallBackUnitTestSuiteTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Framework::AndroidCallBackUnitTestSuiteTesting::MainTest() noexcept
{
}
