/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:12)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionUniform.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionUniform::GLSLReflectionUniform() noexcept
    : ParentType{},
      fullName{},
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

Rendering::GLSLReflectionUniform::GLSLReflectionUniform(std::string name) noexcept
    : ParentType{},
      fullName{},
      name{ std::move(name) },
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

Rendering::ReflectionUniformImpl::ReflectionUniformSharedPtr Rendering::GLSLReflectionUniform::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionUniform)

std::string Rendering::GLSLReflectionUniform::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fullName;
}

void Rendering::GLSLReflectionUniform::SetFullName(const std::string& aFullName)
{
    RENDERING_CLASS_IS_VALID_9;

    fullName = aFullName;
}

std::string Rendering::GLSLReflectionUniform::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionUniform::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionUniform::GLSLReflectionEnumType Rendering::GLSLReflectionUniform::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionUniform::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionUniform::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionUniform::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::GLSLReflectionUniform::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blockIndex;
}

void Rendering::GLSLReflectionUniform::SetBlockIndex(OpenGLInt aBlockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blockIndex = aBlockIndex;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arrayStride;
}

void Rendering::GLSLReflectionUniform::SetArrayStride(OpenGLInt aArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arrayStride = aArrayStride;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return matrixStride;
}

void Rendering::GLSLReflectionUniform::SetMatrixStride(OpenGLInt aMatrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    matrixStride = aMatrixStride;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isRowMajor;
}

void Rendering::GLSLReflectionUniform::SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isRowMajor = aIsRowMajor;
}

Rendering::GLSLReflectionUniform::OpenGLInt Rendering::GLSLReflectionUniform::GetAtomicCounterBufferIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return atomicCounterBufferIndex;
}

void Rendering::GLSLReflectionUniform::SetAtomicCounterBufferIndex(OpenGLInt aAtomicCounterBufferIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    atomicCounterBufferIndex = aAtomicCounterBufferIndex;
}

System::OpenGLInt Rendering::GLSLReflectionUniform::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionUniform::ReferencedBy Rendering::GLSLReflectionUniform::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionUniform::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}
