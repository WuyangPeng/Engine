///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/28 13:12)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MUTEX_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class WaitForMutexTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WaitMutexTest();

        void WaitForMutexTest0(WindowsHandle mutexHandle);
        void WaitForMutexTest1(WindowsHandle mutexHandle);
        void WaitForMutexTest2(WindowsHandle mutexHandle);
        void WaitForMutexTest3(WindowsHandle mutexHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MUTEX_TESTING_H