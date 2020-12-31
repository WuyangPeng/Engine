///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/14 16:26)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Tetrahedron3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Tetrahedron3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Tetrahedron3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Tetrahedron3 = Tetrahedron3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Tetrahedron3(const Vector3D& point, const Tetrahedron3& tetrahedron) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Tetrahedron3 GetTetrahedron() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Tetrahedron3 m_Tetrahedron;
    };

    using FloatDistancePoint3Tetrahedron3 = DistancePoint3Tetrahedron3<float>;
    using DoubleDistancePoint3Tetrahedron3 = DistancePoint3Tetrahedron3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_TETRAHEDRON3_H
