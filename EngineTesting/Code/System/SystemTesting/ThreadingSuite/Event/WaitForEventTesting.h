///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:29)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H

#include "EventTestingBase.h"

namespace System
{
    class WaitForEventTesting final : public EventTestingBase
    {
    public:
        using ClassType = WaitForEventTesting;
        using ParentType = EventTestingBase;

    public:
        explicit WaitForEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WaitEventTest();

        void DoWaitEventTest(WindowsHandle eventHandle);
        void WaitForAutoEventTest0(WindowsHandle eventHandle);
        void WaitForAutoEventTest1(WindowsHandle eventHandle);
        void WaitForAutoEventTest2(WindowsHandle eventHandle);
        void WaitForAutoEventTest3(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H