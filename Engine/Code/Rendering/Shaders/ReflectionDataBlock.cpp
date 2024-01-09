/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/26 15:12)

#include "Rendering/RenderingExport.h"

#include "ReflectionDataBlock.h"
#include "Detail/ReflectionDataBlockFactory.h"
#include "Detail/ReflectionDataBlockImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionDataBlock)

Rendering::ReflectionDataBlock::ReflectionDataBlock(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionDataBlock)

std::string Rendering::ReflectionDataBlock::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionDataBlock::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionDataBlock::OpenGLInt Rendering::ReflectionDataBlock::GetBufferBinding() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferBinding();
}

void Rendering::ReflectionDataBlock::SetBufferBinding(OpenGLInt bufferBinding) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferBinding(bufferBinding);
}

Rendering::ReflectionDataBlock::OpenGLInt Rendering::ReflectionDataBlock::GetBufferDataSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetBufferDataSize();
}

void Rendering::ReflectionDataBlock::SetBufferDataSize(OpenGLInt bufferDataSize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetBufferDataSize(bufferDataSize);
}

System::OpenGLInt Rendering::ReflectionDataBlock::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::ReflectionDataBlock::ReferencedBy Rendering::ReflectionDataBlock::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::ReflectionDataBlock::SetReferencedBy(int index, OpenGLInt referencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, referencedBy);
}

System::OpenGLInt Rendering::ReflectionDataBlock::GetActiveVariables(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariables(index);
}

void Rendering::ReflectionDataBlock::SetActiveVariables(int index, OpenGLInt activeVariables)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetActiveVariables(index, activeVariables);
}

int Rendering::ReflectionDataBlock::GetActiveVariablesCount() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetActiveVariablesCount();
}

void Rendering::ReflectionDataBlock::SetActiveVariables(const ActiveVariables& activeVariables)
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->SetActiveVariables(activeVariables);
}
