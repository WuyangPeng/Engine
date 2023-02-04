///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 19:43)

#ifndef SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H

#include "ThreadToolsTestingBase.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class OpenThreadTesting final : public ThreadToolsTestingBase
    {
    public:
        using ClassType = OpenThreadTesting;
        using ParentType = ThreadToolsTestingBase;

    public:
        explicit OpenThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void DoThreadTest(WindowsHandle mutexHandle, ThreadStandardAccess threadStandardAccess, ThreadSpecificAccess threadSpecificAccess);
        void ThreadResultTest(WindowsHandle threadHandle, WindowsDWord threadID, ThreadStandardAccess threadStandardAccess, ThreadSpecificAccess threadSpecificAccess, WindowsHandle mutexHandle);
        void OpenThreadTest(WindowsHandle openThreadHandle, WindowsDWord threadID, WindowsHandle mutexHandle, WindowsHandle threadHandle);
        void WaitForSystemMutexTest(WindowsHandle mutexHandle);
        void DoWaitForSystemMutexTest(size_t index, WindowsHandle mutexHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter) noexcept;

    private:
        using ThreadStandardAccessContainer = std::vector<ThreadStandardAccess>;
        using ThreadSpecificAccessContainer = std::vector<ThreadSpecificAccess>;

    private:
        ThreadStandardAccessContainer threadStandardAccesses;
        ThreadSpecificAccessContainer threadSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H