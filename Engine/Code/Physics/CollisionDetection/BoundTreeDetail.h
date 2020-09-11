// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 15:48)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_DETAIL_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_DETAIL_H

#include "BoundTree.h"
#include "BoundTreeChildDetail.h"
#include "Rendering/SceneGraph/TrianglePosition.h"
#include "CoreTools/Helper/ClassInvariant/PhysicsClassInvariantMacro.h"

template <typename MeshSmartPointer, typename Bound>
Physics::BoundTree<MeshSmartPointer, Bound>
	::BoundTree(const MeshSmartPointer& mesh, int maxTrianglesPerLeaf,bool storeInteriorTriangles)
	:m_Mesh{ mesh }, m_BoundTreeChild{}, m_MaxTrianglesPerLeaf{ maxTrianglesPerLeaf }, m_StoreInteriorTriangles{ storeInteriorTriangles }
{
	BuildTree();
	 
	PHYSICS_SELF_CLASS_IS_VALID_1;
}


#ifdef OPEN_CLASS_INVARIANT
template <typename MeshSmartPointer, typename Bound>
bool Physics::BoundTree<MeshSmartPointer, Bound>
	::IsValid() const noexcept
{
	if (m_Mesh.IsValidPtr() && m_BoundTreeChild != nullptr && 0 < m_MaxTrianglesPerLeaf)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename MeshSmartPointer, typename Bound>
typename const Physics::BoundTree<MeshSmartPointer, Bound>::BoundTreeChildPtr Physics::BoundTree<MeshSmartPointer, Bound>
	::GetBeginChild()
{
	PHYSICS_CLASS_IS_VALID_1;

	return m_BoundTreeChild;
}

template <typename MeshSmartPointer, typename Bound>
typename const Physics::BoundTree<MeshSmartPointer, Bound>::ConstMeshSmartPointer Physics::BoundTree<MeshSmartPointer, Bound>
	::GetConstMesh() const
{
	PHYSICS_CLASS_IS_VALID_CONST_1;

	return m_Mesh.GetConstSmartPointer();
}

template <typename MeshSmartPointer, typename Bound>
const MeshSmartPointer Physics::BoundTree<MeshSmartPointer, Bound>
	::GetMesh()
{
	PHYSICS_CLASS_IS_VALID_1;

	return m_Mesh;
}

template <typename MeshSmartPointer, typename Bound>
void Physics::BoundTree<MeshSmartPointer, Bound>
	::UpdateWorldBound()
{
	PHYSICS_CLASS_IS_VALID_1;

	m_BoundTreeChild->UpdateWorldBound();
}

// private
template <typename MeshSmartPointer, typename Bound>
void Physics::BoundTree<MeshSmartPointer, Bound>
	::BuildTree()
{
	if (m_MaxTrianglesPerLeaf <= 0)
	{
		return;
	}

	// �����ε��������ڷָ�����
	// ����������ͶӰ���ָ����ϲ��������� 
	// �ָ����ͶӰ����ֵ��
    int numTriangles = m_Mesh->GetNumTriangles();
	std::vector<Mathematics::FloatAPoint> centroids;
    const float oneThird = 1.0f / 3.0f;  
	for (int index = 0; index < numTriangles; ++index)
    {
		Mathematics::FloatAPoint vertex[3];
		Rendering::TrianglePosition  trianglePosition = m_Mesh->GetModelTriangle(index);
        
		centroids.push_back(oneThird * (trianglePosition.GetFirstPosition() + trianglePosition.GetSecondPosition() + trianglePosition.GetThirdPosition()));
    }

	// ��ʼ�����ڴ洢�����������Ķ��������顣��Щ���������񻮷�ʱ�洢������
	std::vector<int> inSplit;    
	for (int index = 0; index < numTriangles; ++index)
    {
		inSplit.push_back(index);
    }

	m_BoundTreeChild = std::make_shared<BoundTreeChild>(m_Mesh, m_MaxTrianglesPerLeaf, centroids, 0, numTriangles - 1, inSplit, m_StoreInteriorTriangles);
}

#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_DETAIL_H