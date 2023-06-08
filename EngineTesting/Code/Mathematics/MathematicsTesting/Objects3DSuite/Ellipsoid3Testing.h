///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/28 14:57)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_ELLIPSOID3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_ELLIPSOID3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Ellipsoid3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Ellipsoid3Testing;
        using ParentType = UnitTest;

    public:
        explicit Ellipsoid3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConstructionTest();
        void CalculateTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_ELLIPSOID3_TESTING_H