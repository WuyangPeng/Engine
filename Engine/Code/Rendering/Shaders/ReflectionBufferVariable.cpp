/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:12)

#include "Rendering/RenderingExport.h"

#include "ReflectionBufferVariable.h"
#include "Detail/ReflectionBufferVariableFactory.h"
#include "Detail/ReflectionBufferVariableImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionBufferVariable)

Rendering::ReflectionBufferVariable::ReflectionBufferVariable(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionBufferVariable)

std::string Rendering::ReflectionBufferVariable::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFullName();
}

void Rendering::ReflectionBufferVariable::SetFullName(const std::string& fullName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFullName(fullName);
}

std::string Rendering::ReflectionBufferVariable::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionBufferVariable::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionBufferVariable::GLSLReflectionEnumType Rendering::ReflectionBufferVariable::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::ReflectionBufferVariable::SetType(GLSLReflectionEnumType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(type);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::ReflectionBufferVariable::SetArraySize(OpenGLInt arraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(arraySize);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::ReflectionBufferVariable::SetOffset(OpenGLInt offset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(offset);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBlockIndex();
}

void Rendering::ReflectionBufferVariable::SetBlockIndex(OpenGLInt blockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBlockIndex(blockIndex);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBlockIndex();
}

void Rendering::ReflectionBufferVariable::SetArrayStride(OpenGLInt arrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArrayStride(arrayStride);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMatrixStride();
}

void Rendering::ReflectionBufferVariable::SetMatrixStride(OpenGLInt matrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetMatrixStride(matrixStride);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsRowMajor();
}

void Rendering::ReflectionBufferVariable::SetIsRowMajor(OpenGLInt isRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsRowMajor(isRowMajor);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetTopLevelArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTopLevelArraySize();
}

void Rendering::ReflectionBufferVariable::SetTopLevelArraySize(OpenGLInt topLevelArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTopLevelArraySize(topLevelArraySize);
}

Rendering::ReflectionBufferVariable::OpenGLInt Rendering::ReflectionBufferVariable::GetTopLevelArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTopLevelArrayStride();
}

void Rendering::ReflectionBufferVariable::SetTopLevelArrayStride(OpenGLInt topLevelArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTopLevelArrayStride(topLevelArrayStride);
}

System::OpenGLInt Rendering::ReflectionBufferVariable::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::ReflectionBufferVariable::ReferencedBy Rendering::ReflectionBufferVariable::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::ReflectionBufferVariable::SetReferencedBy(int index, OpenGLInt referencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, referencedBy);
}
