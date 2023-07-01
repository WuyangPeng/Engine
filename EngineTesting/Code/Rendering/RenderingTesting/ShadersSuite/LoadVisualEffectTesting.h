///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/12 15:03)

#ifndef RENDERING_SHADERS_SUITE_LOAD_VISUAL_EFFECT_TESTING_H
#define RENDERING_SHADERS_SUITE_LOAD_VISUAL_EFFECT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Rendering
{
    class LoadVisualEffectTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = LoadVisualEffectTesting;
        using ParentType = UnitTest;

    public:
        explicit LoadVisualEffectTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void MainTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SHADERS_SUITE_LOAD_VISUAL_EFFECT_TESTING_H