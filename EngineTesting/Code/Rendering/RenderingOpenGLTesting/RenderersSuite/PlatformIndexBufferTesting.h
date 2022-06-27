///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/17 22:53)

#ifndef RENDERING_RENDERERS_SUITE_PLATFORM_INDEX_BUFFER_TESTING_H
#define RENDERING_RENDERERS_SUITE_PLATFORM_INDEX_BUFFER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class PlatformIndexBufferTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PlatformIndexBufferTesting);

    private:
        void MainTest();
        void IndexBufferTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_PLATFORM_INDEX_BUFFER_TESTING_H