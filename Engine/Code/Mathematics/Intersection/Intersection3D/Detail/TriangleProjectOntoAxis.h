///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/24 17:14)

#ifndef MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H
#define MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class TriangleProjectOntoAxis final
    {
    public:
        using ClassType = TriangleProjectOntoAxis<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3D = Vector3D<Real>;

    public:
        TriangleProjectOntoAxis(const Triangle3& triangle, const Vector3D& axis);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetMin() const;
        [[nodiscard]] Real GetMax() const;

    private:
        void Project(const Triangle3& triangle, const Vector3D& axis);

    private:
        Real m_Min;
        Real m_Max;
    };

}

#endif  // MATHEMATICS_INTERSECTION_TRIANGLE_PROJECT_ONTO_AXIS_H
