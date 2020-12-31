///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/15 16:14)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Triangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceTriangle3Triangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceTriangle3Triangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Triangle3 = Triangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceTriangle3Triangle3(const Triangle3& lhsTriangle, const Triangle3& rhsTriangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Triangle3 GetLhsTriangle() const noexcept;
        [[nodiscard]] const Triangle3 GetRhsTriangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        [[nodiscard]] Real GetTriangleBary0(int index) const;
        [[nodiscard]] Real GetTriangleBary1(int index) const;

    private:
        Triangle3 m_LhsTriangle;
        Triangle3 m_RhsTriangle;

        mutable Vector3D m_TriangleBary0;  // closest0 = sum_{i=0}^2 bary0[i]*vertex0[i]
        mutable Vector3D m_TriangleBary1;  // closest1 = sum_{i=0}^2 bary1[i]*vertex1[i]
    };

    using FloatDistanceTriangle3Triangle3 = DistanceTriangle3Triangle3<float>;
    using DoubleDistanceTriangle3Triangle3 = DistanceTriangle3Triangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_TRIANGLE3_TRIANGLE3_H
