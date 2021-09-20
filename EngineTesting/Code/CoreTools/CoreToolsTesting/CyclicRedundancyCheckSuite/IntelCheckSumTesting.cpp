// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.3 (2020/03/06 18:54)

#include "IntelCheckSumTesting.h"
#include "CoreTools/CyclicRedundancyCheck/IntelCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include <array>

using std::array;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(CoreTools, IntelCheckSumTesting)

void CoreTools::IntelCheckSumTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::IntelCheckSumTesting ::SumTest()
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
