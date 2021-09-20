///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.1.6 (2021/07/07 19:43)

#ifndef SYSTEM_WINDOW_SUITE_WINDOW_REGISTER_TESTING_H
#define SYSTEM_WINDOW_SUITE_WINDOW_REGISTER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsRegisterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsRegisterTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsRegisterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_WINDOW_SUITE_WINDOW_REGISTER_TESTING_H