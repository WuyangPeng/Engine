///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.1 (2023/02/01 10:04)

#ifndef SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H

#include "MutexTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class CreateMutexUseFlagsTesting final : public MutexTestingBase
    {
    public:
        using ClassType = CreateMutexUseFlagsTesting;
        using ParentType = MutexTestingBase;

    public:
        explicit CreateMutexUseFlagsTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void CreateMutexTest();
        void CreateMutexUseNameTest();
        void DoCreateMutexTest(size_t index);
        void DoCreateMutexUseNameTest(size_t index);

    private:
        using CreateMutexContainer = std::vector<MutexCreate>;
        using MutexSpecificAccessContainer = std::vector<MutexSpecificAccess>;
        using MutexStandardAccessContainer = std::vector<MutexStandardAccess>;

    private:
        CreateMutexContainer createMutexs;
        MutexSpecificAccessContainer mutexSpecificAccesses;
        MutexStandardAccessContainer mutexStandardAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H