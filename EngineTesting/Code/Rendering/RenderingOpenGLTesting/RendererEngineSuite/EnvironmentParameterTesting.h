///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 16:21)

#ifndef RENDERING_RENDERER_ENGINE_SUITE_ENVIRONMENT_PARAMETER_TESTING_H
#define RENDERING_RENDERER_ENGINE_SUITE_ENVIRONMENT_PARAMETER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class EnvironmentParameterTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnvironmentParameterTesting;
        using ParentType = UnitTest;

    public:
        explicit EnvironmentParameterTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void HWndTest();
    };
}

#endif  // RENDERING_RENDERER_ENGINE_SUITE_ENVIRONMENT_PARAMETER_TESTING_H