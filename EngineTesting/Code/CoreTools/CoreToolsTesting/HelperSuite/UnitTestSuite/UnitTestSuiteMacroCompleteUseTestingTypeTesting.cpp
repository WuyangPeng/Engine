///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/19 11:37)

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
