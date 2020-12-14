///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/11 16:22)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Triangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Triangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Triangle3(const Line3& line, const Triangle3& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLine() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        [[nodiscard]] Real GetTriangleBary(int index) const;

    private:
        Line3 m_Line;
        Triangle3 m_Triangle;

        // 有关最接近点的信息。

        // closest0 = line.origin + param * line.direction
        // closest1 = sum_{i=0}^2 bary[i] * tri.vertex[i]
        mutable Vector3D m_TriangleBary;
    };

    using FloatDistanceLine3Triangle3 = DistanceLine3Triangle3<float>;
    using DoubleDistanceLine3Triangle3 = DistanceLine3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_TRIANGLE3_H
