///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:48)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PTR_COMPARE_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PTR_COMPARE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class PtrCompareTesting : public UnitTest
    {
    public:
        using ClassType = PtrCompareTesting;
        using ParentType = UnitTest;

    public:
        explicit PtrCompareTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void PtrCompareTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_PTR_COMPARE_TESTING_H