///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 23:58)

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
        using ThreadStandardAccessFlagsContainer = std::vector<ThreadStandardAccess>;
        using ThreadSpecificAccessFlagsContainer = std::vector<ThreadSpecificAccess>;

    private:
        ThreadStandardAccessFlagsContainer threadStandardAccessFlags;
        ThreadSpecificAccessFlagsContainer threadSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_THREAD_TESTING_H