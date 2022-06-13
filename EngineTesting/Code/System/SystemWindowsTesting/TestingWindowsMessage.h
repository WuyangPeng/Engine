///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/16 14:28)

#ifndef SYSTEM_WINDOWS_TESTING_TESTING_WINDOWS_MESSAGE_H
#define SYSTEM_WINDOWS_TESTING_TESTING_WINDOWS_MESSAGE_H

#include "Framework/WindowProcess/WindowMessageUnitTestSuite.h"

namespace System
{
    class TestingWindowsMessage final : public Framework::WindowMessageUnitTestSuite
    {
    public:
        using ClassType = TestingWindowsMessage;
        using ParentType = WindowMessageUnitTestSuite;

    public:
        explicit TestingWindowsMessage(int64_t delta);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() final;

        void AddSystemOutputSuite();

        NODISCARD Suite GetMessageBoxSelectionSuite();

        void AddDynamicLinkSuite();

        NODISCARD Suite GetLoadResourceToolsSuite();
        NODISCARD Suite GetEnumResourceToolsSuite();

        void AddOpenGLSuite();
        void AddWindowsSuite();

        NODISCARD Suite GetWindowsProcessSuite();
        NODISCARD Suite GetWindowsRegisterSuite();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_TESTING_WINDOWS_MESSAGE_H
