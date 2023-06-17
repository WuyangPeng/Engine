///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionInputImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionInputImpl::GLSLReflectionInputImpl() noexcept
    : name{},
      type{ 0 },
      location{ 0 },
      arraySize{ 0 },
      referencedBy{},
      isPerPatch{ 0 },
      locationComponent{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionInputImpl::GLSLReflectionInputImpl(const std::string& name)
    : name{ name },
      type{ 0 },
      location{ 0 },
      arraySize{ 0 },
      referencedBy{},
      isPerPatch{ 0 },
      locationComponent{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionInputImpl)

std::string Rendering::GLSLReflectionInputImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionInputImpl::SetName(std::string aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionInputImpl::GLSLReflectionEnumType Rendering::GLSLReflectionInputImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionInputImpl::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionInputImpl::OpenGLInt Rendering::GLSLReflectionInputImpl::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionInputImpl::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionInputImpl::OpenGLInt Rendering::GLSLReflectionInputImpl::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionInputImpl::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionInputImpl::OpenGLInt Rendering::GLSLReflectionInputImpl::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionInputImpl::ReferencedBy Rendering::GLSLReflectionInputImpl::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionInputImpl::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

Rendering::GLSLReflectionInputImpl::OpenGLInt Rendering::GLSLReflectionInputImpl::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isPerPatch;
}

void Rendering::GLSLReflectionInputImpl::SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isPerPatch = aIsPerPatch;
}

Rendering::GLSLReflectionInputImpl::OpenGLInt Rendering::GLSLReflectionInputImpl::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return locationComponent;
}

void Rendering::GLSLReflectionInputImpl::SetLocationComponent(OpenGLInt aLocationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    locationComponent = aLocationComponent;
}
