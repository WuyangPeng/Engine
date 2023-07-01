///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:41)

#ifndef RENDERING_RENDERERS_SUITE_RENDERING_DEVICE_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDERING_DEVICE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class RenderingDeviceTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = RenderingDeviceTesting;
        using ParentType = UnitTest;

    public:
        explicit RenderingDeviceTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void SwapBuffersTest();
    };
}

#endif  // RENDERING_RENDERERS_SUITE_RENDERING_DEVICE_TESTING_H