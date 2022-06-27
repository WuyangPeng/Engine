///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/14 18:47)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CAMERA_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CAMERA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class CameraTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(CameraTesting);

    private:
        void MainTest();
        void FrameTest();
        void FrustumTest();
        void ProjectionMatrixTest();
        void AxesAlignBoundingBoxTest();
        void StreamTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_CAMERA_TESTING_H