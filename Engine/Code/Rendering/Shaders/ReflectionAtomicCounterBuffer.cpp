///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:34)

#include "Rendering/RenderingExport.h"

#include "ReflectionAtomicCounterBuffer.h"
#include "Detail/ReflectionAtomicCounterBufferFactory.h"
#include "Detail/ReflectionAtomicCounterBufferImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionAtomicCounterBuffer)

Rendering::ReflectionAtomicCounterBuffer::ReflectionAtomicCounterBuffer(OpenGLInt bufferBinding)
    : impl{ CoreTools::ImplCreateUseFactory::Default, bufferBinding }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionAtomicCounterBuffer)

Rendering::ReflectionAtomicCounterBuffer::OpenGLInt Rendering::ReflectionAtomicCounterBuffer::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBinding();
}

void Rendering::ReflectionAtomicCounterBuffer::SetBufferBinding(OpenGLInt bufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferBinding(bufferBinding);
}

Rendering::ReflectionAtomicCounterBuffer::OpenGLInt Rendering::ReflectionAtomicCounterBuffer::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferDataSize();
}

void Rendering::ReflectionAtomicCounterBuffer::SetBufferDataSize(OpenGLInt bufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferDataSize(bufferDataSize);
}

System::OpenGLInt Rendering::ReflectionAtomicCounterBuffer::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::ReflectionAtomicCounterBuffer::ReferencedBy Rendering::ReflectionAtomicCounterBuffer::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::ReflectionAtomicCounterBuffer::SetReferencedBy(int index, OpenGLInt referencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, referencedBy);
}

int Rendering::ReflectionAtomicCounterBuffer::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetActiveVariablesCount();
}

System::OpenGLInt Rendering::ReflectionAtomicCounterBuffer::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariables(index);
}

void Rendering::ReflectionAtomicCounterBuffer::SetActiveVariables(int index, OpenGLInt activeVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(index, activeVariables);
}

void Rendering::ReflectionAtomicCounterBuffer::SetActiveVariables(const ActiveVariables& activeVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(activeVariables);
}
