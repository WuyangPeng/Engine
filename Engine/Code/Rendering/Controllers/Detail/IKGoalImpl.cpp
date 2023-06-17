///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:04)

#include "Rendering/RenderingExport.h"

#include "IKGoalImpl.h"

#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"

Rendering::IKGoalImpl::IKGoalImpl(const SpatialSharedPtr& target, const SpatialSharedPtr& effector, float weight) noexcept
    : goalTarget{ target }, effector{ effector }, weight{ weight }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::IKGoalImpl::IKGoalImpl() noexcept
    : goalTarget{}, effector{}, weight{ 1.0f }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, IKGoalImpl)

int Rendering::IKGoalImpl::GetStreamingSize() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = CoreTools::GetStreamSize(weight);
    size += CoreTools::GetStreamSize(goalTarget);
    size += CoreTools::GetStreamSize(effector);

    return size;
}

void Rendering::IKGoalImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Write(weight);
    target.WriteObjectAssociated(goalTarget);
    target.WriteObjectAssociated(effector);
}

void Rendering::IKGoalImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.Read(weight);
    source.ReadObjectAssociated(goalTarget);
    source.ReadObjectAssociated(effector);
}

void Rendering::IKGoalImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(goalTarget);
    source.ResolveLink(effector);
}

void Rendering::IKGoalImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(goalTarget);
    target.Register(effector);
}

Rendering::ConstSpatialSharedPtr Rendering::IKGoalImpl::GetTarget() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return goalTarget.object;
}

Rendering::ConstSpatialSharedPtr Rendering::IKGoalImpl::GetEffector() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return effector.object;
}

Rendering::IKGoalImpl::APoint Rendering::IKGoalImpl::GetTargetPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return goalTarget.object->GetWorldTransform().GetTranslate();
}

Rendering::IKGoalImpl::APoint Rendering::IKGoalImpl::GetEffectorPosition() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return effector.object->GetWorldTransform().GetTranslate();
}

void Rendering::IKGoalImpl::SetWeight(float aWeight) noexcept
{
    RENDERING_CLASS_IS_VALID_9;

    weight = aWeight;
}

float Rendering::IKGoalImpl::GetWeight() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return weight;
}

CoreTools::ObjectSharedPtr Rendering::IKGoalImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto targetObject = goalTarget.object->GetObjectByName(name);

    if (targetObject != nullptr)
    {
        return targetObject;
    }
    else
    {
        auto effectorObject = effector.object->GetObjectByName(name);
        if (effectorObject != nullptr)
            return effectorObject;
        else
            return nullptr;
    }
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::IKGoalImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto objects = goalTarget.object->GetAllObjectsByName(name);
    auto effectorObject = effector.object->GetAllObjectsByName(name);

    objects.insert(objects.end(), effectorObject.begin(), effectorObject.end());

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::IKGoalImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto targetObject = goalTarget.object->GetConstObjectByName(name);

    if (targetObject != nullptr)
    {
        return targetObject;
    }
    else
    {
        auto effectorObject = effector.object->GetConstObjectByName(name);
        if (effectorObject != nullptr)
            return effectorObject;
        else
            return nullptr;
    }
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::IKGoalImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto objects = goalTarget.object->GetAllConstObjectsByName(name);
    auto effectorObject = effector.object->GetAllConstObjectsByName(name);

    objects.insert(objects.end(), effectorObject.begin(), effectorObject.end());

    return objects;
}
