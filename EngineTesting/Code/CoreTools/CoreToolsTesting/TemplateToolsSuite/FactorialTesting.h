///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:46)

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