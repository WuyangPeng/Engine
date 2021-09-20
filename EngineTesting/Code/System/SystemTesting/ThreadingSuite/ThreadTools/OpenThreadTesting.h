///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.3 (2021/05/11 11:18)

#ifndef SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class OpenThreadTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenThreadTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void DoThreadTest(WindowsHandle mutexHandle, ThreadStandardAccess threadStandardAccess, ThreadSpecificAccess threadSpecificAccess);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter) noexcept;

    private:
        using ThreadStandardAccessFlagsCollection = std::vector<ThreadStandardAccess>;
        using ThreadSpecificAccessFlagsCollection = std::vector<ThreadSpecificAccess>;

    private:
        ThreadStandardAccessFlagsCollection threadStandardAccessFlags;
        ThreadSpecificAccessFlagsCollection threadSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H