///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 16:04)

#include "SpecifyCheckSumTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/Flags/SpecifyCheckSumPowersFlags.h"
#include "CoreTools/CyclicRedundancyCheck/SpecifyCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::SpecifyCheckSumTesting::SpecifyCheckSumTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SpecifyCheckSumTesting)

void CoreTools::SpecifyCheckSumTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SpecifyCheckSumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::SpecifyCheckSumTesting::SumTest()
{
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5' };

    const SpecifyCheckSum sevenModElevenCheckSum0{ buff.data(), boost::numeric_cast<int>(buff.size()), SpecifyCheckSumPowers::Seven, 11 };

    ASSERT_RANGE(sevenModElevenCheckSum0.GetOriginalCheckSum(), 0, 9);
    ASSERT_LESS_EQUAL(0, sevenModElevenCheckSum0.GetCollisions());

    const SpecifyCheckSum sevenModElevenCheckSum1{ buff.data(), boost::numeric_cast<int>(buff.size()), SpecifyCheckSumPowers::Nine, 26 };

    ASSERT_RANGE(sevenModElevenCheckSum1.GetOriginalCheckSum(), -25, 25);
    ASSERT_LESS_EQUAL(0, sevenModElevenCheckSum1.GetCollisions());

    const SpecifyCheckSum sevenModElevenCheckSum2{ buff.data(), boost::numeric_cast<int>(buff.size()), SpecifyCheckSumPowers::Nine, 10 };

    ASSERT_RANGE(sevenModElevenCheckSum2.GetOriginalCheckSum(), -9, 9);
    ASSERT_LESS_EQUAL(0, sevenModElevenCheckSum2.GetCollisions());
}
