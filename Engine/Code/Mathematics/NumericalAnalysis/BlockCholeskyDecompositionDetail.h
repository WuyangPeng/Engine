/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/11 15:59)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_CHOLESKY_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_CHOLESKY_DECOMPOSITION_DETAIL_H

#include "BlockCholeskyDecomposition.h"
#include "CholeskyDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::BlockCholeskyDecomposition() noexcept
    : decomposer{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
bool Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
void Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::LowerTriangularSolver(int r, int c, BlockMatrix& a)
{
    const auto& acc = a.at(c).at(c);
    auto& arc = a.at(r).at(c);
    for (auto j = 0; j < BlockSize; ++j)
    {
        for (auto i = 0; i < j; ++i)
        {
            Real lji = acc(j, i);
            for (auto k = 0; k < BlockSize; ++k)
            {
                arc(k, j) -= lji * arc(k, i);
            }
        }

        auto ljj = acc(j, j);
        for (auto k = 0; k < BlockSize; ++k)
        {
            arc(k, j) /= ljj;
        }
    }
}

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
void Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::SubtractiveUpdate(int r, int k, int c, BlockMatrix& a)
{
    const auto& arc = a.at(r).at(c);
    const auto& akc = a.at(k).at(r);
    auto& ark = a.at(r).at(k);
    for (auto j = 0; j < BlockSize; ++j)
    {
        for (auto i = 0; i < BlockSize; ++i)
        {
            for (auto m = 0; m < BlockSize; ++m)
            {
                ark(j, i) -= arc(j, m) * akc(i, m);
            }
        }
    }
}

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
Real Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::Get(const BlockMatrix& m, int row, int col)
{
    const auto b0 = col / BlockSize, b1 = row / BlockSize;
    const auto i0 = col % BlockSize, i1 = row % BlockSize;
    const auto& block = m.at(b1).at(b0);
    return block(i1, i0);
}

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
void Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::Set(BlockMatrix& m, int row, int col, Real value)
{
    const auto b0 = col / BlockSize, b1 = row / BlockSize;
    const auto i0 = col % BlockSize, i1 = row % BlockSize;
    auto& block = m.at(b1).at(b0);
    block(i1, i0) = value;
}

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
bool Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::Factor(BlockMatrix& a)
{
    for (auto c = 0; c < NumBlocks; ++c)
    {
        if (!decomposer.Factor(a.at(c).at(c)))
        {
            return false;
        }

        for (auto r = c + 1; r < NumBlocks; ++r)
        {
            LowerTriangularSolver(r, c, a);
        }

        for (auto k = c + 1; k < NumBlocks; ++k)
        {
            for (auto r = k; r < NumBlocks; ++r)
            {
                SubtractiveUpdate(r, k, c, a);
            }
        }
    }
    return true;
}

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
typename Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::BlockVector Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::SolveLower(const BlockMatrix& l)
{
    BlockVector y{};

    for (auto r = 0; r < NumBlocks; ++r)
    {
        auto& yr = y.at(r);
        for (auto c = 0; c < r; ++c)
        {
            const auto& lrc = l.at(r).at(c);
            const auto& yc = y.at(c);
            for (auto i = 0; i < BlockSize; ++i)
            {
                for (auto j = 0; j < BlockSize; ++j)
                {
                    yr[i] -= lrc(i, j) * yc[j];
                }
            }
        }
        yr = decomposer.SolveLower(l.at(r).at(r));
    }

    return y;
}

template <typename Real, int BlockSize, int NumBlocks>
requires(std::is_arithmetic_v<Real> && 0 <= BlockSize && 0 <= NumBlocks)
typename Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::BlockVector Mathematics::BlockCholeskyDecomposition<Real, BlockSize, NumBlocks>::SolveUpper(const BlockMatrix& l)
{
    BlockVector x{};
    for (auto r = NumBlocks - 1; r >= 0; --r)
    {
        auto& xr = x.at(r);
        for (auto c = r + 1; c < NumBlocks; ++c)
        {
            const auto& lcr = l.at(c).at(r);
            const auto& xc = x.at(c);
            for (auto i = 0; i < BlockSize; ++i)
            {
                for (auto j = 0; j < BlockSize; ++j)
                {
                    xr[i] -= lcr(j, i) * xc[j];
                }
            }
        }
        xr = decomposer.SolveUpper(l.at(r).at(r));
    }

    return x;
}

template <typename Real>
Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::BlockCholeskyDecomposition(int blockSize, int numBlocks)
    : blockSize{ blockSize },
      numBlocks{ numBlocks },
      numDimensions{ numBlocks * blockSize },
      decomposer{ blockSize }
{
    if (!(blockSize > 0 && numBlocks > 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效输入。"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::Get(const BlockMatrix& m, int row, int col)
{
    const auto b0 = col / blockSize, b1 = row / blockSize;
    const auto i0 = col % blockSize, i1 = row % blockSize;
    const auto& block = m.at(GetIndex(b1, b0));
    return block(i1, i0);
}

template <typename Real>
void Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::Set(BlockMatrix& m, int32_t row, int32_t col, Real value)
{
    const auto b0 = col / blockSize, b1 = row / blockSize;
    const auto i0 = col % blockSize, i1 = row % blockSize;
    auto& block = m.at(GetIndex(b1, b0));
    block(i1, i0) = value;
}

template <typename Real>
bool Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::Factor(BlockMatrix& a)
{
    for (auto c = 0; c < numBlocks; ++c)
    {
        if (!decomposer.Factor(a.at(GetIndex(c, c))))
        {
            return false;
        }

        for (auto r = c + 1; r < numBlocks; ++r)
        {
            LowerTriangularSolver(r, c, a);
        }

        for (auto k = c + 1; k < numBlocks; ++k)
        {
            for (auto r = k; r < numBlocks; ++r)
            {
                SubtractiveUpdate(r, k, c, a);
            }
        }
    }
    return true;
}

template <typename Real>
typename Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::BlockVector Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::SolveLower(const BlockMatrix& l)
{
    BlockVector y{};

    for (auto r = 0; r < numBlocks; ++r)
    {
        auto& yr = y.at(r);
        for (auto c = 0; c < r; ++c)
        {
            const auto& lrc = l.at(GetIndex(r, c));
            const auto& yc = y.at(c);
            for (auto i = 0; i < numBlocks; ++i)
            {
                for (auto j = 0; j < numBlocks; ++j)
                {
                    yr[i] -= lrc[GetIndex(i, j)] * yc[j];
                }
            }
        }
        yr = decomposer.SolveLower(l.at(GetIndex(r, r)));
    }

    return y;
}

template <typename Real>
typename Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::BlockVector Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::SolveUpper(const BlockMatrix& l)
{
    BlockVector x{};
    for (auto r = numBlocks - 1; r >= 0; --r)
    {
        auto& xr = x.at(r);
        for (auto c = r + 1; c < numBlocks; ++c)
        {
            const auto& lcr = l.at(GetIndex(c, r));
            const auto& xc = x.at(c);
            for (auto i = 0; i < blockSize; ++i)
            {
                for (auto j = 0; j < blockSize; ++j)
                {
                    xr[i] -= lcr[GetIndex(j, i)] * xc[j];
                }
            }
        }
        xr = decomposer.SolveUpper(l.at(GetIndex(r, r)));
    }
    return x;
}

template <typename Real>
int Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::GetIndex(int row, int col) const noexcept
{
    return col + row * numBlocks;
}

template <typename Real>
void Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::LowerTriangularSolver(int r, int c, BlockMatrix& a)
{
    const auto& acc = a.at(GetIndex(c, c));
    auto& arc = a.at(GetIndex(r, c));
    for (auto j = 0; j < blockSize; ++j)
    {
        for (auto i = 0; i < j; ++i)
        {
            auto lji = acc[GetIndex(j, i)];
            for (auto k = 0; k < blockSize; ++k)
            {
                arc[GetIndex(k, j)] -= lji * arc[GetIndex(k, i)];
            }
        }

        auto ljj = acc[GetIndex(j, j)];
        for (auto k = 0; k < blockSize; ++k)
        {
            arc[GetIndex(k, j)] /= ljj;
        }
    }
}

template <typename Real>
void Mathematics::BlockCholeskyDecomposition<Real, 0, 0>::SubtractiveUpdate(int r, int k, int c, BlockMatrix& a)
{
    const auto& arc = a.at(GetIndex(r, c));
    const auto& akc = a.at(GetIndex(k, c));
    auto& ark = a.at(GetIndex(r, k));
    for (auto j = 0; j < blockSize; ++j)
    {
        for (auto i = 0; i < blockSize; ++i)
        {
            for (auto m = 0; m < blockSize; ++m)
            {
                ark[GetIndex(j, i)] -= arc[GetIndex(j, m)] * akc[GetIndex(i, m)];
            }
        }
    }
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_CHOLESKY_DECOMPOSITION_DETAIL_H
