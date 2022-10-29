///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/04 20:46)

#ifndef RENDERING_STATE_SUITE_RASTERIZER_STATE_TESTING_H
#define RENDERING_STATE_SUITE_RASTERIZER_STATE_TESTING_H

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"
#include "Rendering/State/RasterizerState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RasterizerStateTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = RasterizerStateTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit RasterizerStateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();
        void StreamCreateExceptionTest();

        void StreamTest();
        void GetStreamingSizeTest();

        void LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer);

        NODISCARD int GetCorrectIndex(const RasterizerStateSharedPtr& state) const;

        void RasterizerStateTest();

        void RasterizerStateValueTest();
        void RasterizerStateSaveTest();

        void ConstructorTest();
        void SetFillTest();
        void SetCullTest();
        void SetFrontCCWTest();
        void SetDepthBiasTest();
        void SetDepthBiasClampTest();
        void SetSlopeScaledDepthBiasTest();
        void SetEnableDepthClipTest();
        void SetEnableScissorTest(); 
        void SetEnableMultisampleTest(); 
        void SetEnableAntialiasedLineTest();

        NODISCARD GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const override;

    private:
        RasterizerStateFill fill;
        RasterizerStateCull cull;
        bool frontCCW;
        int depthBias;
        float depthBiasClamp;
        float slopeScaledDepthBias;
        bool enableDepthClip;
        bool enableScissor;
        bool enableMultisample;
        bool enableAntialiasedLine;
        RasterizerStateSharedPtr rasterizerState;
    };
}

#endif  // RENDERING_STATE_SUITE_RASTERIZER_STATE_TESTING_H