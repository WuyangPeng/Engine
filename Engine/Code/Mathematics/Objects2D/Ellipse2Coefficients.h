/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_ELLIPSE2_COEFFICIENTS_H
#define MATHEMATICS_OBJECTS_2D_ELLIPSE2_COEFFICIENTS_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Ellipse2Coefficients final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse2Coefficients<Real>;

        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Vector2 = Vector2<Real>;
        using CoefficientsType = std::vector<Real>;

        static constexpr auto coefficientsSize = 6;

    public:
        Ellipse2Coefficients(const Matrix2& matrix, const Vector2& vector, Real constants);

        explicit Ellipse2Coefficients(CoefficientsType coefficient) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Matrix2 GetMatrix() const;
        NODISCARD Vector2 GetVector() const;
        NODISCARD Real GetConstants() const;
        NODISCARD CoefficientsType GetCoefficients() const;

    private:
        CoefficientsType coefficients;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Ellipse2Coefficients<Real>& lhs, const Ellipse2Coefficients<Real>& rhs, Real epsilon);

    using Ellipse2CoefficientsF = Ellipse2Coefficients<float>;
    using Ellipse2CoefficientsD = Ellipse2Coefficients<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_ELLIPSE2_COEFFICIENTS_H
