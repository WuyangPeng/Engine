///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.3 (2021/09/02 14:15)

#ifndef CORE_TOOLS_THREADING_SUITE_EVENT_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_EVENT_TESTING_H

#include "CoreTools/Threading/Event.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class EventTesting final : public UnitTest
    {
    public:
        using ClassType = EventTesting;
        using ParentType = UnitTest;

    public:
        explicit EventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ManualResetTrueCreateThreadTest();
        void ManualResetFalseCreateThreadTest();

        void Thread0();
        void Thread1();
        void Thread2();
        void Thread3();

        void Thread4();
        void Thread5();
        void Thread6();

    private:
        Event manualResetTrueEvent;
        Event manualResetFlaseEvent;
        int testValue;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_EVENT_TESTING_H