///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/09 09:17)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_DETAIL_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_DETAIL_H

#include "DynamicFindIntersectorBox3Box3.h"
#include "FindContactSet.h"
#include "FindIntersectorAxis.h"
#include "IntersectorConfiguration.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/Flags/ContactSide.h"

template <typename Real>
Mathematics::DynamicFindIntersectorBox3Box3<Real>::DynamicFindIntersectorBox3Box3(const Box3& box0, const Box3& box1, Real tmax, const Vector3& lhsVelocity, const Vector3& rhsVelocity, const Real epsilon)
    : ParentType{ tmax, lhsVelocity, rhsVelocity, epsilon }, box0{ box0 }, box1{ box1 }, point{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersectorBox3Box3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetBox0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box0;
}

template <typename Real>
Mathematics::Box3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetBox1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return box1;
}

template <typename Real>
int Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetQuantity() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(point.size());
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::DynamicFindIntersectorBox3Box3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return point.at(index);
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

    // box 0 法线。
    for (auto i = 0; i < 3; ++i)
    {
        const auto axis = box0.GetAxis(i);

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
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

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
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
            const auto axis = Vector3Tools::CrossProduct(box0.GetAxis(outerIndex), box1.GetAxis(innerIndex));

            // 由于所有轴都是单位长度（假定），因此可以将其与恒定（而非相对）epsilon进行比较。
            if (Vector3Tools::GetLengthSquared(axis) <= Math::GetZeroTolerance())
            {
                /// 轴i0和i1平行。 如果任意两个轴平行，则唯一需要的比较就是面自身之间的比较。
                /// 目前，这些面已经过测试，没有分离，因此所有进一步的分离测试将仅显示重叠。

                FindContactSet<Real> findContactSet{ box0, box1, side, box0Cfg, box1Cfg, this->GetLhsVelocity(), this->GetRhsVelocity(), contactTime };
                point = findContactSet.GetPoint();
                this->SetContactTime(contactTime);
                this->SetIntersectionType(IntersectionType::Other);
                return;
            }

            const FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
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
        const auto axis = Vector3Tools::CrossProduct(relVelocity, box0.GetAxis(i));

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
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
        const auto axis = Vector3Tools::CrossProduct(relVelocity, box1.GetAxis(i));

        const FindIntersectorAxis<Real> findIntersectorAxis{ axis, box0, box1, relVelocity, this->GetTMax() };
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

    const FindContactSet<Real> findContactSet{ box0, box1, side, box0Cfg, box1Cfg, this->GetLhsVelocity(), this->GetRhsVelocity(), contactTime };
    point = findContactSet.GetPoint();

    this->SetContactTime(contactTime);
    this->SetIntersectionType(IntersectionType::Other);
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_BOX3_BOX3_DETAIL_H