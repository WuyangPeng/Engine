///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 16:13)

#ifndef MATHEMATICS_OBJECTS3D_SUITE_CAPSULE3_TESTING_H
#define MATHEMATICS_OBJECTS3D_SUITE_CAPSULE3_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Mathematics
{
    class Capsule3Testing : public CoreTools::UnitTest
    {
    public:
        using ClassType = Capsule3Testing;
        using ParentType = UnitTest;

    public:
        explicit Capsule3Testing(const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CapsuleTest();

        void DoRunUnitTest() override;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_SUITE_CAPSULE3_TESTING_H