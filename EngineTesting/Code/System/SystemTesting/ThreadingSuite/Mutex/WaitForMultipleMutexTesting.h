///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:31)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_MUTEX_TESTING_H

#include "System/Windows/Using/WindowsUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <vector>

namespace System
{
    class WaitForMultipleMutexTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = WaitForMultipleMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit WaitForMultipleMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void WaitMultipleObjectsTest();

        void WaitForMutexTest0(const Container& mutexHandle);
        void WaitForMutexTest1(const Container& mutexHandle);
        void WaitForMutexTest2(const Container& mutexHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_MUTEX_TESTING_H