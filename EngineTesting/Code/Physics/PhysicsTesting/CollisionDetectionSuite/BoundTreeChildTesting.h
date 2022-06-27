///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/20 20:13)

#ifndef PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_CHILD_TESTING_H
#define PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_CHILD_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Physics
{
    class BoundTreeChildTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BoundTreeChildTesting);

    private:
        void MainTest();
        void CreateTrianglesMeshFile();
        void InitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_CHILD_TESTING_H