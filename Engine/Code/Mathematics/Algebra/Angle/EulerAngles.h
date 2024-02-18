///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.5 (2024/02/02 13:47)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_EULER_ANGLES_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_EULER_ANGLES_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"

#include <array>

namespace Mathematics::Algebra
{
    template <typename Real>
    requires(std::is_arithmetic_v<Real>)
    class EulerAngles
    {
    public:
        using ClassType = EulerAngles<Real>;

    public:
        EulerAngles() noexcept;
        EulerAngles(int axis0, int axis1, int axis2, Real angle0, Real angle1, Real angle2) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD EulerResult GetEulerResult() const noexcept;
        NODISCARD int GetAxis(int index) const;
        NODISCARD Real GetAngle(int index) const;

        void SetEulerResult(EulerResult eulerResult) noexcept;
        void SetAxis(int aAxis0, int aAxis1, int aAxis2) noexcept;
        void SetAngle(Real aAngle0, Real aAngle1, Real aAngle2) noexcept;

    private:
        using AxisType = std::array<int, 3>;
        using AngleType = std::array<Real, 3>;

    private:
        AxisType axis;
        AngleType angle;

        // 此成员是在从旋转矩阵、四元数或轴角度转换的过程中设置的。
        EulerResult result;
    };
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_EULER_ANGLES_H
