/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 14:56)

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
    ClassType::Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLStructuredBuffer)

void Rendering::OpenGLStructuredBuffer::AttachToUnit(OpenGLInt shaderStorageBufferUnit)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto buffer = GetStructuredBuffer();

    SetGLBindBufferRange(BindBuffer::ShaderStorageBuffer, shaderStorageBufferUnit, GetGLHandle(), 0, buffer->GetNumBytes());
}

bool Rendering::OpenGLStructuredBuffer::CopyCounterValueToBuffer(const OpenGLBuffer* targetBuffer, OpenGLInt offset)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!targetBuffer)
    {
        return false;
    }

    if (const auto buffer = GetStructuredBuffer();
        CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    SetGLBindBuffer(BindBuffer::CopyReadBuffer, GetGLHandle());
    SetGLBindBuffer(BindBuffer::CopyWriteBuffer, targetBuffer->GetGLHandle());
    SetGLCopyBufferSubData(BindBuffer::CopyReadBuffer, BindBuffer::CopyWriteBuffer, counterOffset, offset, 4);

    return true;
}

bool Rendering::OpenGLStructuredBuffer::CopyCounterValueFromBuffer(const OpenGLBuffer* sourceBuffer, OpenGLInt offset)
{
    RENDERING_CLASS_IS_VALID_9;

    if (!sourceBuffer)
    {
        return false;
    }

    if (const auto buffer = GetStructuredBuffer();
        CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    SetGLBindBuffer(BindBuffer::CopyReadBuffer, sourceBuffer->GetGLHandle());
    SetGLBindBuffer(BindBuffer::CopyWriteBuffer, GetGLHandle());
    SetGLCopyBufferSubData(BindBuffer::CopyReadBuffer, BindBuffer::CopyWriteBuffer, offset, counterOffset, 4);

    return true;
}

bool Rendering::OpenGLStructuredBuffer::GetNumActiveElements()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto buffer = boost::polymorphic_pointer_cast<StructuredBuffer>(GetGraphicsObject());
    if (CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    OpenGLInt count{};
    SetGLBindBuffer(GetType(), GetGLHandle());
    GetGLBufferSubData(GetType(), counterOffset, 4, &count);
    SetGLBindBuffer(GetType(), 0);

    count = std::max(0, count);
    buffer->SetNumActiveElements(count);

    return true;
}

bool Rendering::OpenGLStructuredBuffer::SetNumActiveElements()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto buffer = GetStructuredBuffer();
    if (CounterType::None == buffer->GetCounterType())
    {
        return false;
    }

    if (!buffer->GetKeepInternalCount())
    {
        const auto count = buffer->GetNumActiveElements();

        SetGLBindBuffer(GetType(), GetGLHandle());
        SetGLBufferSubData(GetType(), counterOffset, 4, &count);
        SetGLBindBuffer(GetType(), 0);
    }

    return true;
}

bool Rendering::OpenGLStructuredBuffer::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto buffer = GetStructuredBuffer();

    if (CounterType::None != buffer->GetCounterType())
    {
        if (!GetNumActiveElements())
        {
            return false;
        }
    }

    return ParentType::CopyGpuToCpu();
}

void Rendering::OpenGLStructuredBuffer::Initialize()
{
    if (const auto buffer = GetStructuredBuffer();
        CounterType::None == buffer->GetCounterType())
    {
        ParentType::Initialize();
    }
    else
    {
        SetGLBindBuffer(GetType(), GetGLHandle());

        auto numBytes = buffer->GetNumBytes();

        numBytes = ((numBytes + 3) / 4) * 4;
        counterOffset = numBytes;

        numBytes += 4;

        SetGLBufferData(GetType(), numBytes, nullptr, BufferUsage::Dynamic);

        SetGLBufferSubData(GetType(), 0, buffer->GetNumBytes(), buffer->GetOriginalData());

        const auto count = buffer->GetNumElements();
        SetGLBufferSubData(GetType(), counterOffset, 4, &count);

        SetGLBindBuffer(GetType(), 0);
    }
}

Rendering::ConstStructuredBufferSharedPtr Rendering::OpenGLStructuredBuffer::GetStructuredBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const StructuredBuffer>(GetGraphicsObject());
}
