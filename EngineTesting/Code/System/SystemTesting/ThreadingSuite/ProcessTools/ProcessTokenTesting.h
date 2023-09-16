///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/01 14:35)

#ifndef SYSTEM_THREADING_SUITE_PROCESS_TOKEN_TESTING_H
#define SYSTEM_THREADING_SUITE_PROCESS_TOKEN_TESTING_H

#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class ProcessTokenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProcessTokenTesting;
        using ParentType = UnitTest;

    public:
        explicit ProcessTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void OpenProcessTokenTest();

        void DoOpenProcessTokenTest(size_t index);

    private:
        using TokenStandardAccessContainer = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessContainer = std::vector<TokenSpecificAccess>;

    private:
        TokenStandardAccessContainer tokenStandardAccesses;
        TokenSpecificAccessContainer tokenSpecificAccesses;
        String processFullPath;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PROCESS_TOKEN_TESTING_H