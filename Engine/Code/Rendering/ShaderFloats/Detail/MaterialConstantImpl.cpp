///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 11:02)

#include "Rendering/RenderingExport.h"

#include "MaterialConstantImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

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

    return CoreTools::GetStreamSize(material);
}

CoreTools::ObjectSharedPtr Rendering::MaterialConstantImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetObjectByName(name);
    else
        return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::MaterialConstantImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetAllObjectsByName(name);
    else
        return std::vector<CoreTools::ObjectSharedPtr>{};
}

CoreTools::ConstObjectSharedPtr Rendering::MaterialConstantImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetConstObjectByName(name);
    else
        return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::MaterialConstantImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    if (material.object)
        return material.object->GetAllConstObjectsByName(name);
    else
        return std::vector<CoreTools::ConstObjectSharedPtr>{};
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
