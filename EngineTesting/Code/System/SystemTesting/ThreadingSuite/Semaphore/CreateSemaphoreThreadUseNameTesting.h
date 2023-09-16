///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:36)

#ifndef SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_USE_NAME_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_USE_NAME_TESTING_H

#include "SemaphoreTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class CreateSemaphoreThreadUseNameTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = CreateSemaphoreThreadUseNameTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit CreateSemaphoreThreadUseNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void WaitForSemaphoreTest(WindowsHandle semaphoreHandle);
        void CreateThread(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_USE_NAME_TESTING_H