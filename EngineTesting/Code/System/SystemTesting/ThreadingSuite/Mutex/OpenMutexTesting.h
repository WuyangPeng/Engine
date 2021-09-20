///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/04/28 13:45)

#ifndef SYSTEM_THREADING_SUITE_OPEN_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_MUTEX_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class OpenMutexTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenMutexTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenMutexTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();
        void WaitForMutexTest(const String& mutexName);

    private:
        using MutexStandardAccessFlagsCollection = std::vector<MutexStandardAccess>;
        using MutexSpecificAccessFlagsCollection = std::vector<MutexSpecificAccess>;

    private:
        MutexStandardAccessFlagsCollection mutexStandardAccessFlags;
        MutexSpecificAccessFlagsCollection mutexSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_MUTEX_TESTING_H