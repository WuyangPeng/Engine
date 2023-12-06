/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.1 (2023/11/27 14:42)

#ifndef RENDERING_SCENE_GRAPH_SUITE_PICK_LINE_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_PICK_LINE_TESTING_H

#include "Rendering/RenderingTesting/SceneGraphSuite/Detail/ViewVolumeTool.h"
#include "Rendering/RenderingTesting/SceneGraphSuite/ViewVolume/ViewVolumeTestingBase.h"

namespace Rendering
{
    class PickLineTesting final : public ViewVolumeTestingBase
    {
    public:
        using ClassType = PickLineTesting;
        using ParentType = ViewVolumeTestingBase;

    public:
        explicit PickLineTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void DataTest();

    private:
        ViewVolumeTool viewVolumeTool;
        APointApproximateFunction aPointApproximateFunction;
        AVectorApproximateFunction aVectorApproximateFunction;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_PICK_LINE_TESTING_H