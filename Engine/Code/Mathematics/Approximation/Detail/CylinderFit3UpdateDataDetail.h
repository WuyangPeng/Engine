///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 14:07)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_DETAIL_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_DETAIL_H

#include "CylinderFit3UpdateData.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::CylinderFit3UpdateData<Real>::CylinderFit3UpdateData(const Vector3Type& point, const Vector3Type& center, const Vector3Type& axis)
    : point{ point },
      delta{ point - center },
      deltaCrossAxis{ Vector3Tools<Real>::CrossProduct(delta, axis) },
      deltaCrossAxisLengthQuartic{ Vector3Tools<Real>::GetLengthSquared(deltaCrossAxis) },
      descentDirection{ CalculateDescentDirection(delta, axis) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
typename Mathematics::CylinderFit3UpdateData<Real>::Vector3Type Mathematics::CylinderFit3UpdateData<Real>::CalculateDescentDirection(const Vector3Type& delta, const Vector3Type& axis) noexcept
{
    return Vector3Type{ axis.GetX() * (delta.GetY() * delta.GetY() + delta.GetZ() * delta.GetZ()) - delta.GetX() * (axis.GetY() * delta.GetY() + axis.GetZ() * delta.GetZ()),
                    axis.GetY() * (delta.GetX() * delta.GetX() + delta.GetZ() * delta.GetZ()) - delta.GetY() * (axis.GetX() * delta.GetX() + axis.GetZ() * delta.GetZ()),
                    axis.GetZ() * (delta.GetX() * delta.GetX() + delta.GetY() * delta.GetY()) - delta.GetZ() * (axis.GetX() * delta.GetX() + axis.GetY() * delta.GetY()) };
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::CylinderFit3UpdateData<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::CylinderFit3UpdateData<Real>::Vector3Type Mathematics::CylinderFit3UpdateData<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return point;
}

template <typename Real>
typename Mathematics::CylinderFit3UpdateData<Real>::Vector3Type Mathematics::CylinderFit3UpdateData<Real>::GetDelta() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return delta;
}

template <typename Real>
typename Mathematics::CylinderFit3UpdateData<Real>::Vector3Type Mathematics::CylinderFit3UpdateData<Real>::GetDeltaCrossAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return deltaCrossAxis;
}

template <typename Real>
Real Mathematics::CylinderFit3UpdateData<Real>::GetDeltaCrossAxisLengthQuartic() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return deltaCrossAxisLengthQuartic;
}

template <typename Real>
typename Mathematics::CylinderFit3UpdateData<Real>::Vector3Type Mathematics::CylinderFit3UpdateData<Real>::GetDescentDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return descentDirection;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_DETAIL_H
