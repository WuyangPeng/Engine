// Copyright (c) 2010-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎版本：0.0.2.5 (2020/03/24 17:10)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_ACHIEVE_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_ACHIEVE_H

#include "StaticFindIntersectorLine3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::StaticFindIntersectorLine3Ellipsoid3(const Line3& line, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, m_Line{ line }, m_Ellipsoid{ ellipsoid }, m_NegativeThreshold{}, m_PositiveThreshold{}
{
    Find();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Line;
}

template <typename Real>
const Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Ellipsoid;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::Find()
{
    /// 椭球是(X - K)^T * M * (X - K)-1 = 0并且线是 X = P + t * D。
    /// 将线方程代入椭球方程以获得二次方程
    /// Q(t) = a2 * t^2 + 2 * a1 * t + a0 = 0
    /// 其中a2 = D^T * M * D, a1 = D^T * M * (P - K)，a0 = (P - K)^T * M * (P - K) - 1。

    const auto matrix = m_Ellipsoid.GetMatrix();

    auto diff = m_Line.GetOrigin() - m_Ellipsoid.GetCenter();
    const auto matrixDirection = matrix * m_Line.GetDirection();
    const auto matrixDiff = matrix * diff;
    auto a2 = Vector3DTools::DotProduct(m_Line.GetDirection(), matrixDirection);
    auto a1 = Vector3DTools::DotProduct(m_Line.GetDirection(), matrixDiff);
    auto a0 = Vector3DTools::DotProduct(diff, matrixDiff) - Math::GetValue(1);

    // 如果Q(t)具有实根，则发生相交。
    auto discr = a1 * a1 - a0 * a2;

    if (discr < m_NegativeThreshold)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        m_Quantity = 0;
    }
    else if (discr > m_PositiveThreshold)
    {
        this->SetIntersectionType(IntersectionType::Segment);
        m_Quantity = 2;

        auto root = Math::Sqrt(discr);
        auto inv = (Math::GetValue(1)) / a2;
        auto t0 = (-a1 - root) * inv;
        auto t1 = (-a1 + root) * inv;
        m_Point0 = m_Line.GetOrigin() + t0 * m_Line.GetDirection();
        m_Point1 = m_Line.GetOrigin() + t1 * m_Line.GetDirection();
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Point);
        m_Quantity = 1;

        auto t0 = -a1 / a2;
        m_Point0 = m_Line.GetOrigin() + t0 * m_Line.GetDirection();
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Quantity;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < m_Quantity)
    {
        if (index == 0)
            return m_Point0;
        else if (index == 1)
            return m_Point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("索引越界\n"s));
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::SetNegativeThreshold(Real negThreshold)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_0(Math::GetValue(0) < negThreshold, "负阈值必须为非正数。");

    if (negThreshold <= Math::GetValue(0))
    {
        m_NegativeThreshold = negThreshold;
    }
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetNegativeThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_NegativeThreshold;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::SetPositiveThreshold(Real posThreshold)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_0(posThreshold < Math::GetValue(0), "正阈值必须为非负。");

    if (Math::GetValue(0) <= posThreshold)
    {
        m_PositiveThreshold = posThreshold;
    }
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetPositiveThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_PositiveThreshold;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_ACHIEVE_H