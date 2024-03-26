/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/12 18:04)

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
        void DoRunUnitTest() override;
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
        CreateMutexContainer createMutexContainer;
        MutexSpecificAccessContainer mutexSpecificAccesses;
        MutexStandardAccessContainer mutexStandardAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_MUTEX_TESTING_H