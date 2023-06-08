///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:35)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_DETAIL_H

#include "SolveBanded.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::SolveBanded<Real>::SolveBanded(const BandedMatrix& matrix, const RealContainer& inputVector, Real zeroTolerance)
    : zeroTolerance{ zeroTolerance }, matrix{ matrix }, output{ inputVector }
{
    Solve();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::SolveBanded<Real>::Solve()
{
    const auto size = matrix.GetSize();

    // 正向消除.
    for (auto row = 0; row < size; ++row)
    {
        ForwardEliminate(row);
    }

    // 反向消除。
    for (auto row = size - 2; 0 <= row; --row)
    {
        const auto columnMin = row + 1;
        auto columnMax = columnMin + matrix.GetUpperBandsNumber();
        if (size < columnMax)
        {
            columnMax = size;
        }

        for (auto column = columnMin; column < columnMax; ++column)
        {
            output.at(row) -= matrix(row, column) * output.at(column);
        }
    }
}

template <typename Real>
void Mathematics::SolveBanded<Real>::ForwardEliminate(int reduceRow)
{
    // 枢轴必须按顺序进行且非零。
    auto diag = matrix(reduceRow, reduceRow);
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

    output.at(reduceRow) /= diag;

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

        output.at(row) -= mult * output.at(reduceRow);
    }
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::SolveBanded<Real>::IsValid() const noexcept
{
    if (!output.empty() && Math::GetValue(0) <= zeroTolerance)
    {
        return true;
    }
    else
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::SolveBanded<Real>::RealContainer Mathematics::SolveBanded<Real>::GetResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_DETAIL_H
