///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:36)

#ifndef SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H

#include "SemaphoreTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <vector>

namespace System
{
    class WaitMultipleSemaphoreTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = WaitMultipleSemaphoreTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit WaitMultipleSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void WaitForSemaphoreTest0(const Container& semaphoreHandles);
        void WaitForSemaphoreTest1(const Container& semaphoreHandles);
        void WaitForSemaphoreTest2(const Container& semaphoreHandles);

        void CreateSemaphoreTest(Container& semaphoreHandles);
        void CreateThread(const Container& semaphoreHandles);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H