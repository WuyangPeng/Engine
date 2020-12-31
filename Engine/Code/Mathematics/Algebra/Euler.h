///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/05 17:06)

#ifndef MATHEMATICS_ALGEBRA_EULER_H
#define MATHEMATICS_ALGEBRA_EULER_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Euler final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Euler<Real>;
        using Math = Math<Real>;

    public:
        Euler(ExtractEulerResultType type, ExtractEulerResultOrder order,
              Real x0Angle, Real y0Angle, Real z0Angle,
              Real x1Angle, Real y1Angle, Real z1Angle) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] ExtractEulerResultType GetType() const noexcept;
        [[nodiscard]] ExtractEulerResultOrder GetOrder() const noexcept;
        [[nodiscard]] Real GetX0Angle() const noexcept;
        [[nodiscard]] Real GetY0Angle() const noexcept;
        [[nodiscard]] Real GetZ0Angle() const noexcept;
        [[nodiscard]] Real GetX1Angle() const noexcept;
        [[nodiscard]] Real GetY1Angle() const noexcept;
        [[nodiscard]] Real GetZ1Angle() const noexcept;
        [[nodiscard]] Real GetAngle(MatrixRotationAxis axisIndex) const noexcept;
        void SetAngle(MatrixRotationAxis axisIndex, Real angle) noexcept;

    private:
        ExtractEulerResultType m_Type;
        ExtractEulerResultOrder m_Order;
        Real m_X0Angle;
        Real m_Y0Angle;
        Real m_Z0Angle;
        Real m_X1Angle;
        Real m_Y1Angle;
        Real m_Z1Angle;
    };

    using FloatEuler = Euler<float>;
    using DoubleEuler = Euler<double>;
}

#endif  // MATHEMATICS_ALGEBRA_EULER_H
