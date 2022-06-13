///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/17 18:48)

#ifndef CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H
#define CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class SqrtTesting : public UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SqrtTesting);

    private:
        void MainTest();
        void SqrtTest();
        void IfThenElseTest();

        void DoRunUnitTest() override;
    };
}

#endif  // CORE_TOOLS_TEMPLATE_TOOLS_SUITE_SQRT_TESTING_H
