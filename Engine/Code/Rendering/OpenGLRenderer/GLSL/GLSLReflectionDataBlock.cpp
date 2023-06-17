///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionDataBlock.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionDataBlockImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionDataBlock)

Rendering::GLSLReflectionDataBlock::GLSLReflectionDataBlock(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionDataBlock)

std::string Rendering::GLSLReflectionDataBlock::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionDataBlock::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionDataBlock::OpenGLInt Rendering::GLSLReflectionDataBlock::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBinding();
}

void Rendering::GLSLReflectionDataBlock::SetBufferBinding(OpenGLInt aBufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferBinding(aBufferBinding);
}

Rendering::GLSLReflectionDataBlock::OpenGLInt Rendering::GLSLReflectionDataBlock::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferDataSize();
}

void Rendering::GLSLReflectionDataBlock::SetBufferDataSize(OpenGLInt aBufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferDataSize(aBufferDataSize);
}

System::OpenGLInt Rendering::GLSLReflectionDataBlock::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::GLSLReflectionDataBlock::ReferencedBy Rendering::GLSLReflectionDataBlock::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::GLSLReflectionDataBlock::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, aReferencedBy);
}

System::OpenGLInt Rendering::GLSLReflectionDataBlock::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariables(index);
}

void Rendering::GLSLReflectionDataBlock::SetActiveVariables(int index, OpenGLInt aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(index, aActiveVariables);
}

int Rendering::GLSLReflectionDataBlock::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariablesCount();
}

void Rendering::GLSLReflectionDataBlock::SetActiveVariables(const ActiveVariables& aActiveVariables)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->SetActiveVariables(aActiveVariables);
}
