/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/16 15:18)

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

        /// �ݹ���ԣ����Խ��Ϊʧ��
        void CreateRecursionTestFailureHolder();

        /// ���߳����ɹ�����
        void CreateLockingSuccessThread();
        void CreateThread(Function function);
        void MultiThreadingSuccessCallBack();
        void StaticValueTest();

        /// ���߳���ʧ�ܲ���
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