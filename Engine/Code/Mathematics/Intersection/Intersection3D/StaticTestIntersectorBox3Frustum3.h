///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.1 (2021/01/21 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Frustum3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersectorBox3Frustum3 : public StaticIntersector<Real, Vector3D>
    {
    public:
        using ClassType = StaticTestIntersectorBox3Frustum3<Real>;
        using ParentType = StaticIntersector<Real, Vector3D>;
        using Vector3D = Vector3D<Real>;
        using Box3 = Box3<Real>;
        using Frustum3 = Frustum3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorBox3Frustum3(const Box3& box, const Frustum3& frustum, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Box3 GetBox() const noexcept;
        [[nodiscard]] const Frustum3 GetFrustum() const noexcept;

    private:
        void Test();

    private:
        Box3 m_Box;
        Frustum3 m_Frustum;
    };

    using FloatStaticTestIntersectorBox3Frustum3 = StaticTestIntersectorBox3Frustum3<float>;
    using DoubleStaticTestIntersectorBox3Frustum3 = StaticTestIntersectorBox3Frustum3<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_BOX3_FRUSTUM3_H
