///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.3 (2022/02/23 13:54)

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

        NODISCARD bool IsIntersection() const final;
    };

    using StaticTestIntersector1F = StaticTestIntersector1<float>;
    using StaticTestIntersector1D = StaticTestIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR1_H
