///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 11:08)

#ifndef RENDERING_STATE_SAMPLER_STATE_IMPL_H
#define RENDERING_STATE_SAMPLER_STATE_IMPL_H

#include "Rendering/RenderingDll.h"

#include "CoreTools/ObjectSystems/ObjectSystemsFwd.h"
#include "Rendering/DataTypes/Colour.h"
#include "Rendering/State/StateFwd.h"

#include <array>
#include <vector>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SamplerStateImpl
    {
    public:
        using ClassType = SamplerStateImpl;
        using Colour = Colour<float>;

    public:
        SamplerStateImpl() noexcept;
        SamplerStateImpl(SamplerStateFilter filter,
                         SamplerStateMode mode0,
                         SamplerStateMode mode1) noexcept;
        SamplerStateImpl(SamplerStateFilter filter,
                         SamplerStateMode mode0,
                         SamplerStateMode mode1,
                         SamplerStateMode mode2) noexcept;

        CLASS_INVARIANT_DECLARE;

        void Load(CoreTools::BufferSource& source);
        void Save(CoreTools::BufferTarget& target) const;
        NODISCARD int GetStreamingSize() const noexcept;

        NODISCARD SamplerStateFilter GetFilter() const noexcept;
        NODISCARD SamplerStateMode GetMode(int index) const;
        NODISCARD float GetMipLODBias() const noexcept;
        NODISCARD int GetMaxAnisotropy() const noexcept;
        NODISCARD SamplerStateComparison GetComparison() const noexcept;
        NODISCARD Colour GetBorderColor() const noexcept;
        NODISCARD float GetMinLOD() const noexcept;
        NODISCARD float GetMaxLOD() const noexcept;

    private:
        static constexpr auto numMode = 3;

    private:
        using ModeContainer = std::array<SamplerStateMode, numMode>;

        SamplerStateFilter filter;
        ModeContainer mode;
        float mipLODBias;
        int maxAnisotropy;
        SamplerStateComparison comparison;
        Colour borderColor;
        float minLOD;
        float maxLOD;
    };
}

#endif  // RENDERING_STATE_SAMPLER_STATE_IMPL_H