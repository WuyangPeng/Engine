///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:31)

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