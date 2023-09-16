///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/01 14:39)

#ifndef SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H
#define SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H

#include "ThreadToolsTestingBase.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Threading/Fwd/ThreadingFlagsFwd.h"
#include "System/Threading/Using/ThreadUsing.h"

#include <random>
#include <vector>

namespace System
{
    class ThreadTokenTesting final : public ThreadToolsTestingBase
    {
    public:
        using ClassType = ThreadTokenTesting;
        using ParentType = ThreadToolsTestingBase;

    public:
        explicit ThreadTokenTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD bool RandomShuffleFlags();
        void ThreadTest();

        void TokenTest(ThreadHandle threadHandle, TokenStandardAccess tokenStandardAccess, TokenSpecificAccess tokenSpecificAccess);
        void DoThreadTest(ThreadHandle mutexHandle);
        void TokenThreadTest(ThreadHandle threadHandle, WindowsDWord threadId, ThreadHandle mutexHandle);
        void DoTokenThreadTest(size_t index, ThreadHandle threadHandle);

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter) noexcept;

    private:
        using TokenStandardAccessContainer = std::vector<TokenStandardAccess>;
        using TokenSpecificAccessContainer = std::vector<TokenSpecificAccess>;

    private:
        TokenStandardAccessContainer tokenStandardAccesses;
        TokenSpecificAccessContainer tokenSpecificAccesses;
        std::default_random_engine randomEngine;
        size_t maxSize;
    };
}

#endif  // SYSTEM_THREADING_SUITE_THREAD_TOKEN_TESTING_H