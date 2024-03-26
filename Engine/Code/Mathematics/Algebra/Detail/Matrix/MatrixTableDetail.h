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

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::MatrixTable(Real m00, Real m01, Real m10, Real m11) noexcept requires(NumRows == 2 && NumColumns == 2)

#if defined(MATHEMATICS_USE_ROW_MAJOR)

    : storage{ std::array<Real, NumColumns>{ m00, m01 }, std::array<Real, NumColumns>{ m10, m11 } }

#else  // !MATHEMATICS_USE_ROW_MAJOR

    : storage{ std::array<Real, NumRows>{ m00, m10 }, std::array<Real, NumRows>{ m01, m11 } }

#endif  // MATHEMATICS_USE_ROW_MAJOR

{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::MatrixTable(Real m00, Real m01, Real m02, Real m10, Real m11, Real m12, Real m20, Real m21, Real m22) noexcept requires(NumRows == 3 && NumColumns == 3)

#if defined(MATHEMATICS_USE_ROW_MAJOR)

    : storage{ std::array<Real, NumColumns>{ m00, m01, m02 }, std::array<Real, NumColumns>{ m10, m11, m12 }, std::array<Real, NumColumns>{ m20, m21, m22 } }

#else  // !MATHEMATICS_USE_ROW_MAJOR

    : storage{ std::array<Real, NumColumns>{ m00, m10, m20 }, std::array<Real, NumColumns>{ m01, m11, m21 }, std::array<Real, NumColumns>{ m02, m12, m22 } }

#endif  // MATHEMATICS_USE_ROW_MAJOR

{
    MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int NumRows, int NumColumns, typename Real>
requires(1 <= NumRows && NumRows <= 4 && 1 <= NumColumns && NumColumns <= 4 && std::is_arithmetic_v<Real>)
Mathematics::Algebra::MatrixTable<NumRows, NumColumns, Real>::MatrixTable(Real m00, Real m01, Real m02, Real m03, Real m10, Real m11, Real m12, Real m13, Real m20, Real m21, Real m22, Real m23, Real m30, Real m31, Real m32, Real m33) noexcept requires(NumRows == 4 && NumColumns == 4)

#if defined(MATHEMATICS_USE_ROW_MAJOR)

    : storage{ std::array<Real, NumColumns>{ m00, m01, m02, m03 },
               std::array<Real, NumColumns>{ m10, m11, m12, m13 },
               std::array<Real, NumColumns>{ m20, m21, m22, m23 },
               std::array<Real, NumColumns>{ m30, m31, m32, m33 } }

#else  // !MATHEMATICS_USE_ROW_MAJOR

    : storage{ std::array<Real, NumColumns>{ m00, m10, m20, m30 },
               std::array<Real, NumColumns>{ m01, m11, m21, m31 },
               std::array<Real, NumColumns>{ m02, m12, m22, m32 },
               std::array<Real, NumColumns>{ m03, m13, m23, m33 } }

#endif  // MATHEMATICS_USE_ROW_MAJOR

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
