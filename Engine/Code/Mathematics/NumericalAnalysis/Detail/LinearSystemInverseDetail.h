///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.11 (2023/06/08 16:35)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H

#include "LinearSystemInverse.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::LinearSystemInverse<Real>::LinearSystemInverse(const VariableMatrix& matrix, const RealContainer& input, Real zeroTolerance)
    : zeroTolerance{ zeroTolerance },
      inverse{ matrix },
      size{ inverse.GetRowsNumber() },
      columnsIndex(size),
      rowIndex(size),
      pivoted(size, false),
      currentRow{ 0 },
      currentColumn{ 0 },
      currentMaxValue{},
      output{ input }
{
    Inverse();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::LinearSystemInverse<Real>::LinearSystemInverse(const VariableMatrix& matrix, Real zeroTolerance)
    : zeroTolerance{ zeroTolerance },
      inverse{ matrix },
      size{ inverse.GetRowsNumber() },
      columnsIndex(size),
      rowIndex(size),
      pivoted(size, false),
      currentRow{ 0 },
      currentColumn{ 0 },
      currentMaxValue{},
      output{}
{
    Inverse();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename Real>
bool Mathematics::LinearSystemInverse<Real>::IsValid() const noexcept
{
    try
    {
        if (Math::GetValue(0) <= zeroTolerance &&
            inverse.GetRowsNumber() == inverse.GetColumnsNumber() &&
            size == boost::numeric_cast<int>(columnsIndex.size()) &&
            columnsIndex.size() == rowIndex.size() &&
            rowIndex.size() == pivoted.size() &&
            (output.empty() || boost::numeric_cast<int>(output.size()) == size))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
}

#endif  // OPEN_CLASS_INVARIANT

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>::Inverse()
{
    // 消除了完全旋转。
    for (auto index = 0; index < size; ++index)
    {
        Inverse(index);
    }

    Rearrangement();
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::Inverse(int index)
{
    // 搜索矩阵（不含枢转行）的最大绝对值项。
    CalculateCurrentMaxValue();

    pivoted.at(currentColumn) = true;

    // 交换行使A[col][col]包含枢转项。
    SwapRows();

    // 跟踪行的排列。

    rowIndex.at(index) = currentRow;
    columnsIndex.at(index) = currentColumn;

    // 缩放行，以便枢轴项是1
    ScaleRow();

    // 清零在其他行的枢轴列位置。
    ZeroOutPivotColumnLocations();
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::ScaleRow()
{
    const auto reciprocal = Math::GetValue(1) / inverse(currentColumn, currentColumn);
    inverse(currentColumn, currentColumn) = Math::GetValue(1);
    for (auto index = 0; index < size; index++)
    {
        inverse(currentColumn, index) *= reciprocal;
    }

    if (!output.empty())
    {
        output.at(currentColumn) *= reciprocal;
    }
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::SwapRows()
{
    if (currentRow != currentColumn)
    {
        inverse.SwapRows(currentRow, currentColumn);

        if (!output.empty())
        {
            std::swap(output.at(currentColumn), output.at(currentRow));
        }
    }
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::CalculateCurrentMaxValue()
{
    currentMaxValue = Math::GetValue(0);

    for (auto outerIndex = 0; outerIndex < size; ++outerIndex)
    {
        if (!pivoted.at(outerIndex))
        {
            for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
            {
                if (!pivoted.at(innerIndex))
                {
                    auto absValue = Math::FAbs(inverse(outerIndex, innerIndex));
                    if (currentMaxValue < absValue)
                    {
                        currentMaxValue = absValue;
                        currentRow = outerIndex;
                        currentColumn = innerIndex;
                    }
                }
            }
        }
    }

    if (currentMaxValue <= zeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("矩阵是不可逆的。"s));
    }
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>::ZeroOutPivotColumnLocations()
{
    for (auto outerIndex = 0; outerIndex < size; ++outerIndex)
    {
        if (outerIndex != currentColumn)
        {
            ZeroOutPivotColumnLocations(outerIndex);
        }
    }
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::ZeroOutPivotColumnLocations(int outerIndex)
{
    auto save = inverse(outerIndex, currentColumn);
    inverse(outerIndex, currentColumn) = Math::GetValue(0);
    for (int innerIndex = 0; innerIndex < size; ++innerIndex)
    {
        inverse(outerIndex, innerIndex) -= inverse(currentColumn, innerIndex) * save;
    }

    if (!output.empty())
    {
        output.at(outerIndex) -= output.at(currentColumn) * save;
    }
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>::Rearrangement()
{
    // 重排序列使A[][]存储该原始矩阵的逆。
    for (auto outerIndex = size - 1; 0 <= outerIndex; --outerIndex)
    {
        auto swapRowIndex = rowIndex.at(outerIndex);
        auto swapColumnsIndex = columnsIndex.at(outerIndex);

        if (swapRowIndex != swapColumnsIndex)
        {
            for (auto innerIndex = 0; innerIndex < size; ++innerIndex)
            {
                std::swap(inverse(innerIndex, swapRowIndex), inverse(innerIndex, swapColumnsIndex));
            }
        }
    }
}

template <typename Real>
typename Mathematics::LinearSystemInverse<Real>::VariableMatrix Mathematics::LinearSystemInverse<Real>::GetInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return inverse;
}

template <typename Real>
typename Mathematics::LinearSystemInverse<Real>::RealContainer Mathematics::LinearSystemInverse<Real>::GetResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H
