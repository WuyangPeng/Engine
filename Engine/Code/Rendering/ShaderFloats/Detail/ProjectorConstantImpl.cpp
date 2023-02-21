///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/07 18:09)

#include "Rendering/RenderingExport.h"

#include "ProjectorConstantImpl.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;
using std::vector;

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

CoreTools::ObjectSharedPtr Rendering::ProjectorConstantImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetObjectByName(name);
    else
        return nullptr;
}

vector<CoreTools::ObjectSharedPtr> Rendering::ProjectorConstantImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetAllObjectsByName(name);
    else
        return vector<CoreTools::ObjectSharedPtr>{};
}

CoreTools::ConstObjectSharedPtr Rendering::ProjectorConstantImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetConstObjectByName(name);
    else
        return nullptr;
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::ProjectorConstantImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    if (projector.object)
        return projector.object->GetAllConstObjectsByName(name);
    else
        return vector<CoreTools::ConstObjectSharedPtr>{};
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
