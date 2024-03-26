/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:20)

#ifndef SYSTEM_WINDOW_SUITE_WINDOW_REGISTER_TESTING_H
#define SYSTEM_WINDOW_SUITE_WINDOW_REGISTER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    /// SystemWindowsTesting��windows�����Ĳ��ԡ�
    class WindowsRegisterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsRegisterTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsRegisterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest() const noexcept;
    };
}

#endif  // SYSTEM_WINDOW_SUITE_WINDOW_REGISTER_TESTING_H