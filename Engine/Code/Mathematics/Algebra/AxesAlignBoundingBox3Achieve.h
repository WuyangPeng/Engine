///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 10:19)

#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_ACHIEVE_H

#include "AxesAlignBoundingBox3.h"
#include "Vector3Detail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AxesAlignBoundingBox3<Real>::AxesAlignBoundingBox3(const Vector3& minPoint, const Vector3& maxPoint) noexcept
    : minPoint{ minPoint }, maxPoint{ maxPoint }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::AxesAlignBoundingBox3<Real>::AxesAlignBoundingBox3(Real xMin, Real xMax, Real yMin, Real yMax, Real zMin, Real zMax) noexcept
    : minPoint{ xMin, yMin, zMin }, maxPoint{ xMax, yMax, zMax }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AxesAlignBoundingBox3<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires std::is_arithmetic_v<Real> bool Mathematics::AxesAlignBoundingBox3<Real>::IsBoxValid() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (maxPoint.GetX() < minPoint.GetX() ||
        maxPoint.GetY() < minPoint.GetY() ||
        maxPoint.GetZ() < minPoint.GetZ())
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::AxesAlignBoundingBox3<Real>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Mathematics::Vector3<Real> Mathematics::AxesAlignBoundingBox3<Real>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint;
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetMinPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetMaxPoint(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetMinPoint(PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return minPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetMaxPoint(PointIndex index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return maxPoint[index];
}

template <typename Real>
requires std::is_arithmetic_v<Real>
typename Mathematics::AxesAlignBoundingBox3<Real>::Vector3 Mathematics::AxesAlignBoundingBox3<Real>::GetCenter() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return (maxPoint + minPoint) / Math::GetValue(2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetExtentX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (maxPoint.GetX() - minPoint.GetX()) / Math::GetValue(2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetExtentY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (maxPoint.GetY() - minPoint.GetY()) / Math::GetValue(2);
}

template <typename Real>
requires std::is_arithmetic_v<Real>
Real Mathematics::AxesAlignBoundingBox3<Real>::GetExtentZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (maxPoint.GetZ() - minPoint.GetZ()) / Math::GetValue(2);
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX3_ACHIEVE_H