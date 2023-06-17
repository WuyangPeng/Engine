///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionTransformFeedbackBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionTransformFeedbackBufferImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionTransformFeedbackBuffer)

Rendering::GLSLReflectionTransformFeedbackBuffer::GLSLReflectionTransformFeedbackBuffer(OpenGLInt aBufferBinding)
    : impl{ aBufferBinding }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionTransformFeedbackBuffer)

Rendering::GLSLReflectionTransformFeedbackBuffer::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBuffer::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBinding();
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferBinding(aBufferBinding);
}

Rendering::GLSLReflectionTransformFeedbackBuffer::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBuffer::GetTransformFeedbackBufferStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTransformFeedbackBufferStride();
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTransformFeedbackBufferStride(aTransformFeedbackBufferStride);
}

System::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBuffer::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariables(index);
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(index, aActiveVariables);
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(aActiveVariables);
}
