///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 15:50)

#ifndef MATHEMATICS_PRIMITIVES_HYPER_SPHERE_H
#define MATHEMATICS_PRIMITIVES_HYPER_SPHERE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class HyperSphere
    {
    public:
        using ClassType = HyperSphere<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;

    public:
        /// 默认构造函数将中心设置为(0,...,0)，将半径设置为1。
        HyperSphere() noexcept;

        HyperSphere(const Vector& center, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetCenter() const noexcept;
        NODISCARD Real GetRadius() const noexcept;
        void SetCenter(const Vector& aCenter) noexcept;
        void SetRadius(Real aRadius) noexcept;

    private:
        Vector center;
        Real radius;
    };

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const HyperSphere<N, Real>& lhs, const HyperSphere<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Circle2 = HyperSphere<2, Real>;

        template <typename Real>
        using Sphere3 = HyperSphere<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_HYPER_SPHERE_H
