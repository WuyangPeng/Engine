///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.2 (2022/02/09 11:00)

#ifndef MATHEMATICS_BASE_LEXICO_ARRAY2_DETAIL_H
#define MATHEMATICS_BASE_LEXICO_ARRAY2_DETAIL_H

#include "LexicoArray2.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <gsl/util>

template <typename Real>
Mathematics::LexicoArray2<true, Real>::LexicoArray2(int numRows, int numCols, const Container& matrix)
    : numRows{ numRows },
      numCols{ numCols },
      matrix{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::LexicoArray2<true, Real>::IsValid() const noexcept
{
    const auto numElement = numRows * numCols;
    if (matrix.size() == gsl::narrow_cast<size_t>(numElement))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::LexicoArray2<true, Real>::GetNumRows() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numRows;
}

template <typename Real>
int Mathematics::LexicoArray2<true, Real>::GetNumCols() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numCols;
}

template <typename Real>
const Real& Mathematics::LexicoArray2<true, Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto index = column + numCols * row;

    return matrix.at(index);
}

template <typename Real>
Real& Mathematics::LexicoArray2<true, Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::LexicoArray2<true, Real>::Container Mathematics::LexicoArray2<true, Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return matrix;
}

template <typename Real>
void Mathematics::LexicoArray2<true, Real>::Clear()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(matrix.begin(), matrix.end(), Math::GetValue(0));
}

template <typename Real>
Mathematics::LexicoArray2<false, Real>::LexicoArray2(int numRows, int numCols, const Container& matrix)
    : numRows{ numRows },
      numCols{ numCols },
      matrix{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::LexicoArray2<false, Real>::IsValid() const noexcept
{
    const auto numElement = numRows * numCols;
    if (matrix.size() == gsl::narrow_cast<size_t>(numElement))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::LexicoArray2<false, Real>::GetNumRows() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numRows;
}

template <typename Real>
int Mathematics::LexicoArray2<false, Real>::GetNumCols() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return numCols;
}

template <typename Real>
const Real& Mathematics::LexicoArray2<false, Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto index = row + numRows * column;
    return matrix.at(index);
}

template <typename Real>
Real& Mathematics::LexicoArray2<false, Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real>
typename Mathematics::LexicoArray2<false, Real>::Container Mathematics::LexicoArray2<false, Real>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return matrix;
}

template <typename Real>
void Mathematics::LexicoArray2<false, Real>::Clear()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(matrix.begin(), matrix.end(), Math::GetValue(0));
}

template <typename Real, int NumRows, int NumCols>
Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::LexicoArray2(const Container& matrix)
    : matrix{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
bool Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::IsValid() const noexcept
{
    constexpr auto numElement = NumRows * NumCols;
    if (matrix.size() == gsl::narrow_cast<size_t>(numElement))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
int Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::GetNumRows() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return NumRows;
}

template <typename Real, int NumRows, int NumCols>
int Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::GetNumCols() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return NumCols;
}

template <typename Real, int NumRows, int NumCols>
const Real& Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto index = column + NumCols * row;

    return matrix.at(index);
}

template <typename Real, int NumRows, int NumCols>
Real& Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real, int NumRows, int NumCols>
typename Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::Container Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return matrix;
}

template <typename Real, int NumRows, int NumCols>
void Mathematics::LexicoArray2<true, Real, NumRows, NumCols>::Clear()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(matrix.begin(), matrix.end(), Math::GetValue(0));
}

template <typename Real, int NumRows, int NumCols>
Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::LexicoArray2(const Container& matrix)
    : matrix{ matrix }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
bool Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::IsValid() const noexcept
{
    constexpr auto numElement = NumRows * NumCols;
    if (matrix.size() == gsl::narrow_cast<size_t>(numElement))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real, int NumRows, int NumCols>
int Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::GetNumRows() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return NumRows;
}

template <typename Real, int NumRows, int NumCols>
int Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::GetNumCols() const noexcept
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return NumCols;
}

template <typename Real, int NumRows, int NumCols>
const Real& Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    const auto index = row + NumRows * column;

    return matrix.at(index);
}

template <typename Real, int NumRows, int NumCols>
Real& Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include STSTEM_WARNING_POP
}

template <typename Real, int NumRows, int NumCols>
typename Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::Container Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::GetContainer() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return matrix;
}

template <typename Real, int NumRows, int NumCols>
void Mathematics::LexicoArray2<false, Real, NumRows, NumCols>::Clear()
{
    MATHEMATICS_CLASS_IS_VALID_1;

    fill(matrix.begin(), matrix.end(), Math::GetValue(0));
}

#endif  // MATHEMATICS_BASE_LEXICO_ARRAY2_DETAIL_H
