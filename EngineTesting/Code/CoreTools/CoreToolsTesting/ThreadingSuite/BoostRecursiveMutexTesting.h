///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 15:53)

#ifndef CORE_TOOLS_THREADING_SUITE_BOOST_RECURSIVE_MUTEX_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_BOOST_RECURSIVE_MUTEX_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BoostRecursiveMutexTesting final : public UnitTest
    {
    public:
        using ClassType = BoostRecursiveMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit BoostRecursiveMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

    private:
        using Function = void (ClassType::*)();

        void RecursionTest();
        void MultithreadingLockingSuccessTest();
        void MultithreadingLockingFailureTest();

        // 递归测试
        void CreateRecursionTestHolder();

        // 多线程锁成功测试
        void CreateLockingSuccessThread();
        void CreateThread(Function function);
        void MultithreadingSuccessCallBack();
        void StaticValueTest();

        // 多线程锁失败测试
        void CreateLockingFailureThread();
        void MultithreadingFailureCallBack();
        void CreateFailureCallBackHolder();
        void TryLockFailureTest();

    private:
        Mutex boostMutex0;
        DllMutex boostMutex1;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_BOOST_RECURSIVE_MUTEX_TESTING_H