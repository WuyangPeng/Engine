///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 16:00)

#ifndef MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
#define MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Intersection/StaticIntersector.h"
#include "Mathematics/Objects3D/Lozenge3.h"

namespace Mathematics
{
    template <typename Real>
    class StaticTestIntersectorLozenge3Lozenge3 : public StaticIntersector<Real, Vector3>
    {
    public:
        using ClassType = StaticTestIntersectorLozenge3Lozenge3<Real>;
        using ParentType = StaticIntersector<Real, Vector3>;

        using Vector3Type = Vector3<Real>;
        using Lozenge3Type = Lozenge3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;

    public:
        StaticTestIntersectorLozenge3Lozenge3(const Lozenge3Type& lozenge0, const Lozenge3Type& lozenge1, const Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Lozenge3Type GetLozenge0() const noexcept;
        NODISCARD Lozenge3Type GetLozenge1() const noexcept;

    private:
        void Test();

    private:
        Lozenge3Type lozenge0;
        Lozenge3Type lozenge1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
