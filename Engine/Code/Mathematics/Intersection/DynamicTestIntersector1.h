///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/16 17:07)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H

#include "Mathematics/MathematicsDll.h"

#include "Intersector1.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DynamicTestIntersector1 final : public Intersector1<Real>
    {
    public:
        using ClassType = DynamicTestIntersector1<Real>;
        using ParentType = Intersector1<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersector1(Real u0, Real u1, Real v0, Real v1, Real tMax, Real speedU, Real speedV, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_FINAL_DECLARE;

        [[nodiscard]] bool IsIntersection() const noexcept final;

        // 动态相交查询的两个区间处于第一次/最后一次接触的时间。
        [[nodiscard]] Real GetFirstTime() const;
        [[nodiscard]] Real GetLastTime() const;

    private:
        void Test(Real tMax, Real speedU, Real speedV);

    private:
        // 有关相交的信息。
        Real m_FirstTime;
        Real m_LastTime;

        bool m_Intersection;
    };

    using FloatDynamicTestIntersector1 = DynamicTestIntersector1<float>;
    using DoubleDynamicTestIntersector1 = DynamicTestIntersector1<double>;
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR1_H
