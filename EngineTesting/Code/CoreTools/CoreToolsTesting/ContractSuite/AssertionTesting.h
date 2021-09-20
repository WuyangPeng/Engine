///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.2.2 (2021/08/26 14:17)

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
        void DoRunUnitTest() final;
        void MainTest();

        void AssertionFailTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_ASSERTION_TESTING_H