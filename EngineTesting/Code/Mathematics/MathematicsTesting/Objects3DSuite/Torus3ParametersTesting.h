// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.2 (2019/08/22 15:34)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_TORUS3_PARAMETERS_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_TORUS3_PARAMETERS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Mathematics
{
    class Torus3ParametersTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Torus3ParametersTesting);

    private:
        void MainTest();
        void ParametersTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_TORUS3_PARAMETERS_TESTING_H