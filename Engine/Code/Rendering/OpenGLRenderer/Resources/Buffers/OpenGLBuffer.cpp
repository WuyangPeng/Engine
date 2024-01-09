/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 14:43)

#include "Rendering/RenderingExport.h"

#include "OpenGLBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/UsageType.h"

Rendering::OpenGLBuffer::OpenGLBuffer(const BufferSharedPtr& buffer, const std::string& name, BindBuffer type)
    : ParentType{ buffer, name }, type{ type }, usage{}
{
    SetGLHandle(System::GetGLGenBuffers());

    if (const auto bufferUsage = buffer->GetUsage();
        bufferUsage == UsageType::Immutable)
    {
        usage = BufferUsage::Static;
    }
    else if (bufferUsage == UsageType::DynamicUpdate)
    {
        usage = BufferUsage::Dynamic;
    }
    else  // bufferUsage == UsageType::ShaderOutput
    {
        if (type == BindBuffer::ArrayBuffer)
        {
            usage = BufferUsage::Static;
        }
        else if (type == BindBuffer::ShaderStorageBuffer)
        {
            usage = BufferUsage::Dynamic;
        }
        else
        {
            usage = BufferUsage::Static;
        }
    }

    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::OpenGLBuffer::~OpenGLBuffer() noexcept
{
    System::SetGLDeleteBuffers(ParentType::GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLBuffer)

Rendering::ConstBufferSharedPtr Rendering::OpenGLBuffer::GetBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Buffer>(GetGraphicsObject());
}

Rendering::BufferSharedPtr Rendering::OpenGLBuffer::GetBuffer()
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<Buffer>(GetGraphicsObject());
}

System::BindBuffer Rendering::OpenGLBuffer::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

System::BufferUsage Rendering::OpenGLBuffer::GetUsage() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return usage;
}

void Rendering::OpenGLBuffer::Initialize()
{
    SetGLBindBuffer(type, GetGLHandle());

    const auto buffer = GetBuffer();

    SetGLBufferData(type, buffer->GetNumBytes(), buffer->GetOriginalData(), usage);

    SetGLBindBuffer(type, 0);
}

bool Rendering::OpenGLBuffer::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto buffer = GetBuffer();
    if (buffer->GetUsage() != UsageType::DynamicUpdate)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区使用的不是DynamicUpdate"s))
    }

    if (const auto numActiveBytes = buffer->GetNumActiveBytes();
        0 < numActiveBytes)
    {
        const auto offsetInBytes = buffer->GetOffset() * buffer->GetElementSize();

        const auto* source = buffer->GetOriginalData(offsetInBytes);
        SetGLBindBuffer(type, GetGLHandle());
        SetGLBufferSubData(type, offsetInBytes, numActiveBytes, source);
        SetGLBindBuffer(type, 0);
    }

    return true;
}

bool Rendering::OpenGLBuffer::CopyCpuToGpu()
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::WriteOnly))
    {
        return false;
    }

    const auto buffer = GetBuffer();

    if (const auto numActiveBytes = buffer->GetNumActiveBytes();
        0 < numActiveBytes)
    {
        const auto offsetInBytes = buffer->GetOffset() * buffer->GetElementSize();

        const auto* source = buffer->GetOriginalData(offsetInBytes);
        SetGLBindBuffer(type, GetGLHandle());
        SetGLBufferSubData(type, offsetInBytes, numActiveBytes, source);
        SetGLBindBuffer(type, 0);
    }

    return true;
}

bool Rendering::OpenGLBuffer::CopyGpuToCpu()
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::ReadOnly))
    {
        return false;
    }

    const auto buffer = GetBuffer();

    if (const auto numActiveBytes = buffer->GetNumActiveBytes();
        0 < numActiveBytes)
    {
        const auto offsetInBytes = buffer->GetOffset() * buffer->GetElementSize();

        const auto target = buffer->GetOriginalData(offsetInBytes);
        SetGLBindBuffer(type, GetGLHandle());
        GetGLBufferSubData(type, offsetInBytes, numActiveBytes, target);
        SetGLBindBuffer(type, 0);
    }

    return true;
}
