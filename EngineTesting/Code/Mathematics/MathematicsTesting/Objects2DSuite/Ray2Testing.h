///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 13:47)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_RAY2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_RAY2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Ray2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Ray2Testing;
        using ParentType = UnitTest;

    public:
        explicit Ray2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void RayTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_SUITE_RAY2_TESTING_H