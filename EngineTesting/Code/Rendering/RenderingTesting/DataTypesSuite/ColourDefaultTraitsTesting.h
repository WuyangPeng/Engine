///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/16 14:21)

#ifndef RENDERING_DATA_TYPES_SUITE_COLOUR_DEFAULT_TRAITS_TESTING_H
#define RENDERING_DATA_TYPES_SUITE_COLOUR_DEFAULT_TRAITS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class ColourDefaultTraitsTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ColourDefaultTraitsTesting);

    private:
        void MainTest();
        void TraitsTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_DATA_TYPES_SUITE_COLOUR_DEFAULT_TRAITS_TESTING_H