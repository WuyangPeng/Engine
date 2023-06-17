///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/12 16:38)

#ifndef PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_H
#define PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_H

#include "Physics/PhysicsDll.h"

#include "CoreTools/ObjectSystems/ObjectInterface.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Rendering/DataTypes/Transform.h"

#include <boost/noncopyable.hpp>
#include <type_traits>

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
    class BoundTreeChild : private boost::noncopyable
    {
    public:
        using ClassType = BoundTreeChild<MeshSharedPointer, Bound>;
        using Transform = Rendering::TransformF;
        using BoundTreeChildSharedPtr = std::shared_ptr<ClassType>;
        using APoint = Mathematics::APointF;
        using AVector = Mathematics::AVectorF;
        using Line3 = Mathematics::Line3F;
        using Centroids = std::vector<APoint>;
        using Split = std::vector<int>;
        using ConstMeshSharedPointer = std::shared_ptr<typename const MeshSharedPointer::element_type>;

    public:
        BoundTreeChild(const MeshSharedPointer& mesh,
                       int maxTrianglesPerLeaf,
                       const Centroids& centroids,
                       int beginIndex,
                       int endIndex,
                       const Split& inSplit,
                       bool storeInteriorTriangles);

        CLASS_INVARIANT_DECLARE;

        NODISCARD ConstMeshSharedPointer GetConstMesh() const noexcept;
        NODISCARD MeshSharedPointer GetMesh() noexcept;

        NODISCARD Bound GetWorldBound() const noexcept;

        // ���������transform�ٶ���̬�ı䡣
        void UpdateWorldBound();

        NODISCARD BoundTreeChildSharedPtr GetLeftChild() noexcept;
        NODISCARD BoundTreeChildSharedPtr GetRightChild() noexcept;

        NODISCARD bool IsInteriorNode() const noexcept;
        NODISCARD bool IsLeafNode() const noexcept;

        NODISCARD int GetNumTriangles() const;
        NODISCARD int GetTriangle(int index) const;
        NODISCARD std::vector<int> GetTriangles() const;

    private:
        void BuildTree(int maxTrianglesPerLeaf,
                       const Centroids& centroids,
                       int beginIndex,
                       int endIndex,
                       const Split& inSplit,
                       bool storeInteriorTriangles);

        // �����������Ӽ���ģ��Լ���� �������ڷָ����������ĵ�ͶӰ���ߡ�
        NODISCARD Line3 CreateModelBound(int beginIndex, int endIndex, const Split& inSplit);

    private:
        Bound modelBound;
        Bound worldBound;

        // ��������ʾ��
        BoundTreeChildSharedPtr leftChild;
        BoundTreeChildSharedPtr rightChild;

        std::vector<int> triangles;

        MeshSharedPointer mesh;
    };
}

#endif  // PHYSICS_COLLISION_DETECTION_BOUND_TREE_CHILD_H
