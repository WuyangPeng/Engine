///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionBufferVariable.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionBufferVariableImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionBufferVariable)

Rendering::GLSLReflectionBufferVariable::GLSLReflectionBufferVariable(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionBufferVariable)

std::string Rendering::GLSLReflectionBufferVariable::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFullName();
}

void Rendering::GLSLReflectionBufferVariable::SetFullName(const std::string& aFullName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFullName(aFullName);
}

std::string Rendering::GLSLReflectionBufferVariable::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionBufferVariable::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionBufferVariable::GLSLReflectionEnumType Rendering::GLSLReflectionBufferVariable::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::GLSLReflectionBufferVariable::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(aType);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::GLSLReflectionBufferVariable::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(aArraySize);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::GLSLReflectionBufferVariable::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(aOffset);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBlockIndex();
}

void Rendering::GLSLReflectionBufferVariable::SetBlockIndex(OpenGLInt aBlockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBlockIndex(aBlockIndex);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBlockIndex();
}

void Rendering::GLSLReflectionBufferVariable::SetArrayStride(OpenGLInt aArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArrayStride(aArrayStride);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMatrixStride();
}

void Rendering::GLSLReflectionBufferVariable::SetMatrixStride(OpenGLInt aMatrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetMatrixStride(aMatrixStride);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsRowMajor();
}

void Rendering::GLSLReflectionBufferVariable::SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsRowMajor(aIsRowMajor);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetTopLevelArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTopLevelArraySize();
}

void Rendering::GLSLReflectionBufferVariable::SetTopLevelArraySize(OpenGLInt aTopLevelArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTopLevelArraySize(aTopLevelArraySize);
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetTopLevelArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetTopLevelArrayStride();
}

void Rendering::GLSLReflectionBufferVariable::SetTopLevelArrayStride(OpenGLInt aTopLevelArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetTopLevelArrayStride(aTopLevelArrayStride);
}

System::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::GLSLReflectionBufferVariable::ReferencedBy Rendering::GLSLReflectionBufferVariable::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::GLSLReflectionBufferVariable::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, aReferencedBy);
}
