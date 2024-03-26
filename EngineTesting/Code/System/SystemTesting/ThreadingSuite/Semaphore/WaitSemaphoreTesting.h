/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:07)

#ifndef SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H

#include "SemaphoreTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class WaitSemaphoreTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = WaitSemaphoreTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit WaitSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void WaitForSemaphoreTest0(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest1(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest2(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest3(WindowsHandle semaphoreHandle);

        void CreateThread(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H