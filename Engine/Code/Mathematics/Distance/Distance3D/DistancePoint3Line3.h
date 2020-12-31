///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/10 10:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Line3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistancePoint3Line3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistancePoint3Line3(const Vector3D& point, const Line3& line) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Vector3D GetPoint() const noexcept;
        [[nodiscard]] const Line3 GetLine() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Vector3D m_Point;
        Line3 m_Line;
    };

    using FloatDistancePoint3Line3 = DistancePoint3Line3<float>;
    using DoubleDistancePoint3Line3 = DistancePoint3Line3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H
