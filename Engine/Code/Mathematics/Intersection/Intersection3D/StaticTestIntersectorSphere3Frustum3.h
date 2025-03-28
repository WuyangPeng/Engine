///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 16:02)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Frustum3.h"
#include "Mathematics/Objects3D/Sphere3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorSphere3Frustum3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorSphere3Frustum3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Sphere3 = Sphere3<Real>;
        using Frustum3 = Frustum3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorSphere3Frustum3(const Sphere3& sphere, const Frustum3& frustum, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Sphere3 GetSphere() const noexcept;
        NODISCARD Frustum3 GetFrustum() const noexcept;

    private:
        void Test();

    private:
        Sphere3 sphere;
        Frustum3 frustum;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_SPHERE3_FRUSTUM3_H
