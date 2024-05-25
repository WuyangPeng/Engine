/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/26 12:47)

#include "SharedImplTesting.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Contract/SharedImplDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::SharedImplTesting::SharedImplTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, SharedImplTesting)

void CoreTools::SharedImplTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::SharedImplTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseFactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseUseDefaultConstructionTest);
}

void CoreTools::SharedImplTesting::DefaultTest()
{
    TestingType sharedImpl0{ count };
    ASSERT_EQUAL((*sharedImpl0).GetCount(), count);

    auto sharedImpl1 = sharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, sharedImpl0, sharedImpl1, count);

    sharedImpl0->SetCount(modify);
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, sharedImpl0, sharedImpl1, modify);

    const auto sharedImpl2 = sharedImpl1;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressEqualTest, sharedImpl1, sharedImpl2, modify);
}

void CoreTools::SharedImplTesting::AddressEqualTest(const TestingType& lhs, const TestingType& rhs, int aCount)
{
    ASSERT_EQUAL((*lhs).GetCount(), aCount);
    ASSERT_EQUAL(lhs->GetCount(), aCount);
    ASSERT_EQUAL(rhs->GetCount(), aCount);
    ASSERT_EQUAL(lhs->GetAddress(), rhs->GetAddress());
}

void CoreTools::SharedImplTesting::UseFactoryTest()
{
    TestingType sharedImpl{ ImplCreateUseFactory::Default, count };

    ASSERT_NOT_THROW_EXCEPTION_2(CountTest, sharedImpl, count);
}

void CoreTools::SharedImplTesting::UseUseDefaultConstructionTest()
{
    TestingType sharedImpl{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_NOT_THROW_EXCEPTION_2(CountTest, sharedImpl, 0);
}

void CoreTools::SharedImplTesting::CountTest(TestingType& sharedImpl, int aCount)
{
    ASSERT_EQUAL(sharedImpl->GetCount(), aCount);

    auto copy = sharedImpl;

    ASSERT_EQUAL(copy->GetCount(), aCount);
    ASSERT_EQUAL(sharedImpl->GetAddress(), copy->GetAddress());

    sharedImpl->SetCount(modify);

    ASSERT_EQUAL(sharedImpl->GetCount(), modify);
    ASSERT_EQUAL(copy->GetCount(), modify);
    ASSERT_EQUAL(sharedImpl->GetAddress(), copy->GetAddress());
}
