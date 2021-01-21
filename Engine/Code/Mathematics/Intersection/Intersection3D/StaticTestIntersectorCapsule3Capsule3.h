///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 15:38)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Capsule3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorCapsule3Capsule3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorCapsule3Capsule3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Capsule3 = Capsule3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorCapsule3Capsule3(const Capsule3& capsule0, const Capsule3& capsule1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Capsule3 GetCapsule0() const noexcept;
        [[nodiscard]] const Capsule3 GetCapsule1() const noexcept;

    private:
        void Test();

    private:
        Capsule3 m_Capsule0;
        Capsule3 m_Capsule1;
    };

    using FloatStaticTestIntersectorCapsule3Capsule3 = StaticTestIntersectorCapsule3Capsule3<float>;
    using DoubleStaticTestIntersectorCapsule3Capsule3 = StaticTestIntersectorCapsule3Capsule3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_CAPSULE3_CAPSULE3_H
