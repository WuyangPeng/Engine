///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 10:08)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_ACHIEVE_H

#include "StaticFindIntersectorSegment3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Intersection/StaticFindIntersector1Detail.h"

template <typename Real>
Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::StaticFindIntersectorSegment3Ellipsoid3(const Segment3& segment, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, m_Segment{ segment }, m_Ellipsoid{ ellipsoid }, m_Quantity{}, m_Point0{}, m_Point1{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Segment3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetSegment() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Segment;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipsoid;
}

template <typename Real>
void Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::Find()
{
    /// 椭球是(X - K)^T * M * (X - K)-1 = 0 并且线是X = P + t * D。
    /// 将线方程代入椭球方程以获得二次方程
    /// Q(t) = a2 * t^2 + 2 * a1 * t + a0 = 0
    /// 其中a2 = D^T * M * D, a1 = D^T * M * (P - K)，a0 = (P - K)^T * M * (P - K) - 1。
    const auto matrix = m_Ellipsoid.GetMatrix();

    auto diff = m_Segment.GetCenterPoint() - m_Ellipsoid.GetCenter();
    const auto matrixDirection = matrix * m_Segment.GetDirection();
    const auto matrixDiff = matrix * diff;
    auto a2 = Vector3DTools::DotProduct(m_Segment.GetDirection(), matrixDirection);
    auto a1 = Vector3DTools::DotProduct(m_Segment.GetDirection(), matrixDiff);
    auto a0 = Vector3DTools::DotProduct(diff, matrixDiff) - Math::GetValue(1);

    // 如果 Q(t)具有t >= 0的实根，则发生相交。
    auto discr = a1 * a1 - a0 * a2;

    if (discr < Math::GetValue(0))
    {
        this->SetIntersectionType(IntersectionType::Empty);
        m_Quantity = 0;
    }
    else if (Math::GetZeroTolerance() < discr)
    {
        auto root = Math::Sqrt(discr);
        auto inv = (Math::GetValue(1)) / a2;
        auto t0 = (-a1 - root) * inv;
        auto t1 = (-a1 + root) * inv;

        // 断言：t0 < t1因为a2 > 0
        StaticFindIntersector1<Real> intr{ t0, t1, -m_Segment.GetExtent(), m_Segment.GetExtent() };

        m_Quantity = intr.GetNumIntersections();
        if (m_Quantity == 2)
        {
            this->SetIntersectionType(IntersectionType::Segment);
            m_Point0 = m_Segment.GetCenterPoint() + intr.GetIntersection(0) * m_Segment.GetDirection();
            m_Point1 = m_Segment.GetCenterPoint() + intr.GetIntersection(1) * m_Segment.GetDirection();
        }
        else if (m_Quantity == 1)
        {
            this->SetIntersectionType(IntersectionType::Point);
            m_Point0 = m_Segment.GetCenterPoint() + intr.GetIntersection(0) * m_Segment.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
        }
    }
    else
    {
        auto t0 = -a1 / a2;
        if (Math::FAbs(t0) <= m_Segment.GetExtent())
        {
            this->SetIntersectionType(IntersectionType::Point);
            m_Quantity = 1;
            m_Point0 = m_Segment.GetCenterPoint() + t0 * m_Segment.GetDirection();
        }
        else
        {
            this->SetIntersectionType(IntersectionType::Empty);
            m_Quantity = 0;
        }
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorSegment3Ellipsoid3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_SEGMENT3_ELLIPSOID3_ACHIEVE_H