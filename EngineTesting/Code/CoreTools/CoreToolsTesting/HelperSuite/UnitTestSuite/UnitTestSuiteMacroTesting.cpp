///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 11:43)

#include "UnitTestSuiteMacroTesting.h"
#include "CoreTools/CoreToolsTesting/HelperSuite/Detail/UnitTestSuiteAddTestMacroTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

using std::make_shared;
using std::string;

CoreTools::UnitTestSuiteMacroTesting::UnitTestSuiteMacroTesting(const OStreamShared& stream, bool isPrintRun)
    : ParentType{ stream }, unitTestSuiteMacroSuite{ "单元测试宏测试", GetStream(), isPrintRun }, isPrintRun{ isPrintRun }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteMacroTesting)

void CoreTools::UnitTestSuiteMacroTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

template <typename TestType, typename... Types>
void CoreTools::UnitTestSuiteMacroTesting::AddTest(Suite& suite, MAYBE_UNUSED const string& suiteName, MAYBE_UNUSED const string& testName, Types&&... args)
{
    auto unitTest = std::make_shared<TestType>(GetStream(), std::forward<Types>(args)...);

    suite.AddTest(unitTest);
}

void CoreTools::UnitTestSuiteMacroTesting::MainTest()
{
    ADD_TEST(unitTestSuiteMacroSuite, UnitTestSuiteAddTestMacroTesting);
    ADD_TEST_USE_PARAMETER_1(unitTestSuiteMacroSuite, UnitTestSuiteAddTestMacroTesting, isPrintRun);
    ADD_TEST_USE_PARAMETER_2(unitTestSuiteMacroSuite, UnitTestSuiteAddTestMacroTesting, isPrintRun, 0);
}
