/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/12 11:17)

#ifndef MATHEMATICS_OBJECTS_2D_LINE2_H
#define MATHEMATICS_OBJECTS_2D_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2.h"
#include "Mathematics/Base/MathDetail.h"

#include <iosfwd>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE Line2 final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = Line2<Real>;

        using MathType = Math<Real>;
        using Vector2Type = Vector2<Real>;
        using Vector2ToolsType = Vector2Tools<Real>;

    public:
        // 线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t是任意实数。
        // 用户必须确保D是单位长度。

        Line2(const Vector2Type& origin, const Vector2Type& direction, Real epsilon = MathType::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector2Type GetOrigin() const noexcept;
        NODISCARD Vector2Type GetDirection() const noexcept;

        NODISCARD Line2 GetMove(Real t, const Vector2Type& velocity) const;

        void SetOrigin(const Vector2Type& newOrigin) noexcept;
        void SetDirection(const Vector2Type& newDirection) noexcept;

        // Line表示Dot(N,X) = c。N表示单位法线，c表示线的常量c，X是线上的任意点。
        NODISCARD Real DotProduct() const noexcept;

    private:
        Vector2Type origin;
        Vector2Type direction;
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
