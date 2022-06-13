///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:36)

#ifndef SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_USE_NAME_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_USE_NAME_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class CreateSemaphoreThreadUseNameTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateSemaphoreThreadUseNameTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateSemaphoreThreadUseNameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void WaitForSemaphoreTest(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_USE_NAME_TESTING_H