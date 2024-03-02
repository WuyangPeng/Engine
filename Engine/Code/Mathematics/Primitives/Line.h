///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 14:51)

#ifndef MATHEMATICS_PRIMITIVES_LINE_H
#define MATHEMATICS_PRIMITIVES_LINE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector.h"
#include "Mathematics/Base/Math.h"

namespace Mathematics
{
    /// 该直线由P+t*D表示，其中P是原点，
    /// D是单位长度方向矢量，t是任意实数。
    /// 用户必须确保D为单位长度。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Line
    {
    public:
        using ClassType = Line<N, Real>;

        using Math = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;

    public:
        /// 默认构造函数将原点设置为(0,...,0)，并将线方向设置为 (1,0,...,0)。
        Line() noexcept requires(N == 2);
        Line() noexcept requires(N == 3);

        Line(const Vector& origin, const Vector& direction) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetOrigin() const noexcept;
        NODISCARD Vector GetDirection() const noexcept;

        NODISCARD void SetOrigin(const Vector& aOrigin) noexcept;
        NODISCARD void SetDirection(const Vector& aDirection) noexcept;

    private:
        /// 方向必须是单位长度。
        Vector origin;
        Vector direction;
    };

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Line<N, Real>& lhs, const Line<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Line<N, Real>& lhs, const Line<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Line<N, Real>& lhs, const Line<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Line<N, Real>& lhs, const Line<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Line<N, Real>& lhs, const Line<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Line<N, Real>& lhs, const Line<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，请使用模板别名。
        template <typename Real>
        using Line2 = Line<2, Real>;

        template <typename Real>
        using Line3 = Line<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_LINE_H
