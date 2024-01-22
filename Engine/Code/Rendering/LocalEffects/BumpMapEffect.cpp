/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 16:43)

#include "Rendering/RenderingExport.h"

#include "BumpMapEffect.h"
#include "Detail/BumpMapEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Resources/Buffers/ConstantBufferDetail.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/ShaderDetail.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, BumpMapEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, BumpMapEffect)

CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, BumpMapEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, BumpMapEffect);

Rendering::BumpMapEffect::BumpMapEffect(const std::string& name,
                                        ProgramFactory& factory,
                                        const BaseRendererSharedPtr& baseRenderer,
                                        SamplerStateFilter filter,
                                        SamplerStateMode mode0,
                                        SamplerStateMode mode1,
                                        const Texture2DSharedPtr& baseTexture,
                                        const Texture2DSharedPtr& normalTexture)
    : ParentType{ name,
                  factory,
                  baseRenderer,
                  "Resource/Shader/BumpMapEffect.vs",
                  "Resource/Shader/BumpMapEffect.ps" },
      impl{ filter,
            mode0,
            mode1,
            baseTexture,
            normalTexture }
{
    const auto vertexShader = GetVertexShader();
    const auto pixelShader = GetPixelShader();

    vertexShader->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());

    pixelShader->Set("baseTexture", impl->GetBaseTexture(), "baseSampler", impl->GetCommonSampler());
    pixelShader->Set("normalTexture", impl->GetNormalTexture(), "normalSampler", impl->GetCommonSampler());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BumpMapEffect::BumpMapEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BumpMapEffect)

void Rendering::BumpMapEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("ProjectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}

Rendering::BumpMapEffect::ConstTexture2DSharedPtr Rendering::BumpMapEffect::GetBaseTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBaseTexture();
}

Rendering::BumpMapEffect::ConstTexture2DSharedPtr Rendering::BumpMapEffect::GetNormalTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetNormalTexture();
}

Rendering::BumpMapEffect::ConstSamplerStateSharedPtr Rendering::BumpMapEffect::GetCommonSampler() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCommonSampler();
}

void Rendering::BumpMapEffect::ComputeLightVectors(const VisualSharedPtr& mesh, const Vector4& worldLightDirection)
{
    return ImplType::ComputeLightVectors(mesh, worldLightDirection);
}
