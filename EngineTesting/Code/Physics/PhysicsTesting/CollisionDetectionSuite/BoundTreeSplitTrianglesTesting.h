///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 16:50)

#ifndef PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_SPLIT_TRIANGLES_TESTING_H
#define PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_SPLIT_TRIANGLES_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Physics
{
    class BoundTreeSplitTrianglesTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = BoundTreeSplitTrianglesTesting;
        using ParentType = UnitTest;

    public:
        explicit BoundTreeSplitTrianglesTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void InitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_SPLIT_TRIANGLES_TESTING_H