///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 20:04)

#ifndef SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class WaitMultipleSemaphoreTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitMultipleSemaphoreTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitMultipleSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void WaitForSemaphoreTest0(const Container& semaphoreHandle);
        void WaitForSemaphoreTest1(const Container& semaphoreHandle);
        void WaitForSemaphoreTest2(const Container& semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H