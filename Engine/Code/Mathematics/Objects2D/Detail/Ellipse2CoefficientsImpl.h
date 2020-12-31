///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/16 10:36)

#ifndef MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_IMPL_H
#define MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE Ellipse2CoefficientsImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Ellipse2CoefficientsImpl<Real>;
        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Vector2D = Vector2D<Real>;
        using CoefficientsType = std::vector<Real>;

    public:
        Ellipse2CoefficientsImpl(const Matrix2& matrix, const Vector2D& vector, Real constants);

        explicit Ellipse2CoefficientsImpl(const CoefficientsType& coefficient);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Matrix2 GetMatrix() const;
        [[nodiscard]] const Vector2D GetVector() const;
        [[nodiscard]] Real GetConstants() const;
        [[nodiscard]] const CoefficientsType GetCoefficients() const;

    private:
        constexpr static auto sm_CoefficientsSize = 6;

    private:
        CoefficientsType m_Coefficients;
    };
}

#endif  // MATHEMATICS_OBJECTS2D_ELLIPSE2_COEFFICIENTS_IMPL_H
