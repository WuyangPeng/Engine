///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 11:02)

#include "Rendering/RenderingExport.h"

#include "ProjectorConstantImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::ProjectorConstantImpl::ProjectorConstantImpl(const ProjectorSharedPtr& projector) noexcept
    : projector{ projector }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::ProjectorConstantImpl::ProjectorConstantImpl() noexcept
    : projector{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ProjectorConstantImpl)

Rendering::ConstProjectorSharedPtr Rendering::ProjectorConstantImpl::GetProjector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    if (projector.object)
        return projector.object;
    else
        return nullptr;
}

void Rendering::ProjectorConstantImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(projector);
}

void Rendering::ProjectorConstantImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(projector);
}

int Rendering::ProjectorConstantImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CoreTools::GetStreamSize(projector);
}

CoreTools::ObjectSharedPtr Rendering::ProjectorConstantImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetObjectByName(name);
    else
        return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::ProjectorConstantImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetAllObjectsByName(name);
    else
        return std::vector<CoreTools::ObjectSharedPtr>{};
}

CoreTools::ConstObjectSharedPtr Rendering::ProjectorConstantImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetConstObjectByName(name);
    else
        return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::ProjectorConstantImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetAllConstObjectsByName(name);
    else
        return std::vector<CoreTools::ConstObjectSharedPtr>{};
}

void Rendering::ProjectorConstantImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(projector);
}

void Rendering::ProjectorConstantImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(projector);
}
