///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:08)

#ifndef MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H
#define MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticFindIntersectorRay3Plane3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticFindIntersectorRay3Plane3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Ray3 = Ray3<Real>;
        using Plane3 = Plane3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::MathType;

    public:
        StaticFindIntersectorRay3Plane3(const Ray3& ray, const Plane3& plane, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Ray3 GetRay() const noexcept;
        NODISCARD Plane3 GetPlane() const noexcept;

        NODISCARD Real GetRayParameter() const noexcept;

    private:
        void Find() noexcept;

    private:
        // �ཻ����
        Ray3 ray;
        Plane3 plane;

        // �ཻ������Ϣ
        Real rayParameter;
    };
}

#endif  // MATHEMATICS_INTERSECTION_FIND_INTERSECTOR_RAY3_PLANE3_H
