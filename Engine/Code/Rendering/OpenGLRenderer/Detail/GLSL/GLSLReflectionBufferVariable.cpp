///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionBufferVariable.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionBufferVariable::GLSLReflectionBufferVariable() noexcept
    : ParentType{},
      fullName{},
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

Rendering::GLSLReflectionBufferVariable::GLSLReflectionBufferVariable(const std::string& name)
    : ParentType{},
      fullName{},
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

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionBufferVariable)

Rendering::GLSLReflectionBufferVariable::ReflectionBufferVariableSharedPtr Rendering::GLSLReflectionBufferVariable::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

std::string Rendering::GLSLReflectionBufferVariable::GetFullName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return fullName;
}

void Rendering::GLSLReflectionBufferVariable::SetFullName(const std::string& aFullName)
{
    RENDERING_CLASS_IS_VALID_9;

    fullName = aFullName;
}

std::string Rendering::GLSLReflectionBufferVariable::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionBufferVariable::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionBufferVariable::GLSLReflectionEnumType Rendering::GLSLReflectionBufferVariable::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionBufferVariable::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionBufferVariable::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetOffset() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return offset;
}

void Rendering::GLSLReflectionBufferVariable::SetOffset(OpenGLInt aOffset) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    offset = aOffset;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetBlockIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return blockIndex;
}

void Rendering::GLSLReflectionBufferVariable::SetBlockIndex(OpenGLInt aBlockIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    blockIndex = aBlockIndex;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arrayStride;
}

void Rendering::GLSLReflectionBufferVariable::SetArrayStride(OpenGLInt aArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arrayStride = aArrayStride;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetMatrixStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return matrixStride;
}

void Rendering::GLSLReflectionBufferVariable::SetMatrixStride(OpenGLInt aMatrixStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    matrixStride = aMatrixStride;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetIsRowMajor() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isRowMajor;
}

void Rendering::GLSLReflectionBufferVariable::SetIsRowMajor(OpenGLInt aIsRowMajor) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isRowMajor = aIsRowMajor;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetTopLevelArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return topLevelArraySize;
}

void Rendering::GLSLReflectionBufferVariable::SetTopLevelArraySize(OpenGLInt aTopLevelArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    topLevelArraySize = aTopLevelArraySize;
}

Rendering::GLSLReflectionBufferVariable::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetTopLevelArrayStride() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return topLevelArrayStride;
}

void Rendering::GLSLReflectionBufferVariable::SetTopLevelArrayStride(OpenGLInt aTopLevelArrayStride) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    topLevelArrayStride = aTopLevelArrayStride;
}

System::OpenGLInt Rendering::GLSLReflectionBufferVariable::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionBufferVariable::ReferencedBy Rendering::GLSLReflectionBufferVariable::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionBufferVariable::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}
