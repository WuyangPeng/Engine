///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:36)

#ifndef SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WaitSemaphoreTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitSemaphoreTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void WaitForSemaphoreTest0(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest1(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest2(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest3(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H