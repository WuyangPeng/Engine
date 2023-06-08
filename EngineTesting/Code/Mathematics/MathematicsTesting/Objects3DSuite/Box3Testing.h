///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/28 14:55)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_BOX3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_BOX3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Box3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Box3Testing;
        using ParentType = UnitTest;

    public:
        explicit Box3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void BoxTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_BOX3_TESTING_H