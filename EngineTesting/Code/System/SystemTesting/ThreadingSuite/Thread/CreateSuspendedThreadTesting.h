///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:38)

#ifndef SYSTEM_THREADING_SUITE_CREATE_SUSPENDED_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_SUSPENDED_THREAD_TESTING_H

#include "ThreadTestingBase.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
    class CreateSuspendedThreadTesting final : public ThreadTestingBase
    {
    public:
        using ClassType = CreateSuspendedThreadTesting;
        using ParentType = ThreadTestingBase;

    public:
        explicit CreateSuspendedThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void DoThreadTest(ThreadHandle threadHandle, WindowsDWord threadId);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_SUSPENDED_THREAD_TESTING_H