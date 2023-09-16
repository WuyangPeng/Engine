///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/31 14:36)

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

        using EnvironmentDirectory = Framework::EnvironmentDirectory;

    public:
        TestingWindowsMessage(int64_t delta, const EnvironmentDirectory& environmentDirectory);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void InitSuite() override;

        void AddSystemOutputSuite();

        NODISCARD Suite GetMessageBoxSelectionSuite();

        void AddDynamicLinkSuite();

        NODISCARD Suite GetLoadResourceToolsSuite();
        NODISCARD Suite GetEnumResourceToolsSuite();

        void AddOpenGLSuite();
        void AddWindowsSuite();

        NODISCARD Suite GetWindowsCreateSuite();
        NODISCARD Suite GetWindowsProcessSuite();
        NODISCARD Suite GetWindowsRegisterSuite();
        NODISCARD Suite GetWindowsSystemSuite();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_TESTING_WINDOWS_MESSAGE_H
