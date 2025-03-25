/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/11 18:11)

#ifndef CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H
#define CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H

#include "LexicoArray2.h"
#include "System/Helper/PragmaWarning.h"
#include "CoreTools/Base/SpanIteratorDetail.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename Iter>
CoreTools::LexicoArray2<true, Iter>::LexicoArray2(int numRows, int numColumns, const SpanIteratorType& matrix) noexcept
    : numRows{ numRows },
      numColumns{ numColumns },
      matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Iter>
CoreTools::LexicoArray2<true, Iter>::LexicoArray2(int numRows, int numColumns, const Iter& begin, const Iter& end) noexcept
    : numRows{ numRows },
      numColumns{ numColumns },
      matrix{ begin, end }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Iter>
bool CoreTools::LexicoArray2<true, Iter>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Iter>
int CoreTools::LexicoArray2<true, Iter>::GetNumRows() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numRows;
}

template <typename Iter>
int CoreTools::LexicoArray2<true, Iter>::GetNumColumns() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numColumns;
}

template <typename Iter>
typename CoreTools::LexicoArray2<true, Iter>::Real& CoreTools::LexicoArray2<true, Iter>::operator()(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Iter>
const typename CoreTools::LexicoArray2<true, Iter>::Real& CoreTools::LexicoArray2<true, Iter>::operator()(int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = column + numColumns * row;

    return *matrix.Get(index);
}

template <typename Iter>
template <typename Container>
Container CoreTools::LexicoArray2<true, Iter>::GetContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return Container{ matrix.GetBegin(), matrix.GetEnd() };
}

template <typename Iter>
void CoreTools::LexicoArray2<true, Iter>::FillZero()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    fill(matrix.GetBegin(), matrix.GetEnd(), Real{});
}

template <typename Iter>
CoreTools::LexicoArray2<false, Iter>::LexicoArray2(int numRows, int numColumns, const SpanIterator& matrix) noexcept
    : numRows{ numRows },
      numColumns{ numColumns },
      matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Iter>
CoreTools::LexicoArray2<false, Iter>::LexicoArray2(int numRows, int numColumns, const Iter& begin, const Iter& end) noexcept
    : numRows{ numRows },
      numColumns{ numColumns },
      matrix{ begin, end }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Iter>
bool CoreTools::LexicoArray2<false, Iter>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Iter>
int CoreTools::LexicoArray2<false, Iter>::GetNumRows() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numRows;
}

template <typename Iter>
int CoreTools::LexicoArray2<false, Iter>::GetNumColumns() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return numColumns;
}

template <typename Iter>
typename CoreTools::LexicoArray2<false, Iter>::Real& CoreTools::LexicoArray2<false, Iter>::operator()(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Iter>
const typename CoreTools::LexicoArray2<false, Iter>::Real& CoreTools::LexicoArray2<false, Iter>::operator()(int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = row + numRows * column;

    return *matrix.Get(index);
}

template <typename Iter>
template <typename Container>
Container CoreTools::LexicoArray2<false, Iter>::GetContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return Container{ matrix.GetBegin(), matrix.GetEnd() };
}

template <typename Iter>
void CoreTools::LexicoArray2<false, Iter>::FillZero()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    fill(matrix.GetBegin(), matrix.GetEnd(), Real{});
}

template <typename Iter, int NumRows, int NumCols>
CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::LexicoArray2(const SpanIterator& matrix) noexcept
    : matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Iter, int NumRows, int NumColumns>
CoreTools::LexicoArray2<true, Iter, NumRows, NumColumns>::LexicoArray2(const Iter& begin, const Iter& end) noexcept
    : matrix{ begin, end }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Iter, int NumRows, int NumCols>
bool CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Iter, int NumRows, int NumCols>
int CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::GetNumRows() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumRows;
}

template <typename Iter, int NumRows, int NumCols>
int CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::GetNumColumns() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumCols;
}

template <typename Iter, int NumRows, int NumCols>
typename CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::Real& CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::operator()(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Iter, int NumRows, int NumCols>
const typename CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::Real& CoreTools::LexicoArray2<true, Iter, NumRows, NumCols>::operator()(int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = column + NumCols * row;

    return *matrix.Get(index);
}

template <typename Iter, int NumRows, int NumColumns>
template <typename Container>
Container CoreTools::LexicoArray2<true, Iter, NumRows, NumColumns>::GetContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return Container{ matrix.GetBegin(), matrix.GetEnd() };
}

template <typename Iter, int NumRows, int NumColumns>
void CoreTools::LexicoArray2<true, Iter, NumRows, NumColumns>::FillZero()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    fill(matrix.GetBegin(), matrix.GetEnd(), Real{});
}

template <typename Iter, int NumRows, int NumCols>
CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::LexicoArray2(const SpanIterator& matrix) noexcept
    : matrix{ matrix }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename Iter, int NumRows, int NumColumns>
CoreTools::LexicoArray2<false, Iter, NumRows, NumColumns>::LexicoArray2(const Iter& begin, const Iter& end) noexcept
    : matrix{ begin, end }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Iter, int NumRows, int NumCols>
bool CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Iter, int NumRows, int NumCols>
int CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::GetNumRows() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumRows;
}

template <typename Iter, int NumRows, int NumCols>
int CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::GetNumColumns() noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return NumCols;
}

template <typename Iter, int NumRows, int NumCols>
typename CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::Real& CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::operator()(int row, int column)
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <typename Iter, int NumRows, int NumCols>
const typename CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::Real& CoreTools::LexicoArray2<false, Iter, NumRows, NumCols>::operator()(int row, int column) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    const auto index = row + NumRows * column;

    return *matrix.Get(index);
}

template <typename Iter, int NumRows, int NumColumns>
template <typename Container>
Container CoreTools::LexicoArray2<false, Iter, NumRows, NumColumns>::GetContainer() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return Container{ matrix.GetBegin(), matrix.GetEnd() };
}

template <typename Iter, int NumRows, int NumColumns>
void CoreTools::LexicoArray2<false, Iter, NumRows, NumColumns>::FillZero()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    fill(matrix.GetBegin(), matrix.GetEnd(), Real{});
}

#endif  // CORE_TOOLS_MEMORY_TOOLS_LEXICO_ARRAY2_DETAIL_H
