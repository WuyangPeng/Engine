///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/14 18:51)

#ifndef RENDERING_SCENE_GRAPH_SUITE_SCREEN_TARGET_TESTING_H
#define RENDERING_SCENE_GRAPH_SUITE_SCREEN_TARGET_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class ScreenTargetTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ScreenTargetTesting);

    private:
        void MainTest();
        void CameraTest() noexcept;
        void TrianglesMeshTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SCENE_GRAPH_SUITE_SCREEN_TARGET_TESTING_H