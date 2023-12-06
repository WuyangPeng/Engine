/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.1 (2023/11/23 11:33)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CAMERA_FRUSTUM_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CAMERA_FRUSTUM_TESTING_H

#include "ViewVolumeTestingBase.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTool.h"

namespace Rendering
{
    class CameraFrustumTesting final : public ViewVolumeTestingBase
    {
    public:
        using ClassType = CameraFrustumTesting;
        using ParentType = ViewVolumeTestingBase;

    public:
        explicit CameraFrustumTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void PerspectiveTest();
        void DefaultTest();
        NODISCARD bool SetFrustumTest0();
        NODISCARD bool SetFrustumTest1();
        NODISCARD bool SetFrustumTest2();

    private:
        ViewVolumeTool viewVolumeTool;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_CAMERA_FRUSTUM_TESTING_H