///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 11:45)

#ifndef SYSTEM_THREADING_SUITE_PTHREAD_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_PTHREAD_MUTEX_TESTING_H

#include "MutexTestingBase.h"
#include "System/Threading/Using/MutexUsing.h"

namespace System
{
    class PThreadMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = PThreadMutexTesting;
        using ParentType = MutexTestingBase;

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

        void PthreadMutexInitTest(PthreadMutexattrT& attribute, PthreadMutexT& mutex);
        void CreateThread(PthreadMutexT& mutex);
        void PthreadMutexDestroyTest(PthreadMutexT& mutex, PthreadMutexattrT& attribute);
        void TrylockTimeoutThreadTest(PthreadMutexT& mutex);
        void TrylockSuccessThreadTest(PthreadMutexT& mutex);

    private:
        int threadSum;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PTHREAD_MUTEX_TESTING_H