///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.1.3 (2022/10/22 19:29)

#ifndef SYSTEM_THREADING_SUITE_INTERLOCKED_TESTING_H
#define SYSTEM_THREADING_SUITE_INTERLOCKED_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class InterlockedTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = InterlockedTesting;
        using ParentType = UnitTest;

    public:
        explicit InterlockedTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        template <typename T>
        void InterlockedTest();
    };
}

#endif  // SYSTEM_THREADING_SUITE_INTERLOCKED_TESTING_H