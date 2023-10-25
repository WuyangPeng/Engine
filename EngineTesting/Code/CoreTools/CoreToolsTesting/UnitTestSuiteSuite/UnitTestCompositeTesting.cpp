///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/10/25 14:28)

#include "UnitTestCompositeTesting.h"
#include "System/Windows/Engineering.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UnitTestCompositeTesting::UnitTestCompositeTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestCompositeTesting)

void CoreTools::UnitTestCompositeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestCompositeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(UnitTestCompositeTest);
    ASSERT_THROW_EXCEPTION_0(AddUnitTestExceptionTest);
    ASSERT_THROW_EXCEPTION_0(ClearUnitTestCollectionTest);
}

void CoreTools::UnitTestCompositeTesting::UnitTestCompositeTest()
{
    const OStreamShared oStreamShared{ true };

    UnitTestCompositeTesting unitTestCompositeTesting{ oStreamShared };

    unitTestCompositeTesting.SetTestLoopCount(100);

    unitTestCompositeTesting.SetRandomSeed(100);
    ASSERT_EQUAL(unitTestCompositeTesting.GetEngineRandomSeed(), 100u + System::GetEngineeringOffsetValue());
}

void CoreTools::UnitTestCompositeTesting::AddUnitTestExceptionTest()
{
    const OStreamShared oStreamShared{ true };

    UnitTestCompositeTesting unitTestCompositeTesting{ oStreamShared };

    unitTestCompositeTesting.AddUnitTest(std::make_shared<ClassType>(oStreamShared));
}

void CoreTools::UnitTestCompositeTesting::ClearUnitTestCollectionTest()
{
    const OStreamShared oStreamShared{ true };

    UnitTestCompositeTesting unitTestCompositeTesting{ oStreamShared };

    unitTestCompositeTesting.ClearUnitTestCollection();
}
