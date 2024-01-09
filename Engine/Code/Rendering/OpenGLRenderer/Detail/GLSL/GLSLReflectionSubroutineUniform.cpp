/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2024/01/09 17:12)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionSubroutineUniform.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionSubroutineUniform::GLSLReflectionSubroutineUniform() noexcept
    : name{},
      location{ 0 },
      arraySize{ 0 },
      compatibleSubroutines{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionSubroutineUniform::GLSLReflectionSubroutineUniform(const std::string& name)
    : name{ name },
      location{ 0 },
      arraySize{ 0 },
      compatibleSubroutines{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionSubroutineUniform)

Rendering::ReflectionSubroutineUniformImpl::ReflectionSubroutineUniformSharedPtr Rendering::GLSLReflectionSubroutineUniform::Clone() const
{
    return std::make_shared<ClassType>(*this);
}

std::string Rendering::GLSLReflectionSubroutineUniform::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionSubroutineUniform::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionSubroutineUniform::OpenGLInt Rendering::GLSLReflectionSubroutineUniform::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionSubroutineUniform::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionSubroutineUniform::OpenGLInt Rendering::GLSLReflectionSubroutineUniform::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionSubroutineUniform::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionSubroutineUniform::OpenGLInt Rendering::GLSLReflectionSubroutineUniform::GetCompatibleSubroutines(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return compatibleSubroutines.at(index);
}

void Rendering::GLSLReflectionSubroutineUniform::SetCompatibleSubroutines(int index, OpenGLInt aCompatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    compatibleSubroutines.at(index) = aCompatibleSubroutines;
}

void Rendering::GLSLReflectionSubroutineUniform::SetCompatibleSubroutines(const CompatibleSubroutines& aCompatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    compatibleSubroutines = aCompatibleSubroutines;
}
