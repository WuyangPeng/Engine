///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:08)

#include "Rendering/RenderingExport.h"

#include "GraphicsObject.h"
#include "Flags/GraphicsObjectType.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, GraphicsObject);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, GraphicsObject);
CORE_TOOLS_ABSTRACT_FACTORY_DEFINE(Rendering, GraphicsObject);

Rendering::GraphicsObject::GraphicsObject(const std::string& name, GraphicsObjectType type)
    : ParentType{ name }, graphicsObjectType{ type }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, GraphicsObject);

Rendering::GraphicsObjectType Rendering::GraphicsObject::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return graphicsObjectType;
}

bool Rendering::GraphicsObject::IsBuffer() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::Buffer <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::IndirectArgumentsBuffer;
}

bool Rendering::GraphicsObject::IsTexture() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::TextureSingle <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::Texture3;
}

bool Rendering::GraphicsObject::IsTextureArray() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::TextureArray <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::TextureCubeArray;
}

bool Rendering::GraphicsObject::IsShader() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::Shader <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::ComputeShader;
}

bool Rendering::GraphicsObject::IsDrawingState() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return GraphicsObjectType::DrawingState <= graphicsObjectType && graphicsObjectType <= GraphicsObjectType::RasterizerState;
}

Rendering::GraphicsObject::GraphicsObject(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }, graphicsObjectType{ GraphicsObjectType::None }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::GraphicsObject::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = ParentType::GetStreamingSize();

    size += CoreTools::GetStreamSize(graphicsObjectType);

    return size;
}

int64_t Rendering::GraphicsObject::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::GraphicsObject::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    target.WriteEnum(graphicsObjectType);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::GraphicsObject::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::GraphicsObject::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::GraphicsObject::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    source.ReadEnum(graphicsObjectType);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}