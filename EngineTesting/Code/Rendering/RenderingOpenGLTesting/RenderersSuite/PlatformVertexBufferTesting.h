///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/17 22:54)

#ifndef RENDERING_RENDERERS_SUITE_PLATFORM_VERTEX_BUFFER_TESTING_H
#define RENDERING_RENDERERS_SUITE_PLATFORM_VERTEX_BUFFER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class PlatformVertexBufferTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(PlatformVertexBufferTesting);

    private:
        void MainTest();
        void VertexBufferTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_PLATFORM_VERTEX_BUFFER_TESTING_H