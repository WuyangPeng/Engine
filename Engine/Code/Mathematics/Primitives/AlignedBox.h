/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.6 (2024/02/23 09:19)

#ifndef MATHEMATICS_PRIMITIVES_ALIGNED_BOX_H
#define MATHEMATICS_PRIMITIVES_ALIGNED_BOX_H

#include "Mathematics/MathematicsDll.h"

#include "AlignedBoxCentered.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/Vector/Vector.h"

/// 该框与标准坐标轴对齐，这使我们能够使用沿每个轴的最小值和最大值来表示它。
/// 一些算法更喜欢用于定向框的居中表示。
/// 中心为C，范围为每个坐标轴方向上的一半长度。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class AlignedBox
    {
    public:
        using ClassType = AlignedBox<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using AlignedBoxCenteredType = AlignedBoxCentered<N, Real>;
        using VerticesType = std::array<Vector, (1 << N)>;

    public:
        /// 默认构造函数将最小值设置为-1，将最大值设置为+1。
        AlignedBox() noexcept requires(N == 2);
        AlignedBox() noexcept requires(N == 3);

        /// 请确保所有i的inMin[i] <= inMax[i]。
        AlignedBox(const Vector& inMin, const Vector& inMax);

        CLASS_INVARIANT_DECLARE;

        NODISCARD Vector GetMin() const noexcept;
        NODISCARD Vector GetMax() const noexcept;

        void Set(const Vector& aMin, const Vector& aMax);

        /// 计算居中表示。
        /// 注意：如果设置最小值和最大值，计算C和范围，
        /// 然后重新计算最小值和最高值，则数值舍入误差可能会导致与开始时不同的结果。
        NODISCARD AlignedBoxCenteredType GetCenteredForm() const;

        /// 计算长方体的顶点。
        /// 如果索引i具有比特模式i = b[N-1]...b[0]，则索引i处的角是vertex[i]，
        /// 其中当b[d] = 0时顶点vertex[i][d] = min[d] ，
        /// 或者当b[d] = 1时顶点vertex[i][d] = max[d]。
        NODISCARD VerticesType GetVertices() const;

    private:
        /// 要求min[i] <= max[i]。
        Vector min;
        Vector max;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const AlignedBox<N, Real>& lhs, const AlignedBox<N, Real>& rhs);

    /// 为方便起见，请使用模板别名。
    template <typename T>
    using AlignedBox2 = AlignedBox<2, T>;

    template <typename T>
    using AlignedBox3 = AlignedBox<3, T>;
}

#endif  // MATHEMATICS_OBJECTS_3D_BOX3_H
