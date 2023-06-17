///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 15:49)

#ifndef MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_H
#define MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_H

#include "Mathematics/Intersection/DynamicIntersector.h"

namespace Mathematics
{
    template <typename Real, template <typename> class Vector>
    class DynamicIntersectorTest : public DynamicIntersector<Real, Vector>
    {
    public:
        using ClassType = DynamicIntersectorTest<Real, Vector>;
        using ParentType = DynamicIntersector<Real, Vector>;
        using VectorType = Vector<Real>;
        using Math = Math<Real>;

    public:
        explicit DynamicIntersectorTest(Real tMax,
                                        const VectorType& lhsVelocity,
                                        const VectorType& rhsVelocity,
                                        IntersectionType intersectionType,
                                        Real contactTime,
                                        const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // MATHEMATICS_INTERSECTION_SUITE_DYNAMIC_INTERSECTOR_TEST_H