///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/20 19:35)

#include "Rendering/RenderingExport.h"

#include "TextEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/DataTypes/SpecializedIO.h"
#include "Rendering/LocalEffects/Detail/TextEffectImpl.h"
#include "Rendering/RendererEngine/BaseRenderer.h"
#include "Rendering/Resources/Textures/Texture2D.h"
#include "Rendering/Shaders/Shader.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextEffect);

Rendering::TextEffect::TextEffect(ProgramFactory& factory, const std::string& shaderExtendName, const Texture2DSharedPtr& texture)
    : ParentType{ "TextEffect", factory.CreateFromFiles("Resource/Shader/TextEffect.vs" + shaderExtendName, "Resource/Shader/TextEffect.ps" + shaderExtendName, "") },
      impl{ factory.GetAPI(), Rendering::GetStreamSize<Mathematics::Vector3<float>>(), Rendering::GetStreamSize<Mathematics::Vector4<float>>() }
{
    GetVertexShader()->Set("Translate", GetTranslate());

    const auto pixelShader = GetPixelShader();
    pixelShader->Set("TextColor", GetColor());
    pixelShader->Set("baseTexture", texture, "baseSampler", impl->GetSamplerState());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextEffect)

Rendering::TextEffect::TextEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::ImplCreateUseDefaultConstruction::Default }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CORE_TOOLS_DEFAULT_OBJECT_REGISTER_DEFINE(Rendering, TextEffect)
CORE_TOOLS_DEFAULT_OBJECT_LINK_DEFINE(Rendering, TextEffect)
CORE_TOOLS_DEFAULT_OBJECT_POST_LINK_DEFINE(Rendering, TextEffect)

int Rendering::TextEffect::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

void Rendering::TextEffect::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextEffect::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::TextEffect::ObjectInterfaceSharedPtr Rendering::TextEffect::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::TextEffect::ConstConstantBufferSharedPtr Rendering::TextEffect::GetTranslate() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTranslate();
}

Rendering::TextEffect::ConstConstantBufferSharedPtr Rendering::TextEffect::GetColor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetColor();
}

Rendering::VisualEffect::ConstantBufferSharedPtr Rendering::TextEffect::GetTranslate() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetTranslate();
}

Rendering::VisualEffect::ConstantBufferSharedPtr Rendering::TextEffect::GetColor() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetColor();
}

void Rendering::TextEffect::SetTranslate(float x, float y)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTranslate(x, y);
}

void Rendering::TextEffect::SetNormalizedZ(float z)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetNormalizedZ(z);
}

void Rendering::TextEffect::SetColor(const ColourType& aColor)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetColor(aColor);
}
