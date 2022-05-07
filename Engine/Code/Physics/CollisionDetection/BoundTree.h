///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.0.7 (2022/04/25 13:58)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_H

#include "Physics/PhysicsDll.h"

#include "BoundTreeChild.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "Mathematics/Algebra/APoint.h"
#include "Rendering/SceneGraph/TriangleIndex.h"

#include <type_traits>

// ��Mesh�����Ҿ������½ӿڡ�
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
    class BoundTree
    {
    public:
        using ClassType = BoundTree<MeshSharedPointer, Bound>;
        using BoundTreeChild = BoundTreeChild<MeshSharedPointer, Bound>;
        using BoundTreeChildSharedPtr = std::shared_ptr<BoundTreeChild>;
        using TriangleIndex = Rendering::TriangleIndex;
        using ConstMeshSharedPointer = std::shared_ptr<typename const MeshSharedPointer::element_type>;

    public:
        explicit BoundTree(const MeshSharedPointer& mesh, int maxTrianglesPerLeaf = 1, bool storeInteriorTriangles = false);

        CLASS_INVARIANT_DECLARE;

        // �������˽ṹ��
        NODISCARD BoundTreeChildSharedPtr GetBeginChild() noexcept;

        NODISCARD ConstMeshSharedPointer GetConstMesh() const noexcept;
        NODISCARD MeshSharedPointer GetMesh() noexcept;

        // ��������transform�ٶ���̬�任��
        void UpdateWorldBound();

    private:
        void BuildTree();

    private:
        MeshSharedPointer mesh;
        BoundTreeChildSharedPtr boundTreeChild;
        int maxTrianglesPerLeaf;
        bool storeInteriorTriangles;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_H
