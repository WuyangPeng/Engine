///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 21:16)

#ifndef MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX2_TESTING_H
#define MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class ContBox2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ContBox2Testing);

    private:
        void MainTest();
        void ContAlignedBoxTest();
        void ContOrientedBoxTest();
        void MergeBoxesTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX2_TESTING_H