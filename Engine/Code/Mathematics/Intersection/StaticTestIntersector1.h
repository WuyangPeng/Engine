///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 14:53)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE StaticTestIntersector1 final : public Intersector1<Real>
    {
    public:
        using ClassType = StaticTestIntersector1<Real>;
        using ParentType = Intersector1<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] bool IsIntersection() const final;
    };

    using FloatStaticTestIntersector1 = StaticTestIntersector1<float>;
    using DoubleStaticTestIntersector1 = StaticTestIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H
