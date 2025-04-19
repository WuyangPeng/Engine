///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 13:43)

#ifndef MATHEMATICS_PRIMITIVES_SEGMENT_H
#define MATHEMATICS_PRIMITIVES_SEGMENT_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 线段由(1-t)*P0 + t*P1表示，
/// 其中P0和P1是分段的端点，0 <= t <= 1。
/// 一些算法更喜欢与定义定向边界框的方式类似的居中表示。
/// 该表示为C + s*D，其中 C = (P0 + P1)/2 是线段的中心，
/// D = (P1 - P0)/|P1 - P0|是线段的单位长度方向矢量， |t| <= e。
/// 值e = |P1 - P0|/2是线段范围（或半径或半长度）。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Segment
    {
    public:
        using ClassType = Segment<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using SegmentType = std::array<Vector, 2>;

    public:
        /// 默认构造函数将p0设置为(-1,0,...,0)，将p1设置为(1,0,...,0)。
        /// 注意：如果设置p0和p1；计算C、D和e；
        /// 然后重新计算q0 = C-e*D 和 q1 = C+e*D，
        /// 数值舍入误差可能导致q0不完全等于p0和q1不完全等于p1。
        Segment() noexcept requires(N == 2);
        Segment() noexcept requires(N == 3);

        Segment(const Vector& p0, const Vector& p1) noexcept;
        explicit Segment(const SegmentType& p) noexcept;
        Segment(const Vector& center, const Vector& direction, Real extent);

        CLASS_INVARIANT_DECLARE;

        /// 通过居中形状进行操作。
        void SetCenteredForm(const Vector& center, const Vector& direction, Real extent);

        void GetCenteredForm(Vector& center, Vector& direction, Real& extent) const;

        NODISCARD bool Less(const Segment& rhs) const;
        NODISCARD bool Equal(const Segment& rhs) const;

    private:
        SegmentType p;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Segment<N, Real>& lhs, const Segment<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Segment2 = Segment<2, Real>;

        template <typename Real>
        using Segment3 = Segment<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_SEGMENT_H
