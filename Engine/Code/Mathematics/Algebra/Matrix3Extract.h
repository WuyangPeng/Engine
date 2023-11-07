///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 14:45)

#ifndef MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H
#define MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Matrix3Extract final
    {
    public:
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
