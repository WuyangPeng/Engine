/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/28 17:52)

#include "Rendering/RenderingExport.h"

#include "ViewVolumeNodeImpl.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/MatrixDetail.h"

Rendering::ViewVolumeNodeImpl::ViewVolumeNodeImpl(const ViewVolumeSharedPtr& viewVolume) noexcept
    : viewVolume{ viewVolume }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, ViewVolumeNodeImpl)

void Rendering::ViewVolumeNodeImpl::SetViewVolume(const ViewVolumeSharedPtr& aViewVolume) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    viewVolume.object = aViewVolume;
}

Rendering::ViewVolumeSharedPtr Rendering::ViewVolumeNodeImpl::GetViewVolume() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return viewVolume.object;
}

CoreTools::ObjectSharedPtr Rendering::ViewVolumeNodeImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return viewVolume->GetObjectByName(name);
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::ViewVolumeNodeImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    return viewVolume->GetAllObjectsByName(name);
}

CoreTools::ConstObjectSharedPtr Rendering::ViewVolumeNodeImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return viewVolume->GetConstObjectByName(name);
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::ViewVolumeNodeImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    return viewVolume->GetAllConstObjectsByName(name);
}

int Rendering::ViewVolumeNodeImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return CoreTools::GetStreamSize(viewVolume);
}

void Rendering::ViewVolumeNodeImpl::Register(ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(viewVolume);
}

void Rendering::ViewVolumeNodeImpl::Save(BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteObjectAssociated(viewVolume);
}

void Rendering::ViewVolumeNodeImpl::Link(ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(viewVolume);
}

void Rendering::ViewVolumeNodeImpl::Load(BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadObjectAssociated(viewVolume);
}
