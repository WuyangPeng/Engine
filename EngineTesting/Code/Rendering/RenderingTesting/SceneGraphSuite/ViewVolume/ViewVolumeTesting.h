/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/25 16:48)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TESTING_H

#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTool.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/SceneGraphTestingBase.h"

namespace Rendering
{
    class ViewVolumeTesting final : public SceneGraphTestingBase
    {
    public:
        using ClassType = ViewVolumeTesting;
        using ParentType = SceneGraphTestingBase;

    public:
        explicit ViewVolumeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void NameTest();
        NODISCARD bool StreamTest();

    private:
        APointApproximateFunction aPointApproximateFunction;
        AVectorApproximateFunction aVectorApproximateFunction;
        MatrixApproximateFunction matrixApproximateFunction;
        ViewVolumeTool viewVolumeTool;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_VIEW_VOLUME_TESTING_H