///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 19:31)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_DETAIL_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_DETAIL_H

#include "TrianglePlaneRelations.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"

template <typename Real>
Mathematics::TrianglePlaneRelations<Real>::TrianglePlaneRelations(const Triangle3& triangle, const Plane3& plane, const Real epsilon)
    : distance{}, sign{}, positive{ 0 }, negative{ 0 }, zero{ 0 }
{
    Relations(triangle, plane, epsilon);

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::TrianglePlaneRelations<Real>::Relations(const Triangle3& triangle, const Plane3& plane, const Real epsilon)
{
    // 计算三角形顶点到平面的带符号距离。 使用epsilon平面测试。

    for (auto i = 0; i < size; ++i)
    {
        distance.at(i) = plane.DistanceTo(triangle.GetVertex(i));

        if (epsilon < distance.at(i))
        {
            sign.at(i) = NumericalValueSymbol::Positive;
            ++positive;
        }
        else if (distance.at(i) < -epsilon)
        {
            sign.at(i) = NumericalValueSymbol::Negative;
            ++negative;
        }
        else
        {
            distance.at(i) = Math::GetValue(0);
            sign.at(i) = NumericalValueSymbol::Zero;
            ++zero;
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::TrianglePlaneRelations<Real>::IsValid() const noexcept
{
    if (0 <= positive && 0 <= negative && 0 <= zero)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::TrianglePlaneRelations<Real>::GetDistance(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return distance.at(index);
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::TrianglePlaneRelations<Real>::GetSign(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return sign.at(index);
}

template <typename Real>
int Mathematics::TrianglePlaneRelations<Real>::GetPositive() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return positive;
}

template <typename Real>
int Mathematics::TrianglePlaneRelations<Real>::GetNegative() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return negative;
}

template <typename Real>
int Mathematics::TrianglePlaneRelations<Real>::GetZero() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return zero;
}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PLANE_RELATIONS_DETAIL_H