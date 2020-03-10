// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 15:51)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_DETAIL_H

#include "CollisionRecord.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"
#include "Mathematics/Objects3D/Triangle3.h"
#include "Mathematics/Intersection/Intersection3D/DynamicTestIntersectorTriangle3Triangle3.h"
#include "Mathematics/Intersection/Intersection3D/StaticFindIntersectorTriangle3Triangle3.h"
#include "Mathematics/Intersection/Intersection3D/DynamicFindIntersectorTriangle3Triangle3.h"

template <typename MeshSmartPointer, typename Bound>
Physics::CollisionRecord<MeshSmartPointer, Bound>
	::CollisionRecord(const BoundTreeChildSharedPtr& tree, const AVector& velocity,Callback callback)
	:m_Tree{ tree }, m_Velocity{ velocity }, m_Callback{ callback }
{
	m_Tree->UpdateWorldBound();

	PHYSICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename MeshSmartPointer, typename Bound>
bool Physics::CollisionRecord<MeshSmartPointer, Bound>
	::IsValid() const noexcept
{
	if (m_Callback != nullptr && m_Tree != nullptr  && m_Tree->GetNumTriangles() != 0)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MeshSmartPointer, typename Bound>
typename const Physics::CollisionRecord<MeshSmartPointer, Bound>::ConstMeshSmartPointer Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetConstMesh() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Tree->GetMesh().GetConstSmartPointer();
}

template <typename MeshSmartPointer, typename Bound>
const MeshSmartPointer Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetMesh()
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Tree->GetMesh();
}

template <typename MeshSmartPointer, typename Bound>
const typename Physics::CollisionRecord<MeshSmartPointer, Bound>::AVector Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetVelocity() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Velocity;
}

template <typename MeshSmartPointer, typename Bound>
const Bound Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetWorldBound() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Tree->GetWorldBound();
}

template <typename MeshSmartPointer, typename Bound>
bool Physics::CollisionRecord<MeshSmartPointer, Bound>
	::IsInteriorNode() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Tree->IsInteriorNode();
}

template <typename MeshSmartPointer, typename Bound>
typename const Physics::CollisionRecord<MeshSmartPointer, Bound>::BoundTreeChildSharedPtr Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetLeftChild()
{
	PHYSICS_CLASS_IS_VALID_1;

	return m_Tree->GetLeftChild();
}

template <typename MeshSmartPointer, typename Bound>
typename const Physics::CollisionRecord<MeshSmartPointer, Bound>::BoundTreeChildSharedPtr Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetRightChild()
{
	PHYSICS_CLASS_IS_VALID_1;

	return m_Tree->GetRightChild();
}

template <typename MeshSmartPointer, typename Bound>
typename Physics::CollisionRecord<MeshSmartPointer, Bound>::Callback Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetCallback() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Callback;
}

template <typename MeshSmartPointer, typename Bound>
int Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetNumTriangles() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Tree->GetNumTriangles();
}

template <typename MeshSmartPointer, typename Bound>
int Physics::CollisionRecord<MeshSmartPointer, Bound>
	::GetTriangle(int index) const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Tree->GetTriangle(index);
}

template <typename MeshSmartPointer, typename Bound>
void Physics::TestIntersection(const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord, const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord)
{   
	auto lhsWorldBound = lhsRecord.GetWorldBound();
	auto rhsWorldBound = rhsRecord.GetWorldBound();

	if (TestIntersection(lhsWorldBound, rhsWorldBound))
    {
		if (lhsRecord.IsInteriorNode())
        {
			auto leftChild = lhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.left和rhsRecord
			TestIntersection(leftCollisionRecord, rhsRecord);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.right和rhsRecord
			TestIntersection(rightCollisionRecord, rhsRecord);
        }
		else if (rhsRecord.IsInteriorNode())
        {
			auto leftChild = rhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

			// 计算lhsRecord和rhsRecord.left
			TestIntersection(lhsRecord, leftCollisionRecord);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

			// 计算lhsRecord和rhsRecord.right
			TestIntersection(lhsRecord, rightCollisionRecord);
        }
        else
        {
			auto lhsMesh = lhsRecord.GetConstMesh();
			auto rhsMesh = rhsRecord.GetConstMesh();

            // 每棵树的叶子。
			int lhsNumTriangles = lhsRecord.GetNumTriangles();
            for (int lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
            {
				int lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

                // 获取世界空间三角形。
				auto lhsTrianglePosition =lhsMesh->GetWorldTriangle(lhsTriangleIndex);
								
				Mathematics::Triangle3f tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3D(),
										      lhsTrianglePosition.GetSecondPosition().GetVector3D(),
											  lhsTrianglePosition.GetThirdPosition().GetVector3D()	};

				int rhsNumTriangles = rhsRecord.GetNumTriangles();
                for (int rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
                {
					int rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

					// 获取世界空间三角形。
					auto rhsTrianglePosition = rhsMesh->GetWorldTriangle(rhsTriangleIndex);
                    
					Mathematics::Triangle3f tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3D(),
												  rhsTrianglePosition.GetSecondPosition().GetVector3D(),
												  rhsTrianglePosition.GetThirdPosition().GetVector3D() };

					typename CollisionRecord<MeshSmartPointer, Bound>::IntersectorSharedPtr calc(new Mathematics::StaticTestIntersectorTriangle3Triangle3<float>(tri0, tri1));
                    if (calc.IsIntersection())
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

template <typename MeshSmartPointer, typename Bound>
void Physics
	::FindIntersection(const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord, const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord)
{
	auto lhsWorldBound = lhsRecord.GetWorldBound();
	auto rhsWorldBound = rhsRecord.GetWorldBound();

	if (TestIntersection(lhsWorldBound, rhsWorldBound))
	{
		if (lhsRecord.IsInteriorNode())
		{
			auto leftChild = lhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.left和rhsRecord
			TestIntersection(leftCollisionRecord, rhsRecord);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.right和rhsRecord
			TestIntersection(rightCollisionRecord, rhsRecord);
		}
		else if (rhsRecord.IsInteriorNode())
		{
			auto leftChild = rhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

			// 计算lhsRecord和rhsRecord.left
			TestIntersection(lhsRecord, leftCollisionRecord);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

			// 计算lhsRecord和rhsRecord.right
			TestIntersection(lhsRecord, rightCollisionRecord);
		}
		else
		{
			auto lhsMesh = lhsRecord.GetConstMesh();
			auto rhsMesh = rhsRecord.GetConstMesh();

			// 每棵树的叶子。
			int lhsNumTriangles = lhsRecord.GetNumTriangles();
			for (int lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
			{
				int lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

				// 获取世界空间三角形。
				auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

				Mathematics::Triangle3f tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3D(),
					                          lhsTrianglePosition.GetSecondPosition().GetVector3D(),
											  lhsTrianglePosition.GetThirdPosition().GetVector3D() };

				int rhsNumTriangles = rhsRecord.GetNumTriangles();
				for (int rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
				{
					int rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

					// 获取世界空间三角形。
					auto rhsTrianglePosition =
						rhsMesh->GetWorldTriangle(rhsTriangleIndex);

					Mathematics::Triangle3f tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3D(),
												  rhsTrianglePosition.GetSecondPosition().GetVector3D(),
												  rhsTrianglePosition.GetThirdPosition().GetVector3D()	};

					typename CollisionRecord<MeshSmartPointer, Bound>::IntersectorSharedPtr calc(new Mathematics::StaticFindIntersectorTriangle3Triangle3<float>(tri0, tri1));
					if (calc.IsIntersection())
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

template <typename MeshSmartPointer, typename Bound>
void Physics
	::TestIntersection(const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord, const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord, float tmax)
{
	auto lhsWorldBound = lhsRecord.GetWorldBound();
	auto rhsWorldBound = rhsRecord.GetWorldBound();

	// TODO: Add glue until the Mathematics library uses APoint and AVector.
	Mathematics::Vector3Df velocity0{ lhsRecord.GetVelocity().GetVector3D() };
	Mathematics::Vector3Df velocity1{ rhsRecord.GetVelocity().GetVector3D() };

	if (TestIntersection(lhsWorldBound,velocity0, rhsWorldBound, velocity1,tmax ))
	{
		if (lhsRecord.IsInteriorNode())
		{
			auto leftChild = lhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.left和rhsRecord
			TestIntersection(leftCollisionRecord, rhsRecord,tmax);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.right和rhsRecord
			TestIntersection(rightCollisionRecord, rhsRecord,tmax);
		}
		else if (rhsRecord.IsInteriorNode())
		{
			auto leftChild = rhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

			// 计算lhsRecord和rhsRecord.left
			TestIntersection(lhsRecord, leftCollisionRecord,tmax);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback() };

			// 计算lhsRecord和rhsRecord.right
			TestIntersection(lhsRecord, rightCollisionRecord,tmax);
		}
		else
		{
			auto lhsMesh = lhsRecord.GetConstMesh();
			auto rhsMesh = rhsRecord.GetConstMesh();

			// 每棵树的叶子。
			int lhsNumTriangles = lhsRecord.GetNumTriangles();
			for (int lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
			{
				int lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

				// 获取世界空间三角形。
				auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

				Mathematics::Triangle3f tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3D(),
											  lhsTrianglePosition.GetSecondPosition().GetVector3D(),
											  lhsTrianglePosition.GetThirdPosition().GetVector3D() };

				int rhsNumTriangles = rhsRecord.GetNumTriangles();
				for (int rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
				{
					int rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

					// 获取世界空间三角形。
					auto rhsTrianglePosition = rhsMesh->GetWorldTriangle(rhsTriangleIndex);

					Mathematics::Triangle3f tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3D(),
												  rhsTrianglePosition.GetSecondPosition().GetVector3D(),
												  rhsTrianglePosition.GetThirdPosition().GetVector3D() };

					typename CollisionRecord<MeshSmartPointer, Bound>::IntersectorSharedPtr calc(new Mathematics::DynamicTestIntersectorTriangle3Triangle3<float> (tri0, tri1,tmax, velocity0, velocity1));
					if (calc.IsIntersection())
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

template <typename MeshSmartPointer, typename Bound>
void Physics
	::FindIntersection(const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord,  const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord, float tmax)
{
	auto lhsWorldBound = lhsRecord.GetWorldBound();
	auto rhsWorldBound = rhsRecord.GetWorldBound();

	// TODO: Add glue until the Mathematics library uses APoint and AVector.
	Mathematics::Vector3Df velocity0{ lhsRecord.GetVelocity().GetVector3D() };
	Mathematics::Vector3Df velocity1{ rhsRecord.GetVelocity().GetVector3D() };

	if (TestIntersection(lhsWorldBound,velocity0, rhsWorldBound, velocity1,tmax ))
	{
		if (lhsRecord.IsInteriorNode())
		{
			auto leftChild = lhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord{ leftChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.left和rhsRecord
			TestIntersection(leftCollisionRecord, rhsRecord,tmax);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord{ rightChild, lhsRecord.GetVelocity(), lhsRecord.GetCallback() };

			// 计算lhsRecord.right和rhsRecord
			TestIntersection(rightCollisionRecord, rhsRecord,tmax);
		}
		else if (rhsRecord.IsInteriorNode())
		{
			auto leftChild = rhsRecord.GetLeftChild();
			CollisionRecord<MeshSmartPointer, Bound> leftCollisionRecord(leftChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback());

			// 计算lhsRecord和rhsRecord.left
			TestIntersection(lhsRecord, leftCollisionRecord,tmax);

			auto rightChild = rhsRecord.GetRightChild();
			CollisionRecord<MeshSmartPointer, Bound> rightCollisionRecord(rightChild, rhsRecord.GetVelocity(), rhsRecord.GetCallback());

			// 计算lhsRecord和rhsRecord.right
			TestIntersection(lhsRecord, rightCollisionRecord,tmax);
		}
		else
		{
			auto lhsMesh = lhsRecord.GetConstMesh();
			auto rhsMesh = rhsRecord.GetConstMesh();

			// 每棵树的叶子。
			int lhsNumTriangles = lhsRecord.GetNumTriangles();
			for (int lhsIndex = 0; lhsIndex < lhsNumTriangles; ++lhsIndex)
			{
				int lhsTriangleIndex = lhsRecord.GetTriangle(lhsIndex);

				// 获取世界空间三角形。
				auto lhsTrianglePosition = lhsMesh->GetWorldTriangle(lhsTriangleIndex);

				Mathematics::Triangle3f tri0{ lhsTrianglePosition.GetFirstPosition().GetVector3D(),
											  lhsTrianglePosition.GetSecondPosition().GetVector3D(),
											  lhsTrianglePosition.GetThirdPosition().GetVector3D() };

				int rhsNumTriangles = rhsRecord.GetNumTriangles();
				for (int rhsIndex = 0; rhsIndex < rhsNumTriangles; ++rhsIndex)
				{
					int rhsTriangleIndex = rhsRecord.GetTriangle(rhsIndex);

					// 获取世界空间三角形。
					auto rhsTrianglePosition =
						rhsMesh->GetWorldTriangle(rhsTriangleIndex);

					Mathematics::Triangle3f tri1{ rhsTrianglePosition.GetFirstPosition().GetVector3D(),
												  rhsTrianglePosition.GetSecondPosition().GetVector3D(),
											      rhsTrianglePosition.GetThirdPosition().GetVector3D() };

					typename CollisionRecord<MeshSmartPointer, Bound>::IntersectorSharedPtr calc(new Mathematics::DynamicFindIntersectorTriangle3Triangle3<float>(tri0, tri1,tmax, velocity0, velocity1));
					if (calc.IsIntersection())
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

#endif // PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_DETAIL_H

