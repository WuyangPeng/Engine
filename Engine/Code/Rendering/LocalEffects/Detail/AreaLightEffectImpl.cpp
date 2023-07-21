///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/07 11:10)

#include "Rendering/RenderingExport.h"

#include "AreaLightEffectImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/Resources/Buffers/ConstantBuffer.h"
#include "Rendering/State/SamplerState.h"

Rendering::AreaLightEffectImpl::AreaLightEffectImpl() noexcept
    : materialConstant{},
      cameraConstant{},
      areaLightConstant{},
      baseTexture{},
      normalTexture{},
      commonSampler{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::AreaLightEffectImpl::AreaLightEffectImpl(SamplerStateFilter filter,
                                                    SamplerStateMode mode0,
                                                    SamplerStateMode mode1,
                                                    Texture2DSharedPtr baseTexture,
                                                    Texture2DSharedPtr normalTexture,
                                                    int numMaterialConstantBytes,
                                                    int numLightingConstantBytes,
                                                    int numGeometryConstantBytes)
    : materialConstant{ std::make_shared<ConstantBuffer>(numMaterialConstantBytes, true) },
      cameraConstant{ std::make_shared<ConstantBuffer>(numLightingConstantBytes, true) },
      areaLightConstant{ std::make_shared<ConstantBuffer>(numGeometryConstantBytes, true) },
      baseTexture{ std::move(baseTexture) },
      normalTexture{ std::move(normalTexture) },
      commonSampler{ std::make_shared<SamplerState>(filter, mode0, mode1) }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, AreaLightEffectImpl)

Rendering::AreaLightEffectImpl::ConstConstantBufferSharedPtr Rendering::AreaLightEffectImpl::GetMaterialConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return materialConstant;
}

Rendering::AreaLightEffectImpl::ConstConstantBufferSharedPtr Rendering::AreaLightEffectImpl::GetCameraConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return cameraConstant;
}

Rendering::AreaLightEffectImpl::ConstConstantBufferSharedPtr Rendering::AreaLightEffectImpl::GetAreaLightConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return areaLightConstant;
}

Rendering::AreaLightEffectImpl::ConstantBufferSharedPtr Rendering::AreaLightEffectImpl::GetMaterialConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return materialConstant;
}

Rendering::AreaLightEffectImpl::ConstantBufferSharedPtr Rendering::AreaLightEffectImpl::GetCameraConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return cameraConstant;
}

Rendering::AreaLightEffectImpl::ConstantBufferSharedPtr Rendering::AreaLightEffectImpl::GetAreaLightConstant() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return areaLightConstant;
}

Rendering::AreaLightEffectImpl::Texture2DSharedPtr Rendering::AreaLightEffectImpl::GetBaseTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return baseTexture;
}

Rendering::AreaLightEffectImpl::Texture2DSharedPtr Rendering::AreaLightEffectImpl::GetNormalTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return normalTexture;
}

Rendering::AreaLightEffectImpl::SamplerStateSharedPtr Rendering::AreaLightEffectImpl::GetCommonSampler() noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return commonSampler;
}
