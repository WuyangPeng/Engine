///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/05/07 16:15)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_DETAIL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_DETAIL_H

#include "WindowMessageUnitTestSuite.h"

template <typename TestType, typename... Types>
void Framework::WindowMessageUnitTestSuite::AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
    auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

    AddTest(suiteName, suite, testName, unitTest);
}

#endif  // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_DETAIL_H
