///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/30 14:31)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionUniform.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionUniformImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionUniform)

Rendering::GLSLReflectionUniform::GLSLReflectionUniform(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionUniform)

std::string Rendering::GLSLReflectionUniform::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFullName();
}

void Rendering::GLSLReflectionUniform::SetFullName(const std::string& aFullName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFullName(aFullName);
}

std::string Rendering::GLSLReflectionUniform::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionUniform::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionUniform::GLSLReflectionEnumType Rendering::GLSLReflectionUniform::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::GLSLReflectionUniform::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(aType);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::GLSLReflectionUniform::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(aLocation);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::GLSLReflectionUniform::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(aArraySize);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::GLSLReflectionUniform::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(aOffset);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBlockIndex();
}

void Rendering::GLSLReflectionUniform::SetBlockIndex(OpenGLInt aBlockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBlockIndex(aBlockIndex);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArrayStride();
}

void Rendering::GLSLReflectionUniform::SetArrayStride(OpenGLInt aArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArrayStride(aArrayStride);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMatrixStride();
}

void Rendering::GLSLReflectionUniform::SetMatrixStride(OpenGLInt aMatrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetMatrixStride(aMatrixStride);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsRowMajor();
}

void Rendering::GLSLReflectionUniform::SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsRowMajor(aIsRowMajor);
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetAtomicCounterBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAtomicCounterBufferIndex();
}

void Rendering::GLSLReflectionUniform::SetAtomicCounterBufferIndex(OpenGLInt aAtomicCounterBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAtomicCounterBufferIndex(aAtomicCounterBufferIndex);
}

System::OpenGLInt Rendering::GLSLReflectionUniform::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::GLSLReflectionUniform::ReferencedBy Rendering::GLSLReflectionUniform::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::GLSLReflectionUniform::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, aReferencedBy);
}
