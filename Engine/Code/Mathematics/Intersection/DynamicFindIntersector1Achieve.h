///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 18:30)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_ACHIEVE_H

#include "DynamicFindIntersector1.h"
#include "Intersector1Detail.h"
#include "Detail/DynamicFindIntersector1ImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::DynamicFindIntersector1<Real>::DynamicFindIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon)
    : ParentType{ u0, u1, v0, v1, epsilon }, m_Impl{}
{
    Find(tMax, speedU, speedV);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::DynamicFindIntersector1<Real>::Find(Real tMax, Real speedU, Real speedV)
{
    using IntersectionsType = std::vector<Real>;

    IntersectionsType intersections{};
    auto firstTime = Math::GetValue(0);
    auto lastTime = Math::GetValue(0);

    auto u0 = this->GetU(0);
    auto u1 = this->GetU(1);
    auto v0 = this->GetV(0);
    auto v1 = this->GetV(1);
    auto epsilon = this->GetEpsilon();

    if (u1 + epsilon < v0)
    {
        // [u0,u1]最初在[v0,v1]的左边。
        auto differenceSpeed = speedU - speedV;
        if (Math::GetValue(0) < differenceSpeed)
        {
            // 区间必须朝向彼此移动。
            auto differencePosition = v0 - u1;
            if (differencePosition <= tMax * differenceSpeed)
            {
                // 区间在指定时间内相交。
                firstTime = differencePosition / differenceSpeed;
                lastTime = (v1 - u0) / differenceSpeed;

                intersections.emplace_back(u1 + firstTime * speedU);
            }
        }
    }
    else if (v1 + epsilon < u0)
    {
        // [u0,u1]最初在[v0,v1]的右边。
        auto differenceSpeed = speedV - speedU;
        if (Math::GetValue(0) < differenceSpeed)
        {
            // 区间必须朝向彼此移动。
            auto differencePosition = u0 - v1;
            if (differencePosition <= tMax * differenceSpeed)
            {
                // 区间在指定时间内相交。
                firstTime = differencePosition / differenceSpeed;
                lastTime = (u1 - v0) / differenceSpeed;

                intersections.emplace_back(v1 + firstTime * speedV);
            }
        }
    }
    else
    {
        // 区间本来就相交。
        firstTime = Math::GetValue(0);
        if (speedU + epsilon < speedV)
        {
            lastTime = (u1 - v0) / (speedV - speedU);
        }
        else if (speedV + epsilon < speedU)
        {
            lastTime = (v1 - u0) / (speedU - speedV);
        }
        else
        {
            lastTime = Math::sm_MaxReal;
        }

        if (v0 + epsilon < u1)
        {
            if (u0 + epsilon < v1)
            {
                auto lhsIntersection = (u0 < v0 ? v0 : u0);
                auto rhsIntersection = (v1 < u1 ? v1 : u1);

                if (Math::Approximate(lhsIntersection, rhsIntersection, epsilon))
                {
                    intersections.emplace_back((lhsIntersection + rhsIntersection) / Math::GetValue(2));
                }
                else
                {
                    intersections.emplace_back(lhsIntersection);
                    intersections.emplace_back(rhsIntersection);
                }
            }
            else  // u0 == v1
            {
                intersections.emplace_back((u0 + v1) / Math::GetValue(2));
            }
        }
        else  // u1 == v0
        {
            intersections.emplace_back((u1 + v0) / Math::GetValue(2));
        }
    }

    m_Impl = std::make_shared<ImplType>(firstTime, lastTime, intersections);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::DynamicFindIntersector1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::DynamicFindIntersector1<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsIntersection();
}

template <typename Real>
int Mathematics::DynamicFindIntersector1<Real>::GetNumIntersections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumIntersections();
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1<Real>::GetIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetIntersection(index);
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1<Real>::GetFirstTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetFirstTime();
}

template <typename Real>
Real Mathematics::DynamicFindIntersector1<Real>::GetLastTime() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetLastTime();
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR1_ACHIEVE_H
