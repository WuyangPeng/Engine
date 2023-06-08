///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:44)

#ifndef MATHEMATICS_OBJECTS_3D_ELLIPSOID3_COEFFICIENTS_H
#define MATHEMATICS_OBJECTS_3D_ELLIPSOID3_COEFFICIENTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Ellipsoid3Coefficients final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipsoid3Coefficients<Real>;
        using Math = Math<Real>;
        using Vector3 = Vector3<Real>;
        using Matrix3 = Matrix3<Real>;
        using CoefficientsType = std::vector<Real>;

    public:
        Ellipsoid3Coefficients(const Matrix3& matrix, const Vector3& vector, Real constants);

        explicit Ellipsoid3Coefficients(const CoefficientsType& coefficient);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Matrix3 GetMatrix() const noexcept;
        NODISCARD Vector3 GetVector() const noexcept;
        NODISCARD Real GetConstants() const noexcept;
        NODISCARD CoefficientsType GetCoefficients() const;

        NODISCARD constexpr static int GetCoefficientsSize() noexcept
        {
            return 10;
        }

    private:
        CoefficientsType coefficients;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Ellipsoid3Coefficients<Real>& lhs, const Ellipsoid3Coefficients<Real>& rhs, const Real epsilon);

    using Ellipsoid3CoefficientsF = Ellipsoid3Coefficients<float>;
    using Ellipsoid3CoefficientsD = Ellipsoid3Coefficients<double>;
}

#endif  // MATHEMATICS_OBJECTS_3D_ELLIPSOID3_COEFFICIENTS_H
