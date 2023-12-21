/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/22 16:14)

#ifndef RENDERING_SCENE_GRAPH_SUITE_WORLD_COORDINATE_FRAME_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_WORLD_COORDINATE_FRAME_TESTING_H

#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTool.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SceneGraphTestingBase.h"

namespace Rendering
{
    class WorldCoordinateFrameTesting final : public SceneGraphTestingBase
    {
    public:
        using ClassType = WorldCoordinateFrameTesting;
        using ParentType = SceneGraphTestingBase;

    public:
        explicit WorldCoordinateFrameTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void DefaultTest();
        NODISCARD bool FetchTest();
        NODISCARD bool SetFrameTest();
        NODISCARD bool MatrixTest();
        NODISCARD bool OrthonormalizeTest();

    private:
        APointApproximateFunction aPointApproximateFunction;
        AVectorApproximateFunction aVectorApproximateFunction;
        MatrixApproximateFunction matrixApproximateFunction;
        ViewVolumeTool viewVolumeTool;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_WORLD_COORDINATE_FRAME_TESTING_H