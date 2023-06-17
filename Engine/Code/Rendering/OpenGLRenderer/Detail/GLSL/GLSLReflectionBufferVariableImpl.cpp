///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionBufferVariableImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionBufferVariableImpl::GLSLReflectionBufferVariableImpl() noexcept
    : fullName{},
      name{},
      type{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      blockIndex{ 0 },
      arrayStride{ 0 },
      matrixStride{ 0 },
      isRowMajor{ 0 },
      topLevelArraySize{ 0 },
      topLevelArrayStride{ 0 },
      referencedBy{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionBufferVariableImpl::GLSLReflectionBufferVariableImpl(const std::string& name)
    : fullName{},
      name{ name },
      type{ 0 },
      arraySize{ 0 },
      offset{ 0 },
      blockIndex{ 0 },
      arrayStride{ 0 },
      matrixStride{ 0 },
      isRowMajor{ 0 },
      topLevelArraySize{ 0 },
      topLevelArrayStride{ 0 },
      referencedBy{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionBufferVariableImpl)

std::string Rendering::GLSLReflectionBufferVariableImpl::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fullName;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetFullName(const std::string& aFullName)
{
    RENDERING_CLASS_IS_VALID_9;

    fullName = aFullName;
}

std::string Rendering::GLSLReflectionBufferVariableImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionBufferVariableImpl::GLSLReflectionEnumType Rendering::GLSLReflectionBufferVariableImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blockIndex;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetBlockIndex(OpenGLInt aBlockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blockIndex = aBlockIndex;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arrayStride;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetArrayStride(OpenGLInt aArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arrayStride = aArrayStride;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return matrixStride;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetMatrixStride(OpenGLInt aMatrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    matrixStride = aMatrixStride;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isRowMajor;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isRowMajor = aIsRowMajor;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetTopLevelArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return topLevelArraySize;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetTopLevelArraySize(OpenGLInt aTopLevelArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    topLevelArraySize = aTopLevelArraySize;
}

Rendering::GLSLReflectionBufferVariableImpl::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetTopLevelArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return topLevelArrayStride;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetTopLevelArrayStride(OpenGLInt aTopLevelArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    topLevelArrayStride = aTopLevelArrayStride;
}

System::OpenGLInt Rendering::GLSLReflectionBufferVariableImpl::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionBufferVariableImpl::ReferencedBy Rendering::GLSLReflectionBufferVariableImpl::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionBufferVariableImpl::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}
