///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:23)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WaitForEventTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForEventTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForEventTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WaitEventTest();
        void WaitForAutoEventTest0(WindowsHandle eventHandle);
        void WaitForAutoEventTest1(WindowsHandle eventHandle);
        void WaitForAutoEventTest2(WindowsHandle eventHandle);
        void WaitForAutoEventTest3(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H