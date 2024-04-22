/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/16 15:19)

#ifndef CORE_TOOLS_THREADING_SUITE_THREAD_GUARD_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_THREAD_GUARD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ThreadGuardTesting final : public UnitTest
    {
    public:
        using ClassType = ThreadGuardTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadGuardTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Function = void (ClassType::*)();

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ThreadGuardTest();
        void CreateThread(Function function);
        void CallBack() noexcept;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_GUARD_TESTING_H