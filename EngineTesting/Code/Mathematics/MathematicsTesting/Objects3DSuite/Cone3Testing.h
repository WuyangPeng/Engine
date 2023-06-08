///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/28 14:56)

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