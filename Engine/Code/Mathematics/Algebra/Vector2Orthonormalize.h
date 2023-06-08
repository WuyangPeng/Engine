///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/01 10:07)

#ifndef MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H
#define MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <type_traits>

namespace Mathematics
{
    template <typename Real, bool Robust = false>
    requires std::is_arithmetic_v<Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Vector2Orthonormalize final
    {
    public:
        using ClassType = Vector2Orthonormalize<Real, Robust>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // Gram-Schmidt正交化.
        // 以线性无关的向量U和V，来计算一个正交组（单位长度，相互垂直）。
        Vector2Orthonormalize(const Vector2& lhs, const Vector2& rhs, const Real epsilon = Math::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

        NODISCARD const Vector2 GetUVector() const noexcept;
        NODISCARD const Vector2 GetVVector() const noexcept;

    private:
        void Generate();

    private:
        Vector2 uVector;
        Vector2 vVector;
        Real epsilon;
    };

    using Vector2OrthonormalizeF = Vector2Orthonormalize<float>;
    using Vector2OrthonormalizeD = Vector2Orthonormalize<double>;
}

#endif  // MATHEMATICS_ALGEBRA_VECTOR2_ORTHONORMALIZE_H
