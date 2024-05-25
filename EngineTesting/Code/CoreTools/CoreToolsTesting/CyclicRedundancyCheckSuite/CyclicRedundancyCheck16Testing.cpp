/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 13:08)

#include "CyclicRedundancyCheck16Testing.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheck16.h"
#include "CoreTools/CyclicRedundancyCheck/CyclicRedundancyCheckHandle.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

#include <array>

CoreTools::CyclicRedundancyCheck16Testing::CyclicRedundancyCheck16Testing(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CyclicRedundancyCheck16Testing)

void CoreTools::CyclicRedundancyCheck16Testing::DoRunUnitTest()
{
    CyclicRedundancyCheckHandle::Create();

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    CyclicRedundancyCheckHandle::Destroy();
}

void CoreTools::CyclicRedundancyCheck16Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CheckTest);
}

void CoreTools::CyclicRedundancyCheck16Testing::CheckTest()
{
    std::array buff{ '8', '3', '1', '4', '7', '0', '2', '9', '6', '5', '7', '7' };

    const CyclicRedundancyCheck16 cyclicRedundancyCheck0{ buff.data(), boost::numeric_cast<int>(buff.size()) };
    const auto check0 = cyclicRedundancyCheck0.GetCyclicRedundancyCheck16();

    buff.at(4) = '2';

    const CyclicRedundancyCheck16 cyclicRedundancyCheck1{ buff.data(), boost::numeric_cast<int>(buff.size()) };
    const auto check1 = cyclicRedundancyCheck1.GetCyclicRedundancyCheck16();

    ASSERT_UNEQUAL(check0, check1);
}
