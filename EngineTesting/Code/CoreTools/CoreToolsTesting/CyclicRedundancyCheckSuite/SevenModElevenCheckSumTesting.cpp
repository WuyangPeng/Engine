// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:54)

#include "SevenModElevenCheckSumTesting.h"
#include "CoreTools/CyclicRedundancyCheck/SevenModElevenCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, SevenModElevenCheckSumTesting)

void CoreTools::SevenModElevenCheckSumTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::SevenModElevenCheckSumTesting ::SumTest()
{
    constexpr auto bufferSize = 10;

    array<char, bufferSize> buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5' };

    const SevenModElevenCheckSum sevenModElevenCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    ASSERT_RANGE(sevenModElevenCheckSum.GetCheckSum(), 0, 9);
}
