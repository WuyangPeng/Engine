/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/27 14:52)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CAMERA_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CAMERA_TESTING_H

#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTool.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/ViewVolume/ViewVolumeTestingBase.h"

namespace Rendering
{
    class CameraTesting final : public ViewVolumeTestingBase
    {
    public:
        using ClassType = CameraTesting;
        using ParentType = ViewVolumeTestingBase;

    public:
        explicit CameraTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        NODISCARD bool DefaultMatrixTest();
        NODISCARD bool DefaultProjectionViewMatrixTest();
        NODISCARD bool ProjectionViewMatrixTest();
        NODISCARD bool SetProjectionMatrixTest();
        void GetPickLineTest();
        NODISCARD bool StreamTest();

    private:
        ViewVolumeTool viewVolumeTool;
        APointApproximateFunction aPointApproximateFunction;
        AVectorApproximateFunction aVectorApproximateFunction;
        MatrixApproximateFunction matrixApproximateFunction;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_CAMERA_TESTING_H