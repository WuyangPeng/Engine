// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 19:03)

#include "TelegramLessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/TelegramDetail.h"
#include "CoreTools/MessageEvent/TelegramLessDetail.h"

namespace CoreTools
{
    using TestingType = TelegramLess<int>;
    using TelegramType = Telegram<int>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, TelegramLessTesting)

void CoreTools::TelegramLessTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(LessTest);
}

void CoreTools::TelegramLessTesting ::LessTest()
{
    TelegramType lhs{ 1, 2, 10000 };

    TelegramType rhs{ 1, 2, 10002 };

    const TestingType firstTelegramLess{ 3 };

    ASSERT_FALSE(firstTelegramLess(lhs, rhs));
    ASSERT_FALSE(firstTelegramLess(rhs, lhs));

    const TestingType secondTelegramLess{ 1 };

    ASSERT_TRUE(secondTelegramLess(lhs, rhs));
    ASSERT_FALSE(secondTelegramLess(rhs, lhs));
}
