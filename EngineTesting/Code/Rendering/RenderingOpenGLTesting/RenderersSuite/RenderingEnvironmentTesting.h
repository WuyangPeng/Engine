///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 14:46)

#ifndef RENDERING_RENDERERS_SUITE_RENDERING_ENVIRONMENT_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDERING_ENVIRONMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class RenderingEnvironmentTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderingEnvironmentTesting;
        using ParentType = UnitTest;

    public:
        explicit RenderingEnvironmentTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void NullRenderingEnvironmentTest();
    };
}

#endif  // RENDERING_RENDERERS_SUITE_RENDERING_ENVIRONMENT_TESTING_H