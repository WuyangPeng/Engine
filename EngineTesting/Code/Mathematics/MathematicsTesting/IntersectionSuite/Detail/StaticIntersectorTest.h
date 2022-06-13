///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/06/06 10:27)

#ifndef MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_H

#include "Mathematics/Intersection/StaticIntersector.h"

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class StaticIntersectorTest : public StaticIntersector<Real, Vector>
    {
    public:
        using ClassType = StaticIntersectorTest<Real, Vector>;
        using ParentType = StaticIntersector<Real, Vector>;
        using Math = Math<Real>;

    public:
        explicit StaticIntersectorTest(IntersectionType intersectionType, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_STATIC_INTERSECTOR_TEST_H