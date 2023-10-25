///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:37)

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