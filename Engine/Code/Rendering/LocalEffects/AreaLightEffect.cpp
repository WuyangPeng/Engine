///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/07 12:40)

#include "Rendering/RenderingExport.h"

#include "AreaLightEffect.h"
#include "AreaLightEffectParameters.h"
#include "Material.h"
#include "Detail/AreaLightEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/Resources/Buffers/ConstantBufferDetail.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/ShaderDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, AreaLightEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, AreaLightEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, AreaLightEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, AreaLightEffect);

Rendering::AreaLightEffect::AreaLightEffect(ProgramFactory& factory,
                                            const BaseRendererSharedPtr& baseRenderer,
                                            SamplerStateFilter filter,
                                            SamplerStateMode mode0,
                                            SamplerStateMode mode1,
                                            const Texture2DSharedPtr& baseTexture,
                                            const Texture2DSharedPtr& normalTexture)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/AreaLightEffect.vs",
                  "Resource/Shader/AreaLightEffect.ps" },
      impl{ filter,
            mode0,
            mode1,
            baseTexture,
            normalTexture,
            Material::Create()->GetStreamingSize(),
            Rendering::GetStreamSize<Colour<float>>(),
            AreaLightEffectParameters::Create().GetStreamingSize() }
{
    const auto vertexShader = GetVertexShader();
    const auto pixelShader = GetPixelShader();
    vertexShader->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    pixelShader->Set("Material", impl->GetMaterialConstant());
    pixelShader->Set("Camera", impl->GetCameraConstant());
    pixelShader->Set("AreaLight", impl->GetAreaLightConstant());
    pixelShader->Set("baseTexture", impl->GetBaseTexture(), "baseSampler", impl->GetCommonSampler());
    pixelShader->Set("normalTexture", impl->GetNormalTexture(), "normalSampler", impl->GetCommonSampler());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::AreaLightEffect::AreaLightEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, AreaLightEffect)

void Rendering::AreaLightEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::AreaLightEffect::GetMaterialConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMaterialConstant();
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::AreaLightEffect::GetCameraConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCameraConstant();
}

Rendering::VisualEffect::ConstConstantBufferSharedPtr Rendering::AreaLightEffect::GetAreaLightConstant() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAreaLightConstant();
}
