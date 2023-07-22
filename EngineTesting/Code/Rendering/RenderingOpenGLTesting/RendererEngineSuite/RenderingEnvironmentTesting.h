///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/25 16:51)

#ifndef RENDERING_RENDERER_ENGINE_SUITE_RENDERING_ENVIRONMENT_TESTING_H
#define RENDERING_RENDERER_ENGINE_SUITE_RENDERING_ENVIRONMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class RenderingEnvironmentTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderingEnvironmentTesting;
        using ParentType = UnitTest;

    public:
        explicit RenderingEnvironmentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void NullRenderingEnvironmentTest();
    };
}

#endif  // RENDERING_RENDERER_ENGINE_SUITE_RENDERING_ENVIRONMENT_TESTING_H