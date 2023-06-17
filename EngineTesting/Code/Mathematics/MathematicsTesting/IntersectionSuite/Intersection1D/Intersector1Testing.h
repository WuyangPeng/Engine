///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:49)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TESTING_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Intersector1Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Intersector1Testing;
        using ParentType = UnitTest;

    public:
        explicit Intersector1Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void IntersectorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TESTING_H