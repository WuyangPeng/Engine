///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionTransformFeedbackVaryingImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GLSLReflectionTransformFeedbackVaryingImpl() noexcept
    : name{},
      type{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      transformFeedbackBufferIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GLSLReflectionTransformFeedbackVaryingImpl(const std::string& name)
    : name{ name },
      type{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      transformFeedbackBufferIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionTransformFeedbackVaryingImpl)

std::string Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionTransformFeedbackVaryingImpl::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionTransformFeedbackVaryingImpl::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionTransformFeedbackVaryingImpl::SetType(OpenGLInt aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionTransformFeedbackVaryingImpl::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionTransformFeedbackVaryingImpl::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionTransformFeedbackVaryingImpl::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::GLSLReflectionTransformFeedbackVaryingImpl::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::GLSLReflectionTransformFeedbackVaryingImpl::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVaryingImpl::GetTransformFeedbackBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformFeedbackBufferIndex;
}

void Rendering::GLSLReflectionTransformFeedbackVaryingImpl::SetTransformFeedbackBufferIndex(OpenGLInt aTransformFeedbackBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    transformFeedbackBufferIndex = aTransformFeedbackBufferIndex;
}
