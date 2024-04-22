/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 13:36)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_EXTRACT_ELLIPSES_DETAIL_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_EXTRACT_ELLIPSES_DETAIL_H

#include "ApproximationCone3ExtractEllipses.h"
#include "ApproximationEllipse2.h"
#include "ApproximationGaussian3.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/ComputationalGeometry/OrientedBoundingBoxTreeOfPoints.h"
#include "Mathematics/Objects2D/Ellipse2.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::ApproximationCone3ExtractEllipses<Real>::ApproximationCone3ExtractEllipses() noexcept
    : boxExtentEpsilon{},
      cosAngleEpsilon{},
      orientedBoundingBoxTree{},
      planes{},
      indices{},
      boxes{},
      ellipses{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::ApproximationCone3ExtractEllipses<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3ExtractEllipses<Real>::Extract(const Vector3Container& points, Real aBoxExtentEpsilon, Real aCosAngleEpsilon, const Ellipse3Container& aEllipses)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    boxExtentEpsilon = std::max(aBoxExtentEpsilon, Real{});
    cosAngleEpsilon = std::max(aCosAngleEpsilon, Real{});
    orientedBoundingBoxTree.clear();
    planes.clear();
    indices.clear();
    boxes.clear();
    ellipses.clear();

    CreateOrientedBoundingBoxTree(points);
    LocatePlanes(0);
    AssociatePointsWithPlanes(points);

    for (auto element : indices)
    {
        ellipses.emplace_back(ComputeEllipse(points, element));
    }

    ellipses = aEllipses;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3ExtractEllipses<Real>::Ellipse3Container Mathematics::ApproximationCone3ExtractEllipses<Real>::GetEllipses() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ellipses;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3ExtractEllipses<Real>::OrientedBoundingBoxNodeContainer Mathematics::ApproximationCone3ExtractEllipses<Real>::GetOrientedBoundingBoxTree() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return orientedBoundingBoxTree;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3ExtractEllipses<Real>::Plane3Container Mathematics::ApproximationCone3ExtractEllipses<Real>::GetPlanes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return planes;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3ExtractEllipses<Real>::IndicesContainer Mathematics::ApproximationCone3ExtractEllipses<Real>::GetIndices() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return indices;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3ExtractEllipses<Real>::OrientedBox3Container Mathematics::ApproximationCone3ExtractEllipses<Real>::GetBoxes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return boxes;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3ExtractEllipses<Real>::CreateOrientedBoundingBoxTree(const Vector3Container& points)
{
    OrientedBoundingBoxTreeOfPoints<Real> creator{};
    creator.Create(points);
    orientedBoundingBoxTree = creator.GetNodes();
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3ExtractEllipses<Real>::LocatePlanes(int nodeIndex)
{
    const auto& node = orientedBoundingBoxTree.at(nodeIndex);
    if (node.GetMaxIndex() >= node.GetMinIndex() + 2)
    {
        for (auto j = 0; j < 3; ++j)
        {
            if (node.GetBox().GetExtent(j) <= boxExtentEpsilon)
            {
                boxes.emplace_back(node.GetBox());
                const Plane3 plane{ node.GetBox().GetAxis(j), node.GetBox().GetCenter() };
                ProcessPlane(plane);
                return;
            }
        }
    }

    if (node.GetLeftChild() != std::numeric_limits<int>::max())
    {
        LocatePlanes(node.GetLeftChild());
    }

    if (node.GetRightChild() != std::numeric_limits<int>::max())
    {
        LocatePlanes(node.GetRightChild());
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3ExtractEllipses<Real>::ProcessPlane(const Plane3& plane)
{
    const auto epsilon = cosAngleEpsilon;
    const auto oneMinusEpsilon = Math::GetValue(1) - epsilon;

    for (auto i = 0u; i < planes.size(); ++i)
    {
        auto cosAngle = Dot(plane.GetNormal(), planes.at(i).GetNormal());

        if (cosAngle > Real{})
        {
            const auto absDiff = std::fabs(plane.GetConstant() - planes.at(i).GetConstant());
            if (cosAngle >= oneMinusEpsilon && absDiff <= epsilon)
            {
                /// 这些平面实际上是相同的。
                return;
            }
        }
        else
        {
            cosAngle = -cosAngle;
            const auto absDiff = std::fabs(plane.GetConstant() + planes.at(i).GetConstant());
            if (cosAngle >= oneMinusEpsilon && absDiff <= epsilon)
            {
                /// 这些平面实际上是相同的。
                return;
            }
        }
    }

    planes.emplace_back(plane);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::ApproximationCone3ExtractEllipses<Real>::AssociatePointsWithPlanes(const Vector3Container& points)
{
    indices.resize(planes.size());
    for (auto i = 0u; i < points.size(); ++i)
    {
        const auto& point = points.at(i);
        auto minDistance = std::numeric_limits<Real>::max();
        auto minJ = std::numeric_limits<int>::max();
        for (auto j = 0; j < boost::numeric_cast<int>(planes.size()); ++j)
        {
            const auto& plane = planes.at(j);
            const auto diff = point - plane.GetOrigin();
            const auto distance = std::fabs(Dot(plane.GetNormal(), diff));
            if (distance < minDistance)
            {
                minDistance = distance;
                minJ = j;
            }
        }

        indices.at(minJ).emplace_back(i);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::ApproximationCone3ExtractEllipses<Real>::Ellipse3 Mathematics::ApproximationCone3ExtractEllipses<Real>::ComputeEllipse(const Vector3Container& points, const IndicesType& aIndices)
{
    /// 使用三维高斯分布拟合点。
    /// 特征值是按非递减顺序计算的，这意味着最小的特征值对应于点平面的法向量gBox.axis[0]。
    /// 使用gBox.axis[1]和gBox.aaxis[2]作为点平面的扳手。
    ApproximationGaussian3<Real> gFitter{};
    std::ignore = gFitter.FitIndexed(points, aIndices);
    const auto& gBox = gFitter.GetParameters();

    /// 将点作为2元组投影到平面上。
    std::vector<Algebra::Vector2<Real>> projections(aIndices.size());
    for (auto i = 0u; i < aIndices.size(); ++i)
    {
        const auto diff = points.at(aIndices.at(i)) - gBox.GetCenter();
        projections.at(i)[0] = Dot(gBox.GetAxis(1), diff);
        projections.at(i)[1] = Dot(gBox.GetAxis(2), diff);
    }

    /// 使用二维椭圆拟合投影点。
    ApproximationEllipse2<Real> eFitter{};
    constexpr auto numIterations = 1024;
    constexpr auto useEllipseForInitialGuess = false;
    Algebra::Ellipse2<Real> ellipse2{};
    std::ignore = eFitter(projections, numIterations, useEllipseForInitialGuess, ellipse2);

    /// 将二维椭圆提升为三维椭圆。
    Ellipse3 ellipse3{};
    ellipse3.SetCenter(gBox.GetCenter() + ellipse2.GetCenter()[0] * gBox.GetAxis(1) + ellipse2.GetCenter()[1] * gBox.GetAxis(2));
    ellipse3.SetNormal(gBox.GetAxis(0));
    ellipse3.SetAxis(0, ellipse2.GetAxis(0)[0] * gBox.GetAxis(1) + ellipse2.GetAxis(0)[1] * gBox.GetAxis(2));
    ellipse3.SetAxis(1, ellipse2.GetAxis(1)[0] * gBox.GetAxis(1) + ellipse2.GetAxis(1)[1] * gBox.GetAxis(2));
    ellipse3.SetExtent(ellipse2.GetExtent());
    return ellipse3;
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_EXTRACT_ELLIPSES_DETAIL_H
