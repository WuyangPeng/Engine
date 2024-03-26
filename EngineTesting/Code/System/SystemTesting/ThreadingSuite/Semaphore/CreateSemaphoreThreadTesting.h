/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:06)

#ifndef SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_TESTING_H

#include "SemaphoreTestingBase.h"

namespace System
{
    class CreateSemaphoreThreadTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = CreateSemaphoreThreadTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit CreateSemaphoreThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();
        void WaitForSemaphoreTest(WindowsHandle semaphoreHandle);
        void CreateThread(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_SEMAPHORE_THREAD_TESTING_H