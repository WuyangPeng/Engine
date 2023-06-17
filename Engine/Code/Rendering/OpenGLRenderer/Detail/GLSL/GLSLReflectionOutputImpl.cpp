///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionOutputImpl::GLSLReflectionOutputImpl() noexcept
    : name{},
      type{ 0 },
      location{ 0 },
      arraySize{ 0 },
      referencedBy{},
      isPerPatch{ 0 },
      locationComponent{ 0 },
      locationIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionOutputImpl::GLSLReflectionOutputImpl(const std::string& name)
    : name{ name },
      type{ 0 },
      location{ 0 },
      arraySize{ 0 },
      referencedBy{},
      isPerPatch{ 0 },
      locationComponent{ 0 },
      locationIndex{ 0 }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionOutputImpl)

std::string Rendering::GLSLReflectionOutputImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionOutputImpl::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionOutputImpl::GLSLReflectionEnumType Rendering::GLSLReflectionOutputImpl::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionOutputImpl::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionOutputImpl::OpenGLInt Rendering::GLSLReflectionOutputImpl::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionOutputImpl::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionOutputImpl::OpenGLInt Rendering::GLSLReflectionOutputImpl::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionOutputImpl::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionOutputImpl::OpenGLInt Rendering::GLSLReflectionOutputImpl::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionOutputImpl::ReferencedBy Rendering::GLSLReflectionOutputImpl::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionOutputImpl::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

Rendering::GLSLReflectionOutputImpl::OpenGLInt Rendering::GLSLReflectionOutputImpl::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isPerPatch;
}

void Rendering::GLSLReflectionOutputImpl::SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isPerPatch = aIsPerPatch;
}

Rendering::GLSLReflectionOutputImpl::OpenGLInt Rendering::GLSLReflectionOutputImpl::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return locationComponent;
}

void Rendering::GLSLReflectionOutputImpl::SetLocationComponent(OpenGLInt aLocationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    locationComponent = aLocationComponent;
}

Rendering::GLSLReflectionOutputImpl::OpenGLInt Rendering::GLSLReflectionOutputImpl::GetLocationIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return locationIndex;
}

void Rendering::GLSLReflectionOutputImpl::SetLocationIndex(OpenGLInt aLocationIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    locationIndex = aLocationIndex;
}
