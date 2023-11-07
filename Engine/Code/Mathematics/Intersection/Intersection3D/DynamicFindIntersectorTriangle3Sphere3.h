///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:01)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorTriangle3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle,
                                               const Sphere3& sphere,
                                               Real tMax,
                                               const Vector3& lhsVelocity,
                                               const Vector3& rhsVelocity,
                                               const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetTriangle() const noexcept;
        NODISCARD Sphere3 GetSphere() const noexcept;

        // �Ӵ��㡣
        NODISCARD Vector3 GetPoint() const noexcept;

    private:
        using VertexType = std::vector<Vector3>;

    private:
        /// ��̬���ҽ�����ѯ�� �����ѯ���ء� true������ʹ��GetContactTime()��ȡ��һ���ཻ��
        /// �����ʱ��Ϊ�㣬���������Ѿ��������ཻ�����Ҳ������κ��ཻ����
        /// ������ʱ������������ʹ��GetPoint()��ȡ��һ���ཻ�㡣
        void Find();

    private:
        // ֧�ֶ�̬��ѯ��
        NODISCARD bool FindTriangleSphereCoplanarIntersection(int index, const VertexType& vertexs, const Vector3& sideNorm, const Vector3& side, Real tmax, const Vector3& velocity0, const Vector3& velocity1);

        NODISCARD bool FindSphereVertexIntersection(const Vector3& vertex, Real tmax, const Vector3& velocity0, const Vector3& velocity1);

    private:
        // Ҫ�ཻ�Ķ���
        Triangle3 triangle;
        Sphere3 sphere;

        // ��̬��ѯ���ཻ�㡣
        Vector3 point;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
