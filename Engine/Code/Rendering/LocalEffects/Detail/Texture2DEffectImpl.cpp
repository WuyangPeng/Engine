///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 19:53)

#include "Rendering/RenderingExport.h"

#include "Texture2DEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/SamplerState.h"

Rendering::Texture2DEffectImpl::Texture2DEffectImpl() noexcept
    : texture{}, sampler{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture2DEffectImpl::Texture2DEffectImpl(Texture2DSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1)
    : texture{ std::move(texture) },
      sampler{ std::make_shared<SamplerState>(filter, mode0, mode1) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Texture2DEffectImpl)

Rendering::Texture2DEffectImpl::Texture2DSharedPtr Rendering::Texture2DEffectImpl::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return texture;
}

Rendering::Texture2DEffectImpl::SamplerStateSharedPtr Rendering::Texture2DEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return sampler;
}
