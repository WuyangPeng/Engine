///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/18 16:35)

#ifndef RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H
#define RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Rendering
{
    class OpenGLVertexFormatDataTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(OpenGLVertexFormatDataTesting);

    private:
        void MainTest();
        void AttributeUsagePositionTest();
        void AttributeUsageNormalTest();
        void AttributeUsageTangentTest();
        void AttributeUsageBinormalTest();
        void AttributeUsageBlendIndicesTest();
        void AttributeUsageBlendWeightTest();
        void AttributeUsageFogCoordTest();
        void AttributeUsagePsizeTest();

        void DoRunUnitTest() override;
    };
}

#endif  // RENDERING_RENDERING_OPENGL_RENDERER_SUITE_OPENGL_VERTEX_FORMAT_DATA_TESTING_H