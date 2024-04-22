/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 10:21)

#include "DelayCopyUnsharedImplTesting.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/CoreToolsTesting/ContractSuite/Detail/DelayCopyUnshared.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::DelayCopyUnsharedImplTesting::DelayCopyUnsharedImplTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, DelayCopyUnsharedImplTesting)

void CoreTools::DelayCopyUnsharedImplTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::DelayCopyUnsharedImplTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseFactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseUseDefaultConstructionTest);
}

void CoreTools::DelayCopyUnsharedImplTesting::DefaultTest()
{
    constexpr auto count = 10;
    DelayCopyUnshared delayCopyUnsharedImpl0{ count };

    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetDereferenceCount(), count);

    const auto delayCopyUnsharedImpl1 = delayCopyUnsharedImpl0;

    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), count);
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());

    delayCopyUnsharedImpl0.SetDereferenceCount(1);

    ASSERT_UNEQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), 1);
    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), count);

    delayCopyUnsharedImpl0 = delayCopyUnsharedImpl1;
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), count);
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());

    delayCopyUnsharedImpl0.SetCount(1);

    ASSERT_UNEQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), 1);
    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedImplTesting::UseFactoryTest()
{
    constexpr auto count = 12;
    DelayCopyUnshared delayCopyUnsharedImpl0{ ImplCreateUseFactory::Default, count };

    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), count);

    const auto delayCopyUnsharedImpl1 = delayCopyUnsharedImpl0;

    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), count);
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());

    delayCopyUnsharedImpl0.SetCount(1);

    ASSERT_UNEQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), 1);
    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedImplTesting::UseUseDefaultConstructionTest()
{
    DelayCopyUnshared delayCopyUnsharedImpl0{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), 0);

    const auto delayCopyUnsharedImpl1 = delayCopyUnsharedImpl0;

    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), 0);
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());

    delayCopyUnsharedImpl0.SetCount(1);

    ASSERT_UNEQUAL(delayCopyUnsharedImpl0.GetAddress(), delayCopyUnsharedImpl1.GetAddress());
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetCount(), 1);
    ASSERT_EQUAL(delayCopyUnsharedImpl1.GetCount(), 0);
}
