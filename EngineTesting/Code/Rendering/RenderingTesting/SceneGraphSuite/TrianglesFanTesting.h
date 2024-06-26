///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:31)

#ifndef RENDERING_SCENE_GRAPH_SUITE_TRIANGLES_FAN_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_TRIANGLES_FAN_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class TrianglesFanTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = TrianglesFanTesting;
        using ParentType = UnitTest;

    public:
        explicit TrianglesFanTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void CreateTrianglesMeshFile() noexcept;
        void InitTest() noexcept;
        void CopyTest() noexcept;
        void TransformTest() noexcept;
        void StreamTest() noexcept;
        void FileTest() noexcept;
        void UpdateModelSpaceTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_TRIANGLES_FAN_TESTING_H