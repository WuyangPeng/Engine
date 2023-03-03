///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/03/01 18:03)

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
        void TryLockFailureTest();

    private:
        DllMutex dllCriticalSection;
        Mutex criticalSection;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_CRITICAL_SECTION_TESTING_H