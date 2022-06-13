///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 11:37)

#include "UnitTestSuiteMacroCompleteUseTestingTypeTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/UnitTestSuiteMacroCompleteUseTestingType.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(CoreTools, UnitTestSuiteMacroCompleteUseTestingType)

void CoreTools::UnitTestSuiteMacroCompleteUseTestingTypeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(TypedefTest);
}

void CoreTools::UnitTestSuiteMacroCompleteUseTestingTypeTesting::TypedefTest() noexcept
{
    const TestingType unitTestSuiteMacroCompleteUseTestingType{};
}
