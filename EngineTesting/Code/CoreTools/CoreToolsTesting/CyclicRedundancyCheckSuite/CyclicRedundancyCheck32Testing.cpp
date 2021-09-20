// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:52)

#include "CyclicRedundancyCheck32Testing.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheck32.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CyclicRedundancyCheck32Testing)

void CoreTools::CyclicRedundancyCheck32Testing ::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CheckTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheck32Testing ::CheckTest()
{
    constexpr auto bufferSize = 12;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheck32 firstCyclicRedundancyCheck32{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = firstCyclicRedundancyCheck32.GetCyclicRedundancyCheck32();

    buff.at(4) = '2';

    const CyclicRedundancyCheck32 secondCyclicRedundancyCheck32{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check2 = secondCyclicRedundancyCheck32.GetCyclicRedundancyCheck32();

    ASSERT_UNEQUAL(check1, check2);
}
