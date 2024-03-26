/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/20 13:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_QUARTIC_ROOTS_QR_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_QUARTIC_ROOTS_QR_DETAIL_H

#include "CubicRootsQrDetail.h"
#include "QuarticRootsQr.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::QuarticRootsQr<Real>::QuarticRootsQr() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::QuarticRootsQr<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::QuarticRootsQr<Real>::operator()(int maxIterations, Real c0, Real c1, Real c2, Real c3, int& numRoots, std::array<Real, 4>& roots) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    /// 创建多项式的伴随矩阵。矩阵是上Hessenberg形式。
    Matrix a{};
    a.at(0).at(0) = Real{};
    a.at(0).at(1) = Real{};
    a.at(0).at(2) = Real{};
    a.at(0).at(3) = -c0;
    a.at(1).at(0) = Math::GetValue(1);
    a.at(1).at(1) = Real{};
    a.at(1).at(2) = Real{};
    a.at(1).at(3) = -c1;
    a.at(2).at(0) = Real{};
    a.at(2).at(1) = Math::GetValue(1);
    a.at(2).at(2) = Real{};
    a.at(2).at(3) = -c2;
    a.at(3).at(0) = Real{};
    a.at(3).at(1) = Real{};
    a.at(3).at(2) = Math::GetValue(1);
    a.at(3).at(3) = -c3;

    /// 当c1 = c2 = 0时避免QR循环，当c1和c2接近零时避免缓慢收敛。
    const std::array<Real, 3> v{ Math::GetValue(1),
                                 Math::GetValue(0.36602540378443865),
                                 Math::GetValue(0.36602540378443865) };
    DoIteration(v, a);

    return operator()(maxIterations, a, numRoots, roots);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::QuarticRootsQr<Real>::operator()(int maxIterations, Matrix& a, int& numRoots, std::array<Real, 4>& roots) const
{
    numRoots = 0;
    std::fill(roots.begin(), roots.end(), Real{});

    for (auto numIterations = 0; numIterations < maxIterations; ++numIterations)
    {
        /// 应用Francis QR迭代。
        auto tr = a.at(2).at(2) + a.at(3).at(3);
        auto det = a.at(2).at(2) * a.at(3).at(3) - a.at(2).at(3) * a.at(3).at(2);
        const std::array<Real, 3> x{ a.at(0).at(0) * a.at(0).at(0) + a.at(0).at(1) * a.at(1).at(0) - tr * a.at(0).at(0) + det,
                                     a.at(1).at(0) * (a.at(0).at(0) + a.at(1).at(1) - tr),
                                     a.at(1).at(0) * a.at(2).at(1) };
        const auto v = House<3>(x);
        DoIteration(v, a);

        /// A的解耦试验。
        auto tr12 = a.at(1).at(1) + a.at(2).at(2);
        if (Math::Approximate(tr12 + a.at(2).at(1), tr12))
        {
            GetQuadraticRoots(0, 1, a, numRoots, roots);
            GetQuadraticRoots(2, 3, a, numRoots, roots);
            return numIterations;
        }

        auto tr01 = a.at(0).at(0) + a.at(1).at(1);
        if (Math::Approximate(tr01 + a.at(1).at(0), tr01))
        {
            numRoots = 1;
            roots.at(0) = a.at(0).at(0);

            /// 立方体解算器不是为处理NxN矩阵的3x3个子矩阵而设计的，
            /// 因此将子矩阵a复制到B是运行解算器的一个简单解决方法。
            /// 编写避免此类复制的通用根查找/代码。
            const auto subMaxIterations = maxIterations - numIterations;
            typename CubicRootsQr<Real>::Matrix b{};
            for (auto r = 0, rp1 = 1; r < 3; ++r, ++rp1)
            {
                for (auto c = 0, cp1 = 1; c < 3; ++c, ++cp1)
                {
                    b.at(r).at(c) = a.at(rp1).at(cp1);
                }
            }

            auto numSubRoots = 0;
            std::array<Real, 3> subRoots{};
            const auto numSubIterations = CubicRootsQr<Real>()(subMaxIterations, b, numSubRoots, subRoots);
            for (auto i = 0; i < numSubRoots; ++i)
            {
                roots.at(numRoots) = subRoots.at(i);
                ++numRoots;
            }
            return numIterations + numSubIterations;
        }

        auto tr23 = a.at(2).at(2) + a.at(3).at(3);
        if (Math::Approximate(tr23 + a.at(3).at(2), tr23))
        {
            numRoots = 1;
            roots.at(0) = a.at(3).at(3);

            /// 立方体解算器不是为处理NxN矩阵的3x3个子矩阵而设计的，
            /// 因此将子矩阵a复制到B是运行解算器的一个简单解决方法。
            /// 编写避免此类复制的通用根查找/代码。
            const auto subMaxIterations = maxIterations - numIterations;
            typename CubicRootsQr<Real>::Matrix b{};
            for (auto r = 0; r < 3; ++r)
            {
                for (auto c = 0; c < 3; ++c)
                {
                    b.at(r).at(c) = a.at(r).at(c);
                }
            }

            auto numSubRoots = 0;
            std::array<Real, 3> subRoots{};
            const auto numSubIterations = CubicRootsQr<Real>()(subMaxIterations, b, numSubRoots, subRoots);
            for (auto i = 0; i < numSubRoots; ++i)
            {
                roots.at(numRoots) = subRoots.at(i);
                ++numRoots;
            }
            return numIterations + numSubIterations;
        }
    }
    return maxIterations;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::QuarticRootsQr<Real>::DoIteration(const std::array<Real, 3>& v, Matrix& a) const
{
    auto multV = Math::GetValue(-2) / (v.at(0) * v.at(0) + v.at(1) * v.at(1) + v.at(2) * v.at(2));
    std::array<Real, 3> mv{ multV * v.at(0), multV * v.at(1), multV * v.at(2) };
    RowHouse<3>(0, 2, 0, 3, v, mv, a);
    ColHouse<3>(0, 3, 0, 2, v, mv, a);

    const std::array<Real, 3> x{ a.at(1).at(0), a.at(2).at(0), a.at(3).at(0) };
    const auto locV = House<3>(x);
    multV = Math::GetValue(-2) / (locV.at(0) * locV.at(0) + locV.at(1) * locV.at(1) + locV.at(2) * locV.at(2));
    mv = { multV * locV.at(0), multV * locV.at(1), multV * locV.at(2) };
    RowHouse<3>(1, 3, 0, 3, locV, mv, a);
    ColHouse<3>(0, 3, 1, 3, locV, mv, a);

    const std::array<Real, 2> y{ a.at(2).at(1), a.at(3).at(1) };
    const auto w = House<2>(y);
    const auto multW = Math::GetValue(-2) / (w.at(0) * w.at(0) + w.at(1) * w.at(1));
    const std::array<Real, 2> mw{ multW * w.at(0), multW * w.at(1) };
    RowHouse<2>(2, 3, 0, 3, w, mw, a);
    ColHouse<2>(0, 3, 2, 3, w, mw, a);
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <int N>
std::array<Real, N> Mathematics::QuarticRootsQr<Real>::House(const std::array<Real, N>& x) const
{
    std::array<Real, N> v{};
    Real length{};
    for (auto i = 0; i < N; ++i)
    {
        length += x.at(i) * x.at(i);
    }
    length = std::sqrt(length);
    if (!Math::Approximate(length, Real{}))
    {
        const auto sign = (x.at(0) >= Real{} ? Math::GetValue(1) : Math::GetValue(-1));
        const auto denominator = x.at(0) + sign * length;
        for (int i = 1; i < N; ++i)
        {
            v.at(i) = x.at(i) / denominator;
        }
    }
    else
    {
        v.fill(Real{});
    }
    v.at(0) = Math::GetValue(1);

    return v;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
template <int N>
void Mathematics::QuarticRootsQr<Real>::RowHouse(int rMin, int rMax, int cMin, int cMax, const std::array<Real, N>& v, const std::array<Real, N>& mv, Matrix& a) const
{
    /// 仅使用元素cMin到cMax。
    std::array<Real, 4> w{};

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
void Mathematics::QuarticRootsQr<Real>::ColHouse(int rMin, int rMax, int cMin, int cMax, const std::array<Real, N>& v, const std::array<Real, N>& mv, Matrix& a) const
{
    /// 仅使用元素rMin到rMax。
    std::array<Real, 4> w{};

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
void Mathematics::QuarticRootsQr<Real>::GetQuadraticRoots(int i0, int i1, Matrix const& a, int& numRoots, std::array<Real, 4>& roots) const
{
    //   r0 = t/2 + sign(t/2)*sqrt(D), r1 = trace - r0
    /// 求解x^2 - t * x + d = 0，其中t是迹，d是由索引i0和i1定义的2x2矩阵的行列式。
    /// 判别式为D = (t/2)^2 - d。当D >= 0时，根为实数t/2 - sqrt(D)和t/2 + sqrt(D)。
    /// 为了避免减法消除的潜在数值问题，
    /// 根计算为r0 = t/2 + sign(t/2)*sqrt(D), r1 = trace - r0
    const auto trace = a.at(i0).at(i0) + a.at(i1).at(i1);
    const auto halfTrace = trace * Math::GetRational(1, 2);
    const auto determinant = a.at(i0).at(i0) * a.at(i1).at(i1) - a.at(i0).at(i1) * a.at(i1).at(i0);
    const auto discriminant = halfTrace * halfTrace - determinant;
    if (discriminant >= Real{})
    {
        const auto sign = trace >= Real{} ? Math::GetValue(1) : Math::GetValue(-1);
        const auto root = halfTrace + sign * std::sqrt(discriminant);
        roots.at(numRoots++) = root;
        roots.at(numRoots++) = trace - root;
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_QUARTIC_ROOTS_QR_DETAIL_H
