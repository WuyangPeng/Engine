/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/13 17:16)

#ifndef SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_ACTIVE_WINDOW_TESTING_H
#define SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_ACTIVE_WINDOW_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GetActiveWindowTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GetActiveWindowTesting;
        using ParentType = UnitTest;

    public:
        explicit GetActiveWindowTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void GetActiveWindowTest() const noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_TESTING_WINDOW_SUITE_GET_ACTIVE_WINDOW_TESTING_H