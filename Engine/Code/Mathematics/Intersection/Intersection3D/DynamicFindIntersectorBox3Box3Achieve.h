///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/29 11:30)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_ACHIEVE_H

#include "DynamicFindIntersectorBox3Box3.h"
#include "FindContactSet.h"
#include "FindIntersectorAxis.h"
#include "IntersectorConfiguration.h"
#include "Detail/DynamicFindIntersectorBox3Box3ImplDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox3Box3<Real>::DynamicFindIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, m_Impl{ std::make_shared<ImplType>(box0, box1) }
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersectorBox3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetBox0();
}

template <typename Real>
const Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetBox1();
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetQuantity();
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetPoint(index);
}

template <typename Real>
void Mathematics::DynamicFindIntersectorBox3Box3<Real>::Find()
{
    this->SetContactTime(Math::GetValue(0));

    auto contactTime = Math::GetValue(0);
    auto tLast = Math::GetValue(0);
    auto side = ContactSide::None;
    IntersectorConfiguration<Real> box0Cfg{};
    IntersectorConfiguration<Real> box1Cfg{};

    // box1相对于box0的相对速度。
    auto relVelocity = this->GetRhsVelocity() - this->GetLhsVelocity();

    auto box0 = m_Impl->GetBox0();
    auto box1 = m_Impl->GetBox1();

    // box 0 法线。
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = box0.GetAxis(i);

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        box0Cfg = findIntersectorAxis.GetCfgFinal0();
        box1Cfg = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetIntersectionType(IntersectionType::Empty);
            this->SetContactTime(contactTime);
            return;
        }

        this->SetContactTime(contactTime);
    }

    // box 1 法线
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = box1.GetAxis(i);

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        box0Cfg = findIntersectorAxis.GetCfgFinal0();
        box1Cfg = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetIntersectionType(IntersectionType::Empty);
            this->SetContactTime(contactTime);
            return;
        }

        this->SetContactTime(contactTime);
    }

    // 盒子0边交叉盒子1边
    for (auto outerIndex = 0; outerIndex < 3; ++outerIndex)
    {
        for (auto innerIndex = 0; innerIndex < 3; ++innerIndex)
        {
            const auto axis = Vector3DTools::CrossProduct(box0.GetAxis(outerIndex), box1.GetAxis(innerIndex));

            // 由于所有轴都是单位长度（假定），因此可以将其与恒定（而非相对）epsilon进行比较。
            if (Vector3DTools::VectorMagnitudeSquared(axis) <= Math::GetZeroTolerance())
            {
                /// 轴i0和i1平行。 如果任意两个轴平行，则唯一需要的比较就是面自身之间的比较。
                /// 目前，这些面已经过测试，没有分离，因此所有进一步的分离测试将仅显示重叠。

                FindContactSet<Real> findContactSet{ box0, box1, side, box0Cfg, box1Cfg, this->GetLhsVelocity(), this->GetRhsVelocity(), contactTime };
                m_Impl->SetPoint(findContactSet.GetPoint());
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }

            FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
            contactTime = findIntersectorAxis.GetTFirst();
            tLast = findIntersectorAxis.GetTLast();
            side = findIntersectorAxis.Getside();
            box0Cfg = findIntersectorAxis.GetCfgFinal0();
            box1Cfg = findIntersectorAxis.GetCfgFinal1();
            if (!findIntersectorAxis.GetResult())
            {
                this->SetIntersectionType(IntersectionType::Empty);
                this->SetContactTime(contactTime);
                return;
            }

            this->SetContactTime(contactTime);
        }
    }

    // 速度交叉box0边
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = Vector3DTools::CrossProduct(relVelocity, box0.GetAxis(i));

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        box0Cfg = findIntersectorAxis.GetCfgFinal0();
        box1Cfg = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetIntersectionType(IntersectionType::Empty);
            this->SetContactTime(contactTime);
            return;
        }

        this->SetContactTime(contactTime);
    }

    // 速度交叉box1边
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = Vector3DTools::CrossProduct(relVelocity, box1.GetAxis(i));

        FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
        contactTime = findIntersectorAxis.GetTFirst();
        tLast = findIntersectorAxis.GetTLast();
        side = findIntersectorAxis.Getside();
        box0Cfg = findIntersectorAxis.GetCfgFinal0();
        box1Cfg = findIntersectorAxis.GetCfgFinal1();
        if (!findIntersectorAxis.GetResult())
        {
            this->SetIntersectionType(IntersectionType::Empty);
            this->SetContactTime(contactTime);
            return;
        }

        this->SetContactTime(contactTime);
    }

    if (contactTime <= Math::GetValue(0) || side == ContactSide::None)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        this->SetContactTime(contactTime);
        return;
    }

    FindContactSet<Real> findContactSet{ box0, box1, side, box0Cfg, box1Cfg, this->GetLhsVelocity(), this->GetRhsVelocity(), contactTime };
    m_Impl->SetPoint(findContactSet.GetPoint());

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_ACHIEVE_H