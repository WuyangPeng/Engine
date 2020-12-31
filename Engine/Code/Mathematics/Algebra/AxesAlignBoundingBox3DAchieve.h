///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:46)

// 轴对齐包围盒3D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_ACHIEVE_H

#include "AxesAlignBoundingBox3D.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real>::AxesAlignBoundingBox3D(const Vector3D& minPoint, const Vector3D& maxPoint)
    : m_MinPoint{ minPoint }, m_MaxPoint{ maxPoint }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::AxesAlignBoundingBox3D<Real>::AxesAlignBoundingBox3D(Real xMin, Real xMax, Real yMin, Real yMax, Real zMin, Real zMax)
    : m_MinPoint{ xMin, yMin, zMin }, m_MaxPoint{ xMax, yMax, zMax }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::AxesAlignBoundingBox3D<Real>::Recalculate()
{
    for (auto i = 0; i < Vector3D::sm_PointSize; ++i)
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
bool Mathematics::AxesAlignBoundingBox3D<Real>::IsValid() const noexcept
{
    if (m_MaxPoint.GetX() < m_MinPoint.GetX() ||
        m_MaxPoint.GetY() < m_MinPoint.GetY() ||
        m_MaxPoint.GetZ() < m_MinPoint.GetZ())
    {
        return false;
    }
    else
    {
        return true;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::AxesAlignBoundingBox3D<Real>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinPoint;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::AxesAlignBoundingBox3D<Real>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxPoint;
}

template <typename Real>
typename const Mathematics::AxesAlignBoundingBox3D<Real>::Vector3D Mathematics::AxesAlignBoundingBox3D<Real>::GetCenter() const  
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (m_MaxPoint + m_MinPoint) / Math::GetValue(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox3D<Real>::GetExtentX() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (m_MaxPoint.GetX() - m_MinPoint.GetX()) / Math::GetValue(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox3D<Real>::GetExtentY() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (m_MaxPoint.GetY() - m_MinPoint.GetY()) / Math::GetValue(2);
}

template <typename Real>
Real Mathematics::AxesAlignBoundingBox3D<Real>::GetExtentZ() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return (m_MaxPoint.GetZ() - m_MinPoint.GetZ()) / Math::GetValue(2);
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_3D_ACHIEVE_H