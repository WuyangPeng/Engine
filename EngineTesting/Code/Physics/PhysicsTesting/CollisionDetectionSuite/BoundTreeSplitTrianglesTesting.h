///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 16:50)

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