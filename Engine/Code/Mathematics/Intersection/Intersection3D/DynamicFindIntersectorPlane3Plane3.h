///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.6.0.1 (2021/01/04 16:18)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicFindIntersectorPlane3Plane3 : public DynamicIntersector<Real, Vector3D>
    {
    public:
        using ClassType = DynamicFindIntersectorPlane3Plane3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicFindIntersectorPlane3Plane3(const Plane3& plane0, const Plane3& plane1, Real tmax,
                                           const Vector3D& lhsVelocity, const Vector3D& rhsVelocity, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Plane3 GetPlane0() const noexcept;
        [[nodiscard]] const Plane3 GetPlane1() const noexcept;

        /// �йؽ�������Ϣ�� ����ȡ�뽻�����ͣ�IT_LINE��IT_PLANE�����Ӧ�Ľ�����ض�����
        [[nodiscard]] const Line3 GetIntersectionLine() const noexcept;
        [[nodiscard]] const Plane3 GetIntersectionPlane() const noexcept;

    private:
        void Find();

        Plane3 m_Plane0;
        Plane3 m_Plane1;

        // �йؽ�������Ϣ��
        Line3 m_IntersectionLine;
        Plane3 m_IntersectionPlane;
    };

    using FloatDynamicFindIntersectorPlane3Plane3 = DynamicFindIntersectorPlane3Plane3<float>;
    using DoubleDynamicFindIntersectorPlane3Plane3 = DynamicFindIntersectorPlane3Plane3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
