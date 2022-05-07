///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:05)

#include "Rendering/RenderingExport.h"

#include "MaterialConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;
using std::vector;

Rendering::MaterialConstantImpl::MaterialConstantImpl(const MaterialSharedPtr& material) noexcept
    : material{ material }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::MaterialConstantImpl::MaterialConstantImpl() noexcept
    : material{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, MaterialConstantImpl)

Rendering::ConstMaterialSharedPtr Rendering::MaterialConstantImpl::GetMaterial() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (material.object)
        return material.object;
    else
        return nullptr;
}

void Rendering::MaterialConstantImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ReadObjectAssociated(material);
}

void Rendering::MaterialConstantImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.WriteObjectAssociated(material);
}

int Rendering::MaterialConstantImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return CORE_TOOLS_STREAM_SIZE(material);
}

CoreTools::ObjectSharedPtr Rendering::MaterialConstantImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetObjectByName(name);
    else
        return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::MaterialConstantImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetAllObjectsByName(name);
    else
        return vector<CoreTools::ObjectSharedPtr>{};
}

CoreTools::ConstObjectSharedPtr Rendering::MaterialConstantImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetConstObjectByName(name);
    else
        return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::MaterialConstantImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetAllConstObjectsByName(name);
    else
        return vector<CoreTools::ConstObjectSharedPtr>{};
}

void Rendering::MaterialConstantImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.ResolveLink(material);
}

void Rendering::MaterialConstantImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Register(material);
}
