///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/07 16:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorTriangle3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorTriangle3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Triangle3 = Triangle3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, Real tmax,
                                               const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        // �Ӵ��㡣
        [[nodiscard]] const Vector3D GetPoint() const noexcept;

    private:
        using VertexType = std::vector<Vector3D>;

    private:
        /// ��̬���ҽ�����ѯ�� �����ѯ���ء� true������ʹ��GetContactTime()��ȡ��һ���ཻ��
        /// �����ʱ��Ϊ�㣬���������Ѿ��������ཻ�����Ҳ������κ��ཻ����
        /// ������ʱ������������ʹ��GetPoint()��ȡ��һ���ཻ�㡣
        void Find();

    private:
        // ֧�ֶ�̬��ѯ��
        [[nodiscard]] bool FindTriangleSphereCoplanarIntersection(int index, const VertexType& vertexs, const Vector3D& sideNorm, const Vector3D& side, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1);

        [[nodiscard]] bool FindSphereVertexIntersection(const Vector3D& vertex, Real tmax, const Vector3D& velocity0, const Vector3D& velocity1);

        // Ҫ�ཻ�Ķ���
        Triangle3 m_Triangle;
        Sphere3 m_Sphere;

        // ��̬��ѯ���ཻ�㡣
        Vector3D m_Point;
    };

    using FloatDynamicFindIntersectorTriangle3Sphere3 = DynamicFindIntersectorTriangle3Sphere3<float>;
    using DoubleDynamicFindIntersectorTriangle3Sphere3 = DynamicFindIntersectorTriangle3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_TRIANGLE3_SPHERE3_H
