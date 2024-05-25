/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 10:21)

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
    TestingType nonCopyImpl{ count };
    ASSERT_EQUAL((*nonCopyImpl).GetCount(), count);

    nonCopyImpl->SetCount(modify);
    ASSERT_EQUAL(nonCopyImpl->GetCount(), modify);
}

void CoreTools::NonCopyImplTesting::UseFactoryTest()
{
    TestingType nonCopyImpl{ ImplCreateUseFactory::Default, count };
    ASSERT_EQUAL(nonCopyImpl->GetCount(), count);

    nonCopyImpl->SetCount(modify);
    ASSERT_EQUAL(nonCopyImpl->GetCount(), modify);
}

void CoreTools::NonCopyImplTesting::UseUseDefaultConstructionTest()
{
    const TestingType nonCopyImpl0{ ImplCreateUseDefaultConstruction::Default };
    ASSERT_EQUAL((*nonCopyImpl0).GetCount(), 0);

    TestingType nonCopyImpl1{ ImplCreateUseDefaultConstruction::Default };
    ASSERT_EQUAL((*nonCopyImpl1).GetCount(), 0);

    nonCopyImpl1->SetCount(modify);
    ASSERT_EQUAL(nonCopyImpl1->GetCount(), modify);
}
