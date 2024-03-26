/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:04)

#ifndef SYSTEM_THREADING_SUITE_THREAD_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_MUTEX_TESTING_H

#include "MutexTestingBase.h"

namespace System
{
    class ThreadMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = ThreadMutexTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit ThreadMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void TryLockTest();

        void WaitForMutexTest(WindowsHandle mutexHandle);
        void TryLockSuccessTest(WindowsHandle mutexHandle);
        void TryLockTimeoutTest(WindowsHandle mutexHandle);
        void DoThreadTest(WindowsHandle mutexHandle);
        void DoTryLockTest(WindowsHandle mutexHandle);

        void CreateThread(WindowsHandle mutexHandle);
        void TryLockSuccessThreadTest(WindowsHandle mutexHandle);
        void TryLockTimeoutThreadTest(WindowsHandle mutexHandle);

    private:
        int threadSum;
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_MUTEX_TESTING_H