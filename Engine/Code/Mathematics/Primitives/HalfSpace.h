///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/29 14:35)

#ifndef MATHEMATICS_PRIMITIVES_HALF_SPACE_H
#define MATHEMATICS_PRIMITIVES_HALF_SPACE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 半空间表示为Dot(N,X) >= c，
/// 其中N是单位长度法向量，c是平面常数，X是空间中的任何点。
/// 用户必须确保法向量为单位长度。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class HalfSpace
    {
    public:
        using ClassType = HalfSpace<N, Real>;

        using Math = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;

    public:
        /// 默认构造函数将法线设置为(0,...,0,1)，
        /// 将常量设置为零（半空间x[N-1] >= 0）。
        HalfSpace() noexcept requires(N == 3);

        /// 直接指定N和c。
        HalfSpace(const Vector& normal, Real constant) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetNormal() const noexcept;
        void SetNormal(const Vector& aNormal) noexcept;
        NODISCARD Real GetConstant() const noexcept;
        void SetConstant(Real aConstant) noexcept;

    private:
        Vector normal;
        Real constant;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const HalfSpace<N, Real>& lhs, const HalfSpace<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using HalfSpace3 = HalfSpace<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_HALF_SPACE_H
