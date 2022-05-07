///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.0.7 (2022/04/25 11:44)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_DETAIL_H

#include "BoundTreeChild.h"
#include "BoundTreeSplitTriangles.h"
#include "CoreTools/Helper/Assertion/PhysicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit3Detail.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Rendering/SceneGraph/TriangleIndex.h"

template <typename MeshSharedPointer, typename Bound>
Physics::BoundTreeChild<MeshSharedPointer, Bound>::BoundTreeChild(const MeshSharedPointer& mesh,
                                                                  int maxTrianglesPerLeaf,
                                                                  const Centroids& centroids,
                                                                  int beginIndex,
                                                                  int endIndex,
                                                                  const Split& inSplit,
                                                                  bool storeInteriorTriangles)
    : modelBound{}, worldBound{}, leftChild{}, rightChild{}, triangles{}, mesh{ mesh }
{
    BuildTree(maxTrianglesPerLeaf, centroids, beginIndex, endIndex, inSplit, storeInteriorTriangles);

    PHYSICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
bool Physics::BoundTreeChild<MeshSharedPointer, Bound>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
Bound Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetWorldBound() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return worldBound;
}

template <typename MeshSharedPointer, typename Bound>
void Physics::BoundTreeChild<MeshSharedPointer, Bound>::UpdateWorldBound()
{
    PHYSICS_CLASS_IS_VALID_9;

    worldBound = modelBound.TransformBy(mesh->GetWorldTransform());
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::BoundTreeChild<MeshSharedPointer, Bound>::BoundTreeChildSharedPtr Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetLeftChild() noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    return leftChild;
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::BoundTreeChild<MeshSharedPointer, Bound>::BoundTreeChildSharedPtr Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetRightChild() noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    return rightChild;
}

template <typename MeshSharedPointer, typename Bound>
bool Physics::BoundTreeChild<MeshSharedPointer, Bound>::IsInteriorNode() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return (leftChild != nullptr) || (rightChild != nullptr);
}

template <typename MeshSharedPointer, typename Bound>
bool Physics::BoundTreeChild<MeshSharedPointer, Bound>::IsLeafNode() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return (leftChild == nullptr) && (rightChild == nullptr);
}

template <typename MeshSharedPointer, typename Bound>
int Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetNumTriangles() const
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return boost::numeric_cast<int>(triangles.size());
}

template <typename MeshSharedPointer, typename Bound>
int Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetTriangle(int index) const
{
    PHYSICS_CLASS_IS_VALID_CONST_9;
    PHYSICS_ASSERTION_0(0 <= index && index < GetNumTriangles(), "索引越界\n");

    return triangles.at(index);
}

template <typename MeshSharedPointer, typename Bound>
std::vector<int> Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetTriangles() const
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return triangles;
}

template <typename MeshSharedPointer, typename Bound>
void Physics::BoundTreeChild<MeshSharedPointer, Bound>::BuildTree(int maxTrianglesPerLeaf, const Centroids& centroids, int beginIndex, int endIndex, const Split& inSplit, bool storeInteriorTriangles)
{
    PHYSICS_CLASS_IS_VALID_9;
    PHYSICS_ASSERTION_2(beginIndex <= endIndex, "无效索引顺序\n");

    const auto line = CreateModelBound(beginIndex, endIndex, inSplit);
    const auto origin = line.GetOrigin();
    const auto direction = line.GetDirection();

    if (endIndex - beginIndex < maxTrianglesPerLeaf)
    {
        // 在叶节点。
        const auto numTriangles = endIndex - beginIndex + 1;

        for (auto i = 0; i < numTriangles; ++i)
        {
            const auto index = i + beginIndex;
            triangles.emplace_back(inSplit.at(index));
        }
    }
    else
    {
        // 在内部节点。
        if (storeInteriorTriangles)
        {
            const auto numTriangles = endIndex - beginIndex + 1;

            for (auto i = 0; i < numTriangles; ++i)
            {
                const auto index = i + beginIndex;
                triangles.emplace_back(inSplit.at(index));
            }
        }
        BoundTreeSplitTriangles splitTriangles{ centroids, beginIndex, endIndex, inSplit, Mathematics::APointF{ origin }, Mathematics::AVectorF{ direction } };

        leftChild = std::make_shared<BoundTreeChild>(mesh, maxTrianglesPerLeaf, centroids, beginIndex, splitTriangles.GetFirstOutSplitIndex(), splitTriangles.GetOutSplit(), storeInteriorTriangles);

        rightChild = std::make_shared<BoundTreeChild>(mesh, maxTrianglesPerLeaf, centroids, splitTriangles.GetSecondOutSplitIndex(), endIndex, splitTriangles.GetOutSplit(), storeInteriorTriangles);
    }
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::BoundTreeChild<MeshSharedPointer, Bound>::Line3 Physics::BoundTreeChild<MeshSharedPointer, Bound>::CreateModelBound(int beginIndex, int endIndex, const std::vector<int>& inSplit)
{
    // 标记在子网格中使用的顶点。
    const auto numVertices = mesh->GetNumVertices();
    std::vector<int> valid(numVertices);

    for (auto i = beginIndex; i <= endIndex; ++i)
    {
        const auto triangleIndex = mesh->GetTriangle(inSplit.at(i));
        valid.at(triangleIndex.GetFirstIndex()) = 1;
        valid.at(triangleIndex.GetSecondIndex()) = 1;
        valid.at(triangleIndex.GetThirdIndex()) = 1;
    }

    // 在子网格中创建一组连续的顶点
    std::vector<Mathematics::Vector3F> meshVertices{};
    for (auto i = 0; i < numVertices; ++i)
    {
        if (valid.at(i))
        {
            meshVertices.emplace_back(mesh->GetPosition(i));
        }
    }

    // 计算子网格的边界。
    modelBound.ComputeFromData(meshVertices);

    // 计算子网格的分割线。
    const Mathematics::OrthogonalLineFit3F fit{ meshVertices };

    return fit.GetLine3();
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::BoundTreeChild<MeshSharedPointer, Bound>::ConstMeshSharedPointer Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetConstMesh() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_9;

    return mesh;
}

template <typename MeshSharedPointer, typename Bound>
MeshSharedPointer Physics::BoundTreeChild<MeshSharedPointer, Bound>::GetMesh() noexcept
{
    PHYSICS_CLASS_IS_VALID_9;

    return mesh;
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_DETAIL_H