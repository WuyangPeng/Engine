///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.0.0 (2021/01/24 16:55)

#include "CppStrategiesAndTacticsPlaceholderTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "Example/BookCpp/CppStrategiesAndTactics/Helper/CppStrategiesAndTacticsClassInvariantMacro.h"

BookIntermediate::CppStrategiesAndTactics::CppStrategiesAndTacticsPlaceholderTesting::CppStrategiesAndTacticsPlaceholderTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CPP_STRATEGIES_AND_TACTICS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookIntermediate::CppStrategiesAndTactics, CppStrategiesAndTacticsPlaceholderTesting)

void BookIntermediate::CppStrategiesAndTactics::CppStrategiesAndTacticsPlaceholderTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookIntermediate::CppStrategiesAndTactics::CppStrategiesAndTacticsPlaceholderTesting::MainTest() noexcept
{
}
