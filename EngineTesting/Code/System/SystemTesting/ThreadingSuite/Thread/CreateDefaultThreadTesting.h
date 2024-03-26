/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/12 18:08)

#ifndef SYSTEM_THREADING_SUITE_CREATE_DEFAULT_THREAD_TESTING_H
#define SYSTEM_THREADING_SUITE_CREATE_DEFAULT_THREAD_TESTING_H

#include "ThreadTestingBase.h"
#include "System/Helper/WindowsMacro.h"

namespace System
{
    class CreateDefaultThreadTesting final : public ThreadTestingBase
    {
    public:
        using ClassType = CreateDefaultThreadTesting;
        using ParentType = ThreadTestingBase;

    public:
        explicit CreateDefaultThreadTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadTest();
        void DoThreadTest(ThreadHandle threadHandle, WindowsDWord threadId);

        static WindowsDWord SYSTEM_WIN_API ThreadStartRoutine(void* threadParameter);
    };
}

#endif  // SYSTEM_THREADING_SUITE_CREATE_DEFAULT_THREAD_TESTING_H