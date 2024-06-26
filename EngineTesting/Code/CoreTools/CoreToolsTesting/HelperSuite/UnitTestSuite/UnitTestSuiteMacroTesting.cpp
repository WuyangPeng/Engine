/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/05/06 19:58)

#include "UnitTestSuiteMacroTestingDetail.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/UnitTestSuiteAddTestMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UnitTestSuiteMacroTesting::UnitTestSuiteMacroTesting(const OStreamShared& stream, bool isPrintRun)
    : ParentType{ stream },
      unitTestSuiteMacroSuite{ "��Ԫ���Ժ����", GetStream(), isPrintRun },
      isPrintRun{ isPrintRun }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteMacroTesting)

void CoreTools::UnitTestSuiteMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestSuiteMacroTesting::MainTest()
{
    ADD_TEST(unitTestSuiteMacroSuite, UnitTestSuiteAddTestMacroTesting);
    ADD_TEST_USE_PARAMETER_1(unitTestSuiteMacroSuite, UnitTestSuiteAddTestMacroTesting, isPrintRun);
    ADD_TEST_USE_PARAMETER_2(unitTestSuiteMacroSuite, UnitTestSuiteAddTestMacroTesting, isPrintRun, 0);
}
