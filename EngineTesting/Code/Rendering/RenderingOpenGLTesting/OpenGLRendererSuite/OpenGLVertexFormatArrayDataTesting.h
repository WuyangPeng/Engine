// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.0.3 (2019/09/09 15:36)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_ARRAY_DATA_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_ARRAY_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class OpenGLVertexFormatArrayDataTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLVertexFormatArrayDataTesting);

    private:
        void MainTest();
        void AttributeUsageTextureCoordTest();
        void AttributeUsageColorTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_ARRAY_DATA_TESTING_H