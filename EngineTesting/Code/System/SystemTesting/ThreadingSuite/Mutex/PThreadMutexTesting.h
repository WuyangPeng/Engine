///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/04/28 15:48)

#ifndef SYSTEM_THREADING_SUITE_PTHREAD_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_PTHREAD_MUTEX_TESTING_H

#include "System/Threading/Using/MutexUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class PThreadMutexTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PThreadMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit PThreadMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();
        void TrylockTest();

        void WaitForMutexTest(PthreadMutexT* mutex);
        void TrylockTimeoutTest(PthreadMutexT* mutex);
        void TrylockSuccessTest(PthreadMutexT* mutex);

    private:
        int threadSum;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PTHREAD_MUTEX_TESTING_H