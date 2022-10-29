///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/22 23:59)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadUsing.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

#include <random>
#include <vector>

namespace System
{
    class ThreadTokenTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ThreadTokenTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void TokenTest(ThreadHandle threadHandle, TokenStandardAccess tokenStandardAccess, TokenSpecificAccess tokenSpecificAccess);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter) noexcept;

    private:
        using TokenStandardAccessFlagsContainer = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessFlagsContainer = std::vector<TokenSpecificAccess>;

    private:
        TokenStandardAccessFlagsContainer tokenStandardAccessFlags;
        TokenSpecificAccessFlagsContainer tokenSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H