/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/25 22:08)

#include "CopyUnsharedImplTesting.h"
#include "CoreTools/Contract/CopyUnsharedImplDetail.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::CopyUnsharedImplTesting::CopyUnsharedImplTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CopyUnsharedImplTesting)

void CoreTools::CopyUnsharedImplTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::CopyUnsharedImplTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseFactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseUseDefaultConstructionTest);
}

void CoreTools::CopyUnsharedImplTesting::DefaultTest()
{
    TestingType copyUnsharedImpl0{ count };
    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), count);

    auto copyUnsharedImpl1 = copyUnsharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressUnequalTest, copyUnsharedImpl0, copyUnsharedImpl1, count);

    ASSERT_NOT_THROW_EXCEPTION_2(SetCountTest, copyUnsharedImpl0, copyUnsharedImpl1);

    const auto copyUnsharedImpl2 = copyUnsharedImpl1;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressUnequalTest, copyUnsharedImpl1, copyUnsharedImpl2, count);

    copyUnsharedImpl1 = copyUnsharedImpl0;
    ASSERT_NOT_THROW_EXCEPTION_3(AddressUnequalTest, copyUnsharedImpl0, copyUnsharedImpl1, modify);
}

void CoreTools::CopyUnsharedImplTesting::AddressUnequalTest(const TestingType& lhs, const TestingType& rhs, int aCount)
{
    ASSERT_EQUAL((*rhs).GetCount(), aCount);
    ASSERT_UNEQUAL(lhs->GetAddress(), rhs->GetAddress());
}

void CoreTools::CopyUnsharedImplTesting::SetCountTest(TestingType& lhs, const TestingType& rhs)
{
    lhs->SetCount(1);
    ASSERT_EQUAL(lhs->GetCount(), modify);
    ASSERT_EQUAL(rhs->GetCount(), count);
}

void CoreTools::CopyUnsharedImplTesting::UseFactoryTest()
{
    TestingType copyUnsharedImpl{ ImplCreateUseFactory::Default, count };

    ASSERT_NOT_THROW_EXCEPTION_2(CountTest, copyUnsharedImpl, count);
}

void CoreTools::CopyUnsharedImplTesting::CountTest(TestingType& copyUnsharedImpl, int aCount)
{
    ASSERT_EQUAL(copyUnsharedImpl->GetCount(), aCount);

    auto copy = copyUnsharedImpl;

    ASSERT_EQUAL(copy->GetCount(), aCount);
    ASSERT_UNEQUAL(copyUnsharedImpl->GetAddress(), copy->GetAddress());

    copyUnsharedImpl->SetCount(modify);

    ASSERT_EQUAL(copyUnsharedImpl->GetCount(), modify);
    ASSERT_EQUAL(copy->GetCount(), aCount);
}

void CoreTools::CopyUnsharedImplTesting::UseUseDefaultConstructionTest()
{
    TestingType copyUnsharedImpl{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_NOT_THROW_EXCEPTION_2(CountTest, copyUnsharedImpl, 0);
}

CoreTools::CopyUnsharedImplTesting::ImplSharedPtr CoreTools::CopyUnsharedImplTesting::Clone(const Impl& impl)
{
    return std::make_shared<Impl>(impl.GetCount());
}
