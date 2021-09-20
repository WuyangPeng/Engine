///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/07 19:48)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_CLASS_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_CLASS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class RegisterClassTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RegisterClassTesting;
        using ParentType = UnitTest;

    public:
        explicit RegisterClassTesting(const OStreamShared& stream, WindowsHInstance instance);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void RegisterClassTest();

    private:
        WindowsHInstance instance;
        int count;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOWS_SUITE_REGISTER_CLASS_TESTING_H