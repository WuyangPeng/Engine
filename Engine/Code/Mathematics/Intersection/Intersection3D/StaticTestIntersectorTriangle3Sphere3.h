///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.12 (2023/06/09 09:03)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Sphere3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorTriangle3Sphere3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorTriangle3Sphere3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorTriangle3Sphere3(const Triangle3& triangle, const Sphere3& sphere, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Triangle3 GetTriangle() const noexcept;
        NODISCARD Sphere3 GetSphere() const noexcept;

    private:
        void Test();

    private:
        Triangle3 triangle;
        Sphere3 sphere;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_TRIANGLE3_SPHERE3_H
