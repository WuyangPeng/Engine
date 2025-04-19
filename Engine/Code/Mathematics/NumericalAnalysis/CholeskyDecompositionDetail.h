/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 14:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_CHOLESKY_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_CHOLESKY_DECOMPOSITION_DETAIL_H

#include "CholeskyDecomposition.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real, int N>
requires(std::is_arithmetic_v<Real> && 0 <= N)
Mathematics::CholeskyDecomposition<Real, N>::CholeskyDecomposition() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(std::is_arithmetic_v<Real> && 0 <= N)
bool Mathematics::CholeskyDecomposition<Real, N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int N>
requires(std::is_arithmetic_v<Real> && 0 <= N)
bool Mathematics::CholeskyDecomposition<Real, N>::Factor(MatrixType& a)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto c = 0; c < N; ++c)
    {
        if (a(c, c) <= MathType::GetValue(0))
        {
            return false;
        }
        a(c, c) = std::sqrt(a(c, c));

        for (auto r = c + 1; r < N; ++r)
        {
            a(r, c) /= a(c, c);
        }

        for (auto k = c + 1; k < N; ++k)
        {
            for (auto r = k; r < N; ++r)
            {
                a(r, k) -= a(r, c) * a(k, c);
            }
        }
    }
    return true;
}

template <typename Real, int N>
requires(std::is_arithmetic_v<Real> && 0 <= N)
typename Mathematics::CholeskyDecomposition<Real, N>::VectorType Mathematics::CholeskyDecomposition<Real, N>::SolveLower(const MatrixType& l)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    VectorType y{};
    for (auto r = 0; r < N; ++r)
    {
        for (auto c = 0; c < r; ++c)
        {
            y[r] -= l(r, c) * y[c];
        }
        y[r] /= l(r, r);
    }

    return y;
}

template <typename Real, int N>
requires(std::is_arithmetic_v<Real> && 0 <= N)
typename Mathematics::CholeskyDecomposition<Real, N>::VectorType Mathematics::CholeskyDecomposition<Real, N>::SolveUpper(const MatrixType& l)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    VectorType x{};
    for (auto r = N - 1; r >= 0; --r)
    {
        for (auto c = r + 1; c < N; ++c)
        {
            x[r] -= l(c, r) * x[c];
        }
        x[r] /= l(r, r);
    }

    return x;
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
Mathematics::CholeskyDecomposition<Real, 0>::CholeskyDecomposition(int n) noexcept
    : n{ n }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::CholeskyDecomposition<Real, 0>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
requires(std::is_arithmetic_v<Real>)
bool Mathematics::CholeskyDecomposition<Real, 0>::Factor(VariableMatrixType& a)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (a.GetRowsNumber() == n && a.GetColumnsNumber() == n)
    {
        for (auto c = 0; c < n; ++c)
        {
            if (a(c, c) <= Real{})
            {
                return false;
            }
            a(c, c) = std::sqrt(a(c, c));

            for (auto r = c + 1; r < n; ++r)
            {
                a(r, c) /= a(c, c);
            }

            for (auto k = c + 1; k < n; ++k)
            {
                for (auto r = k; r < n; ++r)
                {
                    a(r, k) -= a(r, c) * a(k, c);
                }
            }
        }
        return true;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("矩阵必须为方形。"))
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::CholeskyDecomposition<Real>::VariableLengthVectorType Mathematics::CholeskyDecomposition<Real, 0>::SolveLower(const VariableMatrixType& l)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    VariableLengthVectorType y{};
    if (l.GetRowsNumber() == n && l.GetColumnsNumber() == n && y.GetSize() == n)
    {
        for (auto r = 0; r < n; ++r)
        {
            for (auto c = 0; c < r; ++c)
            {
                y[r] -= l(r, c) * y[c];
            }
            y[r] /= l(r, r);
        }

        return y;
    }

    THROW_EXCEPTION(SYSTEM_TEXT("无效的大小。"))
}

template <typename Real>
requires(std::is_arithmetic_v<Real>)
typename Mathematics::CholeskyDecomposition<Real>::VariableLengthVectorType Mathematics::CholeskyDecomposition<Real, 0>::SolveUpper(const VariableMatrixType& l)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    VariableLengthVectorType x{};
    if (l.GetRowsNumber() == n && l.GetColumnsNumber() == n && x.GetSize() == n)
    {
        for (auto r = n - 1; r >= 0; --r)
        {
            for (auto c = r + 1; c < n; ++c)
            {
                x[r] -= l(c, r) * x[c];
            }
            x[r] /= l(r, r);
        }
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的大小。"))
    }

    return x;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_CHOLESKY_DECOMPOSITION_DETAIL_H
