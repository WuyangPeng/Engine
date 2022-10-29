///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:53)

#ifndef SYSTEM_THREADING_SUITE_OPEN_PROCESS_TESTING_H
#define SYSTEM_THREADING_SUITE_OPEN_PROCESS_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class OpenProcessTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = OpenProcessTesting;
        using ParentType = UnitTest;

    public:
        explicit OpenProcessTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void OpenProcessTest();

    private:
        using ProcessStandardAccessFlagsContainer = std::vector<ProcessStandardAccess>;
        using ProcessSpecificAccessFlagsContainer = std::vector<ProcessSpecificAccess>;

    private:
        ProcessStandardAccessFlagsContainer processStandardAccessFlags;
        ProcessSpecificAccessFlagsContainer processSpecificAccessFlags;
        String processFullPath;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_OPEN_PROCESS_TESTING_H