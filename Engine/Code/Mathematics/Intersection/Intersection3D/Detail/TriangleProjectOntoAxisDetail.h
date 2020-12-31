///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/24 17:14)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H

#include "TriangleProjectOntoAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"

template <typename Real>
Mathematics::TriangleProjectOntoAxis<Real>::TriangleProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis)
    : m_Min{}, m_Max{}
{
    Project(triangle, axis);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::TriangleProjectOntoAxis<Real>::Project(const Triangle3& triangle, const Vector3D& axis)
{
    using Container = std::vector<Real>;

    Container dot{ Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(0)),
                   Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(1)),
                   Vector3DTools<Real>::DotProduct(axis, triangle.GetVertex(2)) };

    auto minmaxElement = minmax_element(dot.begin(), dot.end());

    m_Min = *minmaxElement.first;
    m_Max = *minmaxElement.second;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::TriangleProjectOntoAxis<Real>::IsValid() const noexcept
{
    if (m_Min <= m_Max)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::TriangleProjectOntoAxis<Real>::GetMin() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Min;
}

template <typename Real>
Real Mathematics::TriangleProjectOntoAxis<Real>::GetMax() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Max;
}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H