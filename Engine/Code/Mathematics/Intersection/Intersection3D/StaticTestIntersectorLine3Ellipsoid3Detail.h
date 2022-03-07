///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 11:39)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H

#include "StaticTestIntersectorLine3Ellipsoid3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::StaticTestIntersectorLine3Ellipsoid3(const Line3& line, const Ellipsoid3& ellipsoid, const Real epsilon)
    : ParentType{ epsilon }, line{ line }, ellipsoid{ ellipsoid }, negativeThreshold{}, positiveThreshold{}
{
    Test();

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::IsValid() const noexcept
{
    if (ParentType::IsValid())
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Line3<Real> Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::GetLine() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return line;
}

template <typename Real>
Mathematics::Ellipsoid3<Real> Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::GetEllipsoid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ellipsoid;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::Test()
{
    const auto matrix = ellipsoid.GetMatrix();

    const auto diff = line.GetOrigin() - ellipsoid.GetCenter();
    const auto matDir = matrix * line.GetDirection();
    const auto matDiff = matrix * diff;
    const auto a2 = Vector3Tools::DotProduct(line.GetDirection(), matDir);
    const auto a1 = Vector3Tools::DotProduct(line.GetDirection(), matDiff);
    const auto a0 = Vector3Tools::DotProduct(diff, matDiff) - Math::GetValue(1);

    const auto discr = a1 * a1 - a0 * a2;
    if (negativeThreshold <= discr)
    {
        this->SetIntersectionType(IntersectionType::Point);
    }
    else
    {
        this->SetIntersectionType(IntersectionType::Empty);
    }
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::SetNegativeThreshold(Real negThreshold)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (negThreshold <= Math::GetValue(0))
    {
        negativeThreshold = negThreshold;
        return;
    }

    MATHEMATICS_ASSERTION_0(false, "负阈值必须是非正的。");
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::GetNegativeThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return negativeThreshold;
}

template <typename Real>
void Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::SetPositiveThreshold(Real posThreshold)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (posThreshold >= Math::GetValue(0))
    {
        positiveThreshold = posThreshold;
        return;
    }

    MATHEMATICS_ASSERTION_0(false, "正阈值必须是非负的。");
}

template <typename Real>
Real Mathematics::StaticTestIntersectorLine3Ellipsoid3<Real>::GetPositiveThreshold() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return positiveThreshold;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_ELLIPSOID3_DETAIL_H