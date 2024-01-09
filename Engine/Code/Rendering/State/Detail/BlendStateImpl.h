/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 11:09)

#ifndef RENDERING_STATE_BLEND_STATE_IMPL_H
#define RENDERING_STATE_BLEND_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/Helper/Constant.h"
#include "Rendering/State/BlendStateTarget.h"

#include <array>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE BlendStateImpl
    {
    public:
        using ClassType = BlendStateImpl;

        using Colour = Colour<float>;
        using BufferSource = CoreTools::BufferSource;
        using BufferTarget = CoreTools::BufferTarget;

    public:
        BlendStateImpl() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool IsEnableAlphaToCoverage() const noexcept;
        void SetEnableAlphaToCoverage(bool aEnableAlphaToCoverage) noexcept;

        NODISCARD bool IsEnableIndependentBlend() const noexcept;
        void SetEnableIndependentBlend(bool aEnableIndependentBlend) noexcept;

        NODISCARD Colour GetBlendColor() const noexcept;
        void SetBlendColor(const Colour& aBlendColor) noexcept;

        NODISCARD uint32_t GetSampleMask() const noexcept;
        void SetSampleMask(uint32_t aSampleMask) noexcept;

        NODISCARD BlendStateTarget GetBlendStateTarget(int index) const;
        void SetBlendStateTarget(int index, const BlendStateTarget& aBlendStateTarget);

        void Load(BufferSource& source);
        void Save(BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

    private:
        using BlendStateTargetContainer = std::array<BlendStateTarget, numBlendStateTargets>;

    private:
        bool enableAlphaToCoverage;
        bool enableIndependentBlend;
        BlendStateTargetContainer blendStateTarget;
        Colour blendColor;
        uint32_t sampleMask;
    };
}

#endif  // RENDERING_STATE_BLEND_STATE_IMPL_H