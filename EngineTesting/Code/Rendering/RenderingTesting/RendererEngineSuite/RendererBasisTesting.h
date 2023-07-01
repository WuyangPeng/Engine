///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/25 14:32)

#ifndef RENDERING_RENDERER_ENGINE_SUITE_RENDERER_BASIS_TESTING_H
#define RENDERING_RENDERER_ENGINE_SUITE_RENDERER_BASIS_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Rendering/RendererEngine/RendererEngineFwd.h"
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
        void DoRunUnitTest() override;
        void MainTest();

        void AccessTest();
        void ConstructionTest();
        void ExceptionTest();

        void ExecuteTest(const RendererBasis& rendererBasis);
        void SetSizeTest(RendererBasis& rendererBasis);
        void SetMultiSamplesNumberTest(RendererBasis& rendererBasis);
        void SetDataFormat(RendererBasis& rendererBasis);

        void WidthConstructionExceptionTest();
        void HeightConstructionExceptionTest();
        void MultiSamplesNumberConstructionExceptionTest();
        void SetWidthConstructionExceptionTest();
        void SetHeightConstructionExceptionTest();
        void SetMultiSamplesNumberConstructionExceptionTest();

    private:
        int windowWidth;
        int windowHeight;
        DataFormatType colorFormat;
        DataFormatType depthStencilFormat;
        int multiSamplesNumber;
    };
}

#endif  // RENDERING_RENDERER_ENGINE_SUITE_RENDERER_BASIS_TESTING_H