///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 0:05)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H

#include "EventTestingBase.h"

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
        void DoRunUnitTest() final;
        void MainTest();

        void WaitMultipleObjectsTest();

        void WaitForManualEventTest0(const Container& eventHandle);
        void WaitForManualEventTest1(const Container& eventHandle);
        void WaitForManualEventTest2(const Container& eventHandle);
        void WaitForManualEventTest(const Container& eventHandles);
        NODISCARD Container GetEventHandle();
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_EVENT_TESTING_H