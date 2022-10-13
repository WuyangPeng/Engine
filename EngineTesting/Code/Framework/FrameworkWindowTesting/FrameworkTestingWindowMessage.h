///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 12:00)

#ifndef FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
#define FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuiteDetail.h"

namespace Framework
{
    class FrameworkTestingWindowMessage final : public WindowMessageUnitTestSuite
    {
    public:
        using ClassType = FrameworkTestingWindowMessage;
        using ParentType = WindowMessageUnitTestSuite;

    public:
        FrameworkTestingWindowMessage(int64_t delta, const Framework::EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() final;

        void AddWindowCreateSuite();
        void AddWindowProcessSuite();
        void AddWindowRegisterSuite();
        void AddApplicationSuite();
    };

    using FrameworkHandle = WindowProcessHandle<FrameworkTestingWindowMessage>;
}

#endif  // FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
