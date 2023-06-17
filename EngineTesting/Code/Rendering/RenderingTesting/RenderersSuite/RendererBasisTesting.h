///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:40)

#ifndef RENDERING_RENDERERS_SUITE_RENDERER_BASIS_TESTING_H
#define RENDERING_RENDERERS_SUITE_RENDERER_BASIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/Renderers/RenderersFwd.h"
#include "Rendering/Resources/ResourcesFwd.h"

namespace Rendering
{
    class RendererBasisTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = RendererBasisTesting;
        using ParentType = UnitTest;

    public:
        explicit RendererBasisTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();
        void ConstructionTest();
        void ExceptionTest();

        void ExecuteTest(const RendererBasis& rendererBasis);
        void SetSizeTest(RendererBasis& rendererBasis);
        void SetMultisamplesNumberTest(RendererBasis& rendererBasis);
        void SetDataFormat(RendererBasis& rendererBasis);

        void WidthConstructionExceptionTest();
        void HeightConstructionExceptionTest();
        void MultisamplesNumberConstructionExceptionTest();
        void SetWidthConstructionExceptionTest();
        void SetHeightConstructionExceptionTest();
        void SetMultisamplesNumberConstructionExceptionTest();

    private:
        int windowWidth;
        int windowHeight;
        DataFormatType colorFormat;
        DataFormatType depthStencilFormat;
        int multisamplesNumber;
    };
}

#endif  // RENDERING_RENDERERS_SUITE_RENDERER_BASIS_TESTING_H