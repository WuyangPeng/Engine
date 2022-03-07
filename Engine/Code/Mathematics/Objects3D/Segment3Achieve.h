///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/10 14:55)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_ACHIEVE_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_ACHIEVE_H

#include "Segment3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::Segment3<Real>::Segment3(const Vector3& beginPoint, const Vector3& endPoint, const Real epsilon)
    : beginPoint{ beginPoint },
      endPoint{ endPoint },
      center{ Math::GetRational(1, 2) * (beginPoint + endPoint) },
      direction{ endPoint - beginPoint },
      extent{ Vector3Tools::GetLength(direction) / Math::GetValue(2) },
      epsilon{ epsilon }
{
    direction.Normalize(epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Segment3<Real>::Segment3(Real extent, const Vector3& center, const Vector3& direction, const Real epsilon)
    : beginPoint{ center - extent * direction },
      endPoint{ center + extent * direction },
      center{ center },
      direction{ direction },
      extent{ extent },
      epsilon{ epsilon }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::Segment3<Real>::IsValid() const noexcept
{
    try
    {
        if (direction.IsNormalize(epsilon) &&
            Vector3Tools::Approximate(beginPoint, center - extent * direction, epsilon) &&
            Vector3Tools::Approximate(endPoint, center + extent * direction, epsilon) &&
            Vector3Tools::Approximate(center, Math::GetRational(1, 2) * (beginPoint + endPoint), epsilon))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Segment3<Real>::GetBeginPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return beginPoint;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Segment3<Real>::GetEndPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return endPoint;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Segment3<Real>::GetCenterPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return center;
}

template <typename Real>
Mathematics::Vector3<Real> Mathematics::Segment3<Real>::GetDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return direction;
}

template <typename Real>
Real Mathematics::Segment3<Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return extent;
}

// private
template <typename Real>
void Mathematics::Segment3<Real>::ComputeCenterDirectionExtent()
{
    center = Math::GetRational(1, 2) * (beginPoint + endPoint);
    direction = endPoint - beginPoint;
    extent = Vector3Tools::GetLength(direction) / Math::GetValue(2);

    direction.Normalize(epsilon);
}

// private
template <typename Real>
void Mathematics::Segment3<Real>::ComputeEndPoints()
{
    beginPoint = center - extent * direction;
    endPoint = center + extent * direction;
}

template <typename Real>
Mathematics::Segment3<Real> Mathematics::Segment3<Real>::GetMove(Real t, const Vector3& velocity) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return Segment3{ extent, center + t * velocity, direction, epsilon };
}

#endif  // MATHEMATICS_OBJECTS3D_SEGMENT3_ACHIEVE_H
