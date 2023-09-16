///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:32)

#ifndef SYSTEM_THREADING_SUITE_P_THREAD_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_P_THREAD_MUTEX_TESTING_H

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
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void TryLockTest();

        void WaitForMutexTest(PThreadMutexT* mutex);
        void TryLockTimeoutTest(PThreadMutexT* mutex);
        void TryLockSuccessTest(PThreadMutexT* mutex);

        void PThreadMutexInitTest(PThreadMutexAttrT& attribute, PThreadMutexT& mutex);
        void CreateThread(PThreadMutexT& mutex);
        void PThreadMutexDestroyTest(PThreadMutexT& mutex, PThreadMutexAttrT& attribute);
        void TryLockTimeoutThreadTest(PThreadMutexT& mutex);
        void TryLockSuccessThreadTest(PThreadMutexT& mutex);

    private:
        int threadSum;
    };
}

#endif  // SYSTEM_THREADING_SUITE_P_THREAD_MUTEX_TESTING_H