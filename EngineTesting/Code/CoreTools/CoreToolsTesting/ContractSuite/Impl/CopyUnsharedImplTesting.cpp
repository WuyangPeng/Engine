///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.2 (2021/08/26 15:18)

#include "CopyUnsharedImplTesting.h"
#include "CoreTools/Contract/CopyUnsharedImplDetail.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;

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
    constexpr auto count = 10;
    TestingType copyUnsharedImpl0{ count };

    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), count);

    auto copyUnsharedImpl1 = copyUnsharedImpl0;

    ASSERT_EQUAL((*copyUnsharedImpl1).GetCount(), count);
    ASSERT_UNEQUAL(copyUnsharedImpl0->GetAddress(), copyUnsharedImpl1->GetAddress());

    copyUnsharedImpl0->SetCount(1);

    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), 1);
    ASSERT_EQUAL(copyUnsharedImpl1->GetCount(), count);

    const auto copyUnsharedImpl2 = copyUnsharedImpl1;

    ASSERT_EQUAL((*copyUnsharedImpl2).GetCount(), count);
    ASSERT_UNEQUAL(copyUnsharedImpl2->GetAddress(), copyUnsharedImpl1->GetAddress());

    copyUnsharedImpl1 = copyUnsharedImpl0;

    ASSERT_EQUAL(copyUnsharedImpl1->GetCount(), 1);
    ASSERT_UNEQUAL(copyUnsharedImpl1->GetAddress(), copyUnsharedImpl0->GetAddress());
}

void CoreTools::CopyUnsharedImplTesting::UseFactoryTest()
{
    constexpr auto count = 12;
    TestingType copyUnsharedImpl0{ ImplCreateUseFactory::Default, count };

    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), count);

    auto copyUnsharedImpl1 = copyUnsharedImpl0;

    ASSERT_EQUAL(copyUnsharedImpl1->GetCount(), count);
    ASSERT_UNEQUAL(copyUnsharedImpl0->GetAddress(), copyUnsharedImpl1->GetAddress());

    copyUnsharedImpl0->SetCount(1);

    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), 1);
    ASSERT_EQUAL(copyUnsharedImpl1->GetCount(), count);
}

void CoreTools::CopyUnsharedImplTesting::UseUseDefaultConstructionTest()
{
    TestingType copyUnsharedImpl0{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), 0);

    auto copyUnsharedImpl1 = copyUnsharedImpl0;

    ASSERT_EQUAL(copyUnsharedImpl1->GetCount(), 0);
    ASSERT_UNEQUAL(copyUnsharedImpl0->GetAddress(), copyUnsharedImpl1->GetAddress());

    copyUnsharedImpl0->SetCount(1);

    ASSERT_EQUAL(copyUnsharedImpl0->GetCount(), 1);
    ASSERT_EQUAL(copyUnsharedImpl1->GetCount(), 0);
}

CoreTools::CopyUnsharedImplTesting::ImplSharedPtr CoreTools::CopyUnsharedImplTesting::Clone(const Impl& impl)
{
    return make_shared<Impl>(impl.GetCount());
}
