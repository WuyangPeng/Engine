// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:52)

#include "CyclicRedundancyCheckCCITTTesting.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCCITT.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CyclicRedundancyCheckCCITTTesting)

void CoreTools::CyclicRedundancyCheckCCITTTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CCITTTest);
}

void CoreTools::CyclicRedundancyCheckCCITTTesting ::CCITTTest()
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
