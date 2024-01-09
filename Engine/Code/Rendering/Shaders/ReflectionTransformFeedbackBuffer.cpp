/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:13)

#include "Rendering/RenderingExport.h"

#include "ReflectionTransformFeedbackBuffer.h"
#include "Detail/ReflectionTransformFeedbackBufferFactory.h"
#include "Detail/ReflectionTransformFeedbackBufferImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionTransformFeedbackBuffer)

Rendering::ReflectionTransformFeedbackBuffer::ReflectionTransformFeedbackBuffer(OpenGLInt bufferBinding)
    : impl{ CoreTools::ImplCreateUseFactory::Default, bufferBinding }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionTransformFeedbackBuffer)

Rendering::ReflectionTransformFeedbackBuffer::OpenGLInt Rendering::ReflectionTransformFeedbackBuffer::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBinding();
}

void Rendering::ReflectionTransformFeedbackBuffer::SetBufferBinding(OpenGLInt bufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferBinding(bufferBinding);
}

Rendering::ReflectionTransformFeedbackBuffer::OpenGLInt Rendering::ReflectionTransformFeedbackBuffer::GetTransformFeedbackBufferStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTransformFeedbackBufferStride();
}

void Rendering::ReflectionTransformFeedbackBuffer::SetTransformFeedbackBufferStride(OpenGLInt transformFeedbackBufferStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTransformFeedbackBufferStride(transformFeedbackBufferStride);
}

System::OpenGLInt Rendering::ReflectionTransformFeedbackBuffer::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariables(index);
}

void Rendering::ReflectionTransformFeedbackBuffer::SetActiveVariables(int index, OpenGLInt activeVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(index, activeVariables);
}

void Rendering::ReflectionTransformFeedbackBuffer::SetActiveVariables(const ActiveVariables& activeVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(activeVariables);
}
