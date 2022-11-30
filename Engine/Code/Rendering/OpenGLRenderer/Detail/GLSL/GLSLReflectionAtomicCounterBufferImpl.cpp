///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/30 14:31)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionAtomicCounterBufferImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionAtomicCounterBufferImpl::GLSLReflectionAtomicCounterBufferImpl() noexcept
    : bufferBinding{ 0 },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionAtomicCounterBufferImpl::GLSLReflectionAtomicCounterBufferImpl(OpenGLInt bufferBinding) noexcept
    : bufferBinding{ bufferBinding },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionAtomicCounterBufferImpl)

Rendering::GLSLReflectionAtomicCounterBufferImpl::OpenGLInt Rendering::GLSLReflectionAtomicCounterBufferImpl::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferBinding;
}

void Rendering::GLSLReflectionAtomicCounterBufferImpl::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferBinding = aBufferBinding;
}

Rendering::GLSLReflectionAtomicCounterBufferImpl::OpenGLInt Rendering::GLSLReflectionAtomicCounterBufferImpl::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferDataSize;
}

void Rendering::GLSLReflectionAtomicCounterBufferImpl::SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferDataSize = aBufferDataSize;
}

System::OpenGLInt Rendering::GLSLReflectionAtomicCounterBufferImpl::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionAtomicCounterBufferImpl::ReferencedBy Rendering::GLSLReflectionAtomicCounterBufferImpl::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionAtomicCounterBufferImpl::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

int Rendering::GLSLReflectionAtomicCounterBufferImpl::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(activeVariables.size());
}

System::OpenGLInt Rendering::GLSLReflectionAtomicCounterBufferImpl::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return activeVariables.at(index);
}

void Rendering::GLSLReflectionAtomicCounterBufferImpl::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables.at(index) = aActiveVariables;
}

void Rendering::GLSLReflectionAtomicCounterBufferImpl::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables = aActiveVariables;
}
