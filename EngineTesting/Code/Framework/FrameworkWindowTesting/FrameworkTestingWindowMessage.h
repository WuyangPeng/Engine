///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.3 (2023/08/10 13:46)

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
        FrameworkTestingWindowMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() override;

        void AddWindowCreateSuite();
        void AddWindowProcessSuite();
        void AddWindowRegisterSuite();
        void AddApplicationSuite();
    };

    using FrameworkHandle = WindowProcessHandle<FrameworkTestingWindowMessage>;
}

#endif  // FRAMEWORK_WINDOW_TESTING_FRAMEWORK_TESTING_WINDOW_MESSAGE_H
