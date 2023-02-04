///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.1 (2023/02/01 15:30)

#ifndef SYSTEM_THREADING_SUITE_OPEN_SEMAPHORE_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_SEMAPHORE_TESTING_H

#include "SemaphoreTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class OpenSemaphoreTesting final : public SemaphoreTestingBase
    {
    public:
        using ClassType = OpenSemaphoreTesting;
        using ParentType = SemaphoreTestingBase;

    public:
        explicit OpenSemaphoreTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void WaitForSemaphoreTest(const String& semaphoreName);

        void OpenSemaphoreFail(const String& semaphoreName);
        void CreateThread(const String& semaphoreName);
        void DoWaitForSemaphoreTest(size_t index, const String& semaphoreName);

    private:
        using SemaphoreStandardAccessContainer = std::vector<MutexStandardAccess>;
        using SemaphoreSpecificAccessContainer = std::vector<SemaphoreSpecificAccess>;

    private:
        SemaphoreStandardAccessContainer semaphoreStandardAccesses;
        SemaphoreSpecificAccessContainer semaphoreSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_SEMAPHORE_TESTING_H