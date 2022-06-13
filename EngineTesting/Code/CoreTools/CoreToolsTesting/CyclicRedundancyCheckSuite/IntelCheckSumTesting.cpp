///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 14:20)

#include "IntelCheckSumTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/IntelCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, IntelCheckSumTesting)

void CoreTools::IntelCheckSumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::IntelCheckSumTesting::SumTest()
{
    constexpr auto bufferSize = 256;

    array<char, bufferSize> buff{};

    for (auto i = 0; i < bufferSize; ++i)
    {
        buff.at(i) = boost::numeric_cast<char>(i - bufferSize / 2);
    }

    const IntelCheckSum intelCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    auto sum = 0;
    for (auto i = 0u; i < buff.size(); ++i)
    {
        sum += buff.at(i);
    }

    ASSERT_EQUAL(-sum, intelCheckSum.GetIntelCheckSum());
}
