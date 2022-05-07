///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 14:13)

#ifndef PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_H
#define PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_H

#include "Physics/PhysicsDll.h"

#include "BoundTree.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Intersection/Intersector.h"

#include <type_traits>

// ��Mesh����������½ӿڡ�
//    int GetNumVertices () const;
//    Vector3D GetPosition(int vertexIndex) const;
//    int GetNumTriangles () const;
//    TriangleIndex GetTriangle(int index) const;
//    TrianglePosition GetModelTriangle(int index) const;
//    TrianglePosition GetWorldTriangle(int index) const;
//    Transform GetWorldTransform() const;

// ��Bound���������½ӿڡ�
//    Bound ();
//    void ComputeFromData (int numElements, int stride, const char* data);
//    Bound TransformBy (const Transform& transform) const;
// �����������·ǳ�Ա����
//    bool TestIntersection (const Bound& lhsBound,const Bound& rhsBound);
//    bool TestIntersection(const Bound& lhsBound,
//                          const Bound::AVector& lhsVelocity,
//                          const Bound& rhsBound,
//                          const Bound::AVector& rhsVelocity,
//                          float tmax);

namespace Physics
{
    template <typename MeshSharedPointer, typename Bound>
    class CollisionRecord
    {
    public:
        using ClassType = CollisionRecord<MeshSharedPointer, Bound>;
        using BoundTreeChild = BoundTreeChild<MeshSharedPointer, Bound>;
        using Intersector = Mathematics::Intersector<float, Mathematics::Vector3>;
        using IntersectorSharedPtr = std::shared_ptr<Intersector>;
        using BoundTreeChildSharedPtr = std::shared_ptr<BoundTreeChild>;
        using AVector = Mathematics::AVectorF;
        using ConstMeshSharedPointer = std::shared_ptr<typename const MeshSharedPointer::element_type>;
        using Callback = void (*)(const CollisionRecord& lhsRecord, int t0,
                                  const CollisionRecord& rhsRecord, int t1,
                                  const IntersectorSharedPtr& intersector);

    public:
        CollisionRecord(const BoundTreeChildSharedPtr& tree, const AVector& velocity, Callback callback);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstMeshSharedPointer GetConstMesh() const noexcept;
        NODISCARD AVector GetVelocity() const noexcept;

        NODISCARD MeshSharedPointer GetMesh() noexcept;

        NODISCARD Bound GetWorldBound() const noexcept;
        NODISCARD bool IsInteriorNode() const noexcept;

        NODISCARD BoundTreeChildSharedPtr GetLeftChild() noexcept;
        NODISCARD BoundTreeChildSharedPtr GetRightChild() noexcept;

        NODISCARD Callback GetCallback() const noexcept;

        NODISCARD int GetNumTriangles() const;
        NODISCARD int GetTriangle(int index) const;

    private:
        BoundTreeChildSharedPtr tree;
        AVector velocity;
        Callback callback;
    };

    // �ཻ��ѯ�������CollisionGroup���е�ע�ͣ�
    // �˽�ͨ���ص�����������Ӧ�ó������Ϣ��
    template <typename MeshSharedPointer, typename Bound>
    void TestIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord);

    template <typename MeshSharedPointer, typename Bound>
    void FindIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord);

    template <typename MeshSharedPointer, typename Bound>
    void TestIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord, float tmax);

    template <typename MeshSharedPointer, typename Bound>
    void FindIntersection(CollisionRecord<MeshSharedPointer, Bound> lhsRecord, CollisionRecord<MeshSharedPointer, Bound> rhsRecord, float tmax);
}

#endif  // PHYSICS_COLLISION_DETECTION_COLLISION_RECORD_H
