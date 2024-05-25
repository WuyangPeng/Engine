/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:02)

#include "TelegramLessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MessageEvent/TelegramDetail.h"
#include "CoreTools/MessageEvent/TelegramLessDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::TelegramLessTesting::TelegramLessTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, TelegramLessTesting)

void CoreTools::TelegramLessTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::TelegramLessTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LessTest);
}

void CoreTools::TelegramLessTesting::LessTest()
{
    const TelegramType lhs{ 1, 2, 10000 };

    const TelegramType rhs{ 1, 2, 10002 };

    ASSERT_NOT_THROW_EXCEPTION_2(Less0Test, lhs, rhs);

    ASSERT_NOT_THROW_EXCEPTION_2(Less1Test, lhs, rhs);
}

void CoreTools::TelegramLessTesting::Less0Test(const TelegramType& lhs, const TelegramType& rhs)
{
    const TestingType telegramLess0{ 3 };

    ASSERT_FALSE(telegramLess0(lhs, rhs));
    ASSERT_FALSE(telegramLess0(rhs, lhs));
}

void CoreTools::TelegramLessTesting::Less1Test(const TelegramType& lhs, const TelegramType& rhs)
{
    const TestingType telegramLess1{ 1 };

    ASSERT_TRUE(telegramLess1(lhs, rhs));
    ASSERT_FALSE(telegramLess1(rhs, lhs));
}
