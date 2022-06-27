///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/16 14:22)

#ifndef RENDERING_DATA_TYPES_SUITE_COLOUR_MANAGE_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_COLOUR_MANAGE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class ColourManagerTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ColourManagerTesting);

    private:
        void MainTest();
        void ColourTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_COLOUR_MANAGE_TESTING_H