///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:23)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_THREAD_TESTING_H

#include "ThreadTestingBase.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
    class WaitForThreadTesting final : public ThreadTestingBase
    {
    public:
        using ClassType = WaitForThreadTesting;
        using ParentType = ThreadTestingBase;

    public:
        explicit WaitForThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WaitThreadTest();
        void WaitThread0Test();
        void WaitThread1Test();
        void WaitThread2Test();
        void WaitThread3Test();

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_THREAD_TESTING_H