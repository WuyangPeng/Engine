///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:17)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_ACHIEVE_H

#include "AxesAlignBoundingBox2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AxesAlignBoundingBox2<Real>::AxesAlignBoundingBox2(const Vector2Type& minPoint, const Vector2Type& maxPoint) noexcept
    : minPoint{ minPoint }, maxPoint{ maxPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AxesAlignBoundingBox2<Real>::AxesAlignBoundingBox2(Real xMin, Real xMax, Real yMin, Real yMax) noexcept
    : minPoint{ xMin, yMin }, maxPoint{ xMax, yMax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AxesAlignBoundingBox2<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AxesAlignBoundingBox2<Real>::IsBoxValid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (maxPoint.GetX() < minPoint.GetX() || maxPoint.GetY() < minPoint.GetY())
        return false;
    else
        return true;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::AxesAlignBoundingBox2<Real>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector2<Real> Mathematics::AxesAlignBoundingBox2<Real>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMinPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMaxPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMinPoint(PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetMaxPoint(PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AxesAlignBoundingBox2<Real>::Vector2Type Mathematics::AxesAlignBoundingBox2<Real>::GetCenter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint + minPoint) / MathType::GetValue(2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetExtentX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint.GetX() - minPoint.GetX()) / MathType::GetValue(2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox2<Real>::GetExtentY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint.GetY() - minPoint.GetY()) / MathType::GetValue(2);
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX2_ACHIEVE_H