///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/03/01 18:06)

#ifndef CORE_TOOLS_THREADING_SUITE_STD_MUTEX_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_STD_MUTEX_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StdMutexTesting final : public UnitTest
    {
    public:
        using ClassType = StdMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit StdMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

    private:
        using Function = void (ClassType::*)();

    private:
        void RecursionTest();
        void MultiThreadingLockingSuccessTest();
        void MultiThreadingLockingFailureTest();

        // 递归测试，测试结果为失败
        void CreateRecursionTestFailureHolder();

        // 多线程锁成功测试
        void CreateLockingSuccessThread();
        void CreateThread(Function function);
        void MultiThreadingSuccessCallBack();
        void StaticValueTest();

        // 多线程锁失败测试
        void CreateLockingFailureThread();
        void MultiThreadingFailureCallBack();
        void CreateFailureCallBackHolder();
        void TryLockFailureTest();

    private:
        Mutex stdMutex;
        DllMutex stdDllMutex;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_STD_MUTEX_TESTING_H