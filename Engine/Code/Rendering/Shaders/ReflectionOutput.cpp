///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:35)

#include "Rendering/RenderingExport.h"

#include "ReflectionOutput.h"
#include "Detail/ReflectionOutputFactory.h"
#include "Detail/ReflectionOutputImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionOutput)

Rendering::ReflectionOutput::ReflectionOutput(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionOutput)

std::string Rendering::ReflectionOutput::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionOutput::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionOutput::GLSLReflectionEnumType Rendering::ReflectionOutput::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::ReflectionOutput::SetType(GLSLReflectionEnumType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(type);
}

Rendering::ReflectionOutput::OpenGLInt Rendering::ReflectionOutput::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::ReflectionOutput::SetLocation(OpenGLInt location) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(location);
}

System::OpenGLInt Rendering::ReflectionOutput::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::ReflectionOutput::SetArraySize(OpenGLInt arraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(arraySize);
}

Rendering::ReflectionOutput::OpenGLInt Rendering::ReflectionOutput::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::ReflectionOutput::ReferencedBy Rendering::ReflectionOutput::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::ReflectionOutput::SetReferencedBy(int index, OpenGLInt referencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, referencedBy);
}

Rendering::ReflectionOutput::OpenGLInt Rendering::ReflectionOutput::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsPerPatch();
}

void Rendering::ReflectionOutput::SetIsPerPatch(OpenGLInt isPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsPerPatch(isPerPatch);
}

Rendering::ReflectionOutput::OpenGLInt Rendering::ReflectionOutput::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocationComponent();
}

void Rendering::ReflectionOutput::SetLocationComponent(OpenGLInt locationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocationComponent(locationComponent);
}

Rendering::ReflectionOutput::OpenGLInt Rendering::ReflectionOutput::GetLocationIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocationIndex();
}

void Rendering::ReflectionOutput::SetLocationIndex(OpenGLInt locationIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocationIndex(locationIndex);
}