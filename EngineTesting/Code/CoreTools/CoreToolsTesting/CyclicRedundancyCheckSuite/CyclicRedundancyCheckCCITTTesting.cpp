///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:11)

#include "CyclicRedundancyCheckCCITTTesting.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCCITT.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <array>

using std::array;

CoreTools::CyclicRedundancyCheckCCITTTesting::CyclicRedundancyCheckCCITTTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheckCCITTTesting)

void CoreTools::CyclicRedundancyCheckCCITTTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CyclicRedundancyCheckCCITTTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CCITTTest);
}

void CoreTools::CyclicRedundancyCheckCCITTTesting::CCITTTest()
{
    constexpr auto bufferSize = 12;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheckCCITT firstCyclicRedundancyCheckCCITT{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = firstCyclicRedundancyCheckCCITT.GetCyclicRedundancyCheck();

    buff.at(4) = '2';

    const CyclicRedundancyCheckCCITT secondCyclicRedundancyCheckCCITT{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check2 = secondCyclicRedundancyCheckCCITT.GetCyclicRedundancyCheck();

    ASSERT_UNEQUAL(check1, check2);
}
