// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.3 (2019/07/29 15:43)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_DETAIL_H 

#include "BoundTreeChild.h"
#include "BoundTreeSplitTriangles.h"
#include "Rendering/SceneGraph/TriangleIndex.h"
#include "Mathematics/Objects3D/Line3Detail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit3Detail.h"
#include "CoreTools/Helper/Assertion/PhysicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

template <typename MeshSmartPointer, typename Bound>
Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::BoundTreeChild(const MeshSmartPointer& mesh,int maxTrianglesPerLeaf,const Centroids& centroids,int beginIndex,
					 int endIndex, const Split& inSplit,bool storeInteriorTriangles)
	:m_ModelBound{}, m_WorldBound{}, m_LeftChild{}, m_RightChild{}, m_Triangles{}, m_Mesh{ mesh }
{
	BuildTree(maxTrianglesPerLeaf, centroids, beginIndex, endIndex, inSplit,storeInteriorTriangles);

	PHYSICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename MeshSmartPointer, typename Bound>
bool Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MeshSmartPointer, typename Bound>
const Bound Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetWorldBound() const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return m_WorldBound;
}

template <typename MeshSmartPointer, typename Bound>
void Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::UpdateWorldBound()
{
	PHYSICS_CLASS_IS_VALID_9;

	m_WorldBound = m_ModelBound.TransformBy(m_Mesh->GetWorldTransform());
}

template <typename MeshSmartPointer, typename Bound>
typename const Physics::BoundTreeChild<MeshSmartPointer, Bound>::BoundTreeChildPtr Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetLeftChild()
{
	PHYSICS_CLASS_IS_VALID_9;

	return m_LeftChild;
}

template <typename MeshSmartPointer, typename Bound>
typename const Physics::BoundTreeChild<MeshSmartPointer, Bound>::BoundTreeChildPtr Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetRightChild()
{
	PHYSICS_CLASS_IS_VALID_9;

	return m_RightChild;
}

template <typename MeshSmartPointer, typename Bound>
bool Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::IsInteriorNode() const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return (m_LeftChild != nullptr) || (m_RightChild != nullptr);
}

template <typename MeshSmartPointer, typename Bound>
bool Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::IsLeafNode() const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return (m_LeftChild == nullptr) && (m_RightChild == nullptr);
}

template <typename MeshSmartPointer, typename Bound>
int Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetNumTriangles() const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return boost::numeric_cast<int>(m_Triangles.size());
}

template <typename MeshSmartPointer, typename Bound>
int Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetTriangle(int index) const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;
	PHYSICS_ASSERTION_0(0 <= index && index < GetNumTriangles(), "索引越界\n");

	return m_Triangles[index];
}

template <typename MeshSmartPointer, typename Bound>
const std::vector<int> Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetTriangles() const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return m_Triangles;
}

template <typename MeshSmartPointer, typename Bound>
void Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::BuildTree(int maxTrianglesPerLeaf,const Centroids& centroids,int beginIndex, int endIndex,const Split& inSplit,bool storeInteriorTriangles)
{
	PHYSICS_CLASS_IS_VALID_9;	
	PHYSICS_ASSERTION_2(beginIndex <= endIndex, "无效索引顺序\n");
	
	auto line = CreateModelBound(beginIndex, endIndex, inSplit);
	auto origin = line.GetOrigin();
	auto direction = line.GetDirection();

	if (endIndex - beginIndex < maxTrianglesPerLeaf)
	{
		// 在叶节点。
		auto numTriangles = endIndex - beginIndex + 1;
		m_Triangles.resize(numTriangles);
		memcpy(&m_Triangles[0], &inSplit[beginIndex], numTriangles * sizeof(int));
	}
	else
	{
		// 在内部节点。
		if (storeInteriorTriangles)
		{
			auto numTriangles = endIndex - beginIndex + 1;
			m_Triangles.resize(numTriangles);
			memcpy(&m_Triangles[0], &inSplit[beginIndex], numTriangles * sizeof(int));
		}		 

		BoundTreeSplitTriangles splitTriangles{ centroids, beginIndex, endIndex,inSplit, origin, direction };

		m_LeftChild = std::make_shared<BoundTreeChild>(m_Mesh,maxTrianglesPerLeaf, centroids, beginIndex, splitTriangles.GetFirstOutSplitIndex(),splitTriangles.GetOutSplit(), storeInteriorTriangles);

		m_RightChild = std::make_shared<BoundTreeChild>(m_Mesh, maxTrianglesPerLeaf, centroids, splitTriangles.GetSecondOutSplitIndex(), endIndex,splitTriangles.GetOutSplit(), storeInteriorTriangles);	
	}
}

template <typename MeshSmartPointer, typename Bound>
const typename Physics::BoundTreeChild<MeshSmartPointer, Bound>::Line3 Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::CreateModelBound(int beginIndex, int endIndex, const std::vector<int>& inSplit)
{    
	// 标记在子网格中使用的顶点。
    int numVertices = m_Mesh->GetNumVertices();
	std::vector<int> valid(numVertices); 
  
	for (int i = beginIndex; i <= endIndex; ++i)
    {
		Rendering::TriangleIndex triangleIndex = m_Mesh->GetTriangle(inSplit[i]);
		valid[triangleIndex.GetFirstIndex()] = 1;
		valid[triangleIndex.GetSecondIndex()] = 1;
		valid[triangleIndex.GetThirdIndex()] = 1;
    }

    // 在子网格中创建一组连续的顶点
	std::vector<Mathematics::FloatVector3D> meshVertices;
    for (int i = 0; i < numVertices; ++i)
    {
        if (valid[i])
        {
            meshVertices.push_back(m_Mesh->GetPosition(i));
        }
    } 

    // 计算子网格的边界。
	m_ModelBound.ComputeFromData(meshVertices);

    // 计算子网格的分割线。
	Mathematics::OrthogonalLineFit3f fit(meshVertices);

	return fit.GetLine3();
}

template <typename MeshSmartPointer, typename Bound>
typename const Physics::BoundTreeChild<MeshSmartPointer, Bound>::ConstMeshSmartPointer Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetConstMesh() const
{
	PHYSICS_CLASS_IS_VALID_CONST_9;

	return m_Mesh.GetConstSmartPointer();
}

template <typename MeshSmartPointer, typename Bound>
const MeshSmartPointer Physics::BoundTreeChild<MeshSmartPointer, Bound>
	::GetMesh()
{
	PHYSICS_CLASS_IS_VALID_9;

	return m_Mesh;
}

#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_DETAIL_H