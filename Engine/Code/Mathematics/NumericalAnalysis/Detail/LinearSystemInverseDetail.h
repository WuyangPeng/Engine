///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/06/08 16:35)

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
    // ��������ȫ��ת��
    for (auto index = 0; index < size; ++index)
    {
        Inverse(index);
    }

    Rearrangement();
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::Inverse(int index)
{
    // �������󣨲�����ת�У���������ֵ�
    CalculateCurrentMaxValue();

    pivoted.at(currentColumn) = true;

    // ������ʹA[col][col]������ת�
    SwapRows();

    // �����е����С�

    rowIndex.at(index) = currentRow;
    columnsIndex.at(index) = currentColumn;

    // �����У��Ա���������1
    ScaleRow();

    // �����������е�������λ�á�
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
        THROW_EXCEPTION(SYSTEM_TEXT("�����ǲ�����ġ�"s));
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
    // ��������ʹA[][]�洢��ԭʼ������档
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
