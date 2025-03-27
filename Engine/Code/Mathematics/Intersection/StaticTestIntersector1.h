///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:05)

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

        using Math = typename ParentType::MathType;

    public:
        StaticTestIntersector1(Real u0, Real u1, Real v0, Real v1, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD bool IsIntersection() const final;
    };

    using StaticTestIntersector1F = StaticTestIntersector1<float>;
    using StaticTestIntersector1D = StaticTestIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H
