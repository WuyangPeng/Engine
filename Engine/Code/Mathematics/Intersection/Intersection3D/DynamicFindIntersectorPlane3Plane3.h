///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 14:59)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Plane3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorPlane3Plane3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorPlane3Plane3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Plane3 = Plane3<Real>;
        using Line3 = Line3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        DynamicFindIntersectorPlane3Plane3(const Plane3& plane0,
                                           const Plane3& plane1,
                                           Real tmax,
                                           const Vector3& lhsVelocity,
                                           const Vector3& rhsVelocity,
                                           const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3 GetPlane0() const noexcept;
        NODISCARD Plane3 GetPlane1() const noexcept;

        /// �йؽ�������Ϣ�� ����ȡ�뽻�����ͣ�IT_LINE��IT_PLANE�����Ӧ�Ľ�����ض�����
        NODISCARD Line3 GetIntersectionLine() const noexcept;
        NODISCARD Plane3 GetIntersectionPlane() const noexcept;

    private:
        void Find();

    private:
        Plane3 plane0;
        Plane3 plane1;

        // �йؽ�������Ϣ��
        Line3 intersectionLine;
        Plane3 intersectionPlane;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
