///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:27)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_DETAIL_H

#include "StaticTestIntersectorPlane3Lozenge3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>::StaticTestIntersectorPlane3Lozenge3(const Plane3Type& plane, const Lozenge3Type& lozenge, const Real epsilon)
    : ParentType{ epsilon }, plane{ plane }, lozenge{ lozenge }
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Plane3<Real> Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>::GetPlane() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return plane;
}

template <typename Real>
Mathematics::Lozenge3<Real> Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>::GetLozenge() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return lozenge;
}

template <typename Real>
void Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>::Test()
{
    const auto sDistMM = plane.DistanceTo(lozenge.GetRectangle().GetMMCorner());
    const auto sDistPM = plane.DistanceTo(lozenge.GetRectangle().GetPMCorner());
    if (sDistMM * sDistPM <= MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    const auto sDistMP = plane.DistanceTo(lozenge.GetRectangle().GetMPCorner());
    if (sDistMM * sDistMP <= MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    const auto sDistPP = plane.DistanceTo(lozenge.GetRectangle().GetPPCorner());
    if (sDistPM * sDistPP <= MathType::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Other);
        return;
    }

    if (MathType::FAbs(sDistMM) <= lozenge.GetRadius() || MathType::FAbs(sDistPM) <= lozenge.GetRadius() || MathType::FAbs(sDistMP) <= lozenge.GetRadius() || MathType::FAbs(sDistPP) <= lozenge.GetRadius())
    {
        this->SetIntersectionType(IntersectionType::Other);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
bool Mathematics::StaticTestIntersectorPlane3Lozenge3<Real>::LozengeIsCulled() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    const auto sDistMM = plane.DistanceTo(lozenge.GetRectangle().GetMMCorner());
    if (sDistMM < MathType::GetValue(0))
    {
        auto sDistPM = plane.DistanceTo(lozenge.GetRectangle().GetPMCorner());
        if (sDistPM < MathType::GetValue(0))
        {
            auto sDistMP = plane.DistanceTo(lozenge.GetRectangle().GetMPCorner());
            if (sDistMP < MathType::GetValue(0))
            {
                auto sDistPP = plane.DistanceTo(lozenge.GetRectangle().GetPPCorner());
                if (sDistPP < MathType::GetValue(0))
                {
                    if (sDistMM <= sDistPM)
                    {
                        if (sDistMM <= sDistMP)
                        {
                            return sDistMM <= -lozenge.GetRadius();
                        }
                        else
                        {
                            return sDistMP <= -lozenge.GetRadius();
                        }
                    }
                    else
                    {
                        if (sDistPM <= sDistPP)
                        {
                            return sDistPM <= -lozenge.GetRadius();
                        }
                        else
                        {
                            return sDistPP <= -lozenge.GetRadius();
                        }
                    }
                }
            }
        }
    }

    return false;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_PLANE3_LOZENGE3_DETAIL_H