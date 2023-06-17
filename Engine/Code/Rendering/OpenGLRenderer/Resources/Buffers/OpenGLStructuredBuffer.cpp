///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:28)

#include "Rendering/RenderingExport.h"

#include "OpenGLStructuredBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/CounterType.h"

Rendering::OpenGLStructuredBuffer::OpenGLStructuredBuffer(const StructuredBufferSharedPtr& buffer, const std::string& name)
    : ParentType{ buffer, name, BindBuffer::ShaderStorageBuffer }, counterOffset{ 0 }
{
    Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLStructuredBuffer)

void Rendering::OpenGLStructuredBuffer::AttachToUnit(OpenGLInt shaderStorageBufferUnit)
{
    RENDERING_CLASS_IS_VALID_9;

    auto buffer = GetStructuredBuffer();

    System::SetGLBindBufferRange(BindBuffer::ShaderStorageBuffer, shaderStorageBufferUnit, GetGLHandle(), 0, buffer->GetNumBytes());
}

bool Rendering::OpenGLStructuredBuffer::CopyCounterValueToBuffer(const OpenGLBuffer* targetBuffer, OpenGLInt offset)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!targetBuffer)
    {
        return false;
    }

    auto buffer = GetStructuredBuffer();
    if (CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    System::SetGLBindBuffer(BindBuffer::CopyReadBuffer, GetGLHandle());
    System::SetGLBindBuffer(BindBuffer::CopyWriteBuffer, targetBuffer->GetGLHandle());
    System::SetGLCopyBufferSubData(BindBuffer::CopyReadBuffer, BindBuffer::CopyWriteBuffer, counterOffset, offset, 4);

    return true;
}

bool Rendering::OpenGLStructuredBuffer::CopyCounterValueFromBuffer(const OpenGLBuffer* sourceBuffer, OpenGLInt offset)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!sourceBuffer)
    {
        return false;
    }

    auto buffer = GetStructuredBuffer();
    if (CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    System::SetGLBindBuffer(BindBuffer::CopyReadBuffer, sourceBuffer->GetGLHandle());
    System::SetGLBindBuffer(BindBuffer::CopyWriteBuffer, GetGLHandle());
    System::SetGLCopyBufferSubData(BindBuffer::CopyReadBuffer, BindBuffer::CopyWriteBuffer, offset, counterOffset, 4);

    return true;
}

bool Rendering::OpenGLStructuredBuffer::GetNumActiveElements()
{
    RENDERING_CLASS_IS_VALID_9;

    auto buffer = boost::polymorphic_pointer_cast<StructuredBuffer>(GetGraphicsObject());
    if (CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    OpenGLInt count{};
    System::SetGLBindBuffer(GetType(), GetGLHandle());
    System::GetGLBufferSubData(GetType(), counterOffset, 4, &count);
    System::SetGLBindBuffer(GetType(), 0);

    count = std::max(0, count);
    buffer->SetNumActiveElements(count);

    return true;
}

bool Rendering::OpenGLStructuredBuffer::SetNumActiveElements()
{
    RENDERING_CLASS_IS_VALID_9;

    auto buffer = GetStructuredBuffer();
    if (CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    if (!buffer->GetKeepInternalCount())
    {
        const auto count = buffer->GetNumActiveElements();

        System::SetGLBindBuffer(GetType(), GetGLHandle());
        System::SetGLBufferSubData(GetType(), counterOffset, 4, &count);
        System::SetGLBindBuffer(GetType(), 0);
    }

    return true;
}

bool Rendering::OpenGLStructuredBuffer::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_9;

    auto buffer = GetStructuredBuffer();

    if (CounterType::None != buffer->GetCounterType())
    {
        if (!GetNumActiveElements())
        {
            return false;
        }
    }

    return ParentType::CopyGpuToCpu();
}

void Rendering::OpenGLStructuredBuffer::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

void Rendering::OpenGLStructuredBuffer::Initialize()
{
    auto buffer = GetStructuredBuffer();

    if (CounterType::None == buffer->GetCounterType())
    {
        ParentType::Initialize();
    }
    else
    {
        System::SetGLBindBuffer(GetType(), GetGLHandle());

        auto numBytes = buffer->GetNumBytes();

        numBytes = ((numBytes + 3) / 4) * 4;
        counterOffset = numBytes;

        numBytes += 4;

        System::SetGLBufferData(GetType(), numBytes, nullptr, BufferUsage::Dynamic);

        System::SetGLBufferSubData(GetType(), 0, buffer->GetNumBytes(), buffer->GetOriginalData());

        const auto count = buffer->GetNumElements();
        System::SetGLBufferSubData(GetType(), counterOffset, 4, &count);

        System::SetGLBindBuffer(GetType(), 0);
    }
}

Rendering::ConstStructuredBufferSharedPtr Rendering::OpenGLStructuredBuffer::GetStructuredBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const StructuredBuffer>(GetGraphicsObject());
}
