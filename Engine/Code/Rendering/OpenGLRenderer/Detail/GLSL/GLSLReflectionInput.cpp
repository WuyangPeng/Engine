/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:11)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionInput.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionInput::GLSLReflectionInput() noexcept
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

Rendering::GLSLReflectionInput::GLSLReflectionInput(const std::string& name)
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

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionInput)

Rendering::GLSLReflectionInput::ReflectionInputSharedPtr Rendering::GLSLReflectionInput::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

std::string Rendering::GLSLReflectionInput::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionInput::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionInput::GLSLReflectionEnumType Rendering::GLSLReflectionInput::GetType() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return type;
}

void Rendering::GLSLReflectionInput::SetType(GLSLReflectionEnumType aType) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    type = aType;
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionInput::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionInput::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetReferencedBy(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy.at(index);
}

Rendering::GLSLReflectionInput::ReferencedBy Rendering::GLSLReflectionInput::GetReferencedBy() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return referencedBy;
}

void Rendering::GLSLReflectionInput::SetReferencedBy(int index, OpenGLInt aReferencedBy)
{
    RENDERING_CLASS_IS_VALID_9;

    referencedBy.at(index) = aReferencedBy;
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetIsPerPatch() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return isPerPatch;
}

void Rendering::GLSLReflectionInput::SetIsPerPatch(OpenGLInt aIsPerPatch) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    isPerPatch = aIsPerPatch;
}

Rendering::GLSLReflectionInput::OpenGLInt Rendering::GLSLReflectionInput::GetLocationComponent() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return locationComponent;
}

void Rendering::GLSLReflectionInput::SetLocationComponent(OpenGLInt aLocationComponent) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    locationComponent = aLocationComponent;
}
