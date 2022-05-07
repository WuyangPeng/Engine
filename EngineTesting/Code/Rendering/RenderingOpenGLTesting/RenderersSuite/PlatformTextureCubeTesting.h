// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/09 15:22)

#ifndef RENDERING_RENDERERS_SUITE_PLATFORM_TEXTURE_CUBE_TESTING_H
#define RENDERING_RENDERERS_SUITE_PLATFORM_TEXTURE_CUBE_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class PlatformTextureCubeTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PlatformTextureCubeTesting);

    private:
        void MainTest();
        void TextureCubeTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_PLATFORM_TEXTURE_CUBE_TESTING_H