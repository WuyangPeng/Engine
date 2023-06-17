///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:25)

#include "Rendering/RenderingExport.h"

#include "StructuredBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "Rendering/OpenGLRenderer/Resources/Buffers/OpenGLStructuredBuffer.h"
#include "Rendering/Renderers/Flags/RendererTypes.h"
#include "Rendering/Resources/Flags/CounterType.h"
#include "Rendering/Resources/Flags/UsageType.h"

CORE_TOOLS_RTTI_DEFINE(Rendering, StructuredBuffer);
CORE_TOOLS_STATIC_OBJECT_FACTORY_DEFINE(Rendering, StructuredBuffer);
CORE_TOOLS_FACTORY_DEFINE(Rendering, StructuredBuffer);

Rendering::StructuredBuffer::StructuredBuffer(int numElements, int elementSize)
    : ParentType{ numElements, elementSize, GraphicsObjectType::StructuredBuffer },
      counterType{ CounterType::None },
      keepInternalCount{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::StructuredBuffer::StructuredBuffer(int numElements, int elementSize, const StorageType& storage)
    : ParentType{ numElements, elementSize, storage, GraphicsObjectType::StructuredBuffer },
      counterType{ CounterType::None },
      keepInternalCount{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, StructuredBuffer)

CoreTools::ObjectInterfaceSharedPtr Rendering::StructuredBuffer::CloneObject() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

Rendering::CounterType Rendering::StructuredBuffer::GetCounterType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return counterType;
}

void Rendering::StructuredBuffer::MakeAppendConsume() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    counterType = CounterType::AppendConsume;
    SetUsage(UsageType::ShaderOutput);
}

void Rendering::StructuredBuffer::MakeCounter() noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    counterType = CounterType::Counter;
    SetUsage(UsageType::ShaderOutput);
}

void Rendering::StructuredBuffer::SetKeepInternalCount(bool aKeepInternalCount) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    if (counterType != CounterType::None)
    {
        keepInternalCount = aKeepInternalCount;
    }
}

bool Rendering::StructuredBuffer::GetKeepInternalCount() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return keepInternalCount;
}

Rendering::StructuredBuffer::StructuredBuffer(LoadConstructor loadConstructor)
    : ParentType{ loadConstructor },
      counterType{ CounterType::None },
      keepInternalCount{ false }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

int Rendering::StructuredBuffer::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::GetStreamingSize();
}

int64_t Rendering::StructuredBuffer::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return ParentType::Register(target);
}

void Rendering::StructuredBuffer::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_SAVE(target);

    ParentType::Save(target);

    CORE_TOOLS_END_DEBUG_STREAM_SAVE(target);
}

void Rendering::StructuredBuffer::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::Link(source);
}

void Rendering::StructuredBuffer::PostLink()
{
    RENDERING_CLASS_IS_VALID_9;

    ParentType::PostLink();
}

void Rendering::StructuredBuffer::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    CORE_TOOLS_BEGIN_DEBUG_STREAM_LOAD(source);

    ParentType::Load(source);

    CORE_TOOLS_END_DEBUG_STREAM_LOAD(source);
}

Rendering::StructuredBuffer::RendererObjectSharedPtr Rendering::StructuredBuffer::CreateRendererObject(RendererTypes rendererTypes)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    switch (rendererTypes)
    {
        case RendererTypes::OpenGL:
            return std::make_shared<OpenGLStructuredBuffer>(boost::polymorphic_pointer_cast<ClassType>(shared_from_this()), GetName());
        default:
            return ParentType::CreateRendererObject(rendererTypes);
    }
}