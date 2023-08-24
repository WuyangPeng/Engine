///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 10:50)

#ifndef WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
#define WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H

#include "SuiteWindowMessage.h"
#include "Framework/MainFunctionHelper/WindowMainFunctionHelperDetail.h"
#include "Framework/WindowsAPIFrame/WindowsAPIFrameBuildDetail.h"

namespace Framework
{
    using TestingHelperBase = WindowMainFunctionHelper<WindowsAPIFrameBuild, WindowProcessTesting>;

    class TestingHelper final : public TestingHelperBase
    {
    public:
        using ClassType = TestingHelper;
        using ParentType = TestingHelperBase;

    public:
        TestingHelper(WindowsHInstance instance, const char* commandLine, const WindowApplicationInformation& information, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;
    };
}

#endif  // WINDOW_MESSAGE_UNIT_TEST_SUITE_TESTING_TESTING_HELPER_H
