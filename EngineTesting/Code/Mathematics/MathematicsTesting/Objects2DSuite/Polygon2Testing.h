///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:10)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_POLYGON2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_POLYGON2_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Polygon2Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Polygon2Testing;
        using ParentType = UnitTest;

    public:
        explicit Polygon2Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void PolygonTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_SUITE_POLYGON2_TESTING_H