///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.5 (2023/10/25 14:33)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TRIGONOMETRIC_FUNCTION_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TRIGONOMETRIC_FUNCTION_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class TrigonometricFunctionTesting final : public UnitTest
    {
    public:
        using ClassType = TrigonometricFunctionTesting;
        using ParentType = UnitTest;

    public:
        explicit TrigonometricFunctionTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void RecursiveVsNonRecursiveTest();
        void NonRecursiveCorrectTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_TRIGONOMETRIC_FUNCTION_TESTING_H