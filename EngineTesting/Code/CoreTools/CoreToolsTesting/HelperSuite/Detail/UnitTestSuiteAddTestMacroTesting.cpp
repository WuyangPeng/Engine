/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 21:08)

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
