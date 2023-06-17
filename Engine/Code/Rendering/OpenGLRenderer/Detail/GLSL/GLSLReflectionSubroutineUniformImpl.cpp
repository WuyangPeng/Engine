///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:41)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionSubroutineUniformImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

Rendering::GLSLReflectionSubroutineUniformImpl::GLSLReflectionSubroutineUniformImpl() noexcept
    : name{},
      location{ 0 },
      arraySize{ 0 },
      compatibleSubroutines{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::GLSLReflectionSubroutineUniformImpl::GLSLReflectionSubroutineUniformImpl(const std::string& name)
    : name{ name },
      location{ 0 },
      arraySize{ 0 },
      compatibleSubroutines{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionSubroutineUniformImpl)

std::string Rendering::GLSLReflectionSubroutineUniformImpl::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return name;
}

void Rendering::GLSLReflectionSubroutineUniformImpl::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    name = aName;
}

Rendering::GLSLReflectionSubroutineUniformImpl::OpenGLInt Rendering::GLSLReflectionSubroutineUniformImpl::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return location;
}

void Rendering::GLSLReflectionSubroutineUniformImpl::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    location = aLocation;
}

Rendering::GLSLReflectionSubroutineUniformImpl::OpenGLInt Rendering::GLSLReflectionSubroutineUniformImpl::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return arraySize;
}

void Rendering::GLSLReflectionSubroutineUniformImpl::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    arraySize = aArraySize;
}

Rendering::GLSLReflectionSubroutineUniformImpl::OpenGLInt Rendering::GLSLReflectionSubroutineUniformImpl::GetCompatibleSubroutines(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return compatibleSubroutines.at(index);
}

void Rendering::GLSLReflectionSubroutineUniformImpl::SetCompatibleSubroutines(int index, OpenGLInt aCompatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    compatibleSubroutines.at(index) = aCompatibleSubroutines;
}

void Rendering::GLSLReflectionSubroutineUniformImpl::SetCompatibleSubroutines(const CompatibleSubroutines& aCompatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    compatibleSubroutines = aCompatibleSubroutines;
}
