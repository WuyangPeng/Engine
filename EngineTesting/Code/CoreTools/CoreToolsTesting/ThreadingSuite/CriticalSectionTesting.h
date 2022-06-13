///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 15:53)

#ifndef CORE_TOOLS_THREADING_SUITE_CRITICAL_SECTION_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_CRITICAL_SECTION_TESTING_H

#include "CoreTools/Threading/Threading.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class CriticalSectionTesting final : public UnitTest
    {
    public:
        using ClassType = CriticalSectionTesting;
        using ParentType = UnitTest;

    public:
        explicit CriticalSectionTesting(const OStreamShared& stream);

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
        void TryLockFailureTest();

    private:
        DllMutex criticalSection0;
        Mutex criticalSection1;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_CRITICAL_SECTION_TESTING_H