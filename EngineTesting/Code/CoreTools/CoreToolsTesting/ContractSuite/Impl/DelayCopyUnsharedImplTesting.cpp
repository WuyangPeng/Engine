/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/25 22:08)

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
    DelayCopyUnshared delayCopyUnsharedImpl0{ count };
    ASSERT_EQUAL(delayCopyUnsharedImpl0.GetDereferenceCount(), count);

    const auto delayCopyUnsharedImpl1 = delayCopyUnsharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_2(AddressEqualTest, delayCopyUnsharedImpl0, delayCopyUnsharedImpl1);

    delayCopyUnsharedImpl0.SetDereferenceCount(modify);
    ASSERT_NOT_THROW_EXCEPTION_2(AddressUnequalTest, delayCopyUnsharedImpl0, delayCopyUnsharedImpl1);

    delayCopyUnsharedImpl0 = delayCopyUnsharedImpl1;
    ASSERT_NOT_THROW_EXCEPTION_2(AddressEqualTest, delayCopyUnsharedImpl0, delayCopyUnsharedImpl1);

    delayCopyUnsharedImpl0.SetCount(modify);
    ASSERT_NOT_THROW_EXCEPTION_2(AddressUnequalTest, delayCopyUnsharedImpl0, delayCopyUnsharedImpl1);
}

void CoreTools::DelayCopyUnsharedImplTesting::AddressEqualTest(const DelayCopyUnshared& lhs, const DelayCopyUnshared& rhs)
{
    ASSERT_EQUAL(lhs.GetAddress(), rhs.GetAddress());
    ASSERT_EQUAL(lhs.GetCount(), count);
    ASSERT_EQUAL(rhs.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedImplTesting::AddressUnequalTest(const DelayCopyUnshared& lhs, const DelayCopyUnshared& rhs)
{
    ASSERT_UNEQUAL(lhs.GetAddress(), rhs.GetAddress());
    ASSERT_EQUAL(lhs.GetCount(), modify);
    ASSERT_EQUAL(rhs.GetCount(), count);
}

void CoreTools::DelayCopyUnsharedImplTesting::UseFactoryTest()
{
    DelayCopyUnshared delayCopyUnsharedImpl{ ImplCreateUseFactory::Default, count };
    ASSERT_NOT_THROW_EXCEPTION_2(CountTest, delayCopyUnsharedImpl, count);
}

void CoreTools::DelayCopyUnsharedImplTesting::UseUseDefaultConstructionTest()
{
    DelayCopyUnshared delayCopyUnsharedImpl{ ImplCreateUseDefaultConstruction::Default };
    ASSERT_NOT_THROW_EXCEPTION_2(CountTest, delayCopyUnsharedImpl, 0);
}

void CoreTools::DelayCopyUnsharedImplTesting::CountTest(DelayCopyUnshared& delayCopyUnsharedImpl, int aCount)
{
    ASSERT_EQUAL(delayCopyUnsharedImpl.GetCount(), aCount);

    const auto delayCopy = delayCopyUnsharedImpl;

    ASSERT_EQUAL(delayCopy.GetCount(), aCount);
    ASSERT_EQUAL(delayCopyUnsharedImpl.GetAddress(), delayCopy.GetAddress());

    delayCopyUnsharedImpl.SetCount(modify);

    ASSERT_UNEQUAL(delayCopyUnsharedImpl.GetAddress(), delayCopy.GetAddress());
    ASSERT_EQUAL(delayCopyUnsharedImpl.GetCount(), modify);
    ASSERT_EQUAL(delayCopy.GetCount(), aCount);
}
