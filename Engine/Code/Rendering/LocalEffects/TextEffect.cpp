///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/05 10:58)

#include "Rendering/RenderingExport.h"

#include "TextEffect.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/LocalEffects/Detail/TextEffectImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, TextEffect)

CORE_TOOLS_RTTI_DEFINE(Rendering, TextEffect);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextEffect);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextEffect);

using namespace std::literals;

namespace
{
    const auto vsSource =
        R"(
    uniform Translate
    {
        vec3 translate;
    };

    layout(location = 0) in vec2 modelPosition;
    layout(location = 1) in vec2 modelTCoord;
    layout(location = 0) out vec2 vertexTCoord;

    void main()
    {
        vertexTCoord = modelTCoord;
        gl_Position.x = 2.0f * modelPosition.x - 1.0f + 2.0f * translate.x;
        gl_Position.y = 2.0f * modelPosition.y - 1.0f + 2.0f * translate.y;
        gl_Position.z = translate.z;
        gl_Position.w = 1.0f;
    }
)"s;

    const auto psSource =
        R"(
    uniform TextColor
    {
        vec4 textColor;
    };

    layout(location = 0) in vec2 vertexTCoord;
    layout(location = 0) out vec4 pixelColor;

    uniform sampler2D baseSampler;

    void main()
    {
        float bitmapAlpha = texture(baseSampler, vertexTCoord).r;
        if (bitmapAlpha > 0.5f)
        {
            discard;
        }
        pixelColor = textColor;
    }
)"s;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Rendering::TextEffect::TextEffect(const ProgramFactorySharedPtr& factory, const Texture2DSharedPtr& texture)
    : ParentType{ factory->CreateFromSources(vsSource, psSource, "") }, impl{ texture, *GetProgram() }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}
#include STSTEM_WARNING_POP

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextEffect)

Rendering::TextEffect::TextEffect(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, impl{ CoreTools::DisableNotThrow::Disable }
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

void Rendering::TextEffect::SetColor(const Colour& aColor)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetColor(aColor);
}
