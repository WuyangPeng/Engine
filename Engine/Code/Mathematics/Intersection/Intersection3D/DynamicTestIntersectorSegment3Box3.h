///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 15:02)

#ifndef MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
#define MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/DynamicIntersector.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class DynamicTestIntersectorSegment3Box3 : public DynamicIntersector<Real, Vector3>
    {
    public:
        using ClassType = DynamicTestIntersectorSegment3Box3<Real>;
        using ParentType = DynamicIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Segment3 = Segment3<Real>;
        using Box3 = Box3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        DynamicTestIntersectorSegment3Box3(const Segment3& segment,
                                           const Box3& box,
                                           bool solid,
                                           Real tMax,
                                           const Vector3& lhsVelocity,
                                           const Vector3& rhsVelocity,
                                           const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Segment3 GetSegment() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

    private:
        void Test();

    private:
        Segment3 segment;
        Box3 box;
        bool solid;
    };
}

#endif  // MATHEMATICS_INTERSECTION_DYNAMIC_TEST_INTERSECTOR_SEGMENT3_BOX3_H
