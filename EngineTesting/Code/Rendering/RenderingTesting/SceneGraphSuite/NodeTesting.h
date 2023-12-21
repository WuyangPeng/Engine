/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/08 10:44)

#ifndef RENDERING_SCENE_GRAPH_SUITE_NODE_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_NODE_TESTING_H

#include "SceneGraphTestingBase.h"
#include "Detail/ViewVolumeTool.h"

namespace Rendering
{
    class NodeTesting final : public SceneGraphTestingBase
    {
    public:
        using ClassType = NodeTesting;
        using ParentType = SceneGraphTestingBase;

    public:
        explicit NodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void InitTest();
        void CloneTest();
        void ParentTest();
        NODISCARD bool TransformTest();
        NODISCARD bool StreamTest();
        void ChildTest();

    private:
        ViewVolumeTool viewVolumeTool;
        TransformApproximateFunction transformApproximateFunction;
        APointApproximateFunction aPointApproximateFunction;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_NODE_TESTING_H