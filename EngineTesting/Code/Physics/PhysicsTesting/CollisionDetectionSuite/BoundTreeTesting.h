///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/20 20:16)

#ifndef PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_TESTING_H
#define PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Physics
{
    class BoundTreeTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(BoundTreeTesting);

    private:
        void MainTest();
        void CreateTrianglesMeshFile();
        void InitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_SUITE_BOUND_TREE_TESTING_H