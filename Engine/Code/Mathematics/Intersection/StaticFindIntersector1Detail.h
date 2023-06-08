///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:17)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_DETAIL_H

#include "Intersector1Detail.h"
#include "StaticFindIntersector1.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticFindIntersector1<Real>::StaticFindIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon)
    : ParentType{ u0, u1, v0, v1, epsilon }, intersections{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::StaticFindIntersector1<Real>::Find()
{
    const auto u0 = this->GetU(0);
    const auto u1 = this->GetU(1);
    const auto v0 = this->GetV(0);
    const auto v1 = this->GetV(1);
    const auto epsilon = this->GetEpsilon();

    if (u0 - epsilon <= v1 && v0 - epsilon <= u1)
    {
        if (v0 + epsilon < u1)
        {
            if (u0 + epsilon <= v1)
            {
                const auto lhsIntersection = (u0 < v0 ? v0 : u0);
                const auto rhsIntersection = (v1 < u1 ? v1 : u1);

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
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersector1<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticFindIntersector1<Real>::IsIntersection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return !intersections.empty();
}

template <typename Real>
int Mathematics::StaticFindIntersector1<Real>::GetNumIntersections() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return boost::numeric_cast<int>(intersections.size());
}

template <typename Real>
Real Mathematics::StaticFindIntersector1<Real>::GetIntersection(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return intersections.at(index);
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR1_DETAIL_H
