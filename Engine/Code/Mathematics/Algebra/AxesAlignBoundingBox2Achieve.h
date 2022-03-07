///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/02 22:18)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_ACHIEVE_H

#include "AxesAlignBoundingBox2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::AxesAlignBoundingBox2<Real>::AxesAlignBoundingBox2(const Vector2& minPoint, const Vector2& maxPoint) noexcept
    : minPoint{ minPoint }, maxPoint{ maxPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::AxesAlignBoundingBox2<Real>::AxesAlignBoundingBox2(Real xMin, Real xMax, Real yMin, Real yMax) noexcept
    : minPoint{ xMin, yMin }, maxPoint{ xMax, yMax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::AxesAlignBoundingBox2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::AxesAlignBoundingBox2<Real>::IsBoxValid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (maxPoint.GetX() < minPoint.GetX() || maxPoint.GetY() < minPoint.GetY())
        return false;
    else
        return true;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::AxesAlignBoundingBox2<Real>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint;
}

template <typename Real>
Mathematics::Vector2<Real> Mathematics::AxesAlignBoundingBox2<Real>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint;
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMinPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint[index];
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMaxPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint[index];
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMinPoint(PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint[index];
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMaxPoint(PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint[index];
}

template <typename Real>
typename Mathematics::AxesAlignBoundingBox2<Real>::Vector2 Mathematics::AxesAlignBoundingBox2<Real>::GetCenter() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint + minPoint) / Math::GetValue(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetExtentX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint.GetX() - minPoint.GetX()) / Math::GetValue(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetExtentY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint.GetY() - minPoint.GetY()) / Math::GetValue(2);
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_ACHIEVE_H