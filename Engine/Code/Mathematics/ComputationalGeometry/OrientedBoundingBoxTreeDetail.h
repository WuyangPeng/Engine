/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/07 19:51)

#ifndef MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_DETAIL_H
#define MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_DETAIL_H

#include "OrientedBoundingBoxProjectionInfoDetail.h"
#include "OrientedBoundingBoxTree.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/BitHacksDetail.h"
#include "Mathematics/NumericalAnalysis/SymmetricEigensolver3x3Detail.h"

#include <numeric>

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::OrientedBoundingBoxTree<Real>::OrientedBoundingBoxTree() noexcept
    : centroids{},
      height{ 0 },
      nodes{},
      partition{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::OrientedBoundingBoxTree<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTree<Real>::Create(const std::vector<Vector3>& aCentroids, int aHeight)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    ASSERT_FAIL_THROW_EXCEPTION(!aCentroids.empty(), SYSTEM_TEXT("无效输入。"));

    centroids = aCentroids;

    if (aHeight == std::numeric_limits<int>::max())
    {
        const auto minPowerOfTwo = BitHacks::RoundUpToPowerOfTwo(boost::numeric_cast<uint32_t>(centroids.size()));
        const auto logMinPowerOfTwo = BitHacks::Log2OfPowerOfTwo(minPowerOfTwo);
        height = boost::numeric_cast<int>(logMinPowerOfTwo);
    }
    else
    {
        height = std::min(aHeight, 31);
    }

    /// 树是递归构建的。
    /// 对OrientedBoundingBoxNode的引用被传递到BuildTree，
    /// 节点被附加到std::vector。
    /// 因为引用在堆栈上，所以我们必须保证不会发生重新分配，以避免引用无效。
    const auto numNodes = (gsl::narrow_cast<size_t>(1) << (height + 1)) - 1;
    nodes.resize(numNodes);

    /// 数组分区将索引存储到质心中，以便在节点上，
    /// 节点表示的质心是索引[partition[node.minIndex], partition[node.maxIndex]]。
    partition.resize(centroids.size());
    std::iota(partition.begin(), partition.end(), 0);

    /// 递归地构建树。
    constexpr auto depth = 0;
    constexpr auto nodeIndex = 0;
    constexpr auto i0 = 0;
    const auto i1 = boost::numeric_cast<int>(centroids.size()) - 1;
    BuildTree(depth, nodeIndex, i0, i1);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::vector<typename Mathematics::OrientedBoundingBoxTree<Real>::Vector3> Mathematics::OrientedBoundingBoxTree<Real>::GetCentroids() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return centroids;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::OrientedBoundingBoxTree<Real>::Vector3 Mathematics::OrientedBoundingBoxTree<Real>::GetCentroids(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return centroids.at(index);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxTree<Real>::GetHeight() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return height;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::vector<typename Mathematics::OrientedBoundingBoxTree<Real>::OrientedBoundingBoxNodeType> Mathematics::OrientedBoundingBoxTree<Real>::GetNodes() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return nodes;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::vector<int> Mathematics::OrientedBoundingBoxTree<Real>::GetPartition() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return partition;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::OrientedBoundingBoxTree<Real>::GetPartition(int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return partition.at(index);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTree<Real>::ComputeInteriorBox(int i0, int i1, OrientedBox3& box)
{
    /// 计算质心的平均值。
    box.SetCenter(Vector3{});
    for (auto i = i0; i <= i1; ++i)
    {
        box.SetCenter(box.GetCenter() + centroids.at(partition.at(i)));
    }
    auto denominator = boost::numeric_cast<Real>(i1 - i0 + 1);
    box.SetCenter(box.GetCenter() / denominator);

    /// 计算质心的协方差矩阵。
    Real covar00{};
    Real covar01{};
    Real covar02{};
    Real covar11{};
    Real covar12{};
    Real covar22{};
    for (auto i = i0; i <= i1; ++i)
    {
        auto diff = centroids.at(partition.at(i)) - box.GetCenter();
        covar00 += diff[0] * diff[0];
        covar01 += diff[0] * diff[1];
        covar02 += diff[0] * diff[2];
        covar11 += diff[1] * diff[1];
        covar12 += diff[1] * diff[2];
        covar22 += diff[2] * diff[2];
    }
    covar00 /= denominator;
    covar01 /= denominator;
    covar02 /= denominator;
    covar11 /= denominator;
    covar12 /= denominator;
    covar22 /= denominator;

    /// 将协方差矩阵的特征向量用于长方体轴。
    const SymmetricEigensolver3x3<Real> es{};
    std::array<Real, 3> eval{};
    std::array<std::array<Real, 3>, 3> evec{};
    es(covar00, covar01, covar02, covar11, covar12, covar22, false, +1, eval, evec);
    for (auto i = 0; i < 3; ++i)
    {
        box.SetAxis(i, Vector3{ evec.at(i) });
    }

    /// box.extent值必须由派生类计算。为了进行调试，请将特征值存储在范围中。
    box.SetExtent(Vector3{ eval });
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTree<Real>::BuildTree(int depth, int nodeIndex, int i0, int i1)
{
    auto& node = nodes.at(nodeIndex);
    node.SetMinIndex(i0);
    node.SetMaxIndex(i1);

    if (i0 < i1)
    {
        /// 节点位于内部。计算质心的定向边界框，
        /// 但随后修改范围以确保该框包含由节点表示的基本体。
        auto box = node.GetBox();
        ComputeInteriorBox(i0, i1, box);
        node.SetBox(box);
        if (depth == height)
        {
            // 已达到用户指定的高度。不要继续递归经过此节点。
            return;
        }

        /// 将与最大范围对应的长方体轴用作分割轴。
        /// 将质心划分为两个子集，一个子集用于左子集，一子集用于右子集。
        /// 子集的元素数量最多相差1，因此树是平衡的。
        auto j0 = 0;
        auto j1 = 0;
        SplitPoints(i0, i1, node.GetBox().GetCenter(), node.GetBox().GetAxis(2), j0, j1);

        /// 重复出现在两个子节点身上。
        node.SetLeftChild(2 * nodeIndex + 1);
        node.SetRightChild(node.GetLeftChild() + 1);
        BuildTree(depth + 1, node.GetLeftChild(), i0, j0);
        BuildTree(depth + 1, node.GetRightChild(), j1, i1);
    }
    else  // i0 = i1
    {
        /// 节点是一片叶子。计算基本体相关的定向边界框。
        auto box = node.GetBox();
        ComputeLeafBox(i0, box);
        node.SetBox(box);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::OrientedBoundingBoxTree<Real>::SplitPoints(int i0, int i1, const Vector3& origin, const Vector3& direction, int& j0, int& j1)
{
    /// 将质心投影到分割轴上。
    const auto numProjections = i1 - i0 + 1;
    std::vector<OrientedBoundingBoxProjectionInfo<Real>> info{};
    info.reserve(numProjections);
    for (auto i = i0; i <= i1; ++i)
    {
        auto pointIndex = partition.at(i);
        const auto diff = centroids.at(pointIndex) - origin;
        auto projection = Dot(direction, diff);
        info.emplace_back(pointIndex, projection);
    }

    /// 用中间带把投影分开。
    const auto medianIndex = (numProjections - 1) / 2;
    std::nth_element(info.begin(), info.begin() + medianIndex, info.end());

    /// 用中值划分质心。
    auto k = 0;
    for (j0 = i0 - 1; k <= medianIndex; ++k)
    {
        partition.at(++j0) = info.at(k).GetPointIndex();
    }
    for (j1 = i1 + 1; k < numProjections; ++k)
    {
        partition.at(--j1) = info.at(k).GetPointIndex();
    }
}

#endif  // MATHEMATICS_COMPUTATIONAL_GEOMETRY_ORIENTED_BOUNDING_BOX_TREE_DETAIL_H
