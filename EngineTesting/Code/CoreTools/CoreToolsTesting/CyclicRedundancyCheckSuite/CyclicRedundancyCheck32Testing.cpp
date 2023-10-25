///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:50)

#include "CyclicRedundancyCheck32Testing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheck32.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::CyclicRedundancyCheck32Testing::CyclicRedundancyCheck32Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheck32Testing)

void CoreTools::CyclicRedundancyCheck32Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CyclicRedundancyCheck32Testing::MainTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(CheckTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheck32Testing::CheckTest()
{
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheck32 cyclicRedundancyCheck0{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check0 = cyclicRedundancyCheck0.GetCyclicRedundancyCheck32();

    buff.at(4) = '2';

    const CyclicRedundancyCheck32 cyclicRedundancyCheck1{ buff.data(), boost::numeric_cast<int>(buff.size()) };

    const auto check1 = cyclicRedundancyCheck1.GetCyclicRedundancyCheck32();

    ASSERT_UNEQUAL(check0, check1);
}
