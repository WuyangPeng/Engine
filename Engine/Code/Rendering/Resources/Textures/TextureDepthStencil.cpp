/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:27)

#include "Rendering/RenderingExport.h"

#include "TextureDepthStencil.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/OpenGLRenderer/Resources/Textures/OpenGLTextureDepthStencil.h"
#include "Rendering/RendererEngine/Flags/RendererTypes.h"
#include "Rendering/Resources/DataFormat.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TextureDepthStencil);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TextureDepthStencil);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TextureDepthStencil);

Rendering::TextureDepthStencil::TextureDepthStencil(const std::string& name, DataFormatType format, int width, int height, bool hasMipMaps, bool createStorage)
    : ParentType{ name, DataFormat::IsDepth(format) ? format : DataFormatType::D24UNormS8UInt, width, height, hasMipMaps, GraphicsObjectType::TextureDepthStencil, createStorage }, shaderInput{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TextureDepthStencil)

Rendering::TextureDepthStencil::TextureDepthStencil(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, shaderInput{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

int64_t Rendering::TextureDepthStencil::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return ParentType::Register(target);
}

void Rendering::TextureDepthStencil::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.Write(shaderInput);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TextureDepthStencil::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::Link(source);
}

void Rendering::TextureDepthStencil::PostLink()
{
    RENDERING_CLASS_IS_VALID_1;

    ParentType::PostLink();
}

void Rendering::TextureDepthStencil::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.Read(shaderInput);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

int Rendering::TextureDepthStencil::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = ParentType::GetStreamingSize();

    size += CoreTools::GetStreamSize(shaderInput);

    return size;
}

Rendering::TextureSharedPtr Rendering::TextureDepthStencil::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return std::make_shared<ClassType>(*this);
}

CoreTools::ObjectInterfaceSharedPtr Rendering::TextureDepthStencil::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return Clone();
}

void Rendering::TextureDepthStencil::MakeShaderInput() noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    shaderInput = true;
}

bool Rendering::TextureDepthStencil::IsShaderInput() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return shaderInput;
}

Rendering::TextureDepthStencil::RendererObjectSharedPtr Rendering::TextureDepthStencil::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
        {
            return std::make_shared<OpenGLTextureDepthStencil>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        }
        default:
        {
            THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
        }
    }
}