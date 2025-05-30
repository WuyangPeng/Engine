///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorLozenge3Lozenge3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceRectangle3Rectangle3Detail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>::StaticTestIntersectorLozenge3Lozenge3(const Lozenge3Type& lozenge0, const Lozenge3Type& lozenge1, const Real epsilon)
    : ParentType{ epsilon }, lozenge0{ lozenge0 }, lozenge1{ lozenge1 }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>::GetLozenge0() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lozenge0;
}

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>::GetLozenge1() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lozenge1;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLozenge3Lozenge3<Real>::Test()
{
    const auto distance = DistanceRectangle3Rectangle3<Real>(lozenge0.GetRectangle(), lozenge1.GetRectangle()).Get().GetDistance();
    const auto rSum = lozenge0.GetRadius() + lozenge1.GetRadius();
    if (distance <= rSum)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_DETAIL_H