///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 16:01)

#include "CyclicRedundancyCheckCCITTTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCCITT.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

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
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheckCCITT cyclicRedundancyCheckCCITT0{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check0 = cyclicRedundancyCheckCCITT0.GetCyclicRedundancyCheck();

    buff.at(4) = '2';

    const CyclicRedundancyCheckCCITT cyclicRedundancyCheckCCITT1{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = cyclicRedundancyCheckCCITT1.GetCyclicRedundancyCheck();

    ASSERT_UNEQUAL(check0, check1);
}
