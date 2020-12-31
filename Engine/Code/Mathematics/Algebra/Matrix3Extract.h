///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/09 9:48)

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
        using Vector3D = Vector3D<Real>;

    public:
        Matrix3Extract(Real angle, const Vector3D& axis) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] Real GetAngle() const noexcept;
        [[nodiscard]] const Vector3D GetAxis() const noexcept;

    private:
        Real m_Angle;
        Vector3D m_Axis;
    };

    using FloatMatrix3Extract = Matrix3Extract<float>;
    using DoubleMatrix3Extract = Matrix3Extract<double>;
}

#endif  // MATHEMATICS_ALGEBRA_MATRIX3_EXTRACT_H
