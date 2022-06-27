///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/15 15:54)

#ifndef RENDERING_RESOURCES_SUITE_TEXTURE_3D_TESTING_H
#define RENDERING_RESOURCES_SUITE_TEXTURE_3D_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class Texture3DTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(Texture3DTesting);

    private:
        void MainTest();
        void BaseTest();
        void MipmapsTest();
        void StreamTest();
        void FileTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RESOURCES_SUITE_TEXTURE_3D_TESTING_H