///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:20)

#include "SpecifyCheckSumTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/Flags/SpecifyCheckSumPowersFlags.h"
#include "CoreTools/CyclicRedundancyCheck/SpecifyCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SpecifyCheckSumTesting)

void CoreTools::SpecifyCheckSumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::SpecifyCheckSumTesting::SumTest()
{
    constexpr auto bufferSize = 10;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5' };

    const SpecifyCheckSum firstSevenModElevenCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()), SpecifyCheckSumPowers::Seven, 11 };

    ASSERT_RANGE(firstSevenModElevenCheckSum.GetOriginalCheckSum(), 0, 9); 
    ASSERT_LESS_EQUAL(0, firstSevenModElevenCheckSum.GetCollisions());

    const SpecifyCheckSum secondSevenModElevenCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()), SpecifyCheckSumPowers::Nine, 26 };

    ASSERT_RANGE(secondSevenModElevenCheckSum.GetOriginalCheckSum(), -25, 25);
    ASSERT_LESS_EQUAL(0, secondSevenModElevenCheckSum.GetCollisions());

    const SpecifyCheckSum thirdSevenModElevenCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()), SpecifyCheckSumPowers::Nine, 10 };

    ASSERT_RANGE(thirdSevenModElevenCheckSum.GetOriginalCheckSum(), -9, 9);
    ASSERT_LESS_EQUAL(0, thirdSevenModElevenCheckSum.GetCollisions());
}
