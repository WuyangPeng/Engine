///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/11 15:33)

#ifndef CORE_TOOLS_CONTRACT_SUITE_ASSERTION_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_ASSERTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class AssertionTesting final : public UnitTest
    {
    public:
        using ClassType = AssertionTesting;
        using ParentType = UnitTest;

    public:
        explicit AssertionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertionFailTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_ASSERTION_TESTING_H