///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:14)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_CONE3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_CONE3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Cone3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Cone3Testing;
        using ParentType = UnitTest;

    public:
        explicit Cone3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void ConeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_CONE3_TESTING_H