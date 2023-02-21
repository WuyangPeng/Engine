///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/18 17:03)

#include "TelegramLessTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/MessageEvent/TelegramDetail.h"
#include "CoreTools/MessageEvent/TelegramLessDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
namespace CoreTools
{
    using TestingType = TelegramLess<int>;
    using TelegramType = Telegram<int>;
}

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
    TelegramType lhs{ 1, 2, 10000 };

    TelegramType rhs{ 1, 2, 10002 };

    const TestingType firstTelegramLess{ 3 };

    ASSERT_FALSE(firstTelegramLess(lhs, rhs));
    ASSERT_FALSE(firstTelegramLess(rhs, lhs));

    const TestingType secondTelegramLess{ 1 };

    ASSERT_TRUE(secondTelegramLess(lhs, rhs));
    ASSERT_FALSE(secondTelegramLess(rhs, lhs));
}
