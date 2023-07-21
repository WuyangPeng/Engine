///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:35)

#include "Rendering/RenderingExport.h"

#include "ReflectionInput.h"
#include "Detail/ReflectionInputFactory.h"
#include "Detail/ReflectionInputImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionInput)

Rendering::ReflectionInput::ReflectionInput(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionInput)

std::string Rendering::ReflectionInput::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionInput::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionInput::GLSLReflectionEnumType Rendering::ReflectionInput::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::ReflectionInput::SetType(GLSLReflectionEnumType type) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(type);
}

Rendering::ReflectionInput::OpenGLInt Rendering::ReflectionInput::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::ReflectionInput::SetLocation(OpenGLInt location) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(location);
}

System::OpenGLInt Rendering::ReflectionInput::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::ReflectionInput::SetArraySize(OpenGLInt arraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(arraySize);
}

Rendering::ReflectionInput::OpenGLInt Rendering::ReflectionInput::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::ReflectionInput::ReferencedBy Rendering::ReflectionInput::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::ReflectionInput::SetReferencedBy(int index, OpenGLInt referencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, referencedBy);
}

Rendering::ReflectionInput::OpenGLInt Rendering::ReflectionInput::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsPerPatch();
}

void Rendering::ReflectionInput::SetIsPerPatch(OpenGLInt isPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsPerPatch(isPerPatch);
}

Rendering::ReflectionInput::OpenGLInt Rendering::ReflectionInput::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocationComponent();
}

void Rendering::ReflectionInput::SetLocationComponent(OpenGLInt locationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocationComponent(locationComponent);
}
