///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/25 14:57)

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
    : m_ZeroTolerance{ zeroTolerance }, m_Matrix{ matrix }, m_Output{ inputVector }
{
    Solve();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::SolveBanded<Real>::Solve()
{
    const auto size = m_Matrix.GetSize();

    // 正向消除.
    for (auto row = 0; row < size; ++row)
    {
        ForwardEliminate(row);
    }

    // 反向消除。
    for (auto row = size - 2; 0 <= row; --row)
    {
        const auto columnMin = row + 1;
        auto columnMax = columnMin + m_Matrix.GetUpperBandsNumber();
        if (size < columnMax)
        {
            columnMax = size;
        }

        for (auto column = columnMin; column < columnMax; ++column)
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

            m_Output[row] -= m_Matrix(row, column) * m_Output[column];

#include STSTEM_WARNING_POP
        }
    }
}

template <typename Real>
void Mathematics::SolveBanded<Real>::ForwardEliminate(int reduceRow)
{
    // 枢轴必须按顺序进行且非零。
    auto diag = m_Matrix(reduceRow, reduceRow);
    if (Math::FAbs(diag) <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("支点必须非零！"s));
    }

    m_Matrix(reduceRow, reduceRow) = Math::GetValue(1);

    // 行相乘使对角线项为1一致
    const auto columnMin = reduceRow + 1;
    auto columnMax = columnMin + m_Matrix.GetUpperBandsNumber();
    if (m_Matrix.GetSize() < columnMax)
    {
        columnMax = m_Matrix.GetSize();
    }

    for (auto column = columnMin; column < columnMax; ++column)
    {
        m_Matrix(reduceRow, column) /= diag;
    }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_Output[reduceRow] /= diag;
#include STSTEM_WARNING_POP

    // 减少剩余行。
    const auto rowMin = reduceRow + 1;
    auto rowMax = rowMin + m_Matrix.GetLowerBandsNumber();
    if (m_Matrix.GetSize() < rowMax)
    {
        rowMax = m_Matrix.GetSize();
    }

    for (auto row = rowMin; row < rowMax; ++row)
    {
        auto mult = m_Matrix(row, reduceRow);
        m_Matrix(row, reduceRow) = Math::GetValue(0);
        for (auto column = columnMin; column < columnMax; ++column)
        {
            m_Matrix(row, column) -= mult * m_Matrix(reduceRow, column);
        }

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Output[row] -= mult * m_Output[reduceRow];
#include STSTEM_WARNING_POP
    }
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SolveBanded<Real>::IsValid() const noexcept
{
    if (!m_Output.empty() && Math::GetValue(0) <= m_ZeroTolerance)
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

    return m_Output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_DETAIL_H
