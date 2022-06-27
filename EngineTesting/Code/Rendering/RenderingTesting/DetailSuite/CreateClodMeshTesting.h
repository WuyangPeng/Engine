///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/15 17:17)

#ifndef RENDERING_DETAIL_SUITE_CREATE_CLOD_MESH_TESTING_H
#define RENDERING_DETAIL_SUITE_CREATE_CLOD_MESH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class CreateClodMeshTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CreateClodMeshTesting);

    private:
        void MainTest();
        void CreateTrianglesMeshFile();
        void InitTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DETAIL_SUITE_CREATE_CLOD_MESH_TESTING_H