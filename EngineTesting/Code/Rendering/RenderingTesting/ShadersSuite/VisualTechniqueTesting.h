///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/11 18:00)

#ifndef RENDERING_SHADERS_SUITE_VISUAL_TECHNIQUE_TESTING_H
#define RENDERING_SHADERS_SUITE_VISUAL_TECHNIQUE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class VisualTechniqueTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(VisualTechniqueTesting);

    private:
        void MainTest();
        void InitTest();
        void CopyTest();
        void StreamTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_SHADERS_SUITE_VISUAL_TECHNIQUE_TESTING_H