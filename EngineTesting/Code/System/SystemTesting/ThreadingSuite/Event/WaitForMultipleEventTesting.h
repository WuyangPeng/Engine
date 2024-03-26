/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:00)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H

#include "EventTestingBase.h"
#include "System/Helper/PragmaWarning/Thread.h"

namespace System
{
    class WaitForMultipleEventTesting final : public EventTestingBase
    {
    public:
        using ClassType = WaitForMultipleEventTesting;
        using ParentType = EventTestingBase;

    public:
        explicit WaitForMultipleEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WaitMultipleObjectsTest();

        void WaitForManualEventTest0(const Container& eventHandle);
        void WaitForManualEventTest1(const Container& eventHandle);
        void WaitForManualEventTest2(const Container& eventHandle);
        void WaitForManualEventTest(const Container& eventHandles);
        NODISCARD Container GetEventHandle();
        void CreateThread(const Container& eventHandles, boost::thread_group& threadGroup);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H