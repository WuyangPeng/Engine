///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 20:02)

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