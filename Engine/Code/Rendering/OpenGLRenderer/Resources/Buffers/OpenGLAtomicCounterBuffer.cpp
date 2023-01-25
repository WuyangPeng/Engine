///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/21 14:12)

#include "Rendering/RenderingExport.h"

#include "OpenGLAtomicCounterBuffer.h"
#include "System/Helper/PragmaWarning/PolymorphicPointerCast.h"
#include "System/OpenGL/Flags/OpenGLFlags.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Rendering/Resources/Flags/CounterType.h"
#include "System/OpenGL/OpenGLBuffers.h"

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

void Rendering::OpenGLAtomicCounterBuffer::AttachToUnit(OpenGLInt atomicCounterBufferUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    System::SetGLBindBufferBase(BindBuffer::AtomicCounterBuffer, atomicCounterBufferUnit, GetGLHandle());
}