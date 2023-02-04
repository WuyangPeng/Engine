///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/01/31 23:49)

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
        void DoRunUnitTest() final;
        void MainTest();

        void EventThreadTest();

        void WaitForEventTest(WindowsHandle eventHandle);
        void DoEventThreadTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_RESET_EVENT_TESTING_H