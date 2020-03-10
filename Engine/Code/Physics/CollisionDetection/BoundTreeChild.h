// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.3 (2019/07/29 15:30)
#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_H 

#include "Physics/PhysicsDll.h"

#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Rendering/DataTypes/Transform.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"

#include <boost/noncopyable.hpp>
#include <type_traits> 

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
	class BoundTreeChild : private boost::noncopyable
	{
	public:
		static_assert(std::is_base_of<CoreTools::ObjectInterface, typename MeshSmartPointer::SubclassType>::value);
		
		using ClassType = BoundTreeChild<MeshSmartPointer,Bound>;
		using Transform = Rendering::Transform;
		using BoundTreeChildPtr = std::shared_ptr<ClassType>;
		using APoint = Mathematics::APointf;
		using AVector = Mathematics::AVectorf;
		using Line3 = Mathematics::Line3f;
		using Centroids = std::vector<APoint>;
		using Split = std::vector<int>;
		using ConstMeshSmartPointer = typename MeshSmartPointer::ConstType;

	public:		
		BoundTreeChild(const MeshSmartPointer& mesh, int maxTrianglesPerLeaf, const Centroids& centroids, int beginIndex,
					   int endIndex,const Split& inSplit,bool storeInteriorTriangles);

		CLASS_INVARIANT_DECLARE;

		const ConstMeshSmartPointer GetConstMesh() const;
		const MeshSmartPointer GetMesh();
 
		const Bound GetWorldBound () const;
		
		// ���������transform�ٶ���̬�ı䡣
		void UpdateWorldBound();
	
		const BoundTreeChildPtr GetLeftChild();
		const BoundTreeChildPtr GetRightChild();

		bool IsInteriorNode() const;
		bool IsLeafNode() const;

		int GetNumTriangles() const;
		int GetTriangle(int index) const;
		const std::vector<int> GetTriangles() const;

	private:
		void BuildTree(int maxTrianglesPerLeaf,const Centroids& centroids,int beginIndex,
					   int endIndex,const Split& inSplit,bool storeInteriorTriangles);
	
		// �����������Ӽ���ģ��Լ���� �������ڷָ����������ĵ�ͶӰ���ߡ�
		const Line3 CreateModelBound(int beginIndex, int endIndex, const Split& inSplit);

	private:
		Bound m_ModelBound;
		Bound m_WorldBound;
		
		// ��������ʾ��
		BoundTreeChildPtr m_LeftChild;
		BoundTreeChildPtr m_RightChild;

		std::vector<int> m_Triangles; 

		MeshSmartPointer m_Mesh;
	};
}

#endif // PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_H
