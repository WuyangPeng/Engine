///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.3 (2021/05/11 14:32)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "System/Threading/Using/ThreadUsing.h"

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
        using TokenStandardAccessFlagsCollection = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessFlagsCollection = std::vector<TokenSpecificAccess>;

    private:
        TokenStandardAccessFlagsCollection tokenStandardAccessFlags;
        TokenSpecificAccessFlagsCollection tokenSpecificAccessFlags;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H