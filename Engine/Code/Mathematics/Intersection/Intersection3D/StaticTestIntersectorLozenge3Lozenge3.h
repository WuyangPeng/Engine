///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.3 (2022/03/04 16:10)

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
        using Vector3 = Vector3<Real>;
        using Lozenge3 = Lozenge3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using Math = typename ParentType::Math;

    public:
        StaticTestIntersectorLozenge3Lozenge3(const Lozenge3& lozenge0, const Lozenge3& lozenge1, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Lozenge3 GetLozenge0() const noexcept;
        NODISCARD Lozenge3 GetLozenge1() const noexcept;

    private:
        void Test();

    private:
        Lozenge3 lozenge0;
        Lozenge3 lozenge1;
    };
}

#endif  // MATHEMATICS_INTERSECTION_STATIC_TEST_INTERSECTOR_LOZENGE3_LOZENGE3_H
