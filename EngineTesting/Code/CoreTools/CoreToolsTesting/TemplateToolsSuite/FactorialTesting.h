///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/17 18:46)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class FactorialTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(FactorialTesting);

    private:
        void MainTest();
        void RecursiveVsNonrecursiveTest();
        void TemplateVersionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_FACTORIAL_TESTING_H