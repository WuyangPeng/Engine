///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 15:52)

#ifndef SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ManualEventThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ManualEventThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit ManualEventThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ManualEventThreadTest();
        void ManualResetEventThreadTest();
        void AllEventThreadTest();

        void WaitForManualEventTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H