// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 15:29)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_H

#include "Physics/PhysicsDll.h"

#include "BoundTreeChild.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/TriangleIndex.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <type_traits> 

// ��ConstMeshSmartPointer������ConstSubclassSmartPointer���Ҿ������½ӿڡ�
//    int GetNumVertices () const;
//    const Vector3D GetPosition(int vertexIndex) const;
//    int GetNumTriangles () const;
//    const TriangleIndex GetTriangle(int index) const;
//    const TrianglePosition GetModelTriangle(int index) const;
//    const TrianglePosition GetWorldTriangle(int index) const;
//    const Transform GetWorldTransform() const;

// ��Bound���������½ӿڡ�
//    Bound ();  
//    void ComputeFromData (int numElements, int stride, const char* data);
//    const Bound TransformBy (const Transform& transform) const;
// �����������·ǳ�Ա����
//    bool TestIntersection (const Bound& lhsBound,const Bound& rhsBound);    
//    bool TestIntersection(const Bound& lhsBound,
//                          const Bound::AVector& lhsVelocity,
//                          const Bound& rhsBound,
//                          const Bound::AVector& rhsVelocity,
//                          float tmax);

namespace Physics
{
	template <typename MeshSmartPointer, typename Bound>
	class BoundTree
	{
	public:
		static_assert(std::is_base_of<CoreTools::ObjectInterface, typename MeshSmartPointer::SubclassType>::value);

		using ClassType = BoundTree<MeshSmartPointer, Bound>;
		using BoundTreeChild = BoundTreeChild<MeshSmartPointer, Bound>;
		using BoundTreeChildPtr = std::shared_ptr<BoundTreeChild>;
		using TriangleIndex = Rendering::TriangleIndex;
		using ConstMeshSmartPointer = typename MeshSmartPointer::ConstType;

	public:
		explicit BoundTree(const MeshSmartPointer& mesh, int maxTrianglesPerLeaf = 1,bool storeInteriorTriangles = false);

		CLASS_INVARIANT_DECLARE;
	
		// �������˽ṹ��
		const BoundTreeChildPtr GetBeginChild();
 
		const ConstMeshSmartPointer GetConstMesh() const;
		const MeshSmartPointer GetMesh();

		// ��������transform�ٶ���̬�任��
		void UpdateWorldBound ();

	private:
		void BuildTree();		
	 
	private:	
		MeshSmartPointer m_Mesh;
		BoundTreeChildPtr m_BoundTreeChild;	
		int m_MaxTrianglesPerLeaf;
		bool m_StoreInteriorTriangles;
	};
}

#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_H
