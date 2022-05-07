///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 14:01)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_DETAIL_H

#include "BoundTree.h"
#include "BoundTreeChildDetail.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Rendering/SceneGraph/TrianglePosition.h"

template <typename MeshSharedPointer, typename Bound>
Physics::BoundTree<MeshSharedPointer, Bound>::BoundTree(const MeshSharedPointer& mesh, int maxTrianglesPerLeaf, bool storeInteriorTriangles)
    : mesh{ mesh }, boundTreeChild{}, maxTrianglesPerLeaf{ maxTrianglesPerLeaf }, storeInteriorTriangles{ storeInteriorTriangles }
{
    BuildTree();

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
bool Physics::BoundTree<MeshSharedPointer, Bound>::IsValid() const noexcept
{
    if (mesh != nullptr && boundTreeChild != nullptr && 0 < maxTrianglesPerLeaf)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
typename Physics::BoundTree<MeshSharedPointer, Bound>::BoundTreeChildSharedPtr Physics::BoundTree<MeshSharedPointer, Bound>::GetBeginChild() noexcept
{
    PHYSICS_CLASS_IS_VALID_1;

    return boundTreeChild;
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::BoundTree<MeshSharedPointer, Bound>::ConstMeshSharedPointer Physics::BoundTree<MeshSharedPointer, Bound>::GetConstMesh() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return mesh;
}

template <typename MeshSharedPointer, typename Bound>
MeshSharedPointer Physics::BoundTree<MeshSharedPointer, Bound>::GetMesh() noexcept
{
    PHYSICS_CLASS_IS_VALID_1;

    return mesh;
}

template <typename MeshSharedPointer, typename Bound>
void Physics::BoundTree<MeshSharedPointer, Bound>::UpdateWorldBound()
{
    PHYSICS_CLASS_IS_VALID_1;

    boundTreeChild->UpdateWorldBound();
}

// private
template <typename MeshSharedPointer, typename Bound>
void Physics::BoundTree<MeshSharedPointer, Bound>::BuildTree()
{
    if (maxTrianglesPerLeaf <= 0)
    {
        return;
    }

    // �����ε��������ڷָ�����
    // ����������ͶӰ���ָ����ϲ���������
    // �ָ����ͶӰ����ֵ��
    const auto numTriangles = mesh->GetNumTriangles();
    std::vector<Mathematics::APointF> centroids{};
    constexpr auto oneThird = 1.0f / 3.0f;
    for (auto index = 0; index < numTriangles; ++index)
    {
        auto trianglePosition = mesh->GetModelTriangle(index);

        centroids.emplace_back(oneThird * (trianglePosition.GetFirstPosition() + trianglePosition.GetSecondPosition() + trianglePosition.GetThirdPosition()));
    }

    // ��ʼ�����ڴ洢�����������Ķ��������顣��Щ���������񻮷�ʱ�洢������
    std::vector<int> inSplit{};
    for (auto index = 0; index < numTriangles; ++index)
    {
        inSplit.emplace_back(index);
    }

    boundTreeChild = std::make_shared<BoundTreeChild>(mesh, maxTrianglesPerLeaf, centroids, 0, numTriangles - 1, inSplit, storeInteriorTriangles);
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_DETAIL_H