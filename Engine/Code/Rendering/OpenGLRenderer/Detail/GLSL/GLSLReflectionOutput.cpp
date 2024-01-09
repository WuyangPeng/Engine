/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:11)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionOutput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionOutput::GLSLReflectionOutput() noexcept
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

Rendering::GLSLReflectionOutput::GLSLReflectionOutput(const std::string& name)
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

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionOutput)

Rendering::ReflectionOutputImpl::ReflectionOutputSharedPtr Rendering::GLSLReflectionOutput::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

std::string Rendering::GLSLReflectionOutput::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionOutput::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionOutput::GLSLReflectionEnumType Rendering::GLSLReflectionOutput::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionOutput::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionOutput::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionOutput::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionOutput::ReferencedBy Rendering::GLSLReflectionOutput::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionOutput::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isPerPatch;
}

void Rendering::GLSLReflectionOutput::SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isPerPatch = aIsPerPatch;
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return locationComponent;
}

void Rendering::GLSLReflectionOutput::SetLocationComponent(OpenGLInt aLocationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    locationComponent = aLocationComponent;
}

Rendering::GLSLReflectionOutput::OpenGLInt Rendering::GLSLReflectionOutput::GetLocationIndex() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return locationIndex;
}

void Rendering::GLSLReflectionOutput::SetLocationIndex(OpenGLInt aLocationIndex) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    locationIndex = aLocationIndex;
}
