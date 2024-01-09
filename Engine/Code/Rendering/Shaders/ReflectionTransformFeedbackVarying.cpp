/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:13)

#include "Rendering/RenderingExport.h"

#include "ReflectionTransformFeedbackVarying.h"
#include "Detail/ReflectionTransformFeedbackVaryingFactory.h"
#include "Detail/ReflectionTransformFeedbackVaryingImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionTransformFeedbackVarying)

Rendering::ReflectionTransformFeedbackVarying::ReflectionTransformFeedbackVarying(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionTransformFeedbackVarying)

std::string Rendering::ReflectionTransformFeedbackVarying::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionTransformFeedbackVarying::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionTransformFeedbackVarying::OpenGLInt Rendering::ReflectionTransformFeedbackVarying::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::ReflectionTransformFeedbackVarying::SetType(OpenGLInt type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(type);
}

Rendering::ReflectionTransformFeedbackVarying::OpenGLInt Rendering::ReflectionTransformFeedbackVarying::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::ReflectionTransformFeedbackVarying::SetArraySize(OpenGLInt arraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(arraySize);
}

Rendering::ReflectionTransformFeedbackVarying::OpenGLInt Rendering::ReflectionTransformFeedbackVarying::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::ReflectionTransformFeedbackVarying::SetOffset(OpenGLInt offset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(offset);
}

Rendering::ReflectionTransformFeedbackVarying::OpenGLInt Rendering::ReflectionTransformFeedbackVarying::GetTransformFeedbackBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTransformFeedbackBufferIndex();
}

void Rendering::ReflectionTransformFeedbackVarying::SetTransformFeedbackBufferIndex(OpenGLInt transformFeedbackBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTransformFeedbackBufferIndex(transformFeedbackBufferIndex);
}
