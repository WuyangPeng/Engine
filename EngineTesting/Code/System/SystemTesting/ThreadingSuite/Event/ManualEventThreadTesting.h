///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/01/31 23:25)

#ifndef SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H

#include "EventTestingBase.h"

namespace System
{
    class ManualEventThreadTesting final : public EventTestingBase
    {
    public:
        using ClassType = ManualEventThreadTesting;
        using ParentType = EventTestingBase;

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
        void DoManualEventThreadTest(WindowsHandle eventHandle);
        void DoManualResetEventThreadTest(WindowsHandle eventHandle);
        void DoAllEventThreadTest(WindowsHandle eventHandle);

        void CreateThread(boost::thread_group& threadGroup, WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_MANUAL_EVENT_THREAD_TESTING_H