///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:29)

#ifndef SYSTEM_THREADING_SUITE_RESET_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_RESET_EVENT_TESTING_H

#include "EventTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class ResetEventTesting final : public EventTestingBase
    {
    public:
        using ClassType = ResetEventTesting;
        using ParentType = EventTestingBase;

    public:
        explicit ResetEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void EventThreadTest();

        void WaitForEventTest(WindowsHandle eventHandle);
        void DoEventThreadTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_RESET_EVENT_TESTING_H