///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/26 15:15)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMAL_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMAL_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2OrthonormalBasis final
    {
    public:
        using ClassType = Vector2OrthonormalBasis<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;

    public:
        explicit Vector2OrthonormalBasis(const Vector2Type& nonzeroVector, Real epsilon = MathType::GetZeroTolerance()) noexcept(gAssert < 1 || gMathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2Type GetUVector() const noexcept;
        NODISCARD Vector2Type GetVVector() const noexcept;

    private:
        void Generate() noexcept(gAssert < 1 || gMathematicsAssert < 1);

    private:
        Vector2Type uVector;
        Vector2Type vVector;
        Real epsilon;
    };

    using Vector2OrthonormalBasisF = Vector2OrthonormalBasis<float>;
    using Vector2OrthonormalBasisD = Vector2OrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMAL_BASIS_H
