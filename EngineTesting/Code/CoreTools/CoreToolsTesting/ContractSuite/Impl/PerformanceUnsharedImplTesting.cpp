/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 12:45)

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
    TestingType performanceUnsharedImpl0{ count };
    ASSERT_EQUAL((*performanceUnsharedImpl0).GetCount(), count);

    const auto performanceUnsharedImpl1 = performanceUnsharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, performanceUnsharedImpl0, performanceUnsharedImpl1, count);

    const auto performanceUnsharedImpl2 = performanceUnsharedImpl1;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, performanceUnsharedImpl1, performanceUnsharedImpl2, count);

    performanceUnsharedImpl0 = performanceUnsharedImpl2;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, performanceUnsharedImpl1, performanceUnsharedImpl0, count);
}

void CoreTools::PerformanceUnsharedImplTesting::UseFactoryTest()
{
    const TestingType performanceUnsharedImpl0{ ImplCreateUseFactory::Default, count };
    ASSERT_EQUAL(performanceUnsharedImpl0->GetCount(), count);

    const auto performanceUnsharedImpl1 = performanceUnsharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, performanceUnsharedImpl0, performanceUnsharedImpl1, count);
}

void CoreTools::PerformanceUnsharedImplTesting::UseUseDefaultConstructionTest()
{
    const TestingType performanceUnsharedImpl0{ ImplCreateUseDefaultConstruction::Default };
    ASSERT_EQUAL(performanceUnsharedImpl0->GetCount(), 0);

    const auto performanceUnsharedImpl1 = performanceUnsharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, performanceUnsharedImpl0, performanceUnsharedImpl1, 0);
}

void CoreTools::PerformanceUnsharedImplTesting::AddressEqualTest(const TestingType& lhs, const TestingType& rhs, int aCount)
{
    ASSERT_EQUAL(lhs->GetCount(), aCount);
    ASSERT_EQUAL(rhs->GetCount(), aCount);
    ASSERT_EQUAL((*rhs).GetCount(), aCount);
    ASSERT_EQUAL(lhs->GetAddress(), rhs->GetAddress());
}
