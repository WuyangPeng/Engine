///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/05 13:34)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H

#include "TriangleProjectOntoAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::TriangleProjectOntoAxis<Real>::TriangleProjectOntoAxis(const Triangle3& triangle, const Vector3& axis)
    : min{}, max{}
{
    Project(triangle, axis);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::TriangleProjectOntoAxis<Real>::Project(const Triangle3& triangle, const Vector3& axis)
{
    using Container = std::vector<Real>;

    Container dot{ Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(0)),
                   Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(1)),
                   Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(2)) };

    auto minmaxElement = minmax_element(dot.begin(), dot.end());

    min = *minmaxElement.first;
    max = *minmaxElement.second;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TriangleProjectOntoAxis<Real>::IsValid() const noexcept
{
    if (min <= max)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::TriangleProjectOntoAxis<Real>::GetMin() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return min;
}

template <typename Real>
Real Mathematics::TriangleProjectOntoAxis<Real>::GetMax() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return max;
}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H