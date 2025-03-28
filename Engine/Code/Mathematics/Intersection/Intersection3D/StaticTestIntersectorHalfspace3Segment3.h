///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.6 (2023/10/28 15:59)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Plane3.h"
#include "Mathematics/Objects3D/Segment3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorHalfspace3Segment3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorHalfspace3Segment3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Plane3Type = Plane3<Real>;
        using Segment3Type = Segment3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorHalfspace3Segment3(const Plane3Type& halfspace, const Segment3Type& segment, const Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Plane3Type GetHalfspace() const noexcept;
        NODISCARD Segment3Type GetSegment() const noexcept;

    private:
        void Test() noexcept;

    private:
        Plane3Type halfspace;
        Segment3Type segment;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_HALFSPACE3_SEGMENT3_H
