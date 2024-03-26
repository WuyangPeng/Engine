/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:04)

#ifndef SYSTEM_THREADING_SUITE_WAIT_FOR_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_FOR_MUTEX_TESTING_H

#include "MutexTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class WaitForMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = WaitForMutexTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit WaitForMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void WaitMutexTest();

        void WaitForMutexTest0(WindowsHandle mutexHandle);
        void WaitForMutexTest1(WindowsHandle mutexHandle);
        void WaitForMutexTest2(WindowsHandle mutexHandle);
        void WaitForMutexTest3(WindowsHandle mutexHandle);

        void CreateThread(WindowsHandle mutexHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_FOR_MUTEX_TESTING_H