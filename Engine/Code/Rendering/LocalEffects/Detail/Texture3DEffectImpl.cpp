///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 20:16)

#include "Rendering/RenderingExport.h"

#include "Texture3DEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/SamplerState.h"

Rendering::Texture3DEffectImpl::Texture3DEffectImpl() noexcept
    : texture{}, sampler{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture3DEffectImpl::Texture3DEffectImpl(Texture3DSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, SamplerStateMode mode2)
    : texture{ std::move(texture) },
      sampler{ std::make_shared<SamplerState>(filter, mode0, mode1, mode2) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Texture3DEffectImpl)

Rendering::Texture3DEffectImpl::Texture3DSharedPtr Rendering::Texture3DEffectImpl::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return texture;
}

Rendering::Texture3DEffectImpl::SamplerStateSharedPtr Rendering::Texture3DEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return sampler;
}
