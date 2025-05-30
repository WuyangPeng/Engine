///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 18:02)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_DETAIL_H

#include "TriangleProjectOntoAxis.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::TriangleProjectOntoAxis<Real>::TriangleProjectOntoAxis(const Triangle3Type& triangle, const Vector3Type& axis)
    : min{}, max{}
{
    Project(triangle, axis);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::TriangleProjectOntoAxis<Real>::Project(const Triangle3Type& triangle, const Vector3Type& axis)
{
    using Container = std::vector<Real>;

    Container dot{ Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(0)),
                   Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(1)),
                   Vector3Tools<Real>::DotProduct(axis, triangle.GetVertex(2)) };

    const auto minmaxElement = minmax_element(dot.begin(), dot.end());

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