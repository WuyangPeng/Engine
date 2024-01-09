/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/08 14:51)

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
    ParentType::Initialize();

    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Rendering, OpenGLAtomicCounterBuffer)

Rendering::ConstRawBufferSharedPtr Rendering::OpenGLAtomicCounterBuffer::GetRawBuffer() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::polymorphic_pointer_cast<const RawBuffer>(GetGraphicsObject());
}

void Rendering::OpenGLAtomicCounterBuffer::AttachToUnit(OpenGLInt atomicCounterBufferUnit) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    SetGLBindBufferBase(BindBuffer::AtomicCounterBuffer, atomicCounterBufferUnit, GetGLHandle());
}
