///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionUniformImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionUniformImpl::GLSLReflectionUniformImpl() noexcept
    : fullName{},
      name{},
      type{ 0 },
      location{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      blockIndex{ 0 },
      arrayStride{ 0 },
      matrixStride{ 0 },
      isRowMajor{ 0 },
      atomicCounterBufferIndex{ 0 },
      referencedBy{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionUniformImpl::GLSLReflectionUniformImpl(const std::string& name)
    : fullName{},
      name{ name },
      type{ 0 },
      location{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      blockIndex{ 0 },
      arrayStride{ 0 },
      matrixStride{ 0 },
      isRowMajor{ 0 },
      atomicCounterBufferIndex{ 0 },
      referencedBy{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionUniformImpl)

std::string Rendering::GLSLReflectionUniformImpl::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fullName;
}

void Rendering::GLSLReflectionUniformImpl::SetFullName(const std::string& aFullName)
{
    RENDERING_CLASS_IS_VALID_9;

    fullName = aFullName;
}

std::string Rendering::GLSLReflectionUniformImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionUniformImpl::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionUniformImpl::GLSLReflectionEnumType Rendering::GLSLReflectionUniformImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionUniformImpl::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionUniformImpl::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionUniformImpl::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::GLSLReflectionUniformImpl::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blockIndex;
}

void Rendering::GLSLReflectionUniformImpl::SetBlockIndex(OpenGLInt aBlockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blockIndex = aBlockIndex;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arrayStride;
}

void Rendering::GLSLReflectionUniformImpl::SetArrayStride(OpenGLInt aArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arrayStride = aArrayStride;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return matrixStride;
}

void Rendering::GLSLReflectionUniformImpl::SetMatrixStride(OpenGLInt aMatrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    matrixStride = aMatrixStride;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isRowMajor;
}

void Rendering::GLSLReflectionUniformImpl::SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isRowMajor = aIsRowMajor;
}

Rendering::GLSLReflectionUniformImpl::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetAtomicCounterBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return atomicCounterBufferIndex;
}

void Rendering::GLSLReflectionUniformImpl::SetAtomicCounterBufferIndex(OpenGLInt aAtomicCounterBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    atomicCounterBufferIndex = aAtomicCounterBufferIndex;
}

System::OpenGLInt Rendering::GLSLReflectionUniformImpl::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionUniformImpl::ReferencedBy Rendering::GLSLReflectionUniformImpl::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionUniformImpl::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}
