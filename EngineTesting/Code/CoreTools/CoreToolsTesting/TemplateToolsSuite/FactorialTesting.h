/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.9 (2024/04/23 11:05)

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
        void DoRunUnitTest() override;
        void MainTest();

        void RecursiveVsNonRecursiveTest();
        void TemplateVersionTest();
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H