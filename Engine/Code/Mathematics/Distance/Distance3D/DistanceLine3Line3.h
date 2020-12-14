///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.5 (2020/12/09 16:44)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistanceLine3Line3 : public DistanceBase<Real, Vector3D<Real>>
    {
    public:
        using ClassType = DistanceLine3Line3<Real>;
        using Vector3D = Vector3D<Real>;
        using ParentType = DistanceBase<Real, Vector3D>;
        using Line3 = Line3<Real>;
        using Vector3DTools = Vector3DTools<Real>;
        using Math = typename ParentType::Math;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Line3(const Line3& lhsLine, const Line3& rhsLine) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] const Line3 GetLhsLine() const noexcept;
        [[nodiscard]] const Line3 GetRhsLine() const noexcept;

        // 静态距离查询。
        [[nodiscard]] const DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        [[nodiscard]] const DistanceResult GetSquared(Real t, const Vector3D& lhsVelocity, const Vector3D& rhsVelocity) const override;

    private:
        Line3 m_LhsLine;
        Line3 m_RhsLine;
    };

    using FloatDistanceLine3Line3 = DistanceLine3Line3<float>;
    using DoubleDistanceLine3Line3 = DistanceLine3Line3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_LINE3_H
