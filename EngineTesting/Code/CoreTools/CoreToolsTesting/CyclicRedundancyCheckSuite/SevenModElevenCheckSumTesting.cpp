/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:09)

#include "SevenModElevenCheckSumTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/SevenModElevenCheckSum.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::SevenModElevenCheckSumTesting::SevenModElevenCheckSumTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SevenModElevenCheckSumTesting)

void CoreTools::SevenModElevenCheckSumTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SevenModElevenCheckSumTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(SumTest);
}

void CoreTools::SevenModElevenCheckSumTesting::SumTest()
{
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5' };

    const SevenModElevenCheckSum sevenModElevenCheckSum{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    ASSERT_RANGE(sevenModElevenCheckSum.GetCheckSum(), 0, 9);
}
