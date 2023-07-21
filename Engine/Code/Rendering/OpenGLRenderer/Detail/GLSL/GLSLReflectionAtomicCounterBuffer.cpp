///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionAtomicCounterBuffer.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionAtomicCounterBuffer::GLSLReflectionAtomicCounterBuffer() noexcept
    : ParentType{},
      bufferBinding{ 0 },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionAtomicCounterBuffer::GLSLReflectionAtomicCounterBuffer(OpenGLInt bufferBinding) noexcept
    : ParentType{},
      bufferBinding{ bufferBinding },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionAtomicCounterBuffer)

Rendering::ReflectionAtomicCounterBufferImpl::ReflectionAtomicCounterBufferSharedPtr Rendering::GLSLReflectionAtomicCounterBuffer::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

Rendering::GLSLReflectionAtomicCounterBuffer::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferBinding;
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferBinding = aBufferBinding;
}

Rendering::GLSLReflectionAtomicCounterBuffer::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferDataSize;
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferDataSize = aBufferDataSize;
}

System::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionAtomicCounterBuffer::ReferencedBy Rendering::GLSLReflectionAtomicCounterBuffer::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

int Rendering::GLSLReflectionAtomicCounterBuffer::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(activeVariables.size());
}

System::OpenGLInt Rendering::GLSLReflectionAtomicCounterBuffer::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return activeVariables.at(index);
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables.at(index) = aActiveVariables;
}

void Rendering::GLSLReflectionAtomicCounterBuffer::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables = aActiveVariables;
}
