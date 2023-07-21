///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 20:16)

#ifndef RENDERING_LOCAL_EFFECTS_TEXTURE_3D_EFFECT_IMPL_H
#define RENDERING_LOCAL_EFFECTS_TEXTURE_3D_EFFECT_IMPL_H

#include "Rendering/RenderingDll.h"

#include "Rendering/Resources/ResourcesFwd.h"
#include "Rendering/State/StateFwd.h"

#include <memory>

namespace Rendering
{
    class RENDERING_HIDDEN_DECLARE Texture3DEffectImpl
    {
    public:
        using ClassType = Texture3DEffectImpl;

        using Texture3DSharedPtr = std::shared_ptr<Texture3D>;
        using SamplerStateSharedPtr = std::shared_ptr<SamplerState>;

    public:
        Texture3DEffectImpl() noexcept;
        Texture3DEffectImpl(Texture3DSharedPtr texture,
                            SamplerStateFilter filter,
                            SamplerStateMode mode0,
                            SamplerStateMode mode1,
                            SamplerStateMode mode2);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Texture3DSharedPtr GetTexture() noexcept;
        NODISCARD SamplerStateSharedPtr GetSamplerState() noexcept;

    private:
        Texture3DSharedPtr texture;
        SamplerStateSharedPtr sampler;
    };
}

#endif  // RENDERING_LOCAL_EFFECTS_TEXTURE_3D_EFFECT_IMPL_H
