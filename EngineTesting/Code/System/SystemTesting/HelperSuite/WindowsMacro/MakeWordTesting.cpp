///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/20 20:37)

#include "MakeWordTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/WindowsMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/SystemClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

System::MakeWordTesting::MakeWordTesting(const OStreamShared& stream)
    : ParentType{ stream }, randomEngine{ GetEngineRandomSeed() }, distribution{ 0x0, maxReverseMakeWord - 1 }
{
    SYSTEM_SELF_CLASS_IS_VALID_9;
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

void System::MakeWordTesting::MakeWordTest()
{
    constexpr auto size = (1 << makeWordShiftNum);
    for (auto high = 0; high < size; ++high)
    {
        for (auto low = 0; low < size; ++low)
        {
            const auto param = MakeWord(low, high);
            const auto expectationParam = boost::numeric_cast<WindowsWord>(low + (high << makeWordShiftNum));

            ASSERT_EQUAL(expectationParam, param);
        }
    }
}

bool System::MakeWordTesting::ReverseMakeWordTest()
{
    const auto low = distribution(randomEngine);
    const auto high = distribution(randomEngine);

    const auto param = low + (high << reverseMakeWordShiftNum);

    const auto reverseLow = LowWord(param);
    const auto reverseHigh = HighWord(param);

    ASSERT_EQUAL(reverseLow, low);
    ASSERT_EQUAL(reverseHigh, high);

    return true;
}
