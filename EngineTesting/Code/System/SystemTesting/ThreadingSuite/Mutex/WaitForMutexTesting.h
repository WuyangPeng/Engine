///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 11:29)

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
        void DoRunUnitTest() final;
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