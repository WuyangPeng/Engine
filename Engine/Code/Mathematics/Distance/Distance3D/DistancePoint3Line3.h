///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 17:10)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H
#define MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE DistancePoint3Line3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistancePoint3Line3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Line3 = Line3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistancePoint3Line3(const Vector3& point, const Line3& line) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD Vector3 GetPoint() const noexcept;
        NODISCARD Line3 GetLine() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 函数计算动态距离查询。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        Vector3 point;
        Line3 line;
    };

    using DistancePoint3Line3F = DistancePoint3Line3<float>;
    using DistancePoint3Line3D = DistancePoint3Line3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_POINT3_LINE3_H
