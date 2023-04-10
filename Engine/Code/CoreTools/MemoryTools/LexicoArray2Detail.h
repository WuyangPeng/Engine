///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.5 (2023/04/04 19:23)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H

#include "LexicoArray2.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <typename Real>
CoreTools::LexicoArray2<true, Real>::LexicoArray2(int numRows, int numCols, Container& matrix)
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
Real& CoreTools::LexicoArray2<true, Real>::operator()(int32_t row, int32_t col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));
}

template <typename Real>
const Real& CoreTools::LexicoArray2<true, Real>::operator()(int32_t row, int32_t col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return matrix.at(col + numCols * row);
}

template <typename Real>
CoreTools::LexicoArray2<false, Real>::LexicoArray2(int numRows, int numCols, Container& matrix)
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
Real& CoreTools::LexicoArray2<false, Real>::operator()(int32_t row, int32_t col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));
}

template <typename Real>
const Real& CoreTools::LexicoArray2<false, Real>::operator()(int32_t row, int32_t col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return matrix.at(row + numRows * col);
}

template <typename Real, int NumRows, int NumCols>
CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::LexicoArray2(Container& matrix)
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
Real& CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::operator()(int32_t row, int32_t col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));
}

template <typename Real, int NumRows, int NumCols>
const Real& CoreTools::LexicoArray2<true, Real, NumRows, NumCols>::operator()(int32_t row, int32_t col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return matrix.at(col + NumCols * row);
}

template <typename Real, int NumRows, int NumCols>
CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::LexicoArray2(Container& matrix)
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
Real& CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::operator()(int32_t row, int32_t col)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, col));
}

template <typename Real, int NumRows, int NumCols>
const Real& CoreTools::LexicoArray2<false, Real, NumRows, NumCols>::operator()(int32_t row, int32_t col) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return matrix.at(row + NumRows * col);
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H
