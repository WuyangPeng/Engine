///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/02 16:17)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_DETAIL_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_DETAIL_H

#include "CylinderFit3UpdateData.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::CylinderFit3UpdateData<Real>::CylinderFit3UpdateData(const Vector3D& point, const Vector3D& center, const Vector3D& axis)
    : m_Point{ point },
      m_Delta{ point - center },
      m_DeltaCrossAxis{ Vector3DTools<Real>::CrossProduct(m_Delta, axis) },
      m_DeltaCrossAxisLengthQuartic{ Vector3DTools<Real>::VectorMagnitudeSquared(m_DeltaCrossAxis) },
      m_DescentDirection{ CalculateDescentDirection(m_Delta, axis) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// static
// private
template <typename Real>
typename const Mathematics::CylinderFit3UpdateData<Real>::Vector3D Mathematics::CylinderFit3UpdateData<Real>::CalculateDescentDirection(const Vector3D& delta, const Vector3D& axis) noexcept
{
    return Vector3D{ axis.GetX() * (delta.GetY() * delta.GetY() + delta.GetZ() * delta.GetZ()) - delta.GetX() * (axis.GetY() * delta.GetY() + axis.GetZ() * delta.GetZ()),
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
typename const Mathematics::CylinderFit3UpdateData<Real>::Vector3D Mathematics::CylinderFit3UpdateData<Real>::GetPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Point;
}

template <typename Real>
typename const Mathematics::CylinderFit3UpdateData<Real>::Vector3D Mathematics::CylinderFit3UpdateData<Real>::GetDelta() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_Delta;
}

template <typename Real>
typename const Mathematics::CylinderFit3UpdateData<Real>::Vector3D Mathematics::CylinderFit3UpdateData<Real>::GetDeltaCrossAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DeltaCrossAxis;
}

template <typename Real>
Real Mathematics::CylinderFit3UpdateData<Real>::GetDeltaCrossAxisLengthQuartic() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DeltaCrossAxisLengthQuartic;
}

template <typename Real>
typename const Mathematics::CylinderFit3UpdateData<Real>::Vector3D Mathematics::CylinderFit3UpdateData<Real>::GetDescentDirection() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return m_DescentDirection;
}

#endif  // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_UPDATE_DATA_DETAIL_H
