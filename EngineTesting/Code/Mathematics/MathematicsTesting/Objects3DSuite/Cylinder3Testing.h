///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/28 14:56)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_CYLINDER3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_CYLINDER3_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Cylinder3Testing : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Cylinder3Testing);

    private:
        void MainTest();
        void CylinderTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_CYLINDER3_TESTING_H