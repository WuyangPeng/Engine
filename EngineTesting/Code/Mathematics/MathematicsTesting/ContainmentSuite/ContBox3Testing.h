///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:29)

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