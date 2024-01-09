///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/19 16:17)

#include "Rendering/RenderingExport.h"

#include "SphereMapEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/State/SamplerState.h"

#include <Mathematics/Algebra/Matrix4.h>

Rendering::SphereMapEffectImpl::SphereMapEffectImpl() noexcept
    : texture{}, sampler{}, viewWorldMatrixConstant{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::SphereMapEffectImpl::SphereMapEffectImpl(Texture2DSharedPtr texture, SamplerStateFilter filter, SamplerStateMode mode0, SamplerStateMode mode1, int numViewWorldMatrixConstantBytes)
    : texture{ std::move(texture) },
      sampler{ std::make_shared<SamplerState>(filter, mode0, mode1) },
      viewWorldMatrixConstant{ std::make_shared<ConstantBuffer>("viewWorldMatrixConstant", numViewWorldMatrixConstantBytes, true) }
{
    const auto matrix = Mathematics::Matrix4<float>::GetIdentity();

    auto data = viewWorldMatrixConstant->GetStorage();
    for (const auto value : matrix.GetContainer())
    {
        data.Increase(value);
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, SphereMapEffectImpl)

Rendering::SphereMapEffectImpl::Texture2DSharedPtr Rendering::SphereMapEffectImpl::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return texture;
}

Rendering::SphereMapEffectImpl::SamplerStateSharedPtr Rendering::SphereMapEffectImpl::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return sampler;
}

Rendering::SphereMapEffectImpl::ConstantBufferSharedPtr Rendering::SphereMapEffectImpl::GetViewWorldMatrixConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return viewWorldMatrixConstant;
}

Rendering::SphereMapEffectImpl::ConstConstantBufferSharedPtr Rendering::SphereMapEffectImpl::GetViewWorldMatrixConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return viewWorldMatrixConstant;
}
