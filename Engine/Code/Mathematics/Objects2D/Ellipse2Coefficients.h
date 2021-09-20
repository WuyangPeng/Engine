///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 10:51)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Ellipse2CoefficientsImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Ellipse2CoefficientsImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Ellipse2CoefficientsImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Ellipse2CoefficientsImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipse2Coefficients final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Ellipse2CoefficientsImpl = Ellipse2CoefficientsImpl<Real>;
       
        TYPE_DECLARE(Ellipse2Coefficients);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Vector2D = Vector2D<Real>;
        using CoefficientsType = std::vector<Real>;

        constexpr static auto sm_CoefficientsSize = 6;

    public:
        Ellipse2Coefficients(const Matrix2& matrix, const Vector2D& vector, Real constants);

        explicit Ellipse2Coefficients(const CoefficientsType& coefficient);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Matrix2 GetMatrix() const;
        [[nodiscard]] const Vector2D GetVector() const;
        [[nodiscard]] Real GetConstants() const;
        [[nodiscard]] const CoefficientsType GetCoefficients() const;

    private:
        PackageType impl;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Ellipse2Coefficients<Real>& lhs, const Ellipse2Coefficients<Real>& rhs, const Real epsilon);

    using FloatEllipse2Coefficients = Ellipse2Coefficients<float>;
    using DoubleEllipse2Coefficients = Ellipse2Coefficients<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_H
