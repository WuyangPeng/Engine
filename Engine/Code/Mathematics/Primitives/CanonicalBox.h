///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/02/28 13:23)

#ifndef MATHEMATICS_PRIMITIVES_CANONICAL_BOX_H
#define MATHEMATICS_PRIMITIVES_CANONICAL_BOX_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Vector/Vector.h"

/// 一个规范的盒子以原点为中心，并与标准的欧几里得基向量对齐。
/// 它具有E = (e[0],e[1],...,e[N-1]) ，其中e[i] >= 0对于所有 i。
/// 允许零的范围，意味着盒子在相应的方向上是退化的。
/// 一个盒子点是X = (x[0],x[1],...,x[N-1]) ，其中对于所有 i，|x[i]| <= e[i]。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class CanonicalBox
    {
    public:
        using ClassType = CanonicalBox<N, Real>;

        using Vector = Algebra::Vector<N, Real>;

        using VerticesType = std::array<Vector, (1 << N)>;

    public:
        /// 默认构造函数将所有成员设置为零。
        CanonicalBox() noexcept;
        explicit CanonicalBox(const Vector& extent) noexcept;

        CLASS_INVARIANT_DECLARE;

        /// 计算长方体的顶点。如果索引i具有位模式
        /// i = b[N-1]...b[0]，则索引i处的角为
        /// vertex[i] = center + sum_{d=0}^{N-1} sign[d]*extent[d]*axis[d]
        /// 其中sign[d] = 2*b[d] - 1。
        NODISCARD VerticesType GetVertices() const;

        NODISCARD Vector GetVector() const noexcept;

    private:
        /// 要求extent[i] >= 0。
        Vector extent;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const CanonicalBox<N, Real>& lhs, const CanonicalBox<N, Real>& rhs);

    /// 为方便起见，请使用模板别名。
    template <typename Real>
    using CanonicalBox2 = CanonicalBox<2, Real>;

    template <typename Real>
    using CanonicalBox3 = CanonicalBox<3, Real>;
}

#endif  // MATHEMATICS_PRIMITIVES_CANONICAL_BOX_H
