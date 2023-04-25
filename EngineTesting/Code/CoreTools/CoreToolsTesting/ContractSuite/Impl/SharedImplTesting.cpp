///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 15:34)

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
    constexpr auto count = 12;
    TestingType sharedImpl0{ count };

    ASSERT_EQUAL((*sharedImpl0).GetCount(), count);

    auto sharedImpl1 = sharedImpl0;

    ASSERT_EQUAL(sharedImpl1->GetCount(), count);
    ASSERT_EQUAL(sharedImpl0->GetAddress(), sharedImpl1->GetAddress());

    sharedImpl0->SetCount(1);

    ASSERT_EQUAL(sharedImpl0->GetCount(), 1);
    ASSERT_EQUAL(sharedImpl1->GetCount(), 1);
    ASSERT_EQUAL(sharedImpl0->GetAddress(), sharedImpl1->GetAddress());

    const auto sharedImpl2 = sharedImpl1;

    ASSERT_EQUAL((*sharedImpl2).GetCount(), 1);
    ASSERT_EQUAL(sharedImpl2->GetAddress(), sharedImpl1->GetAddress());
}

void CoreTools::SharedImplTesting::UseFactoryTest()
{
    constexpr auto count = 12;
    TestingType sharedImpl0{ ImplCreateUseFactory::Default, count };

    ASSERT_EQUAL(sharedImpl0->GetCount(), count);

    auto sharedImpl1 = sharedImpl0;

    ASSERT_EQUAL(sharedImpl1->GetCount(), count);
    ASSERT_EQUAL(sharedImpl0->GetAddress(), sharedImpl1->GetAddress());

    sharedImpl0->SetCount(1);

    ASSERT_EQUAL(sharedImpl0->GetCount(), 1);
    ASSERT_EQUAL(sharedImpl1->GetCount(), 1);
    ASSERT_EQUAL(sharedImpl0->GetAddress(), sharedImpl1->GetAddress());
}

void CoreTools::SharedImplTesting::UseUseDefaultConstructionTest()
{
    TestingType sharedImpl0{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_EQUAL(sharedImpl0->GetCount(), 0);

    auto sharedImpl1 = sharedImpl0;

    ASSERT_EQUAL(sharedImpl1->GetCount(), 0);
    ASSERT_EQUAL(sharedImpl0->GetAddress(), sharedImpl1->GetAddress());

    sharedImpl0->SetCount(1);

    ASSERT_EQUAL(sharedImpl0->GetCount(), 1);
    ASSERT_EQUAL(sharedImpl1->GetCount(), 1);
    ASSERT_EQUAL(sharedImpl0->GetAddress(), sharedImpl1->GetAddress());
}
