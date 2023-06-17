///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 13:51)

#include "Rendering/RenderingExport.h"

#include "BillboardNodeImpl.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

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

    const auto size = CoreTools::GetStreamSize(camera);

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

CoreTools::ConstObjectSharedPtr Rendering::BillboardNodeImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetConstObjectByName(name);
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::BillboardNodeImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetAllConstObjectsByName(name);
}

CoreTools::ObjectSharedPtr Rendering::BillboardNodeImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return camera.object->GetObjectByName(name);
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::BillboardNodeImpl::GetAllObjectsByName(const std::string& name)
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
