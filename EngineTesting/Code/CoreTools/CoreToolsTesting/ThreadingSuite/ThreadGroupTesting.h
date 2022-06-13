///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 15:58)

#ifndef CORE_TOOLS_THREADING_SUITE_THREAD_GROUP_TESTING_H
#define CORE_TOOLS_THREADING_SUITE_THREAD_GROUP_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class ThreadGroupTesting final : public UnitTest
    {
    public:
        using ClassType = ThreadGroupTesting;
        using ParentType = UnitTest;

    public:
        explicit ThreadGroupTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        using Function = void (ClassType::*)();

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadGroupTest();
        void CreateThread(Function function);
        void CallBack() noexcept;
    };
}

#endif  // CORE_TOOLS_THREADING_SUITE_THREAD_GROUP_TESTING_H