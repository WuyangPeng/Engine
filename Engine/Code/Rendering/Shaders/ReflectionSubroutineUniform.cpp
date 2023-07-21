///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.1 (2023/07/05 14:35)

#include "Rendering/RenderingExport.h"

#include "ReflectionSubroutineUniform.h"
#include "Detail/ReflectionSubroutineUniformFactory.h"
#include "Detail/ReflectionSubroutineUniformImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"

COPY_UNSHARED_CLONE_SELF_USE_CLONE_DEFINE(Rendering, ReflectionSubroutineUniform)

Rendering::ReflectionSubroutineUniform::ReflectionSubroutineUniform(const std::string& name)
    : impl{ CoreTools::ImplCreateUseFactory::Default, name }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ReflectionSubroutineUniform)

std::string Rendering::ReflectionSubroutineUniform::GetName() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetName();
}

void Rendering::ReflectionSubroutineUniform::SetName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetName(name);
}

Rendering::ReflectionSubroutineUniform::OpenGLInt Rendering::ReflectionSubroutineUniform::GetLocation() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetLocation();
}

void Rendering::ReflectionSubroutineUniform::SetLocation(OpenGLInt location) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetLocation(location);
}

Rendering::ReflectionSubroutineUniform::OpenGLInt Rendering::ReflectionSubroutineUniform::GetArraySize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetArraySize();
}

void Rendering::ReflectionSubroutineUniform::SetArraySize(OpenGLInt arraySize) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetArraySize(arraySize);
}

Rendering::ReflectionSubroutineUniform::OpenGLInt Rendering::ReflectionSubroutineUniform::GetCompatibleSubroutines(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return impl->GetCompatibleSubroutines(index);
}

void Rendering::ReflectionSubroutineUniform::SetCompatibleSubroutines(int index, OpenGLInt compatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCompatibleSubroutines(index, compatibleSubroutines);
}

void Rendering::ReflectionSubroutineUniform::SetCompatibleSubroutines(const CompatibleSubroutines& compatibleSubroutines)
{
    RENDERING_CLASS_IS_VALID_9;

    return impl->SetCompatibleSubroutines(compatibleSubroutines);
}
