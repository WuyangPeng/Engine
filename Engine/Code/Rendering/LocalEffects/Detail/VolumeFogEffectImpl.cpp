///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/22 13:14)

#include "Rendering/RenderingExport.h"

#include "VolumeFogEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/State/SamplerState.h"

Rendering::VolumeFogEffectImpl::VolumeFogEffectImpl() noexcept
    : texture{}, sampler{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VolumeFogEffectImpl::VolumeFogEffectImpl(Texture2DSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1)
    : texture{ std::move(texture) },
      sampler{ std::make_shared<SamplerState>(filter, mode0, mode1) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VolumeFogEffectImpl)

Rendering::VolumeFogEffectImpl::Texture2DSharedPtr Rendering::VolumeFogEffectImpl::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return texture;
}

Rendering::VolumeFogEffectImpl::SamplerStateSharedPtr Rendering::VolumeFogEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return sampler;
}
