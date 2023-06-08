///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 15:14)

#ifndef MATHEMATICS_OBJECTS_2D_LINE2_H
#define MATHEMATICS_OBJECTS_2D_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>
#include <type_traits>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line2<Real>;
        using Math = Math<Real>;
        using Vector2 = Vector2<Real>;
        using Vector2Tools = Vector2Tools<Real>;

    public:
        // 线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t是任意实数。
        // 用户必须确保D是单位长度。

        Line2(const Vector2& origin, const Vector2& direction, Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2 GetOrigin() const noexcept;
        NODISCARD Vector2 GetDirection() const noexcept;

        NODISCARD Line2 GetMove(Real t, const Vector2& velocity) const;

        void SetOrigin(const Vector2& newOrigin) noexcept;
        void SetDirection(const Vector2& newDirection) noexcept;

        // Line表示Dot(N,X) = c。N表示单位法线，c表示线的常量c，X是线上的任意点。
        NODISCARD Real DotProduct() const noexcept;

    private:
        Vector2 origin;
        Vector2 direction;
        Real epsilon;
    };

    template <typename Real>
    NODISCARD bool Approximate(const Line2<Real>& lhs, const Line2<Real>& rhs, Real epsilon) noexcept(gAssert < 1 || gMathematicsAssert < 1);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line2<Real>& line);

    using Line2F = Line2<float>;
    using Line2D = Line2<double>;
}

#endif  // MATHEMATICS_OBJECTS_2D_LINE2_H
