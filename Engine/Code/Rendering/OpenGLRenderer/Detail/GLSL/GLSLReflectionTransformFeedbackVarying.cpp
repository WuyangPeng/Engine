///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionTransformFeedbackVarying.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionTransformFeedbackVarying::GLSLReflectionTransformFeedbackVarying() noexcept
    : name{},
      type{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      transformFeedbackBufferIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionTransformFeedbackVarying::GLSLReflectionTransformFeedbackVarying(const std::string& name)
    : name{ name },
      type{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      transformFeedbackBufferIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionTransformFeedbackVarying)

Rendering::ReflectionTransformFeedbackVaryingImpl::ReflectionTransformFeedbackVaryingSharedPtr Rendering::GLSLReflectionTransformFeedbackVarying::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

std::string Rendering::GLSLReflectionTransformFeedbackVarying::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetType(OpenGLInt aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetTransformFeedbackBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return transformFeedbackBufferIndex;
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetTransformFeedbackBufferIndex(OpenGLInt aTransformFeedbackBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    transformFeedbackBufferIndex = aTransformFeedbackBufferIndex;
}
