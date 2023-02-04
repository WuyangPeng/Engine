///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/02 21:05)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_WINDOW_MESSAGE_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_WINDOW_MESSAGE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class RegisterWindowMessageTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RegisterWindowMessageTesting;
        using ParentType = UnitTest;

    public:
        explicit RegisterWindowMessageTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RegisterWindowMessageTest();
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_WINDOW_MESSAGE_TESTING_H