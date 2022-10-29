///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 19:31)

#ifndef SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class CreateMutexUseFlagsTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = CreateMutexUseFlagsTesting;
        using ParentType = UnitTest;

    public:
        explicit CreateMutexUseFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateMutexTest();
        void CreateMutexUseNameTest();

    private:
        using CreateMutexFlagsContainer = std::vector<MutexCreate>;
        using MutexSpecificAccessFlagsContainer = std::vector<MutexSpecificAccess>;
        using MutexStandardAccessFlagsContainer = std::vector<MutexStandardAccess>;

    private:
        CreateMutexFlagsContainer createMutexFlags;
        MutexSpecificAccessFlagsContainer mutexSpecificAccessFlags;
        MutexStandardAccessFlagsContainer mutexStandardAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H