///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:20)

#include "SevenModElevenCheckSumTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/SevenModElevenCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SevenModElevenCheckSumTesting)

void CoreTools::SevenModElevenCheckSumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::SevenModElevenCheckSumTesting::SumTest()
{
    constexpr auto bufferSize = 10;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5' };

    const SevenModElevenCheckSum sevenModElevenCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    ASSERT_RANGE(sevenModElevenCheckSum.GetCheckSum(), 0, 9);
}
