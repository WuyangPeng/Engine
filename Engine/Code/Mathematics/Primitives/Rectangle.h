///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/26 13:58)

#ifndef MATHEMATICS_PRIMITIVES_RECTANGLE_H
#define MATHEMATICS_PRIMITIVES_RECTANGLE_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 点R(s0,s1) = C + s0*A0 + s1*A1，
/// 其中C是矩形的中心，
/// A0和A1是单位长度且垂直的轴。
/// 参数s0和s1受到约束，|s0| <= e0 和|s1| <= e1，
/// 其中e0 > 0和e1 > 0 是矩形的范围。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class Rectangle
    {
    public:
        using ClassType = Rectangle<N, Real>;

        using Math = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using Vector2 = Algebra::Vector<2, Real>;
        using Container = std::array<Vector, 2>;
        using VerticesType = std::array<Vector, 4>;

    public:
        /// 默认构造函数将原点设置为(0,...,0)，
        /// 将轴A0设置为(1,0,...,0)，
        /// 将轴A1设置为(0,1,0,...0)，
        /// 并将两个范围都设置为1。
        Rectangle() noexcept requires(N == 2);
        Rectangle() noexcept requires(N == 3);

        Rectangle(const Vector& center,
                  const Container& axis,
                  const Vector2& extent) noexcept;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetCenter() const noexcept;
        NODISCARD Container GetAxis() const noexcept;
        NODISCARD Vector2 GetExtent() const noexcept;

        NODISCARD Vector GetAxis(int index) const;
        NODISCARD Real GetExtent(int index) const;

        void SetCenter(const Vector& aCenter) noexcept;
        void SetAxis(const Container& aAxis) noexcept;
        void SetExtent(const Vector2& aExtent) noexcept;

        /// 计算矩形的顶点。如果索引i的位模式为i = b[1]b[0]，
        /// 那么vertex[i] = center + sum_{d=0}^{1} sign[d] * extent[d] * axis[d]
        /// 其中sign[d] = 2*b[d] - 1
        NODISCARD VerticesType GetVertices() const;

    private:
        Vector center;
        Container axis;
        Vector2 extent;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const Rectangle<N, Real>& lhs, const Rectangle<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Rectangle2 = Rectangle<2, Real>;

        template <typename Real>
        using Rectangle3 = Rectangle<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_RECTANGLE_H
