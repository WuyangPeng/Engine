/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.9 (2024/04/23 11:05)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FIBONACCI_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FIBONACCI_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class FibonacciTesting final : public UnitTest
    {
    public:
        using ClassType = FibonacciTesting;
        using ParentType = UnitTest;

    public:
        explicit FibonacciTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void RecursiveVsNonRecursiveTest();
        void TemplateVersionTest();
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FIBONACCI_TESTING_H