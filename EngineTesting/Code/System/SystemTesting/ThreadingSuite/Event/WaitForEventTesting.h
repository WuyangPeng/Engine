///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 18:22)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_EVENT_TESTING_H

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