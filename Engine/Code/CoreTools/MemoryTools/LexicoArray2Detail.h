/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:42)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H

#include "LexicoArray2.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Real>
CoreTools::LexicoArray2<true, Real>::LexicoArray2(int numRows, int numCols, Container& matrix) noexcept
    : numRows{ numRows },
      numCols{ numCols },
      matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool CoreTools::LexicoArray2<true, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int CoreTools::LexicoArray2<true, Real>::GetNumRows() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numRows;
}

template <typename Real>
int CoreTools::LexicoArray2<true, Real>::GetNumCols() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numCols;
}

template <typename Real>
Real& CoreTools::LexicoArray2<true, Real>::operator()(int row, int col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));

#include SYSTEM_WARNING_POP
}

template <typename Real>
const Real& CoreTools::LexicoArray2<true, Real>::operator()(int row, int col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = col + numCols * row;

    return matrix.at(index);
}

template <typename Real>
CoreTools::LexicoArray2<false, Real>::LexicoArray2(int numRows, int numCols, Container& matrix) noexcept
    : numRows{ numRows },
      numCols{ numCols },
      matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool CoreTools::LexicoArray2<false, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int CoreTools::LexicoArray2<false, Real>::GetNumRows() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numRows;
}

template <typename Real>
int CoreTools::LexicoArray2<false, Real>::GetNumCols() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numCols;
}

template <typename Real>
Real& CoreTools::LexicoArray2<false, Real>::operator()(int row, int col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));

#include SYSTEM_WARNING_POP
}

template <typename Real>
const Real& CoreTools::LexicoArray2<false, Real>::operator()(int row, int col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = row + numRows * col;

    return matrix.at(index);
}

template <typename Real, int NumRows, int NumCols>
CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::LexicoArray2(Container& matrix) noexcept
    : matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
bool CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
int CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::GetNumRows() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumRows;
}

template <typename Real, int NumRows, int NumCols>
int CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::GetNumCols() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumCols;
}

template <typename Real, int NumRows, int NumCols>
Real& CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::operator()(int row, int col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));

#include SYSTEM_WARNING_POP
}

template <typename Real, int NumRows, int NumCols>
const Real& CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::operator()(int row, int col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = col + NumCols * row;

    return matrix.at(index);
}

template <typename Real, int NumRows, int NumCols>
CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::LexicoArray2(Container& matrix) noexcept
    : matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
bool CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
int CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::GetNumRows() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumRows;
}

template <typename Real, int NumRows, int NumCols>
int CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::GetNumCols() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumCols;
}

template <typename Real, int NumRows, int NumCols>
Real& CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::operator()(int row, int col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));

#include SYSTEM_WARNING_POP
}

template <typename Real, int NumRows, int NumCols>
const Real& CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::operator()(int row, int col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = row + NumRows * col;

    return matrix.at(index);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H
