/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/06 11:32)

#ifndef RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_IMPL_H
#define RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Helper/Constant.h"
#include "Rendering/OpenGLRenderer/State/OpenGLBlendStateTarget.h"
#include "Rendering/State/BlendState.h"
#include "Rendering/State/StateFwd.h"

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE OpenGLBlendStateImpl
    {
    public:
        using ClassType = OpenGLBlendStateImpl;

        using Colour = Colour<float>;
        using BlendStateTargetContainer = std::array<OpenGLBlendStateTarget, numBlendStateTargets>;
        using BlendStateTargetContainerConstIter = BlendStateTargetContainer::const_iterator;

    public:
        OpenGLBlendStateImpl() noexcept;
        explicit OpenGLBlendStateImpl(const BlendState& blendState);

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsEnableAlphaToCoverage() const noexcept;
        void SetEnableAlphaToCoverage(bool aEnableAlphaToCoverage) noexcept;

        NODISCARD bool IsEnableIndependentBlend() const noexcept;
        void SetEnableIndependentBlend(bool aEnableIndependentBlend) noexcept;

        NODISCARD Colour GetBlendColor() const noexcept;
        void SetBlendColor(const Colour& aBlendColor) noexcept;

        NODISCARD uint32_t GetSampleMask() const noexcept;
        void SetSampleMask(uint32_t aSampleMask) noexcept;

        NODISCARD OpenGLBlendStateTarget GetBlendStateTarget(int index) const;
        void SetBlendStateTarget(int index, const OpenGLBlendStateTarget& aBlendStateTarget);

        NODISCARD BlendStateTargetContainerConstIter begin() const noexcept;
        NODISCARD BlendStateTargetContainerConstIter end() const noexcept;

        NODISCARD static System::BlendStateMode GetBlendStateMode(BlendStateMode blendStateMode);
        NODISCARD static System::BlendStateOperation GetBlendStateOperation(BlendStateOperation blendStateOperation);

    private:
        bool enableAlphaToCoverage;
        bool enableIndependentBlend;
        BlendStateTargetContainer blendStateTarget;
        Colour blendColor;
        uint32_t sampleMask;
    };
}

#endif  // RENDERING_OPENGL_RENDERER_OPENGL_BLEND_STATE_IMPL_H
