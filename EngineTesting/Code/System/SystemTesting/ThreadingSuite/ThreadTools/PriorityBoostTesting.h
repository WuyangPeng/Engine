///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/12 18:39)

#ifndef SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H
#define SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H

#include "System/Helper/WindowsMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class PriorityBoostTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = PriorityBoostTesting;
        using ParentType = UnitTest;

    public:
        explicit PriorityBoostTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThreadTest();

        static WindowsDWord SYSTEM_WINAPI ThreadStartRoutine(void* threadParameter) noexcept;
    };
}

#endif  // SYSTEM_THREADING_SUITE_PRIORITY_BOOST_TESTING_H