///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:41)

#ifndef RENDERING_RENDERERS_SUITE_RENDER_TARGET_MANAGEMENT_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDER_TARGET_MANAGEMENT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class RenderTargetManagementTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderTargetManagementTesting;
        using ParentType = UnitTest;

    public:
        explicit RenderTargetManagementTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_RENDER_TARGET_MANAGEMENT_TESTING_H