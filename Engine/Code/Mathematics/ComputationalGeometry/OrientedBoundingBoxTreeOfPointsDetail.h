/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 19:54)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_OF_POINTS_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_OF_POINTS_DETAIL_H

#include "OrientedBoundingBoxTreeOfPoints.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::OrientedBoundingBoxTreeOfPoints() noexcept
    : ParentType{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::Create(const Vector3Container& points, int height)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 为质心创建OBB树。这些点已经是质心。
    ParentType::Create(points, height);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::Vector3Container Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::GetPoints() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return this->GetCentroids();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::ComputeInteriorBox(int i0, int i1, OrientedBox3& box)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ParentType::ComputeInteriorBox(i0, i1, box);

    Vector3 pMin{};
    auto pMax = pMin;
    for (auto i = i0; i <= i1; ++i)
    {
        const auto diff = this->GetCentroids(this->GetPartition(i)) - box.GetCenter();
        for (auto j = 0; j < 3; ++j)
        {
            auto dot = Dot(diff, box.GetAxis(j));
            if (dot < pMin[j])
            {
                pMin[j] = dot;
            }
            else if (dot > pMax[j])
            {
                pMax[j] = dot;
            }
        }
    }

    for (auto j = 0; j < 3; ++j)
    {
        box.SetCenter(box.GetCenter() + Math::GetRational(1, 2) * (pMin[j] + pMax[j]) * box.GetAxis(j));
        box.SetExtent(j, Math::GetRational(1, 2) * (pMax[j] - pMin[j]));
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTreeOfPoints<Real>::ComputeLeafBox(int i, OrientedBox3& box)
{
    /// 创建一个以点基本体为中心的退化长方体。
    box.SetCenter(this->GetCentroids(this->GetPartition(i)));
    box.SetAxis(0, Vector3::GetUnit(0));
    box.SetAxis(1, Vector3::GetUnit(1));
    box.SetAxis(2, Vector3::GetUnit(2));
    box.SetExtent(Vector3::GetZero());
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_OF_POINTS_DETAIL_H
