///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/12 15:02)

#ifndef RENDERING_STATE_SUITE_BLEND_STATE_TESTING_H
#define RENDERING_STATE_SUITE_BLEND_STATE_TESTING_H

#include "Rendering/Base/BaseFwd.h"
#include "Rendering/RenderingTesting/BaseSuite/GraphicsObjectTestingBase.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class BlendStateTesting final : public GraphicsObjectTestingBase
    {
    public:
        using ClassType = BlendStateTesting;
        using ParentType = GraphicsObjectTestingBase;

    public:
        explicit BlendStateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        static constexpr auto numTargets = 8;

    private:
        using Colour = Colour<float>;
        using BlendStateTargetContainer = std::array<BlendStateTarget, numTargets>;

    private:
        void DoRunUnitTest() final;

        void MainTest();

        void AccessTest();
        void StreamCreateExceptionTest();

        void StreamTest();
        void GetStreamingSizeTest();

        void LoadExceptionTest(const FileBufferSharedPtr& saveFileBuffer);

        NODISCARD int GetCorrectIndex(const BlendStateSharedPtr& state) const;

        void BlendStateTest();

        void BlendStateValueTest();
        void BlendStateSaveTest();

        void ConstructorTest();
        void SetEnableAlphaToCoverageTest();
        void SetEnableIndependentBlendTest();
        void SetBlendColorTest();
        void SetSampleMaskTest();
        void SetBlendStateTargetTest();

        NODISCARD GraphicsObjectSharedPtr Create(const std::string& name, GraphicsObjectType graphicsObjectType) const override;

    private:
        bool enableAlphaToCoverage;
        bool enableIndependentBlend;
        BlendStateTargetContainer blendStateTarget;
        Colour blendColor;
        uint32_t sampleMask;
        BlendStateSharedPtr blendState;
    };
}

#endif  // RENDERING_STATE_SUITE_BLEND_STATE_TESTING_H