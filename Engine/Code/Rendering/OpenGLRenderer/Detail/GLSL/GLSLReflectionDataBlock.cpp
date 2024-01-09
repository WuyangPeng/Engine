/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:10)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionDataBlock.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionDataBlock::GLSLReflectionDataBlock() noexcept
    : ParentType{},
      name{},
      bufferBinding{ 0 },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionDataBlock::GLSLReflectionDataBlock(std::string name) noexcept
    : ParentType{},
      name{ std::move(name) },
      bufferBinding{ 0 },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ReflectionDataBlockImpl::ReflectionDataBlockSharedPtr Rendering::GLSLReflectionDataBlock::Clone() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return std::make_shared<ClassType>(*this);
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionDataBlock)

std::string Rendering::GLSLReflectionDataBlock::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionDataBlock::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionDataBlock::OpenGLInt Rendering::GLSLReflectionDataBlock::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferBinding;
}

void Rendering::GLSLReflectionDataBlock::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferBinding = aBufferBinding;
}

Rendering::GLSLReflectionDataBlock::OpenGLInt Rendering::GLSLReflectionDataBlock::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferDataSize;
}

void Rendering::GLSLReflectionDataBlock::SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferDataSize = aBufferDataSize;
}

System::OpenGLInt Rendering::GLSLReflectionDataBlock::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionDataBlock::ReferencedBy Rendering::GLSLReflectionDataBlock::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionDataBlock::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

System::OpenGLInt Rendering::GLSLReflectionDataBlock::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return activeVariables.at(index);
}

void Rendering::GLSLReflectionDataBlock::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables.at(index) = aActiveVariables;
}

int Rendering::GLSLReflectionDataBlock::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(activeVariables.size());
}

void Rendering::GLSLReflectionDataBlock::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables = aActiveVariables;
}
