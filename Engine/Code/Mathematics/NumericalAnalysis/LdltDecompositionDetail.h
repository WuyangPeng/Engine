/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/14 10:05)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LDLT_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LDLT_DECOMPOSITION_DETAIL_H

#include "LdltDecomposition.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename T, int N>
requires(0 < N)
Mathematics::LdltDecomposition<T, N>::LdltDecomposition() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, int N>
requires(0 < N)
bool Mathematics::LdltDecomposition<T, N>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, int N>
requires(0 < N)
bool Mathematics::LdltDecomposition<T, N>::Factor(const Matrix& a, Matrix& l, Matrix& d)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    l.MakeZero();
    d.MakeZero();
    for (auto j = 0; j < N; ++j)
    {
        auto djj = a(j, j);
        for (auto k = 0; k < j; ++k)
        {
            auto ljk = l(j, k);
            auto dkk = d(k, k);
            djj -= ljk * ljk * dkk;
        }
        d(j, j) = djj;
        if (MathType::Approximate(djj, T{}))
        {
            return false;
        }

        l(j, j) = MathType::GetValue(1);
        for (auto i = j + 1; i < N; ++i)
        {
            auto lij = a(i, j);
            for (auto k = 0; k < j; ++k)
            {
                auto lik = l(i, k);
                auto ljk = l(j, k);
                auto dkk = d(k, k);
                lij -= lik * ljk * dkk;
            }
            lij /= djj;
            l(i, j) = lij;
        }
    }
    return true;
}

template <typename T, int N>
requires(0 < N)
void Mathematics::LdltDecomposition<T, N>::Solve(const Matrix& l, const Matrix& d, const Vector& e, Vector& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 求解Z的 L * Z = L * (D * L^T * X) = B
    for (auto r = 0; r < N; ++r)
    {
        x[r] = e[r];
        for (auto c = 0; c < r; ++c)
        {
            x[r] -= l(r, c) * x[c];
        }
    }

    /// 求解Y的 D * Y = D * (L^T * X) = Z
    for (auto r = 0; r < N; ++r)
    {
        x[r] /= d(r, r);
    }

    /// 求解X的 L^T * Y = Z.
    for (auto r = N - 1; r >= 0; --r)
    {
        for (auto c = r + 1; c < N; ++c)
        {
            x[r] -= l(c, r) * x[c];
        }
    }
}

template <typename T, int N>
requires(0 < N)
void Mathematics::LdltDecomposition<T, N>::Solve(const Matrix& a, const Vector& b, Vector& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    Matrix l{};
    Matrix d{};
    Factor(a, l, d);
    Solve(l, d, b, x);
}

template <typename T>
Mathematics::LdltDecomposition<T>::LdltDecomposition(int n)
    : n{ n }
{
    if (n <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效大小。"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::LdltDecomposition<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::LdltDecomposition<T>::Factor(const VariableMatrix& a, VariableMatrix& l, VariableMatrix& d)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!(a.GetRowsNumber() == n && a.GetColumnsNumber() == n))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效大小。"))
    }

    l.SetSize(n, n);
    l.MakeZero();
    d.SetSize(n, n);
    d.MakeZero();

    for (auto j = 0; j < n; ++j)
    {
        auto djj = a(j, j);
        for (auto k = 0; k < j; ++k)
        {
            auto ljk = l(j, k);
            auto dkk = d(k, k);
            djj -= ljk * ljk * dkk;
        }
        d(j, j) = djj;
        if (MathType::Approximate(djj, T{}))
        {
            return false;
        }

        l(j, j) = MathType::GetValue(1);
        for (auto i = j + 1; i < n; ++i)
        {
            auto lij = a(i, j);
            for (auto k = 0; k < j; ++k)
            {
                auto lik = l(i, k);
                auto ljk = l(j, k);
                auto dkk = d(k, k);
                lij -= lik * ljk * dkk;
            }

            lij /= djj;
            l(i, j) = lij;
        }
    }
    return true;
}

template <typename T>
void Mathematics::LdltDecomposition<T>::Solve(const VariableMatrix& l, const VariableMatrix& d, const VariableLengthVector& b, VariableLengthVector& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!(l.GetRowsNumber() == n &&
          l.GetColumnsNumber() == n &&
          d.GetRowsNumber() == n &&
          d.GetColumnsNumber() &&
          b.GetSize() == n))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效大小。"))
    }

    x.SetSize(n);

    /// 求解Z的 L * Z = L * (D * L^T * X) = B .
    for (auto r = 0; r < n; ++r)
    {
        x[r] = b[r];
        for (auto c = 0; c < r; ++c)
        {
            x[r] -= l(r, c) * x[c];
        }
    }

    /// 求解Y的 D * Y = D * (L^T * X) = Z.
    for (auto r = 0; r < n; ++r)
    {
        x[r] /= d(r, r);
    }

    /// 求解X的 Solve L^T * Y = Z.
    for (auto r = n - 1; r >= 0; --r)
    {
        for (auto c = r + 1; c < n; ++c)
        {
            x[r] -= l(c, r) * x[c];
        }
    }
}

template <typename T>
void Mathematics::LdltDecomposition<T>::Solve(const VariableMatrix& a, const VariableLengthVector& b, VariableLengthVector& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (!(a.GetRowsNumber() == n && a.GetColumnsNumber() == n && b.GetSize() == n))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效大小。"))
    }

    VariableMatrix l{};
    VariableMatrix d{};

    Factor(a, l, d);
    Solve(l, d, b, x);
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LDLT_DECOMPOSITION_DETAIL_H
