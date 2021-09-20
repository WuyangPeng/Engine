///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 20:16)

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