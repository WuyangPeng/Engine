///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.7 (2023/04/25 16:32)

#ifndef CORE_TOOLS_THREADING_SUITE_NULL_MUTEX_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_NULL_MUTEX_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NullMutexTesting final : public UnitTest
    {
    public:
        using ClassType = NullMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit NullMutexTesting(const OStreamShared& stream);

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

        // �ݹ����
        void CreateRecursionTestHolder();

        // ���߳����ɹ�����
        void CreateLockingSuccessThread();
        void CreateThread(Function function);
        void MultiThreadingSuccessCallBack();
        void StaticValueTest();

        // ���߳���ʧ�ܲ���
        void CreateLockingFailureThread();
        void MultiThreadingFailureCallBack();
        void CreateFailureCallBackHolder();
        void TryLockTest();

    private:
        Mutex nullMutex;
        DllMutex nullDllMutex;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_NULL_MUTEX_TESTING_H