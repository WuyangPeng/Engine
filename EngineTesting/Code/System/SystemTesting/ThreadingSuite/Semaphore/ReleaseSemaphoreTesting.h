///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 15:43)

#ifndef SYSTEM_THREADING_SUITE_RELEASE_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_RELEASE_SEMAPHORE_TESTING_H

#include "SemaphoreTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class ReleaseSemaphoreTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = ReleaseSemaphoreTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit ReleaseSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void InitReleaseTest();

        void WaitForSemaphoreTest(WindowsHandle semaphoreHandle);
        void CreateThread(WindowsHandle semaphoreHandle);
        void DoInitReleaseTest(WindowsHandle semaphoreHandle, WindowsLong maxSemphoreCount);
    };
}

#endif  // SYSTEM_THREADING_SUITE_RELEASE_SEMAPHORE_TESTING_H