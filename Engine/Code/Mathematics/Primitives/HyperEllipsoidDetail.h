///	Copyright (c) 2010-2024
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：1.0.0.6 (2024/03/01 14:30)

#ifndef MATHEMATICS_PRIMITIVES_HYPER_ELLIPSOID_DETAIL_H
#define MATHEMATICS_PRIMITIVES_HYPER_ELLIPSOID_DETAIL_H

#include "HyperEllipsoid.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix/MatrixDetail.h"
#include "Mathematics/NumericalAnalysis/SymmetricEigensolverDetail.h"

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HyperEllipsoid<N, Real>::HyperEllipsoid() noexcept requires(N == 2)
    : center{}, axis{ Vector{ Math::GetValue(1), Math::GetValue(0) }, Vector{ Math::GetValue(0), Math::GetValue(1) } }, extent{ Math::GetValue(1), Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HyperEllipsoid<N, Real>::HyperEllipsoid() noexcept requires(N == 3)
    : center{},
      axis{ Vector{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0) },
            Vector{ Math::GetValue(0), Math::GetValue(1), Math::GetValue(0) },
            Vector{ Math::GetValue(0), Math::GetValue(0), Math::GetValue(1) } },
      extent{ Math::GetValue(1), Math::GetValue(1), Math::GetValue(1) }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
Mathematics::HyperEllipsoid<N, Real>::HyperEllipsoid(const Vector& center, const AxisType& axis, const Vector& extent) noexcept
    : center{ center }, axis{ axis }, extent{ extent }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::HyperEllipsoid<N, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperEllipsoid<N, Real>::Vector Mathematics::HyperEllipsoid<N, Real>::GetCenter() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return center;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperEllipsoid<N, Real>::SetCenter(const Vector& aCenter) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    center = aCenter;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperEllipsoid<N, Real>::AxisType Mathematics::HyperEllipsoid<N, Real>::GetAxis() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return axis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperEllipsoid<N, Real>::SetAxis(const AxisType& aAxis) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    axis = aAxis;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperEllipsoid<N, Real>::Vector Mathematics::HyperEllipsoid<N, Real>::GetExtent() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return extent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperEllipsoid<N, Real>::SetExtent(const Vector& aExtent) noexcept
{
    MATHEMATICS_CLASS_IS_VALID_9;

    extent = aExtent;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperEllipsoid<N, Real>::Matrix Mathematics::HyperEllipsoid<N, Real>::GetM() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix m{};

    for (auto d = 0; d < N; ++d)
    {
        const auto ratio = axis.at(d) / extent[d];
        m += OuterProduct<N, N, Real>(ratio, ratio);
    }

    return m;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperEllipsoid<N, Real>::Matrix Mathematics::HyperEllipsoid<N, Real>::GetMInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    Matrix mInverse{};

    for (auto d = 0; d < N; ++d)
    {
        const auto ratio = axis.at(d) * extent[d];
        mInverse += OuterProduct<N, N, Real>(ratio, ratio);
    }

    return mInverse;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
typename Mathematics::HyperEllipsoid<N, Real>::CoefficientType Mathematics::HyperEllipsoid<N, Real>::ToCoefficients() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    CoefficientType coefficient{};

    constexpr auto numCoefficients = (N + 1) * (N + 2) / 2;
    Matrix a{};
    Vector b{};
    Real c{};
    ToCoefficients(a, b, c);
    Convert(a, b, c, coefficient);

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)

    /// 将二次项的其中一个系数设置为1。
    auto quadIndex = numCoefficients - 1;
    auto maxIndex = quadIndex;
    auto maxValue = Math::FAbs(coefficient.at(quadIndex));

#include SYSTEM_WARNING_POP

    /// 注：当N = 2时，MSVS 2019 16+生成：警告C6294：
    /// 循环定义错误：初始条件不满足测试。
    /// 循环体未执行。这是N=2的正确行为。
    if constexpr (constexpr auto localN = N;
                  3 <= localN)
    {
        for (auto d = 2; d < localN; ++d)
        {
            quadIndex -= d;
            auto absValue = Math::FAbs(coefficient.at(quadIndex));
            if (maxValue < absValue)
            {
                maxIndex = quadIndex;
                maxValue = absValue;
            }
        }
    }

    auto invMaxValue = Math::GetValue(1) / maxValue;
    for (auto i = 0; i < numCoefficients; ++i)
    {
        if (i != maxIndex)
        {
            coefficient.at(i) *= invMaxValue;
        }
        else
        {
            coefficient.at(i) = Math::GetValue(1);
        }
    }

    return coefficient;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperEllipsoid<N, Real>::ToCoefficients(Matrix& a, Vector& b, Real& c) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    a = GetM();
    const auto product = a * center;
    b = Math::GetValue(-2) * product;
    c = Dot(center, product) - Math::GetValue(1);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::HyperEllipsoid<N, Real>::FromCoefficients(const CoefficientType& coefficient)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix a{};
    Vector b{};
    Real c{};
    Convert(coefficient, a, b, c);

    return FromCoefficients(a, b, c);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::HyperEllipsoid<N, Real>::FromCoefficients(const Matrix& a, const Vector& b, Real c)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 计算中心 K = -A^{-1}*B/2.
    bool invertible{};
    const auto invA = Inverse(a, &invertible);
    if (!invertible)
    {
        return false;
    }

    center = Math::GetRational(-1, 2) * (invA * b);

    // 计算 B^T*A^{-1}*B/4 - C = K^T*A*K - C = -K^T*B/2 - C.
    const auto rightSide = Math::GetRational(-1, 2) * Dot(center, b) - c;
    if (Math::Approximate(rightSide, Real{}))
    {
        return false;
    }

    // 计算 M = A/(K^T*A*K - C).
    const auto invRightSide = Math::GetValue(1) / rightSide;
    const auto m = invRightSide * a;

    /// 因子为 M = R*D*R^T。M是对称的，
    /// 所以矩阵是按行主还是列主的顺序存储并不重要；它们是等效的。
    /// 然而，输出R是按行主要顺序排列的。
    SymmetricEigensolver<Real> es{ N, 32 };
    Matrix rotation{};
    std::vector<Real> diagonal{};
    es.Solve(m.GetBaseContainer(), +1);  // diagonal[i] 是不减的
    diagonal = es.GetEigenvalues();
    rotation = Matrix{ es.GetEigenvectors() };
    if (es.GetEigenvectorMatrixType() == 0)
    {
        const auto negLast = -rotation.GetColumn(N - 1);
        rotation.SetColumn(N - 1, negLast);
    }

    for (auto d = 0; d < N; ++d)
    {
        if (diagonal.at(d) <= Real{})
        {
            return false;
        }

        extent[d] = Math::GetValue(1) / Math::Sqrt(diagonal.at(d));
        axis.at(d) = rotation.GetColumn(d);
    }

    return true;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperEllipsoid<N, Real>::Convert(const CoefficientType& coefficient, Matrix& a, Vector& b, Real& c)
{
    auto i = 0;
    c = coefficient.at(i++);

    for (auto j = 0; j < N; ++j, ++i)
    {
        b[j] = coefficient.at(i);
    }

    i = N + 1;
    for (auto r = 0; r < N; ++r)
    {
        for (auto column = 0; column < r; ++column)
        {
            a(r, column) = a(column, r);
        }

        /// 注：MSVS 2019 16+为N = 2生成：
        /// 警告C28020:表达式
        ///  '0 <= _Param_(1)&&_Param(1)<=6-1'在此调用中不为真。
        /// 对于N = 3（上限为10-1），也会出现类似的警告。警告不正确。
        ///
        /// 当 r = N-1, i = (N+1)*(N+2)/2 - 1，它对应于系数[]的最后一个元素。分配有效。
        /// 赋值后，i递增，现在超出coefficient[]的范围。
        /// 然而，赋值之后的循环从c = N开始，并且不执行循环体，之后r循环终止。
        a(r, r) = coefficient.at(i);
        ++i;
        for (auto column = r + 1; column < N; ++column, ++i)
        {
            a(r, column) = coefficient.at(i) * Math::GetRational(1, 2);
        }
    }
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
void Mathematics::HyperEllipsoid<N, Real>::Convert(const Matrix& a, const Vector& b, Real c, CoefficientType& coefficient)
{
    auto i = 0;
    coefficient.at(i++) = c;

    for (auto j = 0; j < N; ++j, ++i)
    {
        coefficient.at(i) = b[j];
    }

    /// 以下代码的结构避免了在此函数的先前实现中使用MSVS 2019 16.*时出现错误警告C28020。
    i = N + 1;
    for (auto r = 0; r < N; ++r)
    {
        coefficient.at(i) = a(r, r);
        ++i;
        for (auto column = r + 1; column < N && i < boost::numeric_cast<int>(coefficient.size()); ++column, ++i)
        {
            coefficient.at(i) = a(r, column) * Math::GetRational(1, 2);
        }
    }
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator==(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs)
{
    return lhs.GetCenter() == rhs.GetCenter() && lhs.GetAxis() == rhs.GetAxis() && lhs.GetExtent() == rhs.GetExtent();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator!=(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs)
{
    return !(lhs == rhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs)
{
    if (lhs.GetCenter() < rhs.GetCenter())
    {
        return true;
    }

    if (rhs.GetCenter() < lhs.GetCenter())
    {
        return false;
    }

    if (lhs.GetAxis() < rhs.GetAxis())
    {
        return true;
    }

    if (rhs.GetAxis() < lhs.GetAxis())
    {
        return false;
    }

    return lhs.GetExtent() < rhs.GetExtent();
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator<=(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs)
{
    return !(rhs < lhs);
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs)
{
    return rhs < lhs;
}

template <int N, typename Real>
requires(1 < N && N < 4 && std::is_arithmetic_v<Real>)
bool Mathematics::operator>=(const HyperEllipsoid<N, Real>& lhs, const HyperEllipsoid<N, Real>& rhs)
{
    return !(lhs < rhs);
}

#endif  // MATHEMATICS_PRIMITIVES_HYPER_ELLIPSOID_DETAIL_H
