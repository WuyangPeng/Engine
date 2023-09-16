///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:26)

#ifndef SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H

#include "EventTestingBase.h"
#include "System/Helper/PragmaWarning/Thread.h"

namespace System
{
    class AutoEventThreadTesting final : public EventTestingBase
    {
    public:
        using ClassType = AutoEventThreadTesting;
        using ParentType = EventTestingBase;

    public:
        explicit AutoEventThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AutoEventThreadTest();
        void DefaultEventThreadTest();
        void InitialSetEventThreadTest();

        void WaitForAutoEventTest(WindowsHandle eventHandle);
        void DoAutoEventThreadTest(WindowsHandle eventHandle);
        void DoDefaultEventThreadTest(WindowsHandle eventHandle);
        void DoInitialSetEventThreadTest(WindowsHandle eventHandle);

        void CreateThread(boost::thread_group& threadGroup, WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_AUTO_EVENT_THREAD_TESTING_H