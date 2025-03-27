///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Lozenge3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorLine3Lozenge3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorLine3Lozenge3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Lozenge3 = Lozenge3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorLine3Lozenge3(const Line3& line, const Lozenge3& lozenge, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Lozenge3 GetLozenge() const noexcept;

    private:
        void Test();

    private:
        Line3 line;
        Lozenge3 lozenge;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LINE3_LOZENGE3_H
