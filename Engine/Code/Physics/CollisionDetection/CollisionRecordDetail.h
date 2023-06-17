///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.12 (2023/06/12 16:37)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_DETAIL_H

#include "CollisionRecord.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Mathematics/Distance/Distance3D/DistanceLine3Triangle3Detail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Triangle3Detail.h"
#include "Mathematics/Distance/DistanceResultDetail.h"
#include "Mathematics/Intersection/DynamicIntersectorDetail.h"
#include "Mathematics/Intersection/Intersection3D/DynamicFindIntersectorTriangle3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection3D/DynamicTestIntersectorTriangle3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorTriangle3Triangle3Detail.h"
#include "Mathematics/Intersection/Intersection3D/StaticTestIntersectorTriangle3Triangle3Detail.h"
#include "Mathematics/Objects3D/Triangle3Detail.h"
#include "Rendering/DataTypes/BoundDetail.h"

template <typename MeshSharedPointer, typename Bound>
Physics::CollisionRecord<MeshSharedPointer, Bound>::CollisionRecord(const BoundTreeChildSharedPtr& tree, const AVector& velocity, Callback callback)
    : tree{ tree }, velocity{ velocity }, callback{ callback }
{
    tree->UpdateWorldBound();

    PHYSICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
bool Physics::CollisionRecord<MeshSharedPointer, Bound>::IsValid() const noexcept
{
    try
    {
        if (callback != nullptr && tree != nullptr && tree->GetNumTriangles() != 0)
            return true;
        else
            return false;
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename MeshSharedPointer, typename Bound>
typename Physics::CollisionRecord<MeshSharedPointer, Bound>::ConstMeshSharedPointer Physics::CollisionRecord<MeshSharedPointer, Bound>::GetConstMesh() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return tree->GetMesh();
}

template <typename MeshSharedPointer, typename Bound>
MeshSharedPointer Physics::CollisionRecord<MeshSharedPointer, Bound>::GetMesh() noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return tree->GetMesh();
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::CollisionRecord<MeshSharedPointer, Bound>::AVector Physics::CollisionRecord<MeshSharedPointer, Bound>::GetVelocity() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return velocity;
}

template <typename MeshSharedPointer, typename Bound>
Bound Physics::CollisionRecord<MeshSharedPointer, Bound>::GetWorldBound() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return tree->GetWorldBound();
}

template <typename MeshSharedPointer, typename Bound>
bool Physics::CollisionRecord<MeshSharedPointer, Bound>::IsInteriorNode() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return tree->IsInteriorNode();
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::CollisionRecord<MeshSharedPointer, Bound>::BoundTreeChildSharedPtr Physics::CollisionRecord<MeshSharedPointer, Bound>::GetLeftChild() noexcept
{
    PHYSICS_CLASS_IS_VALID_1;

    return tree->GetLeftChild();
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::CollisionRecord<MeshSharedPointer, Bound>::BoundTreeChildSharedPtr Physics::CollisionRecord<MeshSharedPointer, Bound>::GetRightChild() noexcept
{
    PHYSICS_CLASS_IS_VALID_1;

    return tree->GetRightChild();
}

template <typename MeshSharedPointer, typename Bound>
typename Physics::CollisionRecord<MeshSharedPointer, Bound>::Callback Physics::CollisionRecord<MeshSharedPointer, Bound>::GetCallback() const noexcept
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return callback;
}

template <typename MeshSharedPointer, typename Bound>
int Physics::CollisionRecord<MeshSharedPointer, Bound>::GetNumTriangles() const
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return tree->GetNumTriangles();
}

template <typename MeshSharedPointer, typename Bound>
int Physics::CollisionRecord<MeshSharedPointer, Bound>::GetTriangle(int index) const
{
    PHYSICS_CLASS_IS_VALID_CONST_1;

    return tree->GetTriangle(index);
}

template <typename MeshSharedPointer, typename Bound>
void Physics::TestIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord)
{
    auto lhsWorldBound = lhsRecord.GetWorldBound();
    auto rhsWorldBound = rhsRecord.GetWorldBound();

    if (TestIntersection(lhsWorldBound, rhsWorldBound))
    {
        if (lhsRecord.IsInteriorNode())
        {
            auto leftChild = lhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.left和rhsRecord
            TestIntersection(leftCollisionRecord, rhsRecord);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.right和rhsRecord
            TestIntersection(rightCollisionRecord, rhsRecord);
        }
        else if (rhsRecord.IsInteriorNode())
        {
            auto leftChild = rhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

            // 计算lhsRecord和rhsRecord.left
            TestIntersection(lhsRecord, leftCollisionRecord);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

            // 计算lhsRecord和rhsRecord.right
            TestIntersection(lhsRecord, rightCollisionRecord);
        }
        else
        {
            auto lhsMesh = lhsRecord.GetConstMesh();
            auto rhsMesh = rhsRecord.GetConstMesh();

            // 每棵树的叶子。
            const auto lhsNumTriangles = lhsRecord.GetNumTriangles();
            for (auto lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
            {
                const auto lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

                // 获取世界空间三角形。
                auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

                Mathematics::Triangle3F tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3(),
                                              lhsTrianglePosition.GetSecondPosition().GetVector3(),
                                              lhsTrianglePosition.GetThirdPosition().GetVector3() };

                const auto rhsNumTriangles = rhsRecord.GetNumTriangles();
                for (auto rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
                {
                    const auto rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

                    // 获取世界空间三角形。
                    auto rhsTrianglePosition = rhsMesh->GetWorldTriangle(rhsTriangleIndex);

                    Mathematics::Triangle3F tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3(),
                                                  rhsTrianglePosition.GetSecondPosition().GetVector3(),
                                                  rhsTrianglePosition.GetThirdPosition().GetVector3() };

                    auto calc = std::make_shared<Mathematics::StaticTestIntersectorTriangle3Triangle3<float>>(tri0, tri1);
                    if (calc->IsIntersection())
                    {
                        auto lhsCallback = lhsRecord.GetCallback();
                        if (lhsCallback)
                        {
                            lhsCallback(lhsRecord, lhsTriangleIndex, rhsRecord, rhsTriangleIndex, calc);
                        }

                        auto rhsCallback = rhsRecord.GetCallback();

                        if (rhsCallback)
                        {
                            rhsCallback(rhsRecord, rhsTriangleIndex, lhsRecord, lhsTriangleIndex, calc);
                        }
                    }
                }
            }
        }
    }
}

template <typename MeshSharedPointer, typename Bound>
void Physics::FindIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord)
{
    auto lhsWorldBound = lhsRecord.GetWorldBound();
    auto rhsWorldBound = rhsRecord.GetWorldBound();

    if (TestIntersection(lhsWorldBound, rhsWorldBound))
    {
        if (lhsRecord.IsInteriorNode())
        {
            auto leftChild = lhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.left和rhsRecord
            TestIntersection(leftCollisionRecord, rhsRecord);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.right和rhsRecord
            TestIntersection(rightCollisionRecord, rhsRecord);
        }
        else if (rhsRecord.IsInteriorNode())
        {
            auto leftChild = rhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

            // 计算lhsRecord和rhsRecord.left
            TestIntersection(lhsRecord, leftCollisionRecord);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

            // 计算lhsRecord和rhsRecord.right
            TestIntersection(lhsRecord, rightCollisionRecord);
        }
        else
        {
            auto lhsMesh = lhsRecord.GetConstMesh();
            auto rhsMesh = rhsRecord.GetConstMesh();

            // 每棵树的叶子。
            const auto lhsNumTriangles = lhsRecord.GetNumTriangles();
            for (auto lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
            {
                const auto lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

                // 获取世界空间三角形。
                auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

                Mathematics::Triangle3F tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3(),
                                              lhsTrianglePosition.GetSecondPosition().GetVector3(),
                                              lhsTrianglePosition.GetThirdPosition().GetVector3() };

                const auto rhsNumTriangles = rhsRecord.GetNumTriangles();
                for (auto rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
                {
                    const auto rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

                    // 获取世界空间三角形。
                    auto rhsTrianglePosition = rhsMesh->GetWorldTriangle(rhsTriangleIndex);

                    Mathematics::Triangle3F tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3(),
                                                  rhsTrianglePosition.GetSecondPosition().GetVector3(),
                                                  rhsTrianglePosition.GetThirdPosition().GetVector3() };

                    auto calc = std::make_shared<Mathematics::StaticFindIntersectorTriangle3Triangle3<float>>(tri0, tri1);
                    if (calc->IsIntersection())
                    {
                        auto lhsCallback = lhsRecord.GetCallback();
                        if (lhsCallback)
                        {
                            lhsCallback(lhsRecord, lhsTriangleIndex, rhsRecord, rhsTriangleIndex, calc);
                        }

                        auto rhsCallback = rhsRecord.GetCallback();

                        if (rhsCallback)
                        {
                            rhsCallback(rhsRecord, rhsTriangleIndex, lhsRecord, lhsTriangleIndex, calc);
                        }
                    }
                }
            }
        }
    }
}

template <typename MeshSharedPointer, typename Bound>
void Physics::TestIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord, float tmax)
{
    auto lhsWorldBound = lhsRecord.GetWorldBound();
    auto rhsWorldBound = rhsRecord.GetWorldBound();

    const auto velocity0 = lhsRecord.GetVelocity();
    const auto velocity1 = rhsRecord.GetVelocity();

    if (Rendering::TestIntersection(lhsWorldBound, velocity0, rhsWorldBound, velocity1, tmax))
    {
        if (lhsRecord.IsInteriorNode())
        {
            auto leftChild = lhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.left和rhsRecord
            TestIntersection(leftCollisionRecord, rhsRecord, tmax);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.right和rhsRecord
            TestIntersection(rightCollisionRecord, rhsRecord, tmax);
        }
        else if (rhsRecord.IsInteriorNode())
        {
            auto leftChild = rhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

            // 计算lhsRecord和rhsRecord.left
            TestIntersection(lhsRecord, leftCollisionRecord, tmax);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

            // 计算lhsRecord和rhsRecord.right
            TestIntersection(lhsRecord, rightCollisionRecord, tmax);
        }
        else
        {
            auto lhsMesh = lhsRecord.GetConstMesh();
            auto rhsMesh = rhsRecord.GetConstMesh();

            // 每棵树的叶子。
            const auto lhsNumTriangles = lhsRecord.GetNumTriangles();
            for (auto lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
            {
                const auto lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

                // 获取世界空间三角形。
                auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

                Mathematics::Triangle3F tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3(),
                                              lhsTrianglePosition.GetSecondPosition().GetVector3(),
                                              lhsTrianglePosition.GetThirdPosition().GetVector3() };

                const auto rhsNumTriangles = rhsRecord.GetNumTriangles();
                for (auto rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
                {
                    const auto rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

                    // 获取世界空间三角形。
                    auto rhsTrianglePosition = rhsMesh->GetWorldTriangle(rhsTriangleIndex);

                    Mathematics::Triangle3F tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3(),
                                                  rhsTrianglePosition.GetSecondPosition().GetVector3(),
                                                  rhsTrianglePosition.GetThirdPosition().GetVector3() };

                    auto calc = std::make_shared<Mathematics::DynamicTestIntersectorTriangle3Triangle3<float>>(tri0, tri1, tmax, velocity0.GetVector3(), velocity1.GetVector3());
                    if (calc->IsIntersection())
                    {
                        auto lhsCallback = lhsRecord.GetCallback();
                        if (lhsCallback)
                        {
                            lhsCallback(lhsRecord, lhsTriangleIndex, rhsRecord, rhsTriangleIndex, calc);
                        }

                        auto rhsCallback = rhsRecord.GetCallback();

                        if (rhsCallback)
                        {
                            rhsCallback(rhsRecord, rhsTriangleIndex, lhsRecord, lhsTriangleIndex, calc);
                        }
                    }
                }
            }
        }
    }
}

template <typename MeshSharedPointer, typename Bound>
void Physics::FindIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord, float tmax)
{
    auto lhsWorldBound = lhsRecord.GetWorldBound();
    auto rhsWorldBound = rhsRecord.GetWorldBound();

    const auto velocity0 = lhsRecord.GetVelocity();
    const auto velocity1 = rhsRecord.GetVelocity();

    if (Rendering::TestIntersection(lhsWorldBound, velocity0, rhsWorldBound, velocity1, tmax))
    {
        if (lhsRecord.IsInteriorNode())
        {
            auto leftChild = lhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.left和rhsRecord
            TestIntersection(leftCollisionRecord, rhsRecord, tmax);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

            // 计算lhsRecord.right和rhsRecord
            TestIntersection(rightCollisionRecord, rhsRecord, tmax);
        }
        else if (rhsRecord.IsInteriorNode())
        {
            auto leftChild = rhsRecord.GetLeftChild();
            CollisionRecord<MeshSharedPointer, Bound> leftCollisionRecord(leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback());

            // 计算lhsRecord和rhsRecord.left
            TestIntersection(lhsRecord, leftCollisionRecord, tmax);

            auto rightChild = rhsRecord.GetRightChild();
            CollisionRecord<MeshSharedPointer, Bound> rightCollisionRecord(rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback());

            // 计算lhsRecord和rhsRecord.right
            TestIntersection(lhsRecord, rightCollisionRecord, tmax);
        }
        else
        {
            auto lhsMesh = lhsRecord.GetConstMesh();
            auto rhsMesh = rhsRecord.GetConstMesh();

            // 每棵树的叶子。
            const auto lhsNumTriangles = lhsRecord.GetNumTriangles();
            for (auto lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
            {
                const auto lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

                // 获取世界空间三角形。
                auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

                Mathematics::Triangle3F tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3(),
                                              lhsTrianglePosition.GetSecondPosition().GetVector3(),
                                              lhsTrianglePosition.GetThirdPosition().GetVector3() };

                const auto rhsNumTriangles = rhsRecord.GetNumTriangles();
                for (int rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
                {
                    const auto rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

                    // 获取世界空间三角形。
                    auto rhsTrianglePosition = rhsMesh->GetWorldTriangle(rhsTriangleIndex);

                    Mathematics::Triangle3F tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3(),
                                                  rhsTrianglePosition.GetSecondPosition().GetVector3(),
                                                  rhsTrianglePosition.GetThirdPosition().GetVector3() };

                    auto calc = std::make_shared<Mathematics::DynamicFindIntersectorTriangle3Triangle3<float>>(tri0, tri1, tmax, velocity0.GetVector3(), velocity1.GetVector3());
                    if (calc->IsIntersection())
                    {
                        auto lhsCallback = lhsRecord.GetCallback();
                        if (lhsCallback)
                        {
                            lhsCallback(lhsRecord, lhsTriangleIndex, rhsRecord, rhsTriangleIndex, calc);
                        }

                        auto rhsCallback = rhsRecord.GetCallback();

                        if (rhsCallback)
                        {
                            rhsCallback(rhsRecord, rhsTriangleIndex, lhsRecord, lhsTriangleIndex, calc);
                        }
                    }
                }
            }
        }
    }
}

#endif  // PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_DETAIL_H
