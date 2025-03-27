/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/09 13:36)

#ifndef MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_EXTRACT_ELLIPSES_H
#define MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_EXTRACT_ELLIPSES_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/ComputationalGeometry/OrientedBoundingBoxNode.h"
#include "Mathematics/Objects3D/Algebra/Ellipse3.h"
#include "Mathematics/Primitives/Hyperplane.h"

namespace Mathematics
{
    /// 如果这些点仅包含平面与圆锥体相交的椭圆横截面，请提取椭圆，
    /// 以便其中一个可以用作ApproximationCone3EllipseAndPoints的输入。
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class ApproximationCone3ExtractEllipses
    {
    public:
        using ClassType = ApproximationCone3ExtractEllipses<Real>;

        using MathType = Math<Real>;
        using Vector3 = Algebra::Vector3<Real>;
        using Vector3Container = std::vector<Vector3>;
        using Ellipse3 = Algebra::Ellipse3<Real>;
        using Ellipse3Container = std::vector<Ellipse3>;
        using OrientedBoundingBoxNode = OrientedBoundingBoxNode<Real>;
        using OrientedBoundingBoxNodeContainer = std::vector<OrientedBoundingBoxNode>;
        using Plane3 = Algebra::Plane3<Real>;
        using Plane3Container = std::vector<Plane3>;
        using IndicesType = std::vector<int>;
        using IndicesContainer = std::vector<IndicesType>;
        using OrientedBox3 = Algebra::OrientedBox3<Real>;
        using OrientedBox3Container = std::vector<OrientedBox3>;

    public:
        ApproximationCone3ExtractEllipses() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// boxExtentEpsilon确定一个长方体何时被视为“平面”。
        /// cosAngleEpsilon用于确定两个平面长方体何时在同一平面上。
        void Extract(const Vector3Container& points,
                     Real aBoxExtentEpsilon,
                     Real aCosAngleEpsilon,
                     const Ellipse3Container& aEllipses);

        /// 访问从输入点提取的椭圆。
        NODISCARD Ellipse3Container GetEllipses() const;

        /// 访问者用于提供信息。
        NODISCARD OrientedBoundingBoxNodeContainer GetOrientedBoundingBoxTree() const;

        NODISCARD Plane3Container GetPlanes() const;

        NODISCARD IndicesContainer GetIndices() const;

        NODISCARD OrientedBox3Container GetBoxes() const;

    private:
        void CreateOrientedBoundingBoxTree(const Vector3Container& points);

        void LocatePlanes(int nodeIndex);

        void ProcessPlane(const Plane3& plane);

        void AssociatePointsWithPlanes(const Vector3Container& points);

        NODISCARD Ellipse3 ComputeEllipse(const Vector3Container& points, const IndicesType& aIndices);

    private:
        Real boxExtentEpsilon;
        Real cosAngleEpsilon;
        OrientedBoundingBoxNodeContainer orientedBoundingBoxTree;
        Plane3Container planes;
        IndicesContainer indices;
        OrientedBox3Container boxes;
        Ellipse3Container ellipses;
    };
}

#endif  // MATHEMATICS_APPROXIMATION_APPROXIMATION_CONE3_EXTRACT_ELLIPSES_H
