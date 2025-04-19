///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/23 14:51)

#ifndef MATHEMATICS_PRIMITIVES_RAY_H
#define MATHEMATICS_PRIMITIVES_RAY_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector.h"
#include "Mathematics/Base/Math.h"

namespace Mathematics
{
    /// 射线表示为P+t*D，其中P是射线原点，
    /// D是单位长度方向矢量，t>=0。
    /// 用户必须确保D为单位长度。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Ray
    {
    public:
        using ClassType = Ray<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;

    public:
        /// 默认构造函数将原点设置为(0,...,0)，并将射线方向设置为 (1,0,...,0)。
        Ray() noexcept requires(N == 2);
        Ray() noexcept requires(N == 3);

        Ray(const Vector& origin, const Vector& direction) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetOrigin() const noexcept;
        NODISCARD Vector GetDirection() const noexcept;

        void SetOrigin(const Vector& aOrigin) noexcept;
        void SetDirection(const Vector& aDirection) noexcept;

    private:
        /// 方向必须是单位长度。
        Vector origin;
        Vector direction;
    };

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Ray<N, Real>& lhs, const Ray<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Ray<N, Real>& lhs, const Ray<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Ray<N, Real>& lhs, const Ray<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Ray<N, Real>& lhs, const Ray<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Ray<N, Real>& lhs, const Ray<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Ray<N, Real>& lhs, const Ray<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，请使用模板别名。
        template <typename Real>
        using Ray2 = Ray<2, Real>;

        template <typename Real>
        using Ray3 = Ray<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_RAY_H
