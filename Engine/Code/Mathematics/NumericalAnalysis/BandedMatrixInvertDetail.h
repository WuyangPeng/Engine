///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.6 (2023/10/27 09:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_DETAIL_H

#include "BandedMatrixInvert.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::BandedMatrixInvert<Real>::BandedMatrixInvert(const BandedMatrix& matrix, Real zeroTolerance)
    : zeroTolerance{ zeroTolerance }, matrix{ matrix }, output{ matrix.GetSize(), matrix.GetSize() }
{
    Solve();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::BandedMatrixInvert<Real>::Solve()
{
    const auto size = matrix.GetSize();

    for (auto row = 0; row < size; ++row)
    {
        for (auto col = 0; col < size; ++col)
        {
            if (row != col)
            {
                output(row, col) = Math::GetValue(0);
            }
            else
            {
                output(row, row) = Math::GetValue(1);
            }
        }
    }

    // 正向消除.
    for (auto row = 0; row < size; ++row)
    {
        ForwardEliminate(row);
    }

    // 反向消除。
    for (auto row = size - 1; 1 <= row; --row)
    {
        BackwardEliminate(row);
    }
}

template <typename Real>
void Mathematics::BandedMatrixInvert<Real>::ForwardEliminate(int reduceRow)
{
    // 枢轴必须按顺序进行且非零。
    const auto diag = matrix(reduceRow, reduceRow);
    if (Math::FAbs(diag) <= zeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("支点必须非零！"s));
    }

    matrix(reduceRow, reduceRow) = Math::GetValue(1);

    // 行相乘使对角线项为1一致
    const auto columnMin = reduceRow + 1;
    auto columnMax = columnMin + matrix.GetUpperBandsNumber();
    if (matrix.GetSize() < columnMax)
    {
        columnMax = matrix.GetSize();
    }

    for (auto column = columnMin; column < columnMax; ++column)
    {
        matrix(reduceRow, column) /= diag;
    }

    for (auto column = 0; column <= reduceRow; ++column)
    {
        output(reduceRow, column) /= diag;
    }

    // 减少剩余行。
    const auto rowMin = reduceRow + 1;
    auto rowMax = rowMin + matrix.GetLowerBandsNumber();
    if (matrix.GetSize() < rowMax)
    {
        rowMax = matrix.GetSize();
    }

    for (auto row = rowMin; row < rowMax; ++row)
    {
        auto mult = matrix(row, reduceRow);
        matrix(row, reduceRow) = Math::GetValue(0);
        for (auto column = columnMin; column < columnMax; ++column)
        {
            matrix(row, column) -= mult * matrix(reduceRow, column);
        }
        for (auto column = 0; column <= reduceRow; ++column)
        {
            output(row, column) -= mult * output(reduceRow, column);
        }
    }
}

template <typename Real>
void Mathematics::BandedMatrixInvert<Real>::BackwardEliminate(int reduceRow)
{
    const auto rowMax = reduceRow - 1;
    auto rowMin = reduceRow - matrix.GetUpperBandsNumber();
    if (rowMin < 0)
    {
        rowMin = 0;
    }

    for (auto row = rowMax; rowMin <= row; --row)
    {
        auto mult = matrix(row, reduceRow);
        matrix(row, reduceRow) = Math::GetValue(0);
        for (auto column = 0; column < output.GetColumnsNumber(); ++column)
        {
            output(row, column) -= mult * output(reduceRow, column);
        }
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::BandedMatrixInvert<Real>::IsValid() const noexcept
{
    if (Math::GetValue(0) <= zeroTolerance)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
Mathematics::VariableMatrix<Real> Mathematics::BandedMatrixInvert<Real>::GetInvert() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_DETAIL_H
