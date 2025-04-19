/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 23:52)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CUBIC_ROOTS_QR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CUBIC_ROOTS_QR_DETAIL_H

#include "CubicRootsQr.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::CubicRootsQr<Real>::CubicRootsQr() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::CubicRootsQr<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::CubicRootsQr<Real>::operator()(int maxIterations, Real c0, Real c1, Real c2, int& numRoots, Roots& roots) const
{
    /// 创建多项式的伴随矩阵。矩阵是上Hessenberg形式。
    MatrixType a{ Roots{ Real{}, Real{}, -c0 },
              Roots{ MathType::GetValue(1), Real{}, -c1 },
              Roots{ Real{}, MathType::GetValue(1), -c2 } };

    /// 当c1 = c2 = 0时避免QR循环，当c1和c2接近零时避免缓慢收敛。
    const Roots v{ MathType::GetValue(1),
                   MathType::GetValue(0.36602540378443865),
                   MathType::GetValue(0.36602540378443865) };
    DoIteration(v, a);

    return operator()(maxIterations, a, numRoots, roots);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::CubicRootsQr<Real>::operator()(int maxIterations, MatrixType& a, int& numRoots, Roots& roots) const
{
    numRoots = 0;
    std::fill(roots.begin(), roots.end(), Real{});

    for (int numIterations = 0; numIterations < maxIterations; ++numIterations)
    {
        /// 应用Francis QR迭代。
        auto tr = a.at(1).at(1) + a.at(2).at(2);
        auto det = a.at(1).at(1) * a.at(2).at(2) - a.at(1).at(2) * a.at(2).at(1);
        const std::array<Real, 3> x{ a.at(0).at(0) * a.at(0).at(0) + a.at(0).at(1) * a.at(1).at(0) - tr * a.at(0).at(0) + det,
                                     a.at(1).at(0) * (a.at(0).at(0) + a.at(1).at(1) - tr),
                                     a.at(1).at(0) * a.at(2).at(1) };
        const auto v = House<3>(x);
        DoIteration(v, a);

        /// A的解耦试验。
        auto tr01 = a.at(0).at(0) + a.at(1).at(1);
        if (MathType::Approximate(tr01 + a.at(1).at(0), tr01))
        {
            numRoots = 1;
            roots.at(0) = a.at(0).at(0);
            GetQuadraticRoots(1, 2, a, numRoots, roots);
            return numIterations;
        }

        auto tr12 = a.at(1).at(1) + a.at(2).at(2);
        if (MathType::Approximate(tr12 + a.at(2).at(1), tr12))
        {
            numRoots = 1;
            roots.at(0) = a.at(2).at(2);
            GetQuadraticRoots(0, 1, a, numRoots, roots);
            return numIterations;
        }
    }
    return maxIterations;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::CubicRootsQr<Real>::DoIteration(const Roots& v, MatrixType& a) const
{
    auto multV = MathType::GetValue(-2) / (v.at(0) * v.at(0) + v.at(1) * v.at(1) + v.at(2) * v.at(2));
    const Roots mv{ multV * v.at(0), multV * v.at(1), multV * v.at(2) };
    RowHouse<3>(0, 2, 0, 2, v, mv, a);
    ColHouse<3>(0, 2, 0, 2, v, mv, a);

    const std::array<Real, 2> y{ a.at(1).at(0), a.at(2).at(0) };
    std::array<Real, 2> w = House<2>(y);
    auto multW = MathType::GetValue(-2) / (w.at(0) * w.at(0) + w.at(1) * w.at(1));
    const std::array<Real, 2> mw{ multW * w.at(0), multW * w.at(1) };
    RowHouse<2>(1, 2, 0, 2, w, mw, a);
    ColHouse<2>(0, 2, 1, 2, w, mw, a);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <int N>
std::array<Real, N> Mathematics::CubicRootsQr<Real>::House(const std::array<Real, N>& x) const
{
    std::array<Real, N> v{};
    Real length{};
    for (auto i = 0; i < N; ++i)
    {
        length += x.at(i) * x.at(i);
    }
    length = std::sqrt(length);
    if (!MathType::Approximate(length, Real{}))
    {
        auto sign = x.at(0) >= Real{} ? MathType::GetValue(1) : MathType::GetValue(-1);
        auto denominator = x.at(0) + sign * length;
        for (int i = 1; i < N; ++i)
        {
            v.at(i) = x.at(i) / denominator;
        }
    }
    else
    {
        v.fill(Real{});
    }
    v.at(0) = MathType::GetValue(1);
    return v;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <int N>
void Mathematics::CubicRootsQr<Real>::RowHouse(int rMin, int rMax, int cMin, int cMax, const std::array<Real, N>& v, const std::array<Real, N>& mv, MatrixType& a) const
{
    /// 仅使用元素cMin到cMax。
    Roots w{};

    for (auto c = cMin; c <= cMax; ++c)
    {
        w.at(c) = Real{};
        for (auto r = rMin, k = 0; r <= rMax; ++r, ++k)
        {
            w.at(c) += v.at(k) * a.at(r).at(c);
        }
    }

    for (auto r = rMin, k = 0; r <= rMax; ++r, ++k)
    {
        for (auto c = cMin; c <= cMax; ++c)
        {
            a.at(r).at(c) += mv.at(k) * w.at(c);
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <int N>
void Mathematics::CubicRootsQr<Real>::ColHouse(int rMin, int rMax, int cMin, int cMax, const std::array<Real, N>& v, const std::array<Real, N>& mv, MatrixType& a) const
{
    /// 仅使用元素rMin到rMax。
    Roots w{};

    for (auto r = rMin; r <= rMax; ++r)
    {
        w.at(r) = Real{};
        for (auto c = cMin, k = 0; c <= cMax; ++c, ++k)
        {
            w.at(r) += v.at(k) * a.at(r).at(c);
        }
    }

    for (auto r = rMin; r <= rMax; ++r)
    {
        for (auto c = cMin, k = 0; c <= cMax; ++c, ++k)
        {
            a.at(r).at(c) += w.at(r) * mv.at(k);
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::CubicRootsQr<Real>::GetQuadraticRoots(int i0, int i1, const MatrixType& a, int& numRoots, Roots& roots) const
{
    /// 求解x^2 - t * x + d = 0，其中t是trace，d是由索引i0和i1定义的2x2矩阵的行列式。
    /// 判别式为 D = (t/2)^2 - d。当D>=0时，根为实数 t/2 - sqrt(D)和t/2 + sqrt(D)。
    /// 为了避免减法消除的潜在数值问题，根计算如下
    ///   r0 = t/2 + sign(t/2)*sqrt(D), r1 = trace - r0.
    auto trace = a.at(i0).at(i0) + a.at(i1).at(i1);
    auto halfTrace = trace * MathType::GetRational(1, 2);
    auto determinant = a.at(i0).at(i0) * a.at(i1).at(i1) - a.at(i0).at(i1) * a.at(i1).at(i0);
    auto discriminant = halfTrace * halfTrace - determinant;
    if (discriminant >= Real{})
    {
        auto sign = (trace >= Real{} ? MathType::GetValue(1) : MathType::GetValue(-1));
        auto root = halfTrace + sign * std::sqrt(discriminant);
        roots.at(numRoots++) = root;
        roots.at(numRoots++) = trace - root;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CUBIC_ROOTS_QR_DETAIL_H
