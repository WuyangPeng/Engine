///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:36)

#ifndef SYSTEM_THREADING_SUITE_OPEN_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_SEMAPHORE_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class OpenSemaphoreTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenSemaphoreTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();
        void WaitForSemaphoreTest(const String& semaphoreName);

    private:
        using SemaphoreStandardAccessFlagsCollection = std::vector<MutexStandardAccess>;
        using SemaphoreSpecificAccessFlagsCollection = std::vector<SemaphoreSpecificAccess>;

    private:
        SemaphoreStandardAccessFlagsCollection semaphoreStandardAccessFlags;
        SemaphoreSpecificAccessFlagsCollection semaphoreSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_SEMAPHORE_TESTING_H