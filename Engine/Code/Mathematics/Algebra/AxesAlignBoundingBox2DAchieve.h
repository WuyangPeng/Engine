///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:00)

// 轴对齐包围盒2D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_ACHIEVE_H

#include "AxesAlignBoundingBox2D.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::AxesAlignBoundingBox2D<Real>::AxesAlignBoundingBox2D(const Vector2D& minPoint, const Vector2D& maxPoint)
    : m_MinPoint{ minPoint }, m_MaxPoint{ maxPoint }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::AxesAlignBoundingBox2D<Real>::AxesAlignBoundingBox2D(Real xMin, Real xMax, Real yMin, Real yMax)
    : m_MinPoint{ xMin, yMin }, m_MaxPoint{ xMax, yMax }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::AxesAlignBoundingBox2D<Real>::Recalculate()
{
    for (auto i = 0; i < Vector2D::sm_PointSize; ++i)
    {
        if (m_MaxPoint[i] < m_MinPoint[i])
        {
            MATHEMATICS_ASSERTION_1(false, "输入的最大点和最小点坐标错误！i = %d", i);

            std::swap(m_MinPoint[i], m_MaxPoint[i]);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::AxesAlignBoundingBox2D<Real>::IsValid() const noexcept
{
    if (m_MaxPoint.GetX() < m_MinPoint.GetX() || m_MaxPoint.GetY() < m_MinPoint.GetY())
        return false;
    else
        return true;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::AxesAlignBoundingBox2D<Real>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinPoint;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::AxesAlignBoundingBox2D<Real>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxPoint;
}

template <typename Real>
typename const Mathematics::AxesAlignBoundingBox2D<Real>::Vector2D Mathematics::AxesAlignBoundingBox2D<Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    Vector2D center{ (m_MinPoint.GetX() + m_MaxPoint.GetX()) / Math::GetValue(2),
                     (m_MinPoint.GetY() + m_MaxPoint.GetY()) / Math::GetValue(2) };

    return center;
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2D<Real>::GetExtentX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (m_MaxPoint.GetX() - m_MinPoint.GetX()) / Math::GetValue(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox2D<Real>::GetExtentY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (m_MaxPoint.GetY() - m_MinPoint.GetY()) / Math::GetValue(2);
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_2D_ACHIEVE_H