// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 15:33)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_H

#include "Physics/PhysicsDll.h"

#include "BoundTree.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Intersection/Intersector.h"

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
	class CollisionRecord
	{
	public:
		static_assert(std::is_base_of<CoreTools::ObjectInterface, typename MeshSmartPointer::SubclassType>::value);
		
		using ClassType = CollisionRecord<MeshSmartPointer, Bound>;
		using BoundTreeChild = BoundTreeChild<MeshSmartPointer, Bound>;
		using Intersector = Mathematics::Intersector<float,Mathematics::Vector3D>;
		using IntersectorSharedPtr = std::shared_ptr<Intersector>;
		using BoundTreeChildSharedPtr = std::shared_ptr<BoundTreeChild> ;
		using AVector = Mathematics::FloatAVector;
		using ConstMeshSmartPointer = typename MeshSmartPointer::ConstType;
		using Callback = void (*) (const CollisionRecord& lhsRecord, int t0,
			                       const CollisionRecord& rhsRecord, int t1,
								   const IntersectorSharedPtr& intersector);

	public:
		CollisionRecord(const BoundTreeChildSharedPtr& tree, const AVector& velocity, Callback callback);

		CLASS_INVARIANT_DECLARE;
		
		const ConstMeshSmartPointer GetConstMesh() const;
		const AVector GetVelocity () const;

		const MeshSmartPointer GetMesh();

		const Bound GetWorldBound() const;
		bool IsInteriorNode() const;

		const BoundTreeChildSharedPtr GetLeftChild();
		const BoundTreeChildSharedPtr GetRightChild();

		Callback GetCallback() const;

		int GetNumTriangles() const;
		int GetTriangle(int index) const;
	
	private:
		BoundTreeChildSharedPtr m_Tree;
		AVector m_Velocity;
		Callback m_Callback;
	};

	// �ཻ��ѯ�������CollisionGroup���е�ע�ͣ�
	// �˽�ͨ���ص�����������Ӧ�ó������Ϣ��
	template <typename MeshSmartPointer, typename Bound>
	void TestIntersection (const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord,const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord);
	
	template <typename MeshSmartPointer, typename Bound>
	void FindIntersection (const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord,const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord);
	
	template <typename MeshSmartPointer, typename Bound>
	void TestIntersection (const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord,const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord,float tmax);

	template <typename MeshSmartPointer, typename Bound>
	void FindIntersection (const CollisionRecord<MeshSmartPointer, Bound>& lhsRecord,const CollisionRecord<MeshSmartPointer, Bound>& rhsRecord,float tmax);
}

#endif // PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_H
