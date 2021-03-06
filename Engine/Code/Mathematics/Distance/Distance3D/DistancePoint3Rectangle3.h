///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.6.0.0 (2020/12/14 16:00)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Rectangle3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Rectangle3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Rectangle3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Vector2D = Vector2D<Real>;
        using Rectangle3 = Rectangle3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Rectangle3(const Vector3D& point, const Rectangle3& rectangle) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Rectangle3 GetRectangle() const noexcept;

        [[nodiscard]] const DistanceResult GetSquared() const override;

        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

        // 有关最接近的矩形点的信息。
        Real GetRectangleCoordinate(int index) const;

    private:
        Vector3D m_Point;
        Rectangle3 m_Rectangle;

        // 有关最接近的矩形点的信息
        // closest1 = rect.center + param0 * rect.dir0 + param1 * rect.dir1
        mutable Vector2D m_RectCoord;
    };

    using FloatDistancePoint3Rectangle3 = DistancePoint3Rectangle3<float>;
    using DoubleDistancePoint3Rectangle3 = DistancePoint3Rectangle3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_RECTANGLE3_H
