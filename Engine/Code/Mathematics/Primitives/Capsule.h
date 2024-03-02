///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 14:09)

#ifndef MATHEMATICS_PRIMITIVES_CAPSULE_H
#define MATHEMATICS_PRIMITIVES_CAPSULE_H

#include "Mathematics/MathematicsDll.h"

#include "Segment.h"

/// 胶囊是一组与线段等距的点，公共距离称为半径。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Capsule
    {
    public:
        using ClassType = Capsule<N, Real>;

        using Math = Math<Real>;
        using Segment = Segment<N, Real>;

    public:
        /// 默认构造函数将线段设置为具有端点p0 = (-1,0,...,0)和p1 = (1,0,...,0)，半径为1。
        Capsule() noexcept;
        Capsule(const Segment& segment, Real radius) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Segment GetSegment() const noexcept;
        void SetSegment(const Segment& aSegment) noexcept;
        NODISCARD Real GetRadius() const noexcept;
        void SetRadius(Real aRadius) noexcept;

    private:
        Segment segment;
        Real radius;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Capsule<N, Real>& lhs, const Capsule<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Capsule3 = Capsule<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_CAPSULE_H
