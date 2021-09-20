///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/10 18:31)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_THREAD_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WaitForThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        bool WaitThreadTest();
        void WaitThread0Test();
        void WaitThread1Test();
        void WaitThread2Test();
        void WaitThread3Test();

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_THREAD_TESTING_H