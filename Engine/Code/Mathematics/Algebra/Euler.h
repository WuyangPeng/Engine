///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/05/31 15:35)

#ifndef MATHEMATICS_ALGEBRA_EULER_H
#define MATHEMATICS_ALGEBRA_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Euler final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Euler<Real>;
        using Math = Math<Real>;

    public:
        Euler(ExtractEulerResultType type,
              ExtractEulerResultOrder order,
              Real x0Angle,
              Real y0Angle,
              Real z0Angle,
              Real x1Angle,
              Real y1Angle,
              Real z1Angle) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD ExtractEulerResultType GetType() const noexcept;
        NODISCARD ExtractEulerResultOrder GetOrder() const noexcept;
        NODISCARD Real GetX0Angle() const noexcept;
        NODISCARD Real GetY0Angle() const noexcept;
        NODISCARD Real GetZ0Angle() const noexcept;
        NODISCARD Real GetX1Angle() const noexcept;
        NODISCARD Real GetY1Angle() const noexcept;
        NODISCARD Real GetZ1Angle() const noexcept;
        NODISCARD Real GetAngle(MatrixRotationAxis axisIndex) const noexcept;
        void SetAngle(MatrixRotationAxis axisIndex, Real angle) noexcept;

    private:
        ExtractEulerResultType extractEulerResultType;
        ExtractEulerResultOrder order;
        Real x0Angle;
        Real y0Angle;
        Real z0Angle;
        Real x1Angle;
        Real y1Angle;
        Real z1Angle;
    };

    using EulerF = Euler<float>;
    using EulerD = Euler<double>;
}

#endif  // MATHEMATICS_ALGEBRA_EULER_H
