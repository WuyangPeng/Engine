/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 15:18)

#ifndef CORE_TOOLS_THREADING_SUITE_BOOST_MUTEX_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_BOOST_MUTEX_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class BoostMutexTesting final : public UnitTest
    {
    public:
        using ClassType = BoostMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit BoostMutexTesting(const OStreamShared& stream);

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

        /// 递归测试
        void CreateRecursionTestHolder();

        /// 多线程锁成功测试
        void CreateLockingSuccessThread();
        void CreateThread(Function function);
        void MultiThreadingSuccessCallBack();
        void StaticValueTest();

        /// 多线程锁失败测试
        void CreateLockingFailureThread();
        void MultiThreadingFailureCallBack();
        void CreateFailureCallBackHolder();
        void TryLockFailureTest();

    private:
        Mutex boostMutex;
        DllMutex boostDllMutex;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_BOOST_MUTEX_TESTING_H