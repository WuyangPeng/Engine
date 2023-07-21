///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 16:17)

#ifndef RENDERING_LOCAL_EFFECTS_SPHERE_MAP_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_SPHERE_MAP_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE SphereMapEffectImpl
    {
    public:
        using ClassType = SphereMapEffectImpl;

        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;
        using ConstantBufferSharedPtr = std::shared_ptr<ConstantBuffer>;
        using ConstConstantBufferSharedPtr = std::shared_ptr<const ConstantBuffer>;

    public:
        SphereMapEffectImpl() noexcept;
        SphereMapEffectImpl(Texture2DSharedPtr texture,
                            SamplerStateFilter filter,
                            SamplerStateMode mode0,
                            SamplerStateMode mode1,
                            int numViewWorldMatrixConstantBytes);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Texture2DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;
        NODISCARD ConstantBufferSharedPtr GetViewWorldMatrixConstant() noexcept;
        NODISCARD ConstConstantBufferSharedPtr GetViewWorldMatrixConstant() const noexcept;

    private:
        Texture2DSharedPtr texture;
        SamplerStateSharedPtr sampler;
        ConstantBufferSharedPtr viewWorldMatrixConstant;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_SPHERE_MAP_EFFECT_IMPL_H
