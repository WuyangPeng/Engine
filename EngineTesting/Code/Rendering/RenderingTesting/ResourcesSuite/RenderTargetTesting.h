///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:37)

#ifndef RENDERING_RESOURCES_SUITE_RENDER_TARGET_TESTING_H
#define RENDERING_RESOURCES_SUITE_RENDER_TARGET_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class RenderTargetTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderTargetTesting;
        using ParentType = UnitTest;

    public:
        explicit RenderTargetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void BaseTest();
        void StreamTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_RENDER_TARGET_TESTING_H