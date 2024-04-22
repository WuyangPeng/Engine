/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/15 10:09)

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

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void AssertionFailTest();
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_ASSERTION_TESTING_H