///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 12:52)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DOrthonormalBasis final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2DOrthonormalBasis<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        explicit Vector2DOrthonormalBasis(const Vector2D& nonzeroVector, const Real epsilon = Math::GetZeroTolerance()) noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetUVector() const noexcept;
        [[nodiscard]] const Vector2D GetVVector() const noexcept;

    private:
        void Generate() noexcept(g_Assert < 1 || g_MathematicsAssert < 1);

    private:
        Vector2D m_UVector;
        Vector2D m_VVector;
        Real m_Epsilon;
    };

    using FloatVector2DOrthonormalBasis = Vector2DOrthonormalBasis<float>;
    using DoubleVector2DOrthonormalBasis = Vector2DOrthonormalBasis<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMA_BASIS_H
