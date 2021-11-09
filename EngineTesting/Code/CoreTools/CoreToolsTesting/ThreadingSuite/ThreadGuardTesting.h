///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.3 (2021/09/02 15:11)

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
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadGuardTest();
        void CreateThread(Function function);
        void CallBack() noexcept;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_GUARD_TESTING_H