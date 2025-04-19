///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 16:30)

#ifndef MATHEMATICS_PRIMITIVES_TRIANGLE_H
#define MATHEMATICS_PRIMITIVES_TRIANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 三角形表示为三个顶点的阵列。
/// 尺寸N必须大于或等于2。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Triangle
    {
    public:
        using ClassType = Triangle<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using Container = std::array<Vector, 3>;

    public:
        /// 默认构造函数将顶点设置为(0,..,0), (1,0,...,0) 和 (0,1,0,...,0)。
        Triangle() noexcept requires(N == 2);
        Triangle() noexcept requires(N == 3);

        Triangle(const Vector& v0, const Vector& v1, const Vector& v2) noexcept;
        explicit Triangle(const Container& v) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool Equal(const Triangle& rhs) const;
        NODISCARD bool Less(const Triangle& rhs) const;

    private:
        Container v;
    };

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Triangle<N, Real>& lhs, const Triangle<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Triangle2 = Triangle<2, Real>;

        template <typename Real>
        using Triangle3 = Triangle<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_TRIANGLE_H
