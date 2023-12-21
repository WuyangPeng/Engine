/// Copyright (c) 2010-2023
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.2 (2023/12/20 16:21)

#ifndef RENDERING_SCENE_GRAPH_SUITE_VISUAL_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_VISUAL_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class VisualTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = VisualTesting;
        using ParentType = UnitTest;

    public:
        explicit VisualTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();
        void InitTest();
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_VISUAL_TESTING_H