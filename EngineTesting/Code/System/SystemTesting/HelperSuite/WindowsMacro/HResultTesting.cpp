/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 09:59)

#include "HResultTesting.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::HResultTesting::HResultTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, HResultTesting)

void System::HResultTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::HResultTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(HResultTest);
}

void System::HResultTesting::HResultTest()
{
    ASSERT_FALSE(IsFailed(0));
    ASSERT_TRUE(IsSucceeded(0));

    ASSERT_FALSE(IsFailed(1));
    ASSERT_TRUE(IsSucceeded(1));

    ASSERT_TRUE(IsFailed(-1));
    ASSERT_FALSE(IsSucceeded(-1));

    ASSERT_EQUAL(gFalse, 0);
    ASSERT_EQUAL(gTrue, 1);
}
