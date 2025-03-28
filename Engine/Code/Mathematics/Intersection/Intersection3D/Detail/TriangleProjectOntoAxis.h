///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/28 14:56)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class TriangleProjectOntoAxis final
    {
    public:
        using ClassType = TriangleProjectOntoAxis<Real>;

        using Triangle3 = Triangle3<Real>;
        using Vector3Type = Vector3<Real>;

    public:
        TriangleProjectOntoAxis(const Triangle3& triangle, const Vector3Type& axis);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetMin() const noexcept;
        NODISCARD Real GetMax() const noexcept;

    private:
        void Project(const Triangle3& triangle, const Vector3Type& axis);

    private:
        Real min;
        Real max;
    };
}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H
