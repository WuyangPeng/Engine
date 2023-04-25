///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 20:50)

#ifndef CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_DETAIL_H
#define CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_DETAIL_H

#include "UnitTestSuiteMacroTesting.h"
#include "System/Helper/Tools.h"
#include "CoreTools/UnitTestSuite/Suite.h"

template <typename TestType, typename... Types>
void CoreTools::UnitTestSuiteMacroTesting::AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
    System::UnusedFunction(suiteName, testName);

    auto unitTest = std::make_shared<TestType>(GetStream(), std::forward<Types>(args)...);

    suite.AddTest(unitTest);
}

#endif  // CORE_TOOLS_HELPER_SUITE_UNIT_TEST_SUITE_MACRO_TESTING_DETAIL_H