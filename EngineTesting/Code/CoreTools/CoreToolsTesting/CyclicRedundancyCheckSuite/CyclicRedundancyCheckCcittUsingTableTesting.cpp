/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:08)

#include "CyclicRedundancyCheckCcittUsingTableTesting.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCcitt.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckCcittUsingTable.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::CyclicRedundancyCheckCcittUsingTableTesting::CyclicRedundancyCheckCcittUsingTableTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheckCcittUsingTableTesting)

void CoreTools::CyclicRedundancyCheckCcittUsingTableTesting::DoRunUnitTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheckCcittUsingTableTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CcittTest);
}

void CoreTools::CyclicRedundancyCheckCcittUsingTableTesting::CcittTest()
{
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheckCcittUsingTable cyclicRedundancyCheckCcitt0{ buff.data(), boost::numeric_cast<int>(buff.size()) };
    const auto check0 = cyclicRedundancyCheckCcitt0.GetCyclicRedundancyCheck();

    buff.at(4) = '2';

    const CyclicRedundancyCheckCcittUsingTable cyclicRedundancyCheckCcitt1{ buff.data(), boost::numeric_cast<int>(buff.size()) };
    const auto check1 = cyclicRedundancyCheckCcitt1.GetCyclicRedundancyCheck();

    ASSERT_UNEQUAL(check0, check1);

    const CyclicRedundancyCheckCcitt cyclicRedundancyCheckCcitt2{ buff.data(), boost::numeric_cast<int>(buff.size()) };
    const auto check2 = cyclicRedundancyCheckCcitt2.GetCyclicRedundancyCheck();

    ASSERT_EQUAL(check2, check1);
}
