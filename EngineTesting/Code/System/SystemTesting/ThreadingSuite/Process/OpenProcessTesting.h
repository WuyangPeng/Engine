/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:05)

#ifndef SYSTEM_THREADING_SUITE_OPEN_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_PROCESS_TESTING_H

#include "ProcessTestingBase.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"

#include <random>
#include <vector>

namespace System
{
    class OpenProcessTesting final : public ProcessTestingBase
    {
    public:
        using ClassType = OpenProcessTesting;
        using ParentType = ProcessTestingBase;

    public:
        explicit OpenProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void OpenProcessTest();

        void DoOpenProcessTest(size_t index, const ProcessInformation& processInformation);

    private:
        using ProcessStandardAccessContainer = std::vector<ProcessStandardAccess>;
        using ProcessSpecificAccessContainer = std::vector<ProcessSpecificAccess>;

    private:
        ProcessStandardAccessContainer processStandardAccesses;
        ProcessSpecificAccessContainer processSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_PROCESS_TESTING_H