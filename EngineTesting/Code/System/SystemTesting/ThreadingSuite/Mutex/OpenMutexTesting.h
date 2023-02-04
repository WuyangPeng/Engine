///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 10:19)

#ifndef SYSTEM_THREADING_SUITE_OPEN_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_MUTEX_TESTING_H

#include "MutexTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class OpenMutexTesting final : public MutexTestingBase
    {
    public:
        using ClassType = OpenMutexTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit OpenMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void CreateThreadTest(const String& mutexName);
        void WaitForMutexTest(const String& mutexName);
        void DoWaitForMutexTest(size_t index, const String& mutexName);

    private:
        using MutexStandardAccessContainer = std::vector<MutexStandardAccess>;
        using MutexSpecificAccessContainer = std::vector<MutexSpecificAccess>;

    private:
        MutexStandardAccessContainer mutexStandardAccesses;
        MutexSpecificAccessContainer mutexSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_MUTEX_TESTING_H