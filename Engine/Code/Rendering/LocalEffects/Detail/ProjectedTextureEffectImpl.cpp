///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 14:16)

#include "Rendering/RenderingExport.h"

#include "ProjectedTextureEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/State/SamplerState.h"

Rendering::ProjectedTextureEffectImpl::ProjectedTextureEffectImpl() noexcept
    : texture{}, sampler{}, projectorMatrixConstant{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectedTextureEffectImpl::ProjectedTextureEffectImpl(Texture2DSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, int numProjectorMatrixConstantBytes)
    : texture{ std::move(texture) },
      sampler{ std::make_shared<SamplerState>(filter, mode0, mode1) },
      projectorMatrixConstant{ std::make_shared<ConstantBuffer>("projectorMatrixConstant", numProjectorMatrixConstantBytes, true) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProjectedTextureEffectImpl)

Rendering::ProjectedTextureEffectImpl::Texture2DSharedPtr Rendering::ProjectedTextureEffectImpl::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return texture;
}

Rendering::ProjectedTextureEffectImpl::SamplerStateSharedPtr Rendering::ProjectedTextureEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return sampler;
}

Rendering::ProjectedTextureEffectImpl::ConstantBufferSharedPtr Rendering::ProjectedTextureEffectImpl::GetProjectorMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return projectorMatrixConstant;
}
