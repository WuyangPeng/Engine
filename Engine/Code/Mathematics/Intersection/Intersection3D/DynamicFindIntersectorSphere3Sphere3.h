///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/06 18:22)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorSphere3Sphere3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorSphere3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0, const Sphere3& sphere1, Real tmax,
                                             const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Sphere3 GetSphere0() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere1() const noexcept;

        // ���ھ�̬���ҽ�����ѯ�Ľ���㼯��
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

        // ���ڶ�̬�����ཻ��ѯ���ཻ����
        [[nodiscard]] const Vector3D GetContactPoint() const noexcept;

    private:
        // ��̬���ҽ�����ѯ��
        void Find();

        // Ҫ�ཻ�Ķ���
        Sphere3 m_Sphere0;
        Sphere3 m_Sphere1;

        // ��̬������ཻԲ��
        Circle3 m_Circle;

        // ��̬����Ľ��㡣
        Vector3D m_ContactPoint;
    };

    using FloatDynamicFindIntersectorSphere3Sphere3 = DynamicFindIntersectorSphere3Sphere3<float>;
    using DoubleDynamicFindIntersectorSphere3Sphere3 = DynamicFindIntersectorSphere3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
