///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 10:50)

// 轴对齐包围盒4D类的实现
#ifndef MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_ACHIEVE_H
#define MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_ACHIEVE_H

#include "AxesAlignBoundingBox4D.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::AxesAlignBoundingBox4D<T>::AxesAlignBoundingBox4D(const Vector4D& minPoint, const Vector4D& maxPoint)
    : m_MinPoint{ minPoint }, m_MaxPoint{ maxPoint }
{
    Recalculate();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename T>
void Mathematics::AxesAlignBoundingBox4D<T>::Recalculate()
{
    for (auto i = 0; i < Vector4D::sm_PointSize; ++i)
    {
        if (m_MaxPoint[i] < m_MinPoint[i])
        {
            MATHEMATICS_ASSERTION_1(false, "输入的最大点和最小点坐标错误！i = %d", i);

            std::swap(m_MinPoint[i], m_MaxPoint[i]);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::AxesAlignBoundingBox4D<T>::IsValid() const noexcept
{
    if (m_MaxPoint.GetX() < m_MinPoint.GetX() ||
        m_MaxPoint.GetY() < m_MinPoint.GetY() ||
        m_MaxPoint.GetZ() < m_MinPoint.GetZ() ||
        m_MaxPoint.GetW() < m_MinPoint.GetW())
    {
        return false;
    }
    else
    {
        return true;
    }
}
#endif  // OPEN_CLASS_INVARIANT

template <typename T>
const Mathematics::Vector4D<T> Mathematics::AxesAlignBoundingBox4D<T>::GetMinPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MinPoint;
}

template <typename T>
const Mathematics::Vector4D<T> Mathematics::AxesAlignBoundingBox4D<T>::GetMaxPoint() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_MaxPoint;
}

#endif  // MATHEMATICS_ALGEBRA_AXES_ALIGN_BOUNDING_BOX_4D_ACHIEVE_H