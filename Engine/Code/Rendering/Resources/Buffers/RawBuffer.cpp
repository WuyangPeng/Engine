///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.0 (2022/08/10 10:27)

#include "Rendering/RenderingExport.h"

#include "RawBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, RawBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, RawBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, RawBuffer);

Rendering::RawBuffer::RawBuffer(int numElements)
    : ParentType{ numElements, 4, GraphicsObjectType::RawBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::RawBuffer::RawBuffer(int numElements, const StorageType& storage)
    : ParentType{ numElements, 4, storage, GraphicsObjectType::RawBuffer }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, RawBuffer)

CoreTools::ObjectInterfaceSharedPtr Rendering::RawBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::RawBuffer::RawBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::RawBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::RawBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::RawBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::RawBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::RawBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::RawBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}
