///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/20 18:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorPlane3Sphere3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticFindIntersectorPlane3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorPlane3Sphere3(const Plane3& plane, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane() const noexcept;
        [[nodiscard]] const Sphere3 GetSphere() const noexcept;

        /// �޳�֧�֡� ��׶̨����Ϊλ��ƽ������ࡣ ���������ƽ��ĸ��࣬�����޳���
        [[nodiscard]] bool SphereIsCulled() const noexcept;

        // �ཻ���� ��Բ����Find()���ء� true��ʱ����Ч�� ����������ཻ����Բ�뾶����Ϊ-1���Ը���ָʾԲ��Ч��
        [[nodiscard]] const Circle3 GetCircle() const noexcept;

    private:
        void Find();

    private:
        Plane3 m_Plane;
        Sphere3 m_Sphere;

        Circle3 m_Circle;
    };

    using FloatStaticFindIntersectorPlane3Sphere3 = StaticFindIntersectorPlane3Sphere3<float>;
    using DoubleStaticFindIntersectorPlane3Sphere3 = StaticFindIntersectorPlane3Sphere3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_FIND_INTERSECTOR_PLANE3_SPHERE3_H
