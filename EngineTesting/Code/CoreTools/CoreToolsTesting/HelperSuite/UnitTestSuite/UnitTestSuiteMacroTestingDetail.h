///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/24 16:22)

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