///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/08 11:40)

#ifndef MATHEMATICS_APPROXIMATION_SUITE_GREAT_CIRCLE_FIT3_TESTING_H
#define MATHEMATICS_APPROXIMATION_SUITE_GREAT_CIRCLE_FIT3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class GreatCircleFit3Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(GreatCircleFit3Testing);

    private:
        void MainTest();
        void FitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_SUITE_GREAT_CIRCLE_FIT3_TESTING_H