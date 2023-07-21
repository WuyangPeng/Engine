///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 20:16)

#include "Rendering/RenderingExport.h"

#include "Texture3DEffect.h"
#include "Detail/Texture3DEffectImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/Resources/Textures/Texture3D.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture3DEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture3DEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture3DEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture3DEffect);

Rendering::Texture3DEffect::Texture3DEffect(ProgramFactory& factory,
                                            const BaseRendererSharedPtr& baseRenderer,
                                            const Texture3DSharedPtr& texture,
                                            SamplerStateFilter filter,
                                            SamplerStateMode mode0,
                                            SamplerStateMode mode1,
                                            SamplerStateMode mode2)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/Texture3DEffect.vs",
                  "Resource/Shader/Texture3DEffect.ps" },
      impl{ texture, filter, mode0, mode1, mode2 }
{
    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    GetPixelShader()->Set("baseTexture", texture, "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture3DEffect::Texture3DEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Texture3DEffect)

Rendering::Texture3DEffect::Texture3DSharedPtr Rendering::Texture3DEffect::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTexture();
}

Rendering::Texture3DEffect::SamplerStateSharedPtr Rendering::Texture3DEffect::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetSamplerState();
}

void Rendering::Texture3DEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}
