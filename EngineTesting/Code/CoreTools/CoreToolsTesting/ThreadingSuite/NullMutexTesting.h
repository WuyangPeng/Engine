///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/02 14:29)

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
        void DoRunUnitTest() final;
        void MainTest();

    private:
        using Function = void (ClassType::*)();

    private:
        void RecursionTest();
        void MultithreadingLockingSuccessTest();
        void MultithreadingLockingFailureTest();

        // �ݹ����
        void CreateRecursionTestHolder();

        // ���߳����ɹ�����
        void CreateLockingSuccessThread();
        void CreateThread(Function function);
        void MultithreadingSuccessCallBack();
        void StaticValueTest();

        // ���߳���ʧ�ܲ���
        void CreateLockingFailureThread();
        void MultithreadingFailureCallBack();
        void CreateFailureCallBackHolder();
        void TryLockTest();

    private:
        Mutex nullMutex0;
        DllMutex nullMutex1;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_NULL_MUTEX_TESTING_H