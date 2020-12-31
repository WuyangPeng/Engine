///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 11:04)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RAY3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Ray3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Ray3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Ray3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Ray3 = Ray3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Ray3(const Vector3D& point, const Ray3& ray) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Ray3 GetRay() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Ray3 m_Ray;
    };

    using FloatDistancePoint3Ray3 = DistancePoint3Ray3<float>;
    using DoubleDistancePoint3Ray3 = DistancePoint3Ray3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT2_RAY2_H
