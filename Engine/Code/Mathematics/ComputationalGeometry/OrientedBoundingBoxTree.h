/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 19:51)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_H

#include "Mathematics/MathematicsDll.h"

#include "OrientedBoundingBoxNode.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector3.h"

/// OrientedBoundingBoxTree是一个抽象类，用于计算基元集合的定向边界盒树。
/// 派生类为OrientedBoundingBoxTreeOfPoints（点基元）、
/// OrientedBoundingBoxTreeOfSegments（线段基元）和OrientedBoundingBoxTreeOfTriangles（三角形基元）。
/// 派生类为每个树节点创建一个框。
/// 长方体中心是节点表示的基本体的质心的平均值。
/// 盒轴方向是这些质心的协方差矩阵的特征向量。计算长方体范围以确保长方体包含由节点表示的基本体。
///
/// 非空树中节点的深度是节点到树根的距离。
/// 高度是最大深度。具有单个节点的树的高度为0。
/// 具有相同深度的树的节点集被称为与该深度相对应的树的级别。
/// 高度为H的完全二叉树具有2^{H+1}-1个节点。
/// 与深度D对应的级别具有2^D个节点，
/// 在这种情况下，叶节点（深度H处的节点）的数量为2^H。
/// 在节点的左右子节点之间划分基元是基于基元的质心在由对应于协方差矩阵的最大特征值的特征向量确定的线上的投影。
/// 选择投影的中值以将基元划分为大小相等或绝对大小差为1的两个子集。
/// 这导致了一个平衡的树，这有助于树遍历的性能。
namespace Mathematics
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class OrientedBoundingBoxTree
    {
    public:
        using ClassType = OrientedBoundingBoxTree<Real>;

        using Vector3 = Algebra::Vector3<Real>;
        using Vector3Container = std::vector<Vector3>;
        using OrientedBoundingBoxNodeType = OrientedBoundingBoxNode<Real>;
        using NodeContainer = std::vector<OrientedBoundingBoxNodeType>;
        using PartitionContainer = std::vector<int>;

    public:
        OrientedBoundingBoxTree() noexcept;
        virtual ~OrientedBoundingBoxTree() noexcept = default;
        OrientedBoundingBoxTree(const OrientedBoundingBoxTree& rhs) = default;
        OrientedBoundingBoxTree& operator=(const OrientedBoundingBoxTree& rhs) = default;
        OrientedBoundingBoxTree(OrientedBoundingBoxTree&& rhs) = default;
        OrientedBoundingBoxTree& operator=(OrientedBoundingBoxTree&& rhs) = default;

        CLASS_INVARIANT_DECLARE;

        /// 输入高度指定树的所需高度，并且不得大于31。
        /// 如果std::numeric_limits<int>::max()，
        /// 则构建整个树，并根据centroids.size()计算实际高度。
        /// 如果大于31，则高度被夹紧为31。
        virtual void Create(const Vector3Container& aCentroids, int aHeight);

        /// 成员访问
        NODISCARD Vector3Container GetCentroids() const;
        NODISCARD Vector3 GetCentroids(int index) const;
        NODISCARD int GetHeight() const noexcept;
        NODISCARD NodeContainer GetNodes() const;
        NODISCARD PartitionContainer GetPartition() const;
        NODISCARD int GetPartition(int index) const;

    protected:
        using OrientedBox3 = Algebra::OrientedBox3<Real>;

    protected:
        /// 派生类必须重写ComputeInteriorBox，首先调用基类函数。
        /// 然后，它们必须计算长方体范围，以确保长方体包含由节点表示的基本体。
        virtual void ComputeInteriorBox(int i0, int i1, OrientedBox3& box);

        /// 派生类必须重写ComputeLeafBox。
        /// 内部长方体尺寸取决于几何图元。
        virtual void ComputeLeafBox(int i, OrientedBox3& box) = 0;

    private:
        void BuildTree(int depth, int nodeIndex, int i0, int i1);

        void SplitPoints(int i0,
                         int i1,
                         const Vector3& origin,
                         const Vector3& direction,
                         int& j0,
                         int& j1);

    private:
        Vector3Container centroids;
        int height;
        NodeContainer nodes;
        PartitionContainer partition;
    };
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_H
