///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/17 22:55)

#ifndef RENDERING_RENDERERS_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H
#define RENDERING_RENDERERS_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class VertexFormatManagementTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(VertexFormatManagementTesting);

    private:
        void MainTest();
        void VertexFormatTest() noexcept;

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H