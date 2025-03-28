///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:00)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Circle3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicFindIntersectorSphere3Sphere3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicFindIntersectorSphere3Sphere3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Circle3 = Circle3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        DynamicFindIntersectorSphere3Sphere3(const Sphere3& sphere0,
                                             const Sphere3& sphere1,
                                             Real tMax,
                                             const Vector3& lhsVelocity,
                                             const Vector3& rhsVelocity,
                                             const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Sphere3 GetSphere0() const noexcept;
        NODISCARD Sphere3 GetSphere1() const noexcept;

        // ���ھ�̬���ҽ�����ѯ�Ľ���㼯��
        NODISCARD Circle3 GetCircle() const noexcept;

        // ���ڶ�̬�����ཻ��ѯ���ཻ����
        NODISCARD Vector3 GetContactPoint() const noexcept;

    private:
        // ��̬���ҽ�����ѯ��
        void Find();

    private:
        // Ҫ�ཻ�Ķ���
        Sphere3 sphere0;
        Sphere3 sphere1;

        // ��̬������ཻԲ��
        Circle3 circle;

        // ��̬����Ľ��㡣
        Vector3 contactPoint;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_FIND_INTERSECTOR_SPHERE3_SPHERE3_H
