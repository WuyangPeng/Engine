///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/17 10:45)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_IMPL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Ellipsoid3CoefficientsImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipsoid3CoefficientsImpl<Real>;
        using Math = Math<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector3D = Vector3D<Real>;
        using CoefficientsType = std::vector<Real>;

    public:
        Ellipsoid3CoefficientsImpl(const Matrix3& matrix, const Vector3D& vector, Real constants);

        explicit Ellipsoid3CoefficientsImpl(const CoefficientsType& coefficient);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Matrix3 GetMatrix() const noexcept;
        [[nodiscard]] const Vector3D GetVector() const noexcept;
        [[nodiscard]] Real GetConstants() const noexcept;
        [[nodiscard]] const CoefficientsType GetCoefficients() const;

        [[nodiscard]] constexpr static int GetCoefficientsSize() noexcept
        {
            return 10;
        }

    private:
        CoefficientsType m_Coefficients;
    };
}

#endif  // MATHEMATICS_OBJECTS3D_ELLIPSOID3_COEFFICIENTS_IMPL_H
