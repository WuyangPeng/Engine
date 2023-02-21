///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/01 23:52)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2OrthonormalBasis final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2OrthonormalBasis<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        explicit Vector2OrthonormalBasis(const Vector2& nonzeroVector, const Real epsilon = Math::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetUVector() const noexcept;
        NODISCARD Vector2 GetVVector() const noexcept;

    private:
        void Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1);

    private:
        Vector2 uVector;
        Vector2 vVector;
        Real epsilon;
    };

    using Vector2OrthonormalBasisF = Vector2OrthonormalBasis<float>;
    using Vector2OrthonormalBasisD = Vector2OrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMA_BASIS_H
