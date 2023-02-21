///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:20)

#include "CyclicRedundancyCheckCCITTUsingTableTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCCITT.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCCITTUsingTable.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <array>

using std::array;

CoreTools::CyclicRedundancyCheckCCITTUsingTableTesting::CyclicRedundancyCheckCCITTUsingTableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheckCCITTUsingTableTesting)

void CoreTools::CyclicRedundancyCheckCCITTUsingTableTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CyclicRedundancyCheckCCITTUsingTableTesting::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CCITTTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheckCCITTUsingTableTesting::CCITTTest()
{
    constexpr auto bufferSize = 12;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheckCCITTUsingTable firstCyclicRedundancyCheckCCITT{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = firstCyclicRedundancyCheckCCITT.GetCyclicRedundancyCheck();

    buff.at(4) = '2';

    const CyclicRedundancyCheckCCITTUsingTable secondCyclicRedundancyCheckCCITT{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check2 = secondCyclicRedundancyCheckCCITT.GetCyclicRedundancyCheck();

    ASSERT_UNEQUAL(check1, check2);

    const CyclicRedundancyCheckCCITT thirdCyclicRedundancyCheckCCITT{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check3 = thirdCyclicRedundancyCheckCCITT.GetCyclicRedundancyCheck();

    ASSERT_EQUAL(check3, check2);
}
