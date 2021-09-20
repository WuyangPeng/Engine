///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/28 11:36)

#ifndef SYSTEM_THREADING_SUITE_THREAD_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_MUTEX_TESTING_H

#include "System/Threading/Using/MutexUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class ThreadMutexTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void TrylockTest();
        void WaitForMutexTest(WindowsHandle mutexHandle);
        void TrylockSuccessTest(WindowsHandle mutexHandle);
        void TrylockTimeoutTest(WindowsHandle mutexHandle);

    private:
        int threadSum;
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_MUTEX_TESTING_H