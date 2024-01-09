/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/29 14:03)

#include "Rendering/RenderingExport.h"

#include "IndirectArgumentsBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, IndirectArgumentsBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, IndirectArgumentsBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, IndirectArgumentsBuffer);

Rendering::IndirectArgumentsBuffer::IndirectArgumentsBuffer(const std::string& name, int numElements, bool createStorage)
    : ParentType{ name, numElements, 4, GraphicsObjectType::IndirectArgumentsBuffer, createStorage }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::IndirectArgumentsBuffer::IndirectArgumentsBuffer(const std::string& name, int numElements, const StorageType& storage)
    : ParentType{ name, numElements, 4, storage, GraphicsObjectType::IndirectArgumentsBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, IndirectArgumentsBuffer)

CoreTools::ObjectInterfaceSharedPtr Rendering::IndirectArgumentsBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::GraphicsObject::RendererObjectSharedPtr Rendering::IndirectArgumentsBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_SELF_CLASS_IS_VALID_9;

    System::UnusedFunction(rendererTypes);

    THROW_EXCEPTION(SYSTEM_TEXT("渲染类型不存在。"s))
}

Rendering::IndirectArgumentsBuffer::IndirectArgumentsBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::IndirectArgumentsBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::IndirectArgumentsBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::IndirectArgumentsBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::IndirectArgumentsBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::IndirectArgumentsBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::IndirectArgumentsBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
