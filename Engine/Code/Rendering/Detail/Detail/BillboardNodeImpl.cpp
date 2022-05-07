///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.6 (2022/04/08 18:26)

#include "Rendering/RenderingExport.h"

#include "BillboardNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

using std::string;
using std::vector;

Rendering::BillboardNodeImpl::BillboardNodeImpl() noexcept
    : camera{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::BillboardNodeImpl::BillboardNodeImpl(const CameraSharedPtr& camera) noexcept
    : camera{ camera }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, BillboardNodeImpl)

int Rendering::BillboardNodeImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto size = CORE_TOOLS_STREAM_SIZE(camera);

    return size;
}

void Rendering::BillboardNodeImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(camera);
}

void Rendering::BillboardNodeImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(camera);
}

void Rendering::BillboardNodeImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(camera);
}

void Rendering::BillboardNodeImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(camera);
}

CoreTools::ConstObjectSharedPtr Rendering::BillboardNodeImpl::GetConstObjectByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetConstObjectByName(name);
}

vector<CoreTools::ConstObjectSharedPtr> Rendering::BillboardNodeImpl::GetAllConstObjectsByName(const string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetAllConstObjectsByName(name);
}

CoreTools::ObjectSharedPtr Rendering::BillboardNodeImpl::GetObjectByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetObjectByName(name);
}

vector<CoreTools::ObjectSharedPtr> Rendering::BillboardNodeImpl::GetAllObjectsByName(const string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetAllObjectsByName(name);
}

void Rendering::BillboardNodeImpl::AlignTo(const CameraSharedPtr& aCamera) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    camera.object = aCamera;
}

Rendering::ConstCameraSharedPtr Rendering::BillboardNodeImpl::GetCamera() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return camera.object;
}
