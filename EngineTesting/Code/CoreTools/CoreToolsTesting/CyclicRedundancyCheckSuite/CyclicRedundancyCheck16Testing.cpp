// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:52)

#include "CyclicRedundancyCheck16Testing.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheck16.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, CyclicRedundancyCheck16Testing)

void CoreTools::CyclicRedundancyCheck16Testing ::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CheckTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheck16Testing ::CheckTest()
{
    constexpr auto bufferSize = 12;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheck16 firstCyclicRedundancyCheck16{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = firstCyclicRedundancyCheck16.GetCyclicRedundancyCheck16();

    buff.at(4) = '2';

    const CyclicRedundancyCheck16 secondCyclicRedundancyCheck16{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check2 = secondCyclicRedundancyCheck16.GetCyclicRedundancyCheck16();

    ASSERT_UNEQUAL(check1, check2);
}
