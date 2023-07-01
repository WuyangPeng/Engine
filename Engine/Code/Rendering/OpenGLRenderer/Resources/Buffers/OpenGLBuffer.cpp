///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

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

    const auto bufferUsage = buffer->GetUsage();
    if (bufferUsage == UsageType::Immutable)
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
    System::SetGLDeleteBuffers(GetGLHandle());

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLBuffer)

Rendering::ConstBufferSharedPtr Rendering::OpenGLBuffer::GetBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const Buffer>(GetGraphicsObject());
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
    System::SetGLBindBuffer(type, GetGLHandle());

    auto buffer = GetBuffer();

    System::SetGLBufferData(type, buffer->GetNumBytes(), buffer->GetOriginalData(), usage);

    System::SetGLBindBuffer(type, 0);
}

bool Rendering::OpenGLBuffer::Update()
{
    RENDERING_CLASS_IS_VALID_9;

    auto buffer = GetBuffer();
    if (buffer->GetUsage() != UsageType::DynamicUpdate)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("缓冲区使用的不是DynamicUpdate"s));
    }

    const auto numActiveBytes = buffer->GetNumActiveBytes();
    if (0 < numActiveBytes)
    {
        const auto offsetInBytes = buffer->GetOffset() * buffer->GetElementSize();

        auto source = buffer->GetOriginalData(offsetInBytes);
        System::SetGLBindBuffer(type, GetGLHandle());
        System::SetGLBufferSubData(type, offsetInBytes, numActiveBytes, source);
        System::SetGLBindBuffer(type, 0);
    }

    return true;
}

bool Rendering::OpenGLBuffer::Update(MAYBE_UNUSED int level) noexcept
{
    return true;
}

bool Rendering::OpenGLBuffer::Update(MAYBE_UNUSED int item, MAYBE_UNUSED int level) noexcept
{
    return true;
}

bool Rendering::OpenGLBuffer::CopyCpuToGpu()
{
    RENDERING_CLASS_IS_VALID_9;

    if (!PreparedForCopy(BufferLocking::WriteOnly))
    {
        return false;
    }

    auto buffer = GetBuffer();
    const auto numActiveBytes = buffer->GetNumActiveBytes();
    if (0 < numActiveBytes)
    {
        const auto offsetInBytes = buffer->GetOffset() * buffer->GetElementSize();

        auto source = buffer->GetOriginalData(offsetInBytes);
        System::SetGLBindBuffer(type, GetGLHandle());
        System::SetGLBufferSubData(type, offsetInBytes, numActiveBytes, source);
        System::SetGLBindBuffer(type, 0);
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

    auto buffer = boost::polymorphic_pointer_cast<Buffer>(GetGraphicsObject());
    const auto numActiveBytes = buffer->GetNumActiveBytes();
    if (0 < numActiveBytes)
    {
        const auto offsetInBytes = buffer->GetOffset() * buffer->GetElementSize();

        auto target = buffer->GetOriginalData(offsetInBytes);
        System::SetGLBindBuffer(type, GetGLHandle());
        System::GetGLBufferSubData(type, offsetInBytes, numActiveBytes, target);
        System::SetGLBindBuffer(type, 0);
    }

    return true;
}
