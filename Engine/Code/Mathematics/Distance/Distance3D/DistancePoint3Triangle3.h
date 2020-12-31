///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/14 18:27)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Triangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Triangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Triangle3(const Vector3D& point, const Triangle3& triangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Triangle3 GetTriangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        // 有关最接近的三角形点的信息。
        [[nodiscard]] Real GetTriangleBary(int index) const;

    private:
        Vector3D m_Point;
        Triangle3 m_Triangle;

        // closest1 = sum_{i=0}^2 bary[i]*tri.vertex[i]
        mutable Vector3D m_TriangleBary;
    };

    using FloatDistancePoint3Triangle3 = DistancePoint3Triangle3<float>;
    using DoubleDistancePoint3Triangle3 = DistancePoint3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_RIANGLE3_H
