///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/28 16:36)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_DETAIL_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_DETAIL_H

#include "CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename TestType, typename... Types>
void CoreTools::CMainFunctionTestingHelper::AddTest(Suite& aSuite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

    AddTest(suiteName, aSuite, testName, unitTest);
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_DETAIL_H