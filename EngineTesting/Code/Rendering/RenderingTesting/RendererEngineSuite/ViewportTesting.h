///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.0 (2023/06/21 10:11)

#ifndef RENDERING_RENDERER_ENGINE_SUITE_VIEWPORT_TESTING_H
#define RENDERING_RENDERER_ENGINE_SUITE_VIEWPORT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class ViewportTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ViewportTesting;
        using ParentType = UnitTest;

    public:
        explicit ViewportTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void IsInViewportStaticTest() noexcept;
        void IsInViewportTrueTest();
        void IsInViewportFalseTest();
    };
}

#endif  // RENDERING_RENDERER_ENGINE_SUITE_VIEWPORT_TESTING_H