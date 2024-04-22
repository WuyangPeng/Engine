///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 16:05)

#ifndef MATHEMATICS_PRIMITIVES_ORIENTED_BOX_H
#define MATHEMATICS_PRIMITIVES_ORIENTED_BOX_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 长方体具有中心C、轴方向U[i]和范围e[i]。
/// 集合{U[0],...,U[N-1]}是正交的，这意味着向量是单位长度的并且相互垂直。
/// 范围是非负的；零是允许的，这意味着长方体在相应的方向上退化。
/// 点X在框坐标中表示为X = C + y[0]*U[0] + y[1]*U[1]。
/// 对于所有i，每当 |y[i]| <= e[i]时，该点都在框内或框上。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class OrientedBox
    {
    public:
        using ClassType = OrientedBox<N, Real>;

        using Math = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using AxisType = std::array<Vector, N>;
        using VertexType = std::array<Vector, (1 << N)>;

    public:
        /// 默认构造函数将中心设置为(0,...,0)，
        /// 将轴d设置为Vector<N,T>::Unit(d)，
        /// 将范围d设置为+1。
        OrientedBox() noexcept requires(N == 2);
        OrientedBox() noexcept requires(N == 3);

        OrientedBox(const Vector& center, const AxisType& axis, const Vector& extent) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetCenter() const noexcept;
        void SetCenter(const Vector& aCenter) noexcept;

        NODISCARD AxisType GetAxis() const noexcept;
        void SetAxis(const AxisType& aAxis) noexcept;
        NODISCARD Vector GetAxis(int index) const;
        void SetAxis(int index, const Vector& aAxis);

        NODISCARD Vector GetExtent() const noexcept;
        void SetExtent(const Vector& aExtent) noexcept;
        NODISCARD Real GetExtent(int index) const;
        void SetExtent(int index, Real aExtent);

        /// 计算长方体的顶点。
        /// 如果索引i具有比特模式i = b[N-1]...b[0]，
        /// 则vertex[i] = center + sum_{d=0}^{N-1} sign[d] * extent[d] * axis[d]，
        /// 其中sign[d] = 2*b[d] - 1。
        NODISCARD VertexType GetVertices() const;

    private:
        /// 要求 extent[i] >= 0.
        Vector center;
        AxisType axis;
        Vector extent;
    };

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const OrientedBox<N, Real>& lhs, const OrientedBox<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using OrientedBox2 = OrientedBox<2, Real>;

        template <typename Real>
        using OrientedBox3 = OrientedBox<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_ORIENTED_BOX_H
