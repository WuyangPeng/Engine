///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 19:53)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE_2D_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE_2D_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Texture2DEffectImpl
    {
    public:
        using ClassType = Texture2DEffectImpl;

        using Texture2DSharedPtr = std::shared_ptr<Texture2D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        Texture2DEffectImpl() noexcept;
        Texture2DEffectImpl(Texture2DSharedPtr texture,
                            SamplerStateFilter filter,
                            SamplerStateMode mode0,
                            SamplerStateMode mode1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Texture2DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;

    private:
        Texture2DSharedPtr texture;
        SamplerStateSharedPtr sampler;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE_2D_EFFECT_IMPL_H
