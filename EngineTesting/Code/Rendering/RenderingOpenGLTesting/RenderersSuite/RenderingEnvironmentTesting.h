///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/10 23:08)

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