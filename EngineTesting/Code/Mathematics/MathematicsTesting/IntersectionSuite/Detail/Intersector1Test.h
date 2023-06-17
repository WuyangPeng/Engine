///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 15:49)

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