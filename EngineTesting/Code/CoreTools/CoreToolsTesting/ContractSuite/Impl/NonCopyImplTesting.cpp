///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 15:34)

#include "NonCopyImplTesting.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Contract/NonCopyImplDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::NonCopyImplTesting::NonCopyImplTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, NonCopyImplTesting)

void CoreTools::NonCopyImplTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::NonCopyImplTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseFactoryTest);
    ASSERT_NOT_THROW_EXCEPTION_0(UseUseDefaultConstructionTest);
}

void CoreTools::NonCopyImplTesting::DefaultTest()
{
    constexpr auto count = 10;
    TestingType nonCopyImpl{ count };

    ASSERT_EQUAL((*nonCopyImpl).GetCount(), count);

    nonCopyImpl->SetCount(1);

    ASSERT_EQUAL(nonCopyImpl->GetCount(), 1);
}

void CoreTools::NonCopyImplTesting::UseFactoryTest()
{
    constexpr auto count = 10;
    TestingType nonCopyImpl{ ImplCreateUseFactory::Default, count };

    ASSERT_EQUAL(nonCopyImpl->GetCount(), count);

    nonCopyImpl->SetCount(1);

    ASSERT_EQUAL(nonCopyImpl->GetCount(), 1);
}

void CoreTools::NonCopyImplTesting::UseUseDefaultConstructionTest()
{
    const TestingType nonCopyImpl0{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_EQUAL((*nonCopyImpl0).GetCount(), 0);

    TestingType nonCopyImpl1{ ImplCreateUseDefaultConstruction::Default };

    ASSERT_EQUAL((*nonCopyImpl1).GetCount(), 0);

    nonCopyImpl1->SetCount(1);

    ASSERT_EQUAL(nonCopyImpl1->GetCount(), 1);
}
