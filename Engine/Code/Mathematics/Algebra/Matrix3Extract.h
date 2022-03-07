///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/07 16:55)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3Extract final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Matrix3Extract<Real>;
        using Vector3 = Vector3<Real>;

    public:
        Matrix3Extract(Real angle, const Vector3& axis) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Real GetAngle() const noexcept;
        NODISCARD Vector3 GetAxis() const noexcept;

    private:
        Real angle;
        Vector3 axis;
    };

    using Matrix3ExtractF = Matrix3Extract<float>;
    using Matrix3ExtractD = Matrix3Extract<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H
