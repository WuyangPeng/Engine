/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/14 10:10)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_LDLT_DECOMPOSITION_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_LDLT_DECOMPOSITION_DETAIL_H

#include "BlockLdltDecomposition.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix/MatrixDetail.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::BlockLdltDecomposition() noexcept
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
bool Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Get(const BlockMatrix& m, int row, int col, T& value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto b0 = col / BlockSize;
    const auto b1 = row / BlockSize;
    const auto i0 = col - BlockSize * b0;
    const auto i1 = row - BlockSize * b1;
    const auto& mBlock = m.at(b1).at(b0);

    value = mBlock(i1, i0);
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Set(BlockMatrix& m, int row, int col, const T& value)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    const auto b0 = col / BlockSize;
    const auto b1 = row / BlockSize;
    const auto i0 = col - BlockSize * b0;
    const auto i1 = row - BlockSize * b1;
    auto& mBlock = m.at(b1).at(b0);

    mBlock(i1, i0) = value;
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Convert(const Algebra::Matrix<numDimensions, numDimensions, T>& m, BlockMatrix& mBlock) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto r = 0, rb = 0; r < NumBlocks; ++r, rb += BlockSize)
    {
        for (auto c = 0, cb = 0; c < NumBlocks; ++c, cb += BlockSize)
        {
            auto& current = mBlock.at(r).at(c);
            for (auto j = 0; j < BlockSize; ++j)
            {
                for (auto i = 0; i < BlockSize; ++i)
                {
                    current(j, i) = m(rb + j, cb + i);
                }
            }
        }
    }
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Convert(const Algebra::Vector<numDimensions, T>& v, BlockVector& vBlock) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto r = 0, rb = 0; r < NumBlocks; ++r, rb += BlockSize)
    {
        auto& current = vBlock.at(r);
        for (auto j = 0; j < BlockSize; ++j)
        {
            current[j] = v[rb + j];
        }
    }
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Convert(const BlockMatrix& mBlock, Algebra::Matrix<numDimensions, numDimensions, T>& m) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto r = 0, rb = 0; r < NumBlocks; ++r, rb += BlockSize)
    {
        for (auto c = 0, cb = 0; c < NumBlocks; ++c, cb += BlockSize)
        {
            const auto& current = mBlock.at(r).at(c);
            for (auto j = 0; j < BlockSize; ++j)
            {
                for (auto i = 0; i < BlockSize; ++i)
                {
                    m(rb + j, cb + i) = current(j, i);
                }
            }
        }
    }
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Convert(const BlockVector& vBlock, Algebra::Vector<numDimensions, T>& v) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    for (auto r = 0, rb = 0; r < NumBlocks; ++r, rb += BlockSize)
    {
        const auto& current = vBlock.at(r);
        for (auto j = 0; j < BlockSize; ++j)
        {
            v[rb + j] = current[j];
        }
    }
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
bool Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Factor(const BlockMatrix& a, BlockMatrix& l, BlockMatrix& d)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    for (auto row = 0; row < NumBlocks; ++row)
    {
        for (auto col = 0; col < NumBlocks; ++col)
        {
            l.at(row).at(col).MakeZero();
            d.at(row).at(col).MakeZero();
        }
    }

    for (auto j = 0; j < NumBlocks; ++j)
    {
        auto djj = a.at(j).at(j);
        for (auto k = 0; k < j; ++k)
        {
            const auto& ljk = l.at(j).at(k);
            const auto& dkk = d.at(k).at(k);
            djj -= MultiplyTransposition(ljk * dkk, ljk);
        }
        d.at(j).at(j) = djj;
        auto invertible = false;
        const auto invDjj = Inverse(djj, &invertible);
        if (!invertible)
        {
            return false;
        }

        l.at(j).at(j).MakeIdentity();
        for (auto i = j + 1; i < NumBlocks; ++i)
        {
            auto lij = a.at(i).at(j);
            for (auto k = 0; k < j; ++k)
            {
                const auto& lik = l.at(i).at(k);
                const auto& ljk = l.at(j).at(k);
                const auto& dkk = d.at(k).at(k);
                lij -= MultiplyTransposition(lik * dkk, ljk);
            }
            lij = lij * invDjj;
            l.at(i).at(j) = lij;
        }
    }
    return true;
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Solve(BlockMatrix const& l, BlockMatrix const& d, BlockVector const& b, BlockVector& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    /// 求解Z的 L * Z = L * (D * L^T * X) = B。
    for (auto r = 0; r < NumBlocks; ++r)
    {
        x.at(r) = b.at(r);
        for (auto c = 0; c < r; ++c)
        {
            x.at(r) -= l.at(r).at(c) * x.at(c);
        }
    }

    /// 求解Y的 D * Y = D * (L^T * X) = Z。
    for (auto r = 0; r < NumBlocks; ++r)
    {
        x.at(r) = Inverse(d.at(r).at(r)) * x.at(r);
    }

    /// 求解X的的 L^T * Y = Z。
    for (auto r = NumBlocks - 1; r >= 0; --r)
    {
        for (auto c = r + 1; c < NumBlocks; ++c)
        {
            x.at(r) -= x.at(c) * l.at(c).at(r);
        }
    }
}

template <typename T, int BlockSize, int NumBlocks>
requires(0 < BlockSize && 0 < NumBlocks)
void Mathematics::BlockLdltDecomposition<T, BlockSize, NumBlocks>::Solve(BlockMatrix const& a, BlockVector const& b, BlockVector& x)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    BlockMatrix l{};
    BlockMatrix d{};
    Factor(a, l, d);
    Solve(l, d, b, x);
}

template <typename T>
Mathematics::BlockLdltDecomposition<T>::BlockLdltDecomposition(int blockSize, int numBlocks)
    : blockSize{ blockSize },
      numBlocks{ numBlocks },
      numDimensions{ blockSize * numBlocks }
{
    if (!(blockSize > 0 && numBlocks > 0))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
    }

    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename T>
bool Mathematics::BlockLdltDecomposition<T>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Get(const BlockMatrix& m, int row, int col, T& value, bool verifySize)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (verifySize)
    {
        if (boost::numeric_cast<int>(m.size()) != numBlocks * numBlocks)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }
    }

    const auto b0 = col / blockSize;
    const auto b1 = row / blockSize;
    const auto i0 = col - blockSize * b0;
    const auto i1 = row - blockSize * b1;
    const auto& mBlock = m.at(GetIndex(b1, b0));

    if (verifySize)
    {
        if (!(mBlock.GetRowsNumber() == blockSize &&
              mBlock.GetColumnsNumber() == blockSize))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }
    }

    value = mBlock(i1, i0);
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Set(BlockMatrix& m, int row, int col, T const& value, bool verifySize)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (verifySize)
    {
        if (boost::numeric_cast<int>(m.size()) != numBlocks * numBlocks)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }
    }

    const auto b0 = col / blockSize;
    const auto b1 = row / blockSize;
    const auto i0 = col - blockSize * b0;
    const auto i1 = row - blockSize * b1;
    auto& mBlock = m.at(GetIndex(b1, b0));

    if (verifySize)
    {
        if (!(mBlock.GetRowsNumber() == blockSize &&
              mBlock.GetColumnsNumber() == blockSize))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }
    }

    mBlock(i1, i0) = value;
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Convert(const VariableMatrix& m, BlockMatrix& mBlock, bool verifySize) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (verifySize)
    {
        if (!(m.GetRowsNumber() == numDimensions &&
              m.GetColumnsNumber() == numDimensions))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }
    }

    const auto szNumBlocks = boost::numeric_cast<size_t>(numBlocks);
    mBlock.resize(szNumBlocks * szNumBlocks);
    for (auto r = 0, rb = 0, index = 0; r < numBlocks; ++r, rb += blockSize)
    {
        for (auto c = 0, cb = 0; c < numBlocks; ++c, cb += blockSize, ++index)
        {
            auto& current = mBlock.at(index);
            current.SetSize(blockSize, blockSize);
            for (auto j = 0; j < blockSize; ++j)
            {
                for (auto i = 0; i < blockSize; ++i)
                {
                    current(j, i) = m(rb + j, cb + i);
                }
            }
        }
    }
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Convert(const VariableLengthVector& v, BlockVector& vBlock, bool verifySize) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (verifySize)
    {
        if (v.GetSize() != numDimensions)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }
    }

    vBlock.resize(numBlocks);
    for (auto r = 0, rb = 0; r < numBlocks; ++r, rb += blockSize)
    {
        auto& current = vBlock.at(r);
        current.SetSize(blockSize);
        for (auto j = 0; j < blockSize; ++j)
        {
            current[j] = v[rb + j];
        }
    }
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Convert(const BlockMatrix& mBlock, VariableMatrix& m, bool verifySize) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (verifySize)
    {
        if (boost::numeric_cast<int>(mBlock.size()) != numBlocks * numBlocks)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }

        for (const auto& current : mBlock)
        {
            if (!(current.GetRowsNumber() == numBlocks &&
                  current.GetColumnsNumber() == numBlocks))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }
    }

    m.SetSize(numDimensions, numDimensions);
    for (auto r = 0, rb = 0, index = 0; r < numBlocks; ++r, rb += blockSize)
    {
        for (auto c = 0, cb = 0; c < numBlocks; ++c, cb += blockSize, ++index)
        {
            const auto& current = mBlock.at(index);
            for (auto j = 0; j < blockSize; ++j)
            {
                for (auto i = 0; i < blockSize; ++i)
                {
                    m(rb + j, cb + i) = current(j, i);
                }
            }
        }
    }
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Convert(const BlockVector& vBlock, VariableLengthVector& v, bool verifySize) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    if (verifySize)
    {
        if (boost::numeric_cast<int>(vBlock.size()) != numBlocks)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }

        for (auto const& current : vBlock)
        {
            if (current.GetSize() != numBlocks)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }
    }

    v.SetSize(numDimensions);
    for (auto r = 0, rb = 0; r < numBlocks; ++r, rb += blockSize)
    {
        const auto& current = vBlock.at(r);
        for (auto j = 0; j < blockSize; ++j)
        {
            v[rb + j] = current[j];
        }
    }
}

template <typename T>
bool Mathematics::BlockLdltDecomposition<T>::Factor(BlockMatrix const& a, BlockMatrix& l, BlockMatrix& d, bool verifySize)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (verifySize)
    {
        if (boost::numeric_cast<int>(a.size()) != numBlocks * numBlocks)
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }

        for (auto i = 0u; i < a.size(); ++i)
        {
            if (!(a.at(i).GetRowsNumber() == blockSize &&
                  a.at(i).GetColumnsNumber() == blockSize))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }
    }

    l.resize(a.size());
    d.resize(a.size());
    for (auto i = 0u; i < l.size(); ++i)
    {
        l.at(i).SetSize(blockSize, blockSize);
        l.at(i).MakeZero();
        d.at(i).SetSize(blockSize, blockSize);
        d.at(i).MakeZero();
    }

    for (auto j = 0; j < numBlocks; ++j)
    {
        auto djj = a.at(GetIndex(j, j));
        for (auto k = 0; k < j; ++k)
        {
            const auto& ljk = l.at(GetIndex(j, k));
            const auto& dkk = d.at(GetIndex(k, k));
            djj -= MultiplyTranspose(ljk * dkk, ljk);
        }
        d.at(GetIndex(j, j)) = djj;
        auto invertible = false;
        auto invDjj = djj.Inverse(&invertible);
        if (!invertible)
        {
            return false;
        }

        l.at(GetIndex(j, j)).MakeIdentity();
        for (auto i = j + 1; i < numBlocks; ++i)
        {
            auto lij = a.at(GetIndex(i, j));
            for (auto k = 0; k < j; ++k)
            {
                const auto& lik = l.at(GetIndex(i, k));
                const auto& ljk = l.at(GetIndex(j, k));
                const auto& dkk = d.at(GetIndex(k, k));
                lij -= MultiplyTranspose(lik * dkk, ljk);
            }
            lij = lij * invDjj;
            l.at(GetIndex(i, j)) = lij;
        }
    }
    return true;
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Solve(BlockMatrix const& l, BlockMatrix const& d, BlockVector const& b, BlockVector& x, bool verifySize)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (verifySize)
    {
        if (!(boost::numeric_cast<int>(l.size()) == numBlocks * numBlocks &&
              boost::numeric_cast<int>(d.size()) == numBlocks * numBlocks &&
              boost::numeric_cast<int>(b.size()) == numBlocks))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }

        for (auto i = 0u; i < l.size(); ++i)
        {
            if (!(l.at(i).GetRowsNumber() == blockSize &&
                  l.at(i).GetColumnsNumber() == blockSize &&
                  d.at(i).GetRowsNumber() == blockSize &&
                  d.at(i).GetColumnsNumber() == blockSize))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }

        for (auto i = 0u; i < b.size(); ++i)
        {
            if (!(b.at(i).GetSize() == blockSize))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }
    }

    // 求解Z的 L * Z = L * (D * L^T * X) = B
    x.resize(numBlocks);
    for (auto r = 0; r < numBlocks; ++r)
    {
        x.at(r) = b.at(r);
        for (auto c = 0; c < r; ++c)
        {
            x.at(r) -= l.at(GetIndex(r, c)) * x.at(c);
        }
    }

    // 求解Y的 D * Y = D * (L^T * X) = Z
    for (auto r = 0; r < numBlocks; ++r)
    {
        x.at(r) = d.at(GetIndex(r, r)).Inverse() * x.at(r);
    }

    // 求解X的  L^T * Y = Z
    for (auto r = numBlocks - 1; r >= 0; --r)
    {
        for (auto c = r + 1; c < numBlocks; ++c)
        {
            x.at(r) -= x.at(c) * l.at(GetIndex(c, r));
        }
    }
}

template <typename T>
void Mathematics::BlockLdltDecomposition<T>::Solve(BlockMatrix const& a, BlockVector const& b, BlockVector& x, bool verifySize)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    if (verifySize)
    {
        if (!(boost::numeric_cast<int>(a.size()) == numBlocks * numBlocks &&
              boost::numeric_cast<int>(b.size()) == numBlocks))
        {
            THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
        }

        for (auto i = 0u; i < a.size(); ++i)
        {
            if (!(a.at(i).GetRowsNumber() == blockSize &&
                  a.at(i).GetColumnsNumber() == blockSize))
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }

        for (auto i = 0u; i < b.size(); ++i)
        {
            if (b.at(i).GetSize() != blockSize)
            {
                THROW_EXCEPTION(SYSTEM_TEXT("无效的大小"))
            }
        }
    }

    BlockMatrix l{};
    BlockMatrix d{};

    Factor(a, l, d, false);
    Solve(l, d, b, x, false);
}

template <typename T>
int Mathematics::BlockLdltDecomposition<T>::GetIndex(int row, int col) const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return col + row * numBlocks;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BLOCK_LDLT_DECOMPOSITION_DETAIL_H
