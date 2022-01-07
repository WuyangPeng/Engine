///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/29 22:08)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_DETAIL_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_DETAIL_H

#include "CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename TestType, typename... Types>
void CoreTools::CMainFunctionTestingHelper::AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

    AddTest(suiteName, suite, testName, unitTest);
}

#endif  // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_DETAIL_H