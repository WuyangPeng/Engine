///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:36)

#ifndef SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H

#include "SemaphoreTestingBase.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    class WaitSemaphoreTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = WaitSemaphoreTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit WaitSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();

        void WaitForSemaphoreTest0(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest1(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest2(WindowsHandle semaphoreHandle);
        void WaitForSemaphoreTest3(WindowsHandle semaphoreHandle);

        void CreateThread(WindowsHandle semaphoreHandle);
    };
}

#endif  // SYSTEM_THREADING_SUITE_WAIT_SEMAPHORE_TESTING_H