/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 10:00)

#include "MakeWordTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeWordTesting::MakeWordTesting(const OStreamShared& stream)
    : ParentType{ stream }, randomEngine{ GetEngineRandomSeed() }, distribution{ 0x0, maxReverseMakeWord - 1 }
{
    SYSTEM_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(System, MakeWordTesting)

void System::MakeWordTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void System::MakeWordTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MakeWordTest);
    ASSERT_EXECUTE_LOOP_TESTING_NOT_THROW_EXCEPTION(ReverseMakeWordTest);
}

void System::MakeWordTesting::DoMakeWordTest(int high, int low)
{
    const auto param = MakeWord(low, high);
    const auto expectationParam = boost::numeric_cast<WindowsWord>(low + (high << makeWordShiftNum));

    ASSERT_EQUAL(expectationParam, param);
}

void System::MakeWordTesting::MakeWordTest()
{
    constexpr auto size = (1 << makeWordShiftNum);
    for (auto high = 0; high < size; ++high)
    {
        for (auto low = 0; low < size; ++low)
        {
            ASSERT_NOT_THROW_EXCEPTION_2(DoMakeWordTest, high, low);
        }
    }
}

bool System::MakeWordTesting::ReverseMakeWordTest()
{
    const auto low = distribution(randomEngine);
    const auto high = distribution(randomEngine);

    const auto param = low + (high << reverseMakeWordShiftNum);

    const auto reverseLow = GetLowWord(param);
    const auto reverseHigh = GetHighWord(param);

    ASSERT_EQUAL(reverseLow, low);
    ASSERT_EQUAL(reverseHigh, high);

    return true;
}
