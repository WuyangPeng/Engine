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

        using Vector3Type = Vector3<Real>;
        using Plane3Type = Plane3<Real>;
        using Line3Type = Line3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorPlane3Plane3(const Plane3Type& plane0,
                                           const Plane3Type& plane1,
                                           Real tmax,
                                           const Vector3Type& lhsVelocity,
                                           const Vector3Type& rhsVelocity,
                                           const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetPlane0() const noexcept;
        NODISCARD Plane3Type GetPlane1() const noexcept;

        /// �йؽ�������Ϣ�� ����ȡ�뽻�����ͣ�IT_LINE��IT_PLANE�����Ӧ�Ľ�����ض�����
        NODISCARD Line3Type GetIntersectionLine() const noexcept;
        NODISCARD Plane3Type GetIntersectionPlane() const noexcept;

    private:
        void Find();

    private:
        Plane3Type plane0;
        Plane3Type plane1;

        // �йؽ�������Ϣ��
        Line3Type intersectionLine;
        Plane3Type intersectionPlane;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_PLANE3_PLANE3_H
