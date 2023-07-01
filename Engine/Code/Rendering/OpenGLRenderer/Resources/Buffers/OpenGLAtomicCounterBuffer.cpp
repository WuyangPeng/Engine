///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "OpenGLAtomicCounterBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"
#include "System/OpenGL/OpenGLBuffers.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/CounterType.h"

Rendering::OpenGLAtomicCounterBuffer::OpenGLAtomicCounterBuffer(const RawBufferSharedPtr& buffer, const std::string& name)
    : ParentType{ buffer, name, BindBuffer::AtomicCounterBuffer }
{
    Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLAtomicCounterBuffer)

Rendering::ConstRawBufferSharedPtr Rendering::OpenGLAtomicCounterBuffer::GetRawBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const RawBuffer>(GetGraphicsObject());
}

void Rendering::OpenGLAtomicCounterBuffer::Enable() noexcept
{
    RENDERING_CLASS_IS_VALID_9;
}

bool Rendering::OpenGLAtomicCounterBuffer::CopyGpuToCpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLAtomicCounterBuffer::CopyGpuToCpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLAtomicCounterBuffer::CopyCpuToGpu(MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLAtomicCounterBuffer::CopyCpuToGpu(MAYBE_UNUSED int item, MAYBE_UNUSED int level)
{
    CoreTools::DisableNoexcept();

    return false;
}

bool Rendering::OpenGLAtomicCounterBuffer::GetNumActiveElements()
{
    CoreTools::DisableNoexcept();

    return false;
}

void Rendering::OpenGLAtomicCounterBuffer::AttachToUnit(OpenGLInt atomicCounterBufferUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindBufferBase(BindBuffer::AtomicCounterBuffer, atomicCounterBufferUnit, GetGLHandle());
}
