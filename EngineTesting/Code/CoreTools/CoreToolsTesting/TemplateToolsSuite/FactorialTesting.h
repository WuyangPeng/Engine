///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.6 (2023/04/25 11:17)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FactorialTesting final : public UnitTest
    {
    public:
        using ClassType = FactorialTesting;
        using ParentType = UnitTest;

    public:
        explicit FactorialTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void RecursiveVsNonRecursiveTest();
        void TemplateVersionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H