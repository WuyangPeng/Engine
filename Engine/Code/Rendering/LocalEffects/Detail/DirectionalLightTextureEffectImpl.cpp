///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/12 11:08)

#include "Rendering/RenderingExport.h"

#include "DirectionalLightTextureEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/SamplerState.h"

Rendering::DirectionalLightTextureEffectImpl::DirectionalLightTextureEffectImpl() noexcept
    : texture{},
      sampler{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::DirectionalLightTextureEffectImpl::DirectionalLightTextureEffectImpl(Texture2DSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1)
    : texture{ std::move(texture) },
      sampler{ std::make_shared<SamplerState>(filter, mode0, mode1) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, DirectionalLightTextureEffectImpl)

Rendering::DirectionalLightTextureEffectImpl::Texture2DSharedPtr Rendering::DirectionalLightTextureEffectImpl::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return texture;
}

Rendering::DirectionalLightTextureEffectImpl::SamplerStateSharedPtr Rendering::DirectionalLightTextureEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return sampler;
}
