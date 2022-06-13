///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/06 10:27)

#ifndef MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_H

#include "Mathematics/Intersection/Intersector1.h"

namespace Mathematics
{
    template <typename Real>
    class Intersector1Test : public Intersector1<Real>
    {
    public:
        using ClassType = Intersector1Test<Real>;
        using ParentType = Intersector1<Real>;

    public:
        explicit Intersector1Test(Real u0, Real u1, Real v0, Real v1) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD bool IsIntersection() const noexcept override;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_INTERSECTOR1_TEST_H