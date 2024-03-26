/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:04)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_MUTEX_TESTING_H

#include "MutexTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

#include <vector>

namespace System
{
    class WaitForMultipleMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = WaitForMultipleMutexTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit WaitForMultipleMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Container = std::vector<WindowsHandle>;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WaitMultipleObjectsTest();

        void WaitForMutexTest0(const Container& mutexHandles);
        void WaitForMutexTest1(const Container& mutexHandles);
        void WaitForMutexTest2(const Container& mutexHandles);

        void CreateMutexTest(Container& mutexHandles);
        void CreateThreadTest(const Container& mutexHandles);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MULTIPLE_MUTEX_TESTING_H