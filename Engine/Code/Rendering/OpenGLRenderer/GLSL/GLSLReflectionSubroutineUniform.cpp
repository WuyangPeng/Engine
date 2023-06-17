///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:29)

#include "Rendering/RenderingExport.h"

#include "GLSLReflectionSubroutineUniform.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "Rendering/OpenGLRenderer/Detail/GLSL/GLSLReflectionSubroutineUniformImpl.h"

COPY_UNSHARED_CLONE_SELF_DEFINE(Rendering, GLSLReflectionSubroutineUniform)

Rendering::GLSLReflectionSubroutineUniform::GLSLReflectionSubroutineUniform(const std::string& name)
    : impl{ name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, GLSLReflectionSubroutineUniform)

std::string Rendering::GLSLReflectionSubroutineUniform::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::GLSLReflectionSubroutineUniform::SetName(const std::string& aName)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(aName);
}

Rendering::GLSLReflectionSubroutineUniform::OpenGLInt Rendering::GLSLReflectionSubroutineUniform::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::GLSLReflectionSubroutineUniform::SetLocation(OpenGLInt aLocation) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(aLocation);
}

Rendering::GLSLReflectionSubroutineUniform::OpenGLInt Rendering::GLSLReflectionSubroutineUniform::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::GLSLReflectionSubroutineUniform::SetArraySize(OpenGLInt aArraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(aArraySize);
}

Rendering::GLSLReflectionSubroutineUniform::OpenGLInt Rendering::GLSLReflectionSubroutineUniform::GetCompatibleSubroutines(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCompatibleSubroutines(index);
}

void Rendering::GLSLReflectionSubroutineUniform::SetCompatibleSubroutines(int index, OpenGLInt aCompatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCompatibleSubroutines(index, aCompatibleSubroutines);
}

void Rendering::GLSLReflectionSubroutineUniform::SetCompatibleSubroutines(const CompatibleSubroutines& aCompatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCompatibleSubroutines(aCompatibleSubroutines);
}
