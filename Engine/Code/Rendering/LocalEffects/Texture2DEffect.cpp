///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:45)

#include "Rendering/RenderingExport.h"

#include "Texture2DEffect.h"
#include "Detail/Texture2DEffectImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, Texture2DEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, Texture2DEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, Texture2DEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, Texture2DEffect);

Rendering::Texture2DEffect::Texture2DEffect(ProgramFactory& factory,
                                            const BaseRendererSharedPtr& baseRenderer,
                                            const Texture2DSharedPtr& texture,
                                            SamplerStateFilter filter,
                                            SamplerStateMode mode0,
                                            SamplerStateMode mode1)
    : ParentType{ "Texture2DEffect",
                  factory,
                  baseRenderer,
                  "Resource/Shader/Texture2DEffect.vs",
                  "Resource/Shader/Texture2DEffect.ps" },
      impl{ texture, filter, mode0, mode1 }
{
    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    GetPixelShader()->Set("baseTexture", texture, "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::Texture2DEffect::Texture2DEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, Texture2DEffect)

void Rendering::Texture2DEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::Texture2DEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::Texture2DEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

int64_t Rendering::Texture2DEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::Texture2DEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::Texture2DEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

Rendering::Texture2DEffect::Texture2DSharedPtr Rendering::Texture2DEffect::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTexture();
}

Rendering::Texture2DEffect::SamplerStateSharedPtr Rendering::Texture2DEffect::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetSamplerState();
}

void Rendering::Texture2DEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}
