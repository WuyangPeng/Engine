///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionInputImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionInput)

Rendering::GLSLReflectionInput::GLSLReflectionInput(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionInput)

std::string Rendering::GLSLReflectionInput::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionInput::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionInput::GLSLReflectionEnumType Rendering::GLSLReflectionInput::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::GLSLReflectionInput::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(aType);
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::GLSLReflectionInput::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(aLocation);
}

System::OpenGLInt Rendering::GLSLReflectionInput::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::GLSLReflectionInput::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(aArraySize);
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::GLSLReflectionInput::ReferencedBy Rendering::GLSLReflectionInput::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::GLSLReflectionInput::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, aReferencedBy);
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsPerPatch();
}

void Rendering::GLSLReflectionInput::SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsPerPatch(aIsPerPatch);
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocationComponent();
}

void Rendering::GLSLReflectionInput::SetLocationComponent(OpenGLInt aLocationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocationComponent(aLocationComponent);
}
