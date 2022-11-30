///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/29 22:17)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionOutput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionOutputImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionOutput)

Rendering::GLSLReflectionOutput::GLSLReflectionOutput(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionOutput)

std::string Rendering::GLSLReflectionOutput::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionOutput::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionOutput::GLSLReflectionEnumType Rendering::GLSLReflectionOutput::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetType();
}

void Rendering::GLSLReflectionOutput::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetType(aType);
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::GLSLReflectionOutput::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(aLocation);
}

System::OpenGLInt Rendering::GLSLReflectionOutput::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::GLSLReflectionOutput::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(aArraySize);
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy(index);
}

Rendering::GLSLReflectionOutput::ReferencedBy Rendering::GLSLReflectionOutput::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetReferencedBy();
}

void Rendering::GLSLReflectionOutput::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetReferencedBy(index, aReferencedBy);
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetIsPerPatch();
}

void Rendering::GLSLReflectionOutput::SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetIsPerPatch(aIsPerPatch);
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocationComponent();
}

void Rendering::GLSLReflectionOutput::SetLocationComponent(OpenGLInt aLocationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocationComponent(aLocationComponent);
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetLocationIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocationIndex();
}

void Rendering::GLSLReflectionOutput::SetLocationIndex(OpenGLInt aLocationIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocationIndex(aLocationIndex);
}