///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionDataBlockImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionDataBlockImpl::GLSLReflectionDataBlockImpl() noexcept
    : name{},
      bufferBinding{ 0 },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionDataBlockImpl::GLSLReflectionDataBlockImpl(const std::string& name)
    : name{ name },
      bufferBinding{ 0 },
      bufferDataSize{ 0 },
      referencedBy{},
      activeVariables{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionDataBlockImpl)

std::string Rendering::GLSLReflectionDataBlockImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionDataBlockImpl::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionDataBlockImpl::OpenGLInt Rendering::GLSLReflectionDataBlockImpl::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferBinding;
}

void Rendering::GLSLReflectionDataBlockImpl::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferBinding = aBufferBinding;
}

Rendering::GLSLReflectionDataBlockImpl::OpenGLInt Rendering::GLSLReflectionDataBlockImpl::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return bufferDataSize;
}

void Rendering::GLSLReflectionDataBlockImpl::SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    bufferDataSize = aBufferDataSize;
}

System::OpenGLInt Rendering::GLSLReflectionDataBlockImpl::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionDataBlockImpl::ReferencedBy Rendering::GLSLReflectionDataBlockImpl::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionDataBlockImpl::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

System::OpenGLInt Rendering::GLSLReflectionDataBlockImpl::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return activeVariables.at(index);
}

void Rendering::GLSLReflectionDataBlockImpl::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables.at(index) = aActiveVariables;
}

int Rendering::GLSLReflectionDataBlockImpl::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(activeVariables.size());
}

void Rendering::GLSLReflectionDataBlockImpl::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    activeVariables = aActiveVariables;
}
