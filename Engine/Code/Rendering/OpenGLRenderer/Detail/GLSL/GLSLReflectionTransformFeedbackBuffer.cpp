///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionTransformFeedbackBuffer.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionTransformFeedbackBuffer::GLSLReflectionTransformFeedbackBuffer() noexcept
    : bufferBinding{ 0 },
      transformFeedbackBufferStride{ 0 },
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionTransformFeedbackBuffer::GLSLReflectionTransformFeedbackBuffer(OpenGLInt aBufferBinding) noexcept
    : bufferBinding{ aBufferBinding },
      transformFeedbackBufferStride{ 0 },
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionTransformFeedbackBuffer)

Rendering::ReflectionTransformFeedbackBufferImpl::ReflectionTransformFeedbackBufferSharedPtr Rendering::GLSLReflectionTransformFeedbackBuffer::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

Rendering::GLSLReflectionTransformFeedbackBuffer::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBuffer::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferBinding;
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferBinding = aBufferBinding;
}

Rendering::GLSLReflectionTransformFeedbackBuffer::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBuffer::GetTransformFeedbackBufferStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformFeedbackBufferStride;
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    transformFeedbackBufferStride = aTransformFeedbackBufferStride;
}

System::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBuffer::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return activeVariables.at(index);
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables.at(index) = aActiveVariables;
}

void Rendering::GLSLReflectionTransformFeedbackBuffer::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables = aActiveVariables;
}
