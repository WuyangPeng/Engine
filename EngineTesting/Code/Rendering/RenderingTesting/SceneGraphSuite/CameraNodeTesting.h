///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:29)

#ifndef RENDERING_SCENE_GRAPH_SUITE_CAMERA_NODE_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_CAMERA_NODE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class CameraNodeTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = CameraNodeTesting;
        using ParentType = UnitTest;

    public:
        explicit CameraNodeTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void InitTest() noexcept;
        void CopyTest() noexcept;
        void TransformTest() noexcept;
        void ChildTest() noexcept;
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_CAMERA_NODE_TESTING_H