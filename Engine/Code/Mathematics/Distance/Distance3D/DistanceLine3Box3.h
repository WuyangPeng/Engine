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
        using Vector3Type = Vector3<Real>;
        using ParentType = DistanceBase<Real, Vector3Type>;

        using Line3Type = Line3<Real>;
        using Box3Type = Box3<Real>;
        using Vector3ToolsType = Vector3Tools<Real>;
        using MathType = typename ParentType::MathType;
        using DistanceResult = typename ParentType::DistanceResultType;

    public:
        DistanceLine3Box3(const Line3Type& line, const Box3Type& box) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        // 对象访问。
        NODISCARD Line3Type GetLine() const noexcept;
        NODISCARD Box3Type GetBox() const noexcept;

        // 静态距离查询。
        NODISCARD DistanceResult GetSquared() const override;

        // 动态距离查询的函数计算。
        NODISCARD DistanceResult GetSquared(Real t, const Vector3Type& lhsVelocity, const Vector3Type& rhsVelocity) const override;

    private:
        NODISCARD Real Face(int i0, int i1, int i2, const Vector3Type& dir, const Vector3Type& pointMinusExtent, Real& lineParameter, Vector3Type& point) const;

        NODISCARD Real CaseNoZeros(const Vector3Type& direction, Real& lineParameter, Vector3Type& point) const;

        NODISCARD Real Case0(int i0, int i1, int i2, const Vector3Type& direction, Real& lineParameter, Vector3Type& point) const;

        NODISCARD Real Case00(int i0, int i1, int i2, const Vector3Type& direction, Real& lineParameter, Vector3Type& point) const;

        NODISCARD Real Case000(Vector3Type& point) const;

    private:
        Line3Type line;
        Box3Type box;
    };

    using DistanceLine3Box3F = DistanceLine3Box3<float>;
    using DistanceLine3Box3D = DistanceLine3Box3<double>;
}

#endif  // MATHEMATICS_DISTANCE_DISTANCE_LINE3_BOX3_H
