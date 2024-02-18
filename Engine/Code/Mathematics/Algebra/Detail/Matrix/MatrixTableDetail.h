/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.5 (2024/01/30 20:01)

#ifndef MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_TABLE_DETAIL_H
#define MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_TABLE_DETAIL_H

#include "MatrixTable.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::MatrixTable() noexcept
    : storage{}
{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
const Real& Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::operator()(int row, int column) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#if defined(MATHEMATICS_USE_ROW_MAJOR)

    return storage.at(row).at(column);

#else  // !MATHEMATICS_USE_ROW_MAJOR

    return storage.at(column).at(row);

#endif  // MATHEMATICS_USE_ROW_MAJOR
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real& Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::operator()(int row, int column)
{
    MATHEMATICS_CLASS_IS_VALID_9;

#include SYSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26492)

    return const_cast<Real&>(static_cast<const ClassType&>(*this)(row, column));

#include SYSTEM_WARNING_POP
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
const Real& Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::operator[](int index) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

#if defined(MATHEMATICS_USE_ROW_MAJOR)

    return storage.at(index / NumRows).at(index % NumRows);

#else  // !MATHEMATICS_USE_ROW_MAJOR

    return storage.at(index / NumColumns).at(index % NumColumns);

#endif  // MATHEMATICS_USE_ROW_MAJOR
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Real& Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::operator[](int index)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::operator==(const MatrixTable& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return storage == rhs.storage;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
bool Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::operator<(const MatrixTable& rhs) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return storage < rhs.storage;
}

#endif  // MATHEMATICS_ALGEBRA_ALGEBRA_MATRIX_TABLE_DETAIL_H
