///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 22:17)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionTransformFeedbackBufferImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionTransformFeedbackBufferImpl::GLSLReflectionTransformFeedbackBufferImpl() noexcept
    : bufferBinding{ 0 },
      transformFeedbackBufferStride{ 0 },
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionTransformFeedbackBufferImpl::GLSLReflectionTransformFeedbackBufferImpl(OpenGLInt aBufferBinding) noexcept
    : bufferBinding{ aBufferBinding },
      transformFeedbackBufferStride{ 0 },
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionTransformFeedbackBufferImpl)

Rendering::GLSLReflectionTransformFeedbackBufferImpl::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBufferImpl::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferBinding;
}

void Rendering::GLSLReflectionTransformFeedbackBufferImpl::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferBinding = aBufferBinding;
}

Rendering::GLSLReflectionTransformFeedbackBufferImpl::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBufferImpl::GetTransformFeedbackBufferStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformFeedbackBufferStride;
}

void Rendering::GLSLReflectionTransformFeedbackBufferImpl::SetTransformFeedbackBufferStride(OpenGLInt aTransformFeedbackBufferStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    transformFeedbackBufferStride = aTransformFeedbackBufferStride;
}

System::OpenGLInt Rendering::GLSLReflectionTransformFeedbackBufferImpl::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return activeVariables.at(index);
}

void Rendering::GLSLReflectionTransformFeedbackBufferImpl::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables.at(index) = aActiveVariables;
}

void Rendering::GLSLReflectionTransformFeedbackBufferImpl::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables = aActiveVariables;
}
