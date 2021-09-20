///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/27 14:53)

#ifndef SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H

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
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void WaitForSemaphoreTest0(const std::vector<WindowsHandle>& semaphoreHandle);
        void WaitForSemaphoreTest1(const std::vector<WindowsHandle>& semaphoreHandle);
        void WaitForSemaphoreTest2(const std::vector<WindowsHandle>& semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_MULTIPLE_SEMAPHORE_TESTING_H