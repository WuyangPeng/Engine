///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 13:49)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H

#include "StaticFindIntersectorLine3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::StaticFindIntersectorLine3Ellipsoid3(const Line3& line, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, ellipsoid{ ellipsoid }, negativeThreshold{}, positiveThreshold{}
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
Mathematics::Line3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return line;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::Find()
{
    /// ������(X - K)^T * M * (X - K)-1 = 0�������� X = P + t * D��
    /// ���߷��̴������򷽳��Ի�ö��η���
    /// Q(t) = a2 * t^2 + 2 * a1 * t + a0 = 0
    /// ����a2 = D^T * M * D, a1 = D^T * M * (P - K)��a0 = (P - K)^T * M * (P - K) - 1��

    const auto matrix = ellipsoid.GetMatrix();

    auto diff = line.GetOrigin() - ellipsoid.GetCenter();
    const auto matrixDirection = matrix * line.GetDirection();
    const auto matrixDiff = matrix * diff;
    auto a2 = Vector3Tools::DotProduct(line.GetDirection(), matrixDirection);
    auto a1 = Vector3Tools::DotProduct(line.GetDirection(), matrixDiff);
    auto a0 = Vector3Tools::DotProduct(diff, matrixDiff) - Math::GetValue(1);

    // ���Q(t)����ʵ���������ཻ��
    auto discr = a1 * a1 - a0 * a2;

    if (discr < negativeThreshold)
    {
        this->SetIntersectionType(IntersectionType::Empty);
        quantity = 0;
    }
    else if (discr > positiveThreshold)
    {
        this->SetIntersectionType(IntersectionType::Segment);
        quantity = 2;

        auto root = Math::Sqrt(discr);
        auto inv = (Math::GetValue(1)) / a2;
        auto t0 = (-a1 - root) * inv;
        auto t1 = (-a1 + root) * inv;
        point0 = line.GetOrigin() + t0 * line.GetDirection();
        point1 = line.GetOrigin() + t1 * line.GetDirection();
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Point);
        quantity = 1;

        auto t0 = -a1 / a2;
        point0 = line.GetOrigin() + t0 * line.GetDirection();
    }
}

template <typename Real>
int Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetQuantity() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return quantity;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    if (index < quantity)
    {
        if (index == 0)
            return point0;
        else if (index == 1)
            return point1;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("����Խ��\n"s));
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::SetNegativeThreshold(Real negThreshold)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_0(Math::GetValue(0) < negThreshold, "����ֵ����Ϊ��������");

    if (negThreshold <= Math::GetValue(0))
    {
        negativeThreshold = negThreshold;
    }
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetNegativeThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return negativeThreshold;
}

template <typename Real>
void Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::SetPositiveThreshold(Real posThreshold)
{
    MATHEMATICS_CLASS_IS_VALID_1;

    MATHEMATICS_ASSERTION_0(posThreshold < Math::GetValue(0), "����ֵ����Ϊ�Ǹ���");

    if (Math::GetValue(0) <= posThreshold)
    {
        positiveThreshold = posThreshold;
    }
}

template <typename Real>
Real Mathematics::StaticFindIntersectorLine3Ellipsoid3<Real>::GetPositiveThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return positiveThreshold;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H