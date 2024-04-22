/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 19:54)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_OF_POINTS_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_OF_POINTS_H

#include "Mathematics/MathematicsDll.h"

#include "OrientedBoundingBoxTree.h"

namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class OrientedBoundingBoxTreeOfPoints : public OrientedBoundingBoxTree<Real>
    {
    public:
        using ClassType = OrientedBoundingBoxTreeOfPoints<Real>;
        using ParentType = OrientedBoundingBoxTree<Real>;

        using OrientedBox3 = Algebra::OrientedBox3<Real>;
        using Vector3 = Algebra::Vector3<Real>;
        using Vector3Container = std::vector<Vector3>;
        using Math = Math<Real>;

    public:
        OrientedBoundingBoxTreeOfPoints() noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 输入高度指定树的所需高度，并且不得大于31。
        /// 如果std::numeric_limits<size_t>::max()，则构建整个树，并根据centroids.size()计算实际高度。
        /// 如果大于31，则高度被夹紧为31。
        void Create(const Vector3Container& points, int height = std::numeric_limits<int>::max()) override;

        /// 成员访问。
        NODISCARD Vector3Container GetPoints() const;

    private:
        /// 设C为箱中心，设U0、U1和U2为箱轴。
        /// 每个输入点的形式为X = C + y0*U0 + y1*U1 + y2*U2。
        /// 以下代码计算min(y0), max(y0), min(y1), max(y1)然后将箱子中心调整为
        //   C' = C + 0.5*(min(y0)+max(y0))*U0 + 0.5*(min(y1)+max(y1))*U1
        //        + 0.5*(min(y2)+max(y2))*U2
        void ComputeInteriorBox(int i0, int i1, OrientedBox3& box) override;

        void ComputeLeafBox(int i, OrientedBox3& box) override;
    };
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_OF_POINTS_H
