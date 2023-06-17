///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:50)

#ifndef PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_CHILD_TESTING_H
#define PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_CHILD_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Physics
{
    class BoundTreeChildTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BoundTreeChildTesting;
        using ParentType = UnitTest;

    public:
        explicit BoundTreeChildTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CreateTrianglesMeshFile() noexcept;
        void InitTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_CHILD_TESTING_H