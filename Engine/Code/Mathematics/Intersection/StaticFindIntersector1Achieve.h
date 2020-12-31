///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 15:44)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_ACHIEVE_H

#include "Intersector1Detail.h"
#include "StaticFindIntersector1.h"
#include "Detail/StaticFindIntersector1ImplDetail.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersector1<Real>::StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon)
    : ParentType{ u0, u1, v0, v1, epsilon }, m_Impl{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersector1<Real>::Find()
{
    using IntersectionsType = std::vector<Real>;

    IntersectionsType intersections{};

    auto u0 = this->GetU(0);
    auto u1 = this->GetU(1);
    auto v0 = this->GetV(0);
    auto v1 = this->GetV(1);
    auto epsilon = this->GetEpsilon();

    if (u0 - epsilon <= v1 && v0 - epsilon <= u1)
    {
        if (v0 + epsilon < u1)
        {
            if (u0 + epsilon <= v1)
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
        else  // v0 == u1
        {
            intersections.emplace_back((v0 + u1) / Math::GetValue(2));
        }
    }

    m_Impl = std::make_shared<ImplType>(intersections);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersector1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_Impl != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersector1<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->IsIntersection();
}

template <typename Real>
int Mathematics::StaticFindIntersector1<Real>::GetNumIntersections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetNumIntersections();
}

template <typename Real>
Real Mathematics::StaticFindIntersector1<Real>::GetIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Impl->GetIntersection(index);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_ACHIEVE_H
