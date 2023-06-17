///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionAtomicCounterBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionAtomicCounterBufferImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionAtomicCounterBuffer)

Rendering::GLSLReflectionAtomicCounterBuffer::GLSLReflectionAtomicCounterBuffer(OpenGLInt bufferBinding)
    : impl{ bufferBinding }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionAtomicCounterBuffer)

Rendering::GLSLReflectionAtomicCounterBuffer::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBinding();
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferBinding(aBufferBinding);
}

Rendering::GLSLReflectionAtomicCounterBuffer::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferDataSize();
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferDataSize(aBufferDataSize);
}

System::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::GLSLReflectionAtomicCounterBuffer::ReferencedBy Rendering::GLSLReflectionAtomicCounterBuffer::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, aReferencedBy);
}

int Rendering::GLSLReflectionAtomicCounterBuffer::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->GetActiveVariablesCount();
}

System::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariables(index);
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(index, aActiveVariables);
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(aActiveVariables);
}
