///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 0:04)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_DETAIL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_DETAIL_H

#include "AndroidCallBackUnitTestSuite.h"
#include "CoreTools/Helper/ClassInvariant/FrameworkClassInvariantMacro.h"

template <typename TestType, typename... Types>
void Framework::AndroidCallBackUnitTestSuite::AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
{
    FRAMEWORK_CLASS_IS_VALID_1;

    auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

    AddTest(suiteName, suite, testName, unitTest);
}

#endif  // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_DETAIL_H
