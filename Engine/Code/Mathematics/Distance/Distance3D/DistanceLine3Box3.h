///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 16:50)

#ifndef MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H
#define MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Distance/DistanceBase.h"
#include "Mathematics/Objects3D/Box3.h"
#include "Mathematics/Objects3D/Line3.h"

namespace Mathematics
{
    template <typename Real>
    class DistanceLine3Box3 : public DistanceBase<Real, Vector3<Real>>
    {
    public:
        using ClassType = DistanceLine3Box3<Real>;
        using Vector3 = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3>;

        using Line3 = Line3<Real>;
        using Box3 = Box3<Real>;
        using Vector3Tools = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResult;

    public:
        DistanceLine3Box3(const Line3& line, const Box3& box) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 对象访问。
        NODISCARD Line3 GetLine() const noexcept;
        NODISCARD Box3 GetBox() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 动态距离查询的函数计算。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3& lhsVelocity, const Vector3& rhsVelocity) const override;

    private:
        NODISCARD Real Face(int i0, int i1, int i2, const Vector3& dir, const Vector3& pointMinusExtent, Real& lineParameter, Vector3& point) const;

        NODISCARD Real CaseNoZeros(const Vector3& direction, Real& lineParameter, Vector3& point) const;

        NODISCARD Real Case0(int i0, int i1, int i2, const Vector3& direction, Real& lineParameter, Vector3& point) const;

        NODISCARD Real Case00(int i0, int i1, int i2, const Vector3& direction, Real& lineParameter, Vector3& point) const;

        NODISCARD Real Case000(Vector3& point) const;

    private:
        Line3 line;
        Box3 box;
    };

    using DistanceLine3Box3F = DistanceLine3Box3<float>;
    using DistanceLine3Box3D = DistanceLine3Box3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H
