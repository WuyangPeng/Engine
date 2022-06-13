///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/31 13:46)

#ifndef MATHEMATICS_OBJECTS2D_SUITE_CONVEX_POLYGON2_TESTING_H
#define MATHEMATICS_OBJECTS2D_SUITE_CONVEX_POLYGON2_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class ConvexPolygon2Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConvexPolygon2Testing);

    private:
        void MainTest();
        void ConvexPolygonTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_SUITE_CONVEX_POLYGON2_TESTING_H