///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:45)

#ifndef MATHEMATICS_ALGEBRA_AXIS_ANGLE_H
#define MATHEMATICS_ALGEBRA_AXIS_ANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE AxisAngle final
    {
    public:
        using ClassType = AxisAngle<Real>;

        using Vector3 = Vector3<Real>;

    public:
        AxisAngle(Real angle, const Vector3& axis) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetAngle() const noexcept;
        NODISCARD Vector3 GetAxis() const noexcept;

    private:
        Real angle;
        Vector3 axis;
    };

    using Matrix3ExtractF = AxisAngle<float>;
    using Matrix3ExtractD = AxisAngle<double>;
}

#endif  // MATHEMATICS_ALGEBRA_AXIS_ANGLE_H
