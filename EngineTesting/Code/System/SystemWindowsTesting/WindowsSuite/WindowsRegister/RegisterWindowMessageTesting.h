///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.4 (2022/11/05 19:44)

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