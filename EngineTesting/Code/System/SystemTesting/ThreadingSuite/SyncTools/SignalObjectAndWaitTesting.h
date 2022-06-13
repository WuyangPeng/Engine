///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:36)

#ifndef SYSTEM_THREADING_SUITE_SIGNAL_OBJECT_AND_WAIT_TESTING_H
#define SYSTEM_THREADING_SUITE_SIGNAL_OBJECT_AND_WAIT_TESTING_H

#include "System/Threading/Using/MutexUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class SignalObjectAndWaitTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SignalObjectAndWaitTesting;
        using ParentType = UnitTest;

    public:
        explicit SignalObjectAndWaitTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignalObjectAndWaitTest();
        void WaitForEventTest(WindowsHandle eventHandle);
        void WaitForMutexTest(WindowsHandle eventHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_SIGNAL_OBJECT_AND_WAIT_TESTING_H