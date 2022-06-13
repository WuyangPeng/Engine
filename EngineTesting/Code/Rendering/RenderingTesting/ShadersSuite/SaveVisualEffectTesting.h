///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/11 17:59)

#ifndef RENDERING_SHADERS_SUITE_SAVE_VISUAL_EFFECT_TESTING_H
#define RENDERING_SHADERS_SUITE_SAVE_VISUAL_EFFECT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class SaveVisualEffectTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SaveVisualEffectTesting);

    private:
        void MainTest();
        void CreateVisualEffectFile() noexcept;
        void SaveFile();
        void SaveTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SHADERS_SUITE_SAVE_VISUAL_EFFECT_TESTING_H