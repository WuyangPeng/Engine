///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 15:42)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorLine3Lozenge3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Rectangle3.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Lozenge3<Real>::StaticTestIntersectorLine3Lozenge3(const Line3& line, const Lozenge3& lozenge, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, lozenge{ lozenge }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Lozenge3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Lozenge3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorLine3Lozenge3<Real>::GetLozenge() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Lozenge3<Real>::Test()
{
    const auto distance = DistanceLine3Rectangle3<Real>(line, lozenge.GetRectangle()).Get().GetDistance();

    if (distance <= lozenge.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_DETAIL_H