///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 14:04)

#include "Rendering/RenderingExport.h"

#include "IKJointImpl.h"
#include "System/Helper/PragmaWarning.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/RenderingCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/RenderingClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/BufferSourceDetail.h"
#include "CoreTools/ObjectSystems/BufferTargetDetail.h"
#include "CoreTools/ObjectSystems/ObjectLinkDetail.h"
#include "CoreTools/ObjectSystems/ObjectManager.h"
#include "CoreTools/ObjectSystems/ObjectRegisterDetail.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/TransformDetail.h"

Rendering::IKJointImpl::IKJointImpl() noexcept
    : allowTranslation{},
      minTranslation{ -Mathematics::MathF::maxReal, -Mathematics::MathF::maxReal, -Mathematics::MathF::maxReal },
      maxTranslation{ Mathematics::MathF::maxReal, Mathematics::MathF::maxReal, Mathematics::MathF::maxReal },
      allowRotation{},
      minRotation{ -Mathematics::MathF::GetPI(), -Mathematics::MathF::GetPI(), -Mathematics::MathF::GetPI() },
      maxRotation{ Mathematics::MathF::GetPI(), Mathematics::MathF::GetPI(), Mathematics::MathF::GetPI() },
      object{},
      goals{}
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

Rendering::IKJointImpl::IKJointImpl(const SpatialSharedPtr& object, const IKGoalSharedPtrVector& goals)
    : allowTranslation{},
      minTranslation{ -Mathematics::MathF::maxReal, -Mathematics::MathF::maxReal, -Mathematics::MathF::maxReal },
      maxTranslation{ Mathematics::MathF::maxReal, Mathematics::MathF::maxReal, Mathematics::MathF::maxReal },
      allowRotation{},
      minRotation{ -Mathematics::MathF::GetPI(), -Mathematics::MathF::GetPI(), -Mathematics::MathF::GetPI() },
      maxRotation{ Mathematics::MathF::GetPI(), Mathematics::MathF::GetPI(), Mathematics::MathF::GetPI() },
      object{ object },
      goals{ goals }
{
    RENDERING_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Rendering, IKJointImpl)

int Rendering::IKJointImpl::GetStreamingSize() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    auto size = numAxis * CoreTools::GetStreamSize(allowTranslation.at(0));
    size += numAxis * CoreTools::GetStreamSize(minTranslation.at(0));
    size += numAxis * CoreTools::GetStreamSize(maxTranslation.at(0));
    size += numAxis * CoreTools::GetStreamSize(allowRotation.at(0));
    size += numAxis * CoreTools::GetStreamSize(minRotation.at(0));
    size += numAxis * CoreTools::GetStreamSize(maxRotation.at(0));
    size += CoreTools::GetStreamSize(object);
    size += CoreTools::GetStreamSize(boost::numeric_cast<int32_t>(goals.size()));

    if (!goals.empty())
    {
        size += boost::numeric_cast<int32_t>(goals.size() * CoreTools::GetStreamSize(goals.at(0)));
    }

    return size;
}

void Rendering::IKJointImpl::Save(CoreTools::BufferTarget& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.WriteContainer(allowTranslation);
    target.WriteContainer(minTranslation);
    target.WriteContainer(maxTranslation);
    target.WriteContainer(allowRotation);
    target.WriteContainer(minRotation);
    target.WriteContainer(maxRotation);
    target.WriteObjectAssociated(object);
    target.WriteObjectAssociatedContainerWithNumber(goals);
}

void Rendering::IKJointImpl::Load(CoreTools::BufferSource& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ReadContainer(allowTranslation);
    source.ReadContainer(minTranslation);
    source.ReadContainer(maxTranslation);
    source.ReadContainer(allowRotation);
    source.ReadContainer(minRotation);
    source.ReadContainer(maxRotation);
    source.ReadObjectAssociated(object);
    source.ReadObjectAssociatedContainer(goals);
}

void Rendering::IKJointImpl::Link(CoreTools::ObjectLink& source)
{
    RENDERING_CLASS_IS_VALID_9;

    source.ResolveLink(object);
    source.ResolveLinkContainer(goals);
}

void Rendering::IKJointImpl::Register(CoreTools::ObjectRegister& target) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    target.Register(object);
    target.RegisterContainer(goals);
}

CoreTools::ObjectSharedPtr Rendering::IKJointImpl::GetObjectByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = object.object->GetObjectByName(name);

    if (result != nullptr)
        return result;
    else
    {
        for (auto& pointer : goals)
        {
            result = pointer.object->GetObjectByName(name);

            if (result != nullptr)
            {
                return result;
            }
        }

        return nullptr;
    }
}

std::vector<CoreTools::ObjectSharedPtr> Rendering::IKJointImpl::GetAllObjectsByName(const std::string& name)
{
    RENDERING_CLASS_IS_VALID_9;

    auto objects = object.object->GetAllObjectsByName(name);

    for (auto& pointer : goals)
    {
        auto pointerObjects = pointer.object->GetAllObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

CoreTools::ConstObjectSharedPtr Rendering::IKJointImpl::GetConstObjectByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto result = object.object->GetConstObjectByName(name);

    if (result != nullptr)
    {
        return result;
    }
    else
    {
        for (auto& pointer : goals)
        {
            result = pointer.object->GetConstObjectByName(name);
            if (result != nullptr)
            {
                return result;
            }
        }

        return nullptr;
    }
}

std::vector<CoreTools::ConstObjectSharedPtr> Rendering::IKJointImpl::GetAllConstObjectsByName(const std::string& name) const
{
    RENDERING_CLASS_IS_VALID_9;

    auto objects = object.object->GetAllConstObjectsByName(name);

    for (const auto& pointer : goals)
    {
        auto pointerObjects = pointer.object->GetAllConstObjectsByName(name);
        objects.insert(objects.end(), pointerObjects.begin(), pointerObjects.end());
    }

    return objects;
}

Rendering::IKJointImpl::AVector Rendering::IKJointImpl::GetAxis(MatrixRotationAxis axisIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    const auto parent = object.object->GetParent();
    if (!parent->IsNullObject())
    {
        return AVector{ parent->GetWorldTransform().GetRotate().GetColumn(System::EnumCastUnderlying(axisIndex)) };
    }
    else if (axisIndex == Mathematics::MatrixRotationAxis::X)
    {
        return Mathematics::AVectorF::GetUnitX();
    }
    else if (axisIndex == Mathematics::MatrixRotationAxis::Y)
    {
        return Mathematics::AVectorF::GetUnitY();
    }
    else  //  axisIndex == MatrixRotationAxis::Z
    {
        return Mathematics::AVectorF::GetUnitZ();
    }
}

void Rendering::IKJointImpl::UpdateWorldTransform()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto parent = object.object->GetParent();
    if (!parent->IsNullObject())
    {
        object.object->SetWorldTransform(parent->GetWorldTransform() * object.object->GetLocalTransform());
    }
    else
    {
        object.object->SetWorldTransform(object.object->GetLocalTransform());
    }
}

void Rendering::IKJointImpl::UpdateWorldRotateAndTranslate()
{
    RENDERING_CLASS_IS_VALID_9;

    const auto parent = object.object->GetParent();
    if (!parent->IsNullObject())
    {
        auto transform = object.object->GetWorldTransform();

        const auto rotate = parent->GetWorldTransform().GetRotate() * object.object->GetLocalTransform().GetRotate();
        transform.SetRotate(rotate);

        const auto translate = parent->GetWorldTransform() * object.object->GetLocalTransform().GetTranslate();

        transform.SetTranslate(translate);
        object.object->SetWorldTransform(transform);
    }
    else
    {
        auto transform = object.object->GetWorldTransform();

        transform.SetRotate(object.object->GetLocalTransform().GetRotate());
        transform.SetTranslate(object.object->GetLocalTransform().GetTranslate());
        object.object->SetWorldTransform(transform);
    }
}

bool Rendering::IKJointImpl::UpdateLocalTranslate(MatrixRotationAxis axisIndex)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto axis = GetAxis(axisIndex);

    auto oldNorm = 0.0f;
    auto numer = 0.0f;
    auto denom = 0.0f;
    for (const auto& goal : goals)
    {
        const auto goalMinusEffector = goal.object->GetTargetPosition() - goal.object->GetEffectorPosition();
        oldNorm += goalMinusEffector.SquaredLength();
        numer += goal.object->GetWeight() * Dot(axis, goalMinusEffector);
        denom += goal.object->GetWeight();
    }

    if (Mathematics::MathF::FAbs(denom) <= Mathematics::MathF::GetZeroTolerance())
    {
        // Ȩ��̫С��û��ת����
        return false;
    }

    // ������axis(i) ת���ľ��롣
    auto distance = numer / denom;

    // �ضϵ���Χ
    auto translate = object.object->GetLocalTransform().GetTranslate();
    auto desired = translate[System::EnumCastUnderlying(axisIndex)] + distance;
    if (desired > minTranslation.at(System::EnumCastUnderlying(axisIndex)))
    {
        if (desired < maxTranslation.at(System::EnumCastUnderlying(axisIndex)))
        {
            translate[System::EnumCastUnderlying(axisIndex)] = desired;
        }
        else
        {
            distance = maxTranslation.at(System::EnumCastUnderlying(axisIndex)) - translate[System::EnumCastUnderlying(axisIndex)];
            translate[System::EnumCastUnderlying(axisIndex)] = maxTranslation.at(System::EnumCastUnderlying(axisIndex));
        }
    }
    else
    {
        distance = minTranslation.at(System::EnumCastUnderlying(axisIndex)) - translate[System::EnumCastUnderlying(axisIndex)];
        translate[System::EnumCastUnderlying(axisIndex)] = minTranslation.at(System::EnumCastUnderlying(axisIndex));
    }

    // ���Բ����Ƿ�Ӧ�ò�ȡ��
    auto newNorm = 0.0f;
    auto step = distance * axis;
    for (const auto& goal : goals)
    {
        const auto newEffector = goal.object->GetEffectorPosition() + step;
        const auto difference = goal.object->GetTargetPosition() - newEffector;
        newNorm += difference.SquaredLength();
    }
    if (oldNorm <= newNorm)
    {
        // ת����û�еõ����ӽ�Ŀ���Ч����
        return false;
    }

    // ���±��ص�ת����
    object.object->SetLocalTransformTranslate(translate);

    return true;
}

bool Rendering::IKJointImpl::UpdateLocalRotate(MatrixRotationAxis axisIndex)
{
    RENDERING_CLASS_IS_VALID_9;

    const auto axis = GetAxis(axisIndex);

    auto numer = 0.0f;
    auto denom = 0.0f;
    auto oldNorm = 0.0f;

    for (const auto& goal : goals)
    {
        const auto effectorMinusPoint = goal.object->GetEffectorPosition() - object.object->GetWorldTransform().GetTranslate();
        const auto goalMinusPoint = goal.object->GetTargetPosition() - object.object->GetWorldTransform().GetTranslate();
        const auto goalMinusEffector = goal.object->GetTargetPosition() - goal.object->GetEffectorPosition();
        oldNorm += goalMinusEffector.SquaredLength();
        const auto axisCrossEffectorMinusPoint = Cross(axis, effectorMinusPoint);
        const auto axisCrossAxisCrossEffectorMinusPoint = Cross(axis, axisCrossEffectorMinusPoint);
        numer += goal.object->GetWeight() * Dot(goalMinusPoint, axisCrossEffectorMinusPoint);
        denom -= goal.object->GetWeight() * Dot(goalMinusPoint, axisCrossAxisCrossEffectorMinusPoint);
    }

    if (numer * numer + denom * denom <= Mathematics::MathF::GetZeroTolerance())
    {
        // δ���� atan2,����ת��
        return false;
    }

    // ����Ƕ���axis(i)��ת��
    auto theta = Mathematics::MathF::ATan2(numer, denom);

    // �ֲ�������תŷ���ǡ�
    auto rotate = object.object->GetLocalTransform().GetRotate();
    auto rotateMatrix3 = rotate.GetMatrix3();
    auto euler = rotateMatrix3.ExtractEulerZYX();

    // �ضϵ���Χ
    auto desired = euler.GetAngle(axisIndex) + theta;
    if (desired > minRotation.at(System::EnumCastUnderlying(axisIndex)))
    {
        if (desired < maxRotation.at(System::EnumCastUnderlying(axisIndex)))
        {
            euler.SetAngle(axisIndex, desired);
        }
        else
        {
            theta = maxRotation.at(System::EnumCastUnderlying(axisIndex)) - euler.GetAngle(axisIndex);
            euler.SetAngle(axisIndex, maxRotation.at(System::EnumCastUnderlying(axisIndex)));
        }
    }
    else
    {
        theta = minRotation.at(System::EnumCastUnderlying(axisIndex)) - euler.GetAngle(axisIndex);
        euler.SetAngle(axisIndex, minRotation.at(System::EnumCastUnderlying(axisIndex)));
    }

    // ���Բ����Ƿ�Ӧ�ò�ȡ��
    auto newNorm = 0.0f;
    rotate.MakeRotation(axis, theta);
    for (const auto& goal : goals)
    {
        const auto effectorMinusPoint = goal.object->GetEffectorPosition() - object.object->GetWorldTransform().GetTranslate();
        const auto newEffector = object.object->GetWorldTransform().GetTranslate() + rotate * effectorMinusPoint;
        const auto goalMinusEffector = goal.object->GetTargetPosition() - newEffector;
        newNorm += goalMinusEffector.SquaredLength();
    }

    if (oldNorm <= newNorm)
    {
        // ��ת��û�еõ����ӽ�Ŀ���Ч����
        return false;
    }

    // ���¾ֲ���ת
    rotateMatrix3.MakeEulerZYX(euler.GetZ0Angle(), euler.GetY0Angle(), euler.GetX0Angle());

    rotate = Mathematics::MatrixF{ rotateMatrix3 };
    object.object->SetLocalTransformRotate(rotate);

    return true;
}

Rendering::ConstSpatialSharedPtr Rendering::IKJointImpl::GetObjectSharedPtr() const noexcept
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return object.object;
}

Rendering::ConstIKGoalSharedPtr Rendering::IKJointImpl::GetGoalsSharedPtr(int index) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= index && index < boost::numeric_cast<int>(goals.size()), "��������");

    return goals.at(index).object;
}

int Rendering::IKJointImpl::GetGoalsNum() const
{
    RENDERING_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(goals.size());
}

void Rendering::IKJointImpl::SetAllowTranslation(MatrixRotationAxis axisIndex, bool aAllowTranslation)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < numAxis, "��������");

    allowTranslation.at(System::EnumCastUnderlying(axisIndex)) = aAllowTranslation;
}

void Rendering::IKJointImpl::SetAllowRotation(MatrixRotationAxis axisIndex, bool aAllowRotation)
{
    RENDERING_CLASS_IS_VALID_9;
    RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < numAxis, "��������");

    allowRotation.at(System::EnumCastUnderlying(axisIndex)) = aAllowRotation;
}

bool Rendering::IKJointImpl::IsAllowTranslation(MatrixRotationAxis axisIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < numAxis, "��������");

    return allowTranslation.at(System::EnumCastUnderlying(axisIndex));
}

bool Rendering::IKJointImpl::IsAllowRotation(MatrixRotationAxis axisIndex) const
{
    RENDERING_CLASS_IS_VALID_CONST_9;
    RENDERING_ASSERTION_0(0 <= System::EnumCastUnderlying(axisIndex) && System::EnumCastUnderlying(axisIndex) < numAxis, "��������");

    return allowRotation.at(System::EnumCastUnderlying(axisIndex));
}
