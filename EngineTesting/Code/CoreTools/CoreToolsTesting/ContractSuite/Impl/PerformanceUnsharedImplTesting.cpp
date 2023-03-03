///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/23 14:36)

#include "PerformanceUnsharedImplTesting.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Contract/PerformanceUnsharedImplDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::PerformanceUnsharedImplTesting::PerformanceUnsharedImplTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, PerformanceUnsharedImplTesting)

void CoreTools::PerformanceUnsharedImplTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::PerformanceUnsharedImplTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseFactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseUseDefaultConstructionTest);
}

void CoreTools::PerformanceUnsharedImplTesting::DefaultTest()
{
    constexpr auto count = 12;
    TestingType performanceUnsharedImpl0{ count };

    ASSERT_EQUAL((*performanceUnsharedImpl0).GetCount(), count);

    const auto performanceUnsharedImpl1 = performanceUnsharedImpl0;

    ASSERT_EQUAL(performanceUnsharedImpl1->GetCount(), count);
    ASSERT_EQUAL(performanceUnsharedImpl0->GetAddress(), performanceUnsharedImpl1->GetAddress());

    const auto performanceUnsharedImpl2 = performanceUnsharedImpl1;

    ASSERT_EQUAL((*performanceUnsharedImpl2).GetCount(), count);
    ASSERT_EQUAL(performanceUnsharedImpl2->GetAddress(), performanceUnsharedImpl1->GetAddress());

    performanceUnsharedImpl0 = performanceUnsharedImpl2;

    ASSERT_EQUAL(performanceUnsharedImpl0->GetCount(), count);
    ASSERT_EQUAL(performanceUnsharedImpl0->GetAddress(), performanceUnsharedImpl1->GetAddress());
}

void CoreTools::PerformanceUnsharedImplTesting::UseFactoryTest()
{
    constexpr auto count = 12;
    const TestingType performanceUnsharedImpl0{ ImplCreateUseFactory::Default, count };

    ASSERT_EQUAL(performanceUnsharedImpl0->GetCount(), count);

    const auto performanceUnsharedImpl1 = performanceUnsharedImpl0;

    ASSERT_EQUAL(performanceUnsharedImpl1->GetCount(), count);
    ASSERT_EQUAL(performanceUnsharedImpl0->GetAddress(), performanceUnsharedImpl1->GetAddress());
}

void CoreTools::PerformanceUnsharedImplTesting::UseUseDefaultConstructionTest()
{
    const TestingType performanceUnsharedImpl0{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_EQUAL(performanceUnsharedImpl0->GetCount(), 0);

    const auto performanceUnsharedImpl1 = performanceUnsharedImpl0;

    ASSERT_EQUAL(performanceUnsharedImpl1->GetCount(), 0);
    ASSERT_EQUAL(performanceUnsharedImpl0->GetAddress(), performanceUnsharedImpl1->GetAddress());
}
