///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.1 (2021/08/20 11:40)

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
