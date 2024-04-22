/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/14 11:39)

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