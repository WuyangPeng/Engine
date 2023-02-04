///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 19:23)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H

#include "ThreadTestingBase.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Using/ThreadUsing.h"

#include <vector>

namespace System
{
    class WaitForMultipleThreadTesting final : public ThreadTestingBase
    {
    public:
        using ClassType = WaitForMultipleThreadTesting;
        using ParentType = ThreadTestingBase;

    public:
        explicit WaitForMultipleThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<System::ThreadHandle>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WaitMultipleObjectsTest();

        void WaitMultipleObjects0Test();
        void WaitMultipleObjects1Test();
        void WaitMultipleObjects2Test();

        NODISCARD Container CreateThread();
        void CloseThread(const Container& threadHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_THREAD_TESTING_H