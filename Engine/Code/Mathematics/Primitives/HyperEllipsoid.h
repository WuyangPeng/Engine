///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 14:29)

#ifndef MATHEMATICS_PRIMITIVES_HYPER_ELLIPSOID_H
#define MATHEMATICS_PRIMITIVES_HYPER_ELLIPSOID_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix/Matrix.h"
#include "Mathematics/Algebra/Vector/Vector.h"

/// 超椭球体的中心是K；
/// 轴方向U[0]到U[N-1]，所有单位长度矢量；
/// 以及范围e[0]到e[N-1]，都是正数。
/// 当sum_{d=0}^{N-1} (y[d]/e[d])^2 = 1时，
/// 点X = K + sum_{d=0}^{N-1} y[d]*U[d]在超椭球上。
/// 超椭球体的代数表示是(X-K)^T * M * (X-K) = 1，
/// 其中M是NxN对称矩阵M = sum_{d=0}^{N-1} U[d]*U[d]^T/e[d]^2，其中上标T表示转置。
/// 观察U[i]*U[i]^T是一个矩阵，而不是标量点积。
/// 超椭球还由二次方程0 = C + B^T*X + X^T*A*X表示，其中C是标量，B是Nx1向量，a是具有正特征值的NxN对称矩阵。
/// 可以从最低程度到最高程度来存储系数，
///   C = k[0]
///   B = k[1], ..., k[N]
///   A = k[N+1], ..., k[(N+1)(N+2)/2 - 1]
/// 其中A系数是按行主要顺序列出的A的上三角元素。
/// 对于N=2，X = (x[0],x[1])和
///   0 = k[0] +
///       k[1]*x[0] + k[2]*x[1] +
///       k[3]*x[0]*x[0] + k[4]*x[0]*x[1]
///                      + k[5]*x[1]*x[1]
/// 对于 N = 3, X = (x[0],x[1],x[2]) 和
///   0 = k[0] +
///       k[1]*x[0] + k[2]*x[1] + k[3]*x[2] +
///       k[4]*x[0]*x[0] + k[5]*x[0]*x[1] + k[6]*x[0]*x[2] +
///                      + k[7]*x[1]*x[1] + k[8]*x[1]*x[2] +
///                                       + k[9]*x[2]*x[2]
/// 该方程可分解为 (X-K)^T * M * (X-K) = 1，这里
/// K = -A^{-1}*B/2, M = A/(B^T*A^{-1}*B/4-C)。
namespace Mathematics
{
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    class HyperEllipsoid
    {
    public:
        using ClassType = HyperEllipsoid<N, Real>;

        using MathType = Math<Real>;
        using Vector = Algebra::Vector<N, Real>;
        using AxisType = std::array<Vector, N>;
        using Matrix = Algebra::Matrix<N, N, Real>;
        using CoefficientType = std::array<Real, (N + 1) * (N + 2) / 2>;

    public:
        /// 默认构造函数将中心设置为Vector<N,Real>::Zero()，
        /// 将轴设置为Vector<N,Real>::Unit(d)，并将所有范围设置为1。
        HyperEllipsoid() noexcept requires(N == 2);
        HyperEllipsoid() noexcept requires(N == 3);

        HyperEllipsoid(const Vector& center, const AxisType& axis, const Vector& extent) noexcept;

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

        /// 计算 M = sum_{d=0}^{N-1} U[d]*U[d]^T/e[d]^2.
        NODISCARD Matrix GetM() const;

        // 计算 M^{-1} = sum_{d=0}^{N-1} U[d]*U[d]^T*e[d]^2.
        NODISCARD Matrix GetMInverse() const;

        /// 构造表示超椭球的二次方程中的系数。
        NODISCARD CoefficientType ToCoefficients() const;

        void ToCoefficients(Matrix& a, Vector& b, Real& c) const;

        /// 根据方程构造C, U[i], 和 e[i]。
        /// 当且仅当输入系数表示超椭球体时，返回值为“true”。
        /// 如果函数返回“false”，则表示超椭圆体数据成员未定义。
        NODISCARD bool FromCoefficients(const CoefficientType& coefficient);

        NODISCARD bool FromCoefficients(const Matrix& a, const Vector& b, Real c);

    private:
        static void Convert(const CoefficientType& coefficient, Matrix& a, Vector& b, Real& c);
        static void Convert(const Matrix& a, const Vector& b, Real c, CoefficientType& coefficient);

    private:
        Vector center;
        AxisType axis;
        Vector extent;
    };

    /// 与支持排序容器的比较。
    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator==(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator!=(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator<=(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs);

    template <int N, typename Real>
    requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
    NODISCARD bool operator>=(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs);

    namespace Algebra
    {
        /// 为方便起见，模板别名。
        template <typename Real>
        using Ellipse2 = HyperEllipsoid<2, Real>;

        template <typename Real>
        using Ellipsoid3 = HyperEllipsoid<3, Real>;
    }
}

#endif  // MATHEMATICS_PRIMITIVES_HYPER_ELLIPSOID_H
