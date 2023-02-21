///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 17:59)

#include "Rendering/RenderingExport.h"

#include "LightConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;
using std::vector;

Rendering::LightConstantImpl::LightConstantImpl(const LightSharedPtr& light) noexcept
    : light{ light }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::LightConstantImpl::LightConstantImpl() noexcept
    : light{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, LightConstantImpl)

Rendering::ConstLightSharedPtr Rendering::LightConstantImpl::GetLight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (light.object)
        return light.object;
    else
        return nullptr;
}

void Rendering::LightConstantImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociated(light);
}

void Rendering::LightConstantImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociated(light);
}

int Rendering::LightConstantImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return CoreTools::GetStreamSize(light);
}

CoreTools::ObjectSharedPtr Rendering::LightConstantImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    if (light.object)
        return light.object->GetObjectByName(name);
    else
        return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::LightConstantImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    if (light.object)
        return light.object->GetAllObjectsByName(name);
    else
        return vector<CoreTools::ObjectSharedPtr>{};
}

CoreTools::ConstObjectSharedPtr Rendering::LightConstantImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (light.object)
        return light.object->GetConstObjectByName(name);
    else
        return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::LightConstantImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (light.object)
        return light.object->GetAllConstObjectsByName(name);
    else
        return vector<CoreTools::ConstObjectSharedPtr>{};
}

void Rendering::LightConstantImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLink(light);
}

void Rendering::LightConstantImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Register(light);
}
