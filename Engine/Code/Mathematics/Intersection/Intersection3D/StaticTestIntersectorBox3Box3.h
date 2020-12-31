///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/25 10:19)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Box3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorBox3Box3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorBox3Box3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorBox3Box3(const Box3& box0, const Box3& box1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox0() const noexcept;
        [[nodiscard]] const Box3 GetBox1() const noexcept;

    private:
        void Test();

    private:
        Box3 m_Box0;
        Box3 m_Box1;
    };

    using FloatStaticTestIntersectorBox3Box3 = StaticTestIntersectorBox3Box3<float>;
    using DoubleStaticTestIntersectorBox3Box3 = StaticTestIntersectorBox3Box3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_BOX3_H
