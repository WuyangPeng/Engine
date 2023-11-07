///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Ray3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    // ���ҽ�����ѯ�� �ཻ����
    // P = origin + t * direction = b0 * V0 + b1 * V1 + b2 * V2
    template <typename Real>
    class StaticFindIntersectorRay3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Ray3 = Ray3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticFindIntersectorRay3Triangle3(const Ray3& ray, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3 GetRay() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

        NODISCARD Real GetRayParameter() const noexcept;
        NODISCARD Real GetTriangleBary0() const noexcept;
        NODISCARD Real GetTriangleBary1() const noexcept;
        NODISCARD Real GetTriangleBary2() const noexcept;

    private:
        void Find();

    private:
        // �ཻ����
        Ray3 ray;
        Triangle3 triangle;

        // �ཻ������Ϣ
        Real rayParameter;
        Real triangleBary0;
        Real triangleBary1;
        Real triangleBary2;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_TRIANGLE3_H
