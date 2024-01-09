///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:30)

#ifndef RENDERING_SCENE_GRAPH_SUITE_PROJECTOR_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_PROJECTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ProjectorTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ProjectorTesting;
        using ParentType = UnitTest;

    public:
        explicit ProjectorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void FrameTest();
        void FrustumTest() noexcept;
        void ProjectionMatrixTest() noexcept;
        void AxesAlignBoundingBoxTest() noexcept;
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_PROJECTOR_TESTING_H