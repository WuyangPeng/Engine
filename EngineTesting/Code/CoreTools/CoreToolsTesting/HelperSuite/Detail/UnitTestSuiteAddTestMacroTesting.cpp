///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.2 (2023/02/16 20:59)

#include "UnitTestSuiteAddTestMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

CoreTools::UnitTestSuiteAddTestMacroTesting::UnitTestSuiteAddTestMacroTesting(const OStreamShared& stream, bool isPrintRun, int count)
    : ParentType{ stream }, isPrintRun{ isPrintRun }, count{ count }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::UnitTestSuiteAddTestMacroTesting::UnitTestSuiteAddTestMacroTesting(const OStreamShared& stream, bool isPrintRun)
    : UnitTestSuiteAddTestMacroTesting{ stream, isPrintRun, 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CoreTools::UnitTestSuiteAddTestMacroTesting::UnitTestSuiteAddTestMacroTesting(const OStreamShared& stream)
    : UnitTestSuiteAddTestMacroTesting{ stream, true }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestSuiteAddTestMacroTesting)

void CoreTools::UnitTestSuiteAddTestMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void CoreTools::UnitTestSuiteAddTestMacroTesting::MainTest() noexcept
{
}
