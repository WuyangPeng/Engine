///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 18:55)

#ifndef RENDERING_SCENE_GRAPH_SUITE_STANDARD_MESH_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_STANDARD_MESH_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class StandardMeshTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(StandardMeshTesting);

    private:
        void MainTest();
        void BaseTest();
        void RectangleTest();
        void DiskTest();
        void BoxTest();
        void CylinderOmittedEndDisksTest();
        void CylinderIncludedEndDisksTest();
        void SphereTest();
        void TorusTest();
        void TetrahedronTest();
        void HexahedronTest();
        void OctahedronTest();
        void DodecahedronTest();
        void IcosahedronTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_STANDARD_MESH_TESTING_H