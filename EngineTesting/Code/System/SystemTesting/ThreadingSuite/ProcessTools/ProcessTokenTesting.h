///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/12 18:36)

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
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

    private:
        using TokenStandardAccessFlagsCollection = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessFlagsCollection = std::vector<TokenSpecificAccess>;

    private:
        TokenStandardAccessFlagsCollection tokenStandardAccessFlags;
        TokenSpecificAccessFlagsCollection tokenSpecificAccessFlags;
        String processFullPath;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PROCESS_TOKEN_TESTING_H