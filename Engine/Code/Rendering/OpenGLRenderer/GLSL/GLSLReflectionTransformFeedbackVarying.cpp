///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.3 (2022/10/29 22:17)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionTransformFeedbackVarying.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionTransformFeedbackVaryingImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionTransformFeedbackVarying)

Rendering::GLSLReflectionTransformFeedbackVarying::GLSLReflectionTransformFeedbackVarying(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionTransformFeedbackVarying)

std::string Rendering::GLSLReflectionTransformFeedbackVarying::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetType(OpenGLInt aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(aType);
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(aArraySize);
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(aOffset);
}

Rendering::GLSLReflectionTransformFeedbackVarying::OpenGLInt Rendering::GLSLReflectionTransformFeedbackVarying::GetTransformFeedbackBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTransformFeedbackBufferIndex();
}

void Rendering::GLSLReflectionTransformFeedbackVarying::SetTransformFeedbackBufferIndex(OpenGLInt aTransformFeedbackBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTransformFeedbackBufferIndex(aTransformFeedbackBufferIndex);
}
