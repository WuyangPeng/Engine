///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 14:04)

#include "Rendering/RenderingExport.h"

#include "IKControllerImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Noexcept.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "Mathematics/Algebra/AlgebraAggregate.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "Rendering/DataTypes/SpecializedIO.h"

Rendering::IKControllerImpl::IKControllerImpl() noexcept
    : iterations{ 128 }, orderEndToRoot{ true }, joints{}
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

Rendering::IKControllerImpl::IKControllerImpl(const IKJointSharedPtrVector& joints)
    : iterations{ 128 }, orderEndToRoot{ true }, joints{ joints }
{
    RENDERING_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Rendering::IKControllerImpl::IsValid() const noexcept
{
    if (0 <= iterations)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

int Rendering::IKControllerImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    auto size = CoreTools::GetStreamSize(iterations);
    size += CoreTools::GetStreamSize(orderEndToRoot);

    auto jointSize = boost::numeric_cast<int>(joints.size());
    size += CoreTools::GetStreamSize(jointSize);

    if (0 < jointSize)
    {
        size += jointSize * CoreTools::GetStreamSize(joints.at(0));
    }

    return size;
}

void Rendering::IKControllerImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    target.Write(iterations);
    target.Write(orderEndToRoot);

    target.WriteObjectAssociatedContainerWithNumber(joints);
}

void Rendering::IKControllerImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_1;

    source.Read(iterations);
    orderEndToRoot = source.ReadBool();

    auto size = 0;
    source.Read(size);

    if (0 < size)
    {
        joints.resize(size);
        source.ReadObjectAssociatedContainer(size, joints);
    }
}

void Rendering::IKControllerImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_1;

    CoreTools::DisableNoexcept();

    if (0 < joints.size())
    {
        source.ResolveLinkContainer(joints);
    }
}

void Rendering::IKControllerImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    if (0 < joints.size())
    {
        target.RegisterContainer(joints);
    }
}

CoreTools::ObjectSharedPtr Rendering::IKControllerImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    for (auto& pointer : joints)
    {
        auto found = pointer.object->GetObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::IKControllerImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<CoreTools::ObjectSharedPtr> objects{};

    for (auto& pointer : joints)
    {
        auto pointerObjects = pointer.object->GetAllObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::IKControllerImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    for (const auto& pointer : joints)
    {
        auto found = pointer.object->GetConstObjectByName(name);
        if (found != nullptr)
        {
            return found;
        }
    }

    return nullptr;
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::IKControllerImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_1;

    std::vector<CoreTools::ConstObjectSharedPtr> objects{};

    for (const auto& pointer : joints)
    {
        auto pointerObjects = pointer.object->GetAllConstObjectsByName(name);

        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

int Rendering::IKControllerImpl::GetIterations() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return iterations;
}

void Rendering::IKControllerImpl::SetIterations(int aIterations) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    iterations = aIterations;
}

bool Rendering::IKControllerImpl::IsOrderEndToRoot() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return orderEndToRoot;
}

void Rendering::IKControllerImpl::SetOrderEndToRoot(bool aOrderEndToRoot) noexcept
{
    RENDERING_CLASS_IS_VALID_1;

    orderEndToRoot = aOrderEndToRoot;
}

int Rendering::IKControllerImpl::GetJointsNum() const
{
    RENDERING_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(joints.size());
}

Rendering::IKJointSharedPtr Rendering::IKControllerImpl::GetJointsSharedPtr(int index)
{
    RENDERING_CLASS_IS_VALID_CONST_1;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(joints.size()), "索引错误！");

    return joints.at(index).object;
}
