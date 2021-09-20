///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 13:03)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "CoreTools/Helper/Export/PerformanceUnsharedExportMacro.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class Ellipsoid3CoefficientsImpl;

    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Ellipsoid3CoefficientsImpl<float>>;
    template class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Ellipsoid3CoefficientsImpl<double>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE CoreTools::PerformanceUnsharedImpl<Ellipsoid3CoefficientsImpl<Real>>;

    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Ellipsoid3Coefficients final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using Ellipsoid3CoefficientsImpl = Ellipsoid3CoefficientsImpl<Real>;
      
        TYPE_DECLARE(Ellipsoid3Coefficients);
        using PackageType = CoreTools::PerformanceUnsharedImpl<ImplType>;
        using ClassShareType = typename PackageType::ClassShareType;
        using Vector3D = Vector3D<Real>;
        using Matrix3 = Matrix3<Real>;
        using CoefficientsType = std::vector<Real>;

        constexpr static auto sm_CoefficientsSize = 6;

    public:
        Ellipsoid3Coefficients(const Matrix3& matrix, const Vector3D& vector, Real constants);

        explicit Ellipsoid3Coefficients(const CoefficientsType& coefficient);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Matrix3 GetMatrix() const noexcept;
        [[nodiscard]] const Vector3D GetVector() const noexcept;
        [[nodiscard]] Real GetConstants() const noexcept;
        [[nodiscard]] const CoefficientsType GetCoefficients() const;

    private:
        PackageType impl;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Ellipsoid3Coefficients<Real>& lhs, const Ellipsoid3Coefficients<Real>& rhs, const Real epsilon);

    using FloatEllipsoid3Coefficients = Ellipsoid3Coefficients<float>;
    using DoubleEllipsoid3Coefficients = Ellipsoid3Coefficients<double>;
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_H
