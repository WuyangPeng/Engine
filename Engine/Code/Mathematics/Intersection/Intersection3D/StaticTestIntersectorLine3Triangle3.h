///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 16:06)

#ifndef MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_H
#define MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    // 测试相交查询。
    template <typename Real>
    class StaticTestIntersectorLine3Triangle3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorLine3Triangle3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;
        using Vector3 = Vector3<Real>;
        using Line3 = Line3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLine3Triangle3(const Line3& line, const Triangle3& triangle, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Triangle3 GetTriangle() const noexcept;

    private:
        void Test();

    private:
        // 相交对象
        Line3 line;
        Triangle3 triangle;
    };
}

#endif  // MATHEMATICS_INTERSECTION_TEST_INTERSECTOR_LINE3_TRIANGLE3_H
