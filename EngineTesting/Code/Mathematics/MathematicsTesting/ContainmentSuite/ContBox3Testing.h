///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/07 21:16)

#ifndef MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX3_TESTING_H
#define MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class ContBox3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = ContBox3Testing;
        using ParentType = UnitTest;

    public:
        explicit ContBox3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ContAlignedBoxTest();
        void ContOrientedBoxTest();
        void MergeBoxesTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_CONTAINMENT_SUITE_CONT_BOX3_TESTING_H