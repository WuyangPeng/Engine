///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.3 (2020/11/13 16:14)

#ifndef MATHEMATICS_OBJECTS2D_LINE2_H
#define MATHEMATICS_OBJECTS2D_LINE2_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector2D.h"
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
        using Vector2D = Vector2D<Real>;
        using Vector2DTools = Vector2DTools<Real>;

    public:
        // 线表示为P+t*D，其中P是线原点，D是单位长度的方向向量，t是任意实数。
        // 用户必须确保D是单位长度。

        Line2(const Vector2D& origin, const Vector2D& direction, const Real epsilon = Math::GetZeroTolerance()) noexcept;

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const Vector2D GetOrigin() const noexcept;
        [[nodiscard]] const Vector2D GetDirection() const noexcept;

        [[nodiscard]] const Line2 GetMove(Real t, const Vector2D& velocity) const;

        void SetOrigin(const Vector2D& origin) noexcept;
        void SetDirection(const Vector2D& direction) noexcept;

        // Line表示Dot(N,X) = c。N表示单位法线，c表示线的常量c，X是线上的任意点。
        [[nodiscard]] Real DotProduct() const noexcept;

    private:
        Vector2D m_Origin;
        Vector2D m_Direction;
        Real m_Epsilon;
    };

    template <typename Real>
    [[nodiscard]] bool Approximate(const Line2<Real>& lhs, const Line2<Real>& rhs, const Real epsilon);

    // 调试输出
    template <typename Real>
    std::ostream& operator<<(std::ostream& outFile, const Line2<Real>& line);

    using FloatLine2 = Line2<float>;
    using DoubleLine2 = Line2<double>;
}

#endif  // MATHEMATICS_OBJECTS2D_LINE2_H
