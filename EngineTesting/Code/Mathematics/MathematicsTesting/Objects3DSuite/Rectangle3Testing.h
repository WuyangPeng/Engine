///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/28 15:00)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_RECTANGLE3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_RECTANGLE3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Rectangle3Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Rectangle3Testing);

    private:
        void MainTest();
        void RectangleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_RECTANGLE3_TESTING_H