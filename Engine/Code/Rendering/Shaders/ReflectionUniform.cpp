///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:36)

#include "Rendering/RenderingExport.h"

#include "ReflectionUniform.h"
#include "Detail/ReflectionUniformFactory.h"
#include "Detail/ReflectionUniformImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionUniform)

Rendering::ReflectionUniform::ReflectionUniform(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionUniform)

std::string Rendering::ReflectionUniform::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetFullName();
}

void Rendering::ReflectionUniform::SetFullName(const std::string& fullName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetFullName(fullName);
}

std::string Rendering::ReflectionUniform::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionUniform::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionUniform::GLSLReflectionEnumType Rendering::ReflectionUniform::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::ReflectionUniform::SetType(GLSLReflectionEnumType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(type);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::ReflectionUniform::SetLocation(OpenGLInt location) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(location);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::ReflectionUniform::SetArraySize(OpenGLInt arraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(arraySize);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetOffset();
}

void Rendering::ReflectionUniform::SetOffset(OpenGLInt offset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetOffset(offset);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBlockIndex();
}

void Rendering::ReflectionUniform::SetBlockIndex(OpenGLInt blockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBlockIndex(blockIndex);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArrayStride();
}

void Rendering::ReflectionUniform::SetArrayStride(OpenGLInt arrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArrayStride(arrayStride);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetMatrixStride();
}

void Rendering::ReflectionUniform::SetMatrixStride(OpenGLInt matrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetMatrixStride(matrixStride);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsRowMajor();
}

void Rendering::ReflectionUniform::SetIsRowMajor(OpenGLInt isRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsRowMajor(isRowMajor);
}

Rendering::ReflectionUniform::OpenGLInt Rendering::ReflectionUniform::GetAtomicCounterBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetAtomicCounterBufferIndex();
}

void Rendering::ReflectionUniform::SetAtomicCounterBufferIndex(OpenGLInt atomicCounterBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetAtomicCounterBufferIndex(atomicCounterBufferIndex);
}

System::OpenGLInt Rendering::ReflectionUniform::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::ReflectionUniform::ReferencedBy Rendering::ReflectionUniform::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::ReflectionUniform::SetReferencedBy(int index, OpenGLInt referencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, referencedBy);
}
