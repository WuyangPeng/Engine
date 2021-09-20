///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.2 (2020/11/12 14:26)

#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2D.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2DOrthonormalize final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Vector2DOrthonormalize<Real>;
        using Math = Math<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // Gram-Schmidt正交化.
        // 以线性无关的向量U和V，来计算一个正交组（单位长度，相互垂直）。
        Vector2DOrthonormalize(const Vector2D& lhs, const Vector2D& rhs, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetUVector() const noexcept;
        [[nodiscard]] const Vector2D GetVVector() const noexcept;

    private:
        void Generate();

    private:
        Vector2D m_UVector;
        Vector2D m_VVector;
        Real m_Epsilon;
    };

    using FloatVector2DOrthonormalize = Vector2DOrthonormalize<float>;
    using DoubleVector2DOrthonormalize = Vector2DOrthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR_2D_ORTHONORMALIZE_H
