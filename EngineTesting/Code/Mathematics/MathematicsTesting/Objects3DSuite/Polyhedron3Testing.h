///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:14)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_POLYHEDRON3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_POLYHEDRON3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Polyhedron3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Polyhedron3Testing;
        using ParentType = UnitTest;

    public:
        explicit Polyhedron3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void PolyhedronTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_POLYHEDRON3_TESTING_H