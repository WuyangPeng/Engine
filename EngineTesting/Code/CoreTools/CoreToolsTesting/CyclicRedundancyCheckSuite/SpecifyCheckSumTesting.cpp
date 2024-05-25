/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:09)

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
    ASSERT_NOT_THROW_EXCEPTION_0(SevenTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Nine0Test);
    ASSERT_NOT_THROW_EXCEPTION_0(Nine1Test);
}

void CoreTools::SpecifyCheckSumTesting::SevenTest()
{
    const SpecifyCheckSum sevenModElevenCheckSum0{ buffer.data(), boost::numeric_cast<int>(buffer.size()), SpecifyCheckSumPowers::Seven, 11 };
    ASSERT_RANGE(sevenModElevenCheckSum0.GetOriginalCheckSum(), 0, 9);
    ASSERT_LESS_EQUAL(0, sevenModElevenCheckSum0.GetCollisions());
}

void CoreTools::SpecifyCheckSumTesting::Nine0Test()
{
    const SpecifyCheckSum sevenModElevenCheckSum1{ buffer.data(), boost::numeric_cast<int>(buffer.size()), SpecifyCheckSumPowers::Nine, 26 };
    ASSERT_RANGE(sevenModElevenCheckSum1.GetOriginalCheckSum(), -25, 25);
    ASSERT_LESS_EQUAL(0, sevenModElevenCheckSum1.GetCollisions());
}

void CoreTools::SpecifyCheckSumTesting::Nine1Test()
{
    const SpecifyCheckSum sevenModElevenCheckSum2{ buffer.data(), boost::numeric_cast<int>(buffer.size()), SpecifyCheckSumPowers::Nine, 10 };
    ASSERT_RANGE(sevenModElevenCheckSum2.GetOriginalCheckSum(), -9, 9);
    ASSERT_LESS_EQUAL(0, sevenModElevenCheckSum2.GetCollisions());
}
