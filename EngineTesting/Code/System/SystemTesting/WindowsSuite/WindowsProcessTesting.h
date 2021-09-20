///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.6 (2021/07/06 23:35)

#ifndef SYSTEM_WINDOWS_SUITE_WINDOWS_PROCESS_TESTING_H
#define SYSTEM_WINDOWS_SUITE_WINDOWS_PROCESS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WindowsProcessTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WindowsProcessTesting;
        using ParentType = UnitTest;

    public:
        explicit WindowsProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest() noexcept;
    };
}

#endif  // SYSTEM_WINDOWS_SUITE_WINDOWS_PROCESS_TESTING_H