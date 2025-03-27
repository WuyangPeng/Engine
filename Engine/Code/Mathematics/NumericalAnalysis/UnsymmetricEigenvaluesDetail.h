/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/03/30 14:43)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_UNSYMMETRIC_EIGENVALUES_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_UNSYMMETRIC_EIGENVALUES_DETAIL_H

#include "UnsymmetricEigenvalues.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#include <gsl/util>
#include <cmath>

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::UnsymmetricEigenvalues<Real>::UnsymmetricEigenvalues(int size, int maxIterations)
    : size{ size >= 3 && maxIterations > 0 ? size : 0 },
      sizeM1{ size >= 3 && maxIterations > 0 ? size - 1 : 0 },
      maxIterations{ size >= 3 && maxIterations > 0 ? maxIterations : 0 },
      matrix(size >= 3 && maxIterations > 0 ? static_cast<size_t>(size) * static_cast<size_t>(size) : 0),
      x(size >= 3 && maxIterations > 0 ? size : 0),
      v(size >= 3 && maxIterations > 0 ? size : 0),
      scaledV(size >= 3 && maxIterations > 0 ? size : 0),
      w(size >= 3 && maxIterations > 0 ? size : 0),
      flagStorage(size >= 3 && maxIterations > 0 ? size + 1 : 0),
      numEigenvalues{ 0 },
      eigenvalues(size >= 3 && maxIterations > 0 ? size : 0)
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::UnsymmetricEigenvalues<Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
int Mathematics::UnsymmetricEigenvalues<Real>::Solve(const std::vector<Real>& input, int sortType)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (size > 0)
    {
        ASSERT_FAIL_THROW_EXCEPTION(input.size() == static_cast<size_t>(size) * static_cast<size_t>(size), SYSTEM_TEXT("输入数组长度不一致。"))

        matrix = input;

        ReduceToUpperHessenberg();

        std::array<int, 2> block{};
        auto found = GetBlock(block);
        auto numIterations = 0;
        for (; numIterations < maxIterations; ++numIterations)
        {
            if (found)
            {
                /// 解决当前子问题.
                FrancisQrStep(block.at(0), block.at(1) + 1);

                /// 查找另一个子问题（如果有）.
                found = GetBlock(block);
            }
            else
            {
                break;
            }
        }

        /// 矩阵是完全解耦的，具有1x1或2x2对角块的上Hessenberg。
        /// Golub和Van Loan称之为“上准三角形”。
        numEigenvalues = 0;
        std::fill(eigenvalues.begin(), eigenvalues.end(), Real{});
        for (auto i = 0; i < sizeM1; ++i)
        {
            if (flagStorage.at(gsl::narrow_cast<size_t>(i) + 1) == 0)
            {
                if (flagStorage.at(i) == 0)
                {
                    /// 我们有一个1x1块与一个真正的特征值。
                    eigenvalues.at(numEigenvalues++) = A(i, i);
                }
            }
            else
            {
                if (flagStorage.at(i) == 0 && flagStorage.at(gsl::narrow_cast<size_t>(i) + 2) == 0)
                {
                    /// 我们有一个2x2块，它可能有真实的特征值。
                    auto a00 = A(i, i);
                    auto a01 = A(i, i + 1);
                    auto a10 = A(i + 1, i);
                    auto a11 = A(i + 1, i + 1);
                    auto tr = a00 + a11;
                    auto det = a00 * a11 - a01 * a10;
                    auto halfTr = tr * MathType::GetRational(1, 2);
                    auto discr = halfTr * halfTr - det;
                    if (discr >= Real{})
                    {
                        auto rootDiscr = std::sqrt(discr);
                        eigenvalues.at(numEigenvalues++) = halfTr - rootDiscr;
                        eigenvalues.at(numEigenvalues++) = halfTr + rootDiscr;
                    }
                }

                /// QR迭代未能在此块处收敛。
                /// 也必须是numIterations==maxIterations的情况。
                /// 调用方在测试返回的numIterations时会意识到这一点。
                /// 这种情况有补救办法吗？这发生在使用多项式的伴随矩阵求根时。
            }
        }

        if (sortType != 0 && numEigenvalues > 1)
        {
            if (sortType > 0)
            {
                std::sort(eigenvalues.begin(), eigenvalues.begin() + numEigenvalues, std::less<Real>());
            }
            else
            {
                std::sort(eigenvalues.begin(), eigenvalues.begin() + numEigenvalues, std::greater<Real>());
            }
        }

        return numIterations;
    }
    return 0;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
std::vector<Real> Mathematics::UnsymmetricEigenvalues<Real>::GetEigenvalues() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (size > 0)
    {
        return std::vector<Real>{ eigenvalues.begin(), eigenvalues.begin() + numEigenvalues };
    }
    else
    {
        return std::vector<Real>{};
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real const& Mathematics::UnsymmetricEigenvalues<Real>::A(int r, int c) const
{
    return matrix.at(c + r * gsl::narrow_cast<size_t>(size));
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Real& Mathematics::UnsymmetricEigenvalues<Real>::A(int r, int c)
{
    return matrix.at(c + r * gsl::narrow_cast<size_t>(size));
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::UnsymmetricEigenvalues<Real>::House(int rMin, int rMax)
{
    Real length{};
    for (auto r = rMin; r <= rMax; ++r)
    {
        length += x.at(r) * x.at(r);
    }
    length = std::sqrt(length);
    if (!MathType::Approximate(length, Real{}))
    {
        auto sign = (x.at(rMin) >= Real{} ? MathType::GetValue(1) : MathType::GetValue(-1));
        auto invDenom = MathType::GetValue(1) / (x.at(rMin) + sign * length);
        for (auto r = rMin + 1; r <= rMax; ++r)
        {
            v.at(r) = x.at(r) * invDenom;
        }
    }
    v.at(rMin) = MathType::GetValue(1);

    auto dot = MathType::GetValue(1);
    for (int r = rMin + 1; r <= rMax; ++r)
    {
        dot += v.at(r) * v.at(r);
    }
    auto scale = MathType::GetValue(-2) / dot;
    for (auto r = rMin; r <= rMax; ++r)
    {
        scaledV.at(r) = scale * v.at(r);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::UnsymmetricEigenvalues<Real>::RowHouse(int rMin, int rMax, int cMin, int cMax)
{
    for (auto c = cMin; c <= cMax; ++c)
    {
        w.at(c) = Real{};
        for (auto r = rMin; r <= rMax; ++r)
        {
            w.at(c) += scaledV.at(r) * A(r, c);
        }
    }

    for (auto r = rMin; r <= rMax; ++r)
    {
        for (auto c = cMin; c <= cMax; ++c)
        {
            A(r, c) += v.at(r) * w.at(c);
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::UnsymmetricEigenvalues<Real>::ColHouse(int rMin, int rMax, int cMin, int cMax)
{
    for (auto r = rMin; r <= rMax; ++r)
    {
        w.at(r) = Real{};
        for (auto c = cMin; c <= cMax; ++c)
        {
            w.at(r) += scaledV.at(c) * A(r, c);
        }
    }

    for (auto r = rMin; r <= rMax; ++r)
    {
        for (auto c = cMin; c <= cMax; ++c)
        {
            A(r, c) += w.at(r) * v.at(c);
        }
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::UnsymmetricEigenvalues<Real>::ReduceToUpperHessenberg()
{
    for (auto c = 0, cp1 = 1; c <= size - 3; ++c, ++cp1)
    {
        for (auto r = cp1; r <= sizeM1; ++r)
        {
            x.at(r) = A(r, c);
        }

        House(cp1, sizeM1);
        RowHouse(cp1, sizeM1, c, sizeM1);
        ColHouse(0, sizeM1, cp1, sizeM1);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
void Mathematics::UnsymmetricEigenvalues<Real>::FrancisQrStep(int rMin, int rMax)
{
    /// 应用双隐式移位步骤。
    const auto i0 = rMax - 1;
    const auto i1 = rMax;
    auto a00 = A(i0, i0);
    auto a01 = A(i0, i1);
    auto a10 = A(i1, i0);
    auto a11 = A(i1, i1);
    auto tr = a00 + a11;
    auto det = a00 * a11 - a01 * a10;

    const auto j0 = rMin;
    const auto j1 = j0 + 1;
    const auto j2 = j1 + 1;
    auto b00 = A(j0, j0);
    auto b01 = A(j0, j1);
    auto b10 = A(j1, j0);
    auto b11 = A(j1, j1);
    auto b21 = A(j2, j1);
    x.at(rMin) = b00 * (b00 - tr) + b01 * b10 + det;
    x.at(gsl::narrow_cast<size_t>(rMin) + 1) = b10 * (b00 + b11 - tr);
    x.at(gsl::narrow_cast<size_t>(rMin) + 2) = b10 * b21;

    House(rMin, rMin + 2);
    RowHouse(rMin, rMin + 2, rMin, rMax);
    ColHouse(rMin, std::min(rMax, rMin + 3), rMin, rMin + 2);

    /// 应用Householder反射将矩阵恢复为上Hessenberg形式。
    for (auto c = 0, cp1 = 1; c <= size - 3; ++c, ++cp1)
    {
        const auto kMax = std::min(cp1 + 2, sizeM1);
        for (auto r = cp1; r <= kMax; ++r)
        {
            x.at(r) = A(r, c);
        }

        House(cp1, kMax);
        RowHouse(cp1, kMax, c, sizeM1);
        ColHouse(0, sizeM1, cp1, kMax);
    }
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::UnsymmetricEigenvalues<Real>::GetBlock(std::array<int, 2>& block)
{
    for (auto i = 0; i < sizeM1; ++i)
    {
        auto a00 = A(i, i);
        auto a11 = A(i + 1, i + 1);
        auto a21 = A(i + 1, i);
        auto sum0 = a00 + a11;
        auto sum1 = sum0 + a21;
        flagStorage.at(gsl::narrow_cast<size_t>(i) + 1) = (!MathType::Approximate(sum1, sum0) ? 1 : 0);
    }

    for (auto i = 0; i < sizeM1; ++i)
    {
        if (flagStorage.at(gsl::narrow_cast<size_t>(i) + 1) == 1)
        {
            block = { i, -1 };
            while (i < sizeM1 && flagStorage.at(gsl::narrow_cast<size_t>(i) + 1) == 1)
            {
                block.at(1) = i++;
            }
            if (block.at(1) != block.at(0))
            {
                return true;
            }
        }
    }
    return false;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_UNSYMMETRIC_EIGENVALUES_DETAIL_H
