///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/22 13:15)

#include "Rendering/RenderingExport.h"

#include "VolumeFogEffect.h"
#include "Detail/VolumeFogEffectImpl.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/ShaderFloats/ProjectionViewMatrixConstant.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, VolumeFogEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, VolumeFogEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, VolumeFogEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, VolumeFogEffect);

Rendering::VolumeFogEffect::VolumeFogEffect(ProgramFactory& factory,
                                            const BaseRendererSharedPtr& baseRenderer,
                                            const Texture2DSharedPtr& texture,
                                            SamplerStateFilter filter,
                                            SamplerStateMode mode0,
                                            SamplerStateMode mode1)
    : ParentType{ factory,
                  baseRenderer,
                  "Resource/Shader/VolumeFogEffect.vs",
                  "Resource/Shader/VolumeFogEffect.ps" },
      impl{ texture, filter, mode0, mode1 }
{
    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
    GetPixelShader()->Set("baseTexture", texture, "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::VolumeFogEffect::VolumeFogEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, VolumeFogEffect)

void Rendering::VolumeFogEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

void Rendering::VolumeFogEffect::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::VolumeFogEffect::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

int64_t Rendering::VolumeFogEffect::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::VolumeFogEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

int Rendering::VolumeFogEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

Rendering::VolumeFogEffect::Texture2DSharedPtr Rendering::VolumeFogEffect::GetTexture() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTexture();
}

Rendering::VolumeFogEffect::SamplerStateSharedPtr Rendering::VolumeFogEffect::GetSamplerState() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetSamplerState();
}

void Rendering::VolumeFogEffect::SetProjectionViewWorldMatrixConstant(const ConstantBufferSharedPtr& buffer)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::SetProjectionViewWorldMatrixConstant(buffer);

    GetVertexShader()->Set("projectionViewWorldMatrix", GetProjectionViewWorldMatrixConstant());
}
