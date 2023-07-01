///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.0 (2023/06/29 17:03)

#include "Rendering/RenderingExport.h"

#include "TypedBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, TypedBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, TypedBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, TypedBuffer);

Rendering::TypedBuffer::TypedBuffer(int numElements, int elementSize)
    : ParentType{ numElements, elementSize, GraphicsObjectType::TypedBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::TypedBuffer::TypedBuffer(int numElements, int elementSize, const StorageType& storage)
    : ParentType{ numElements, elementSize, storage, GraphicsObjectType::TypedBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, TypedBuffer)

CoreTools::ObjectInterfaceSharedPtr Rendering::TypedBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::GraphicsObject::RendererObjectSharedPtr Rendering::TypedBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererTypes);

    THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s));
}

Rendering::TypedBuffer::TypedBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::TypedBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::TypedBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::TypedBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::TypedBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::TypedBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::TypedBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
