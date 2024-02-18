/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/02/02 12:37)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// N=3或N=4的轴角度表示。
/// 当N=4时，轴必须是形式为(x,y,z,0)[三元组方向的仿射表示]的向量。
namespace Mathematics::Algebra
{
    template <int N, typename Real>
    requires(3 <= N && N <= 4 && std::is_arithmetic_v<Real>)
    class AxisAngle
    {
    public:
        using ClassType = AxisAngle<N, Real>;

        using Vector = Vector<N, Real>;

    public:
        AxisAngle() noexcept;
        AxisAngle(const Vector& axis, Real angle) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetAxis() const noexcept;
        NODISCARD Real GetAngle() const noexcept;

        void SetAxis(const Vector& aAxis) noexcept;
        void SetAngle(Real aAngle) noexcept;

    private:
        Vector axis;
        Real angle;
    };

}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_AXIS_ANGLE_H
