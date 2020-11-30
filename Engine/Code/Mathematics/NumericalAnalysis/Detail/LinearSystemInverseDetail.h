///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/25 15:48)

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
    : m_ZeroTolerance{ zeroTolerance },
      m_Inverse{ matrix },
      m_Size{ m_Inverse.GetRowsNumber() },
      m_ColumnsIndex(m_Size),
      m_RowIndex(m_Size),
      m_Pivoted(m_Size, false),
      m_CurrentRow{ 0 },
      m_CurrentColumn{ 0 },
      m_CurrentMaxValue{},
      m_Output{ input }
{
    Inverse();

    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::LinearSystemInverse<Real>::LinearSystemInverse(const VariableMatrix& matrix, Real zeroTolerance)
    : m_ZeroTolerance{ zeroTolerance },
      m_Inverse{ matrix },
      m_Size{ m_Inverse.GetRowsNumber() },
      m_ColumnsIndex(m_Size),
      m_RowIndex(m_Size),
      m_Pivoted(m_Size, false),
      m_CurrentRow{ 0 },
      m_CurrentColumn{ 0 },
      m_CurrentMaxValue{},
      m_Output{}
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
        if (Math::GetValue(0) <= m_ZeroTolerance &&
            m_Inverse.GetRowsNumber() == m_Inverse.GetColumnsNumber() &&
            m_Size == boost::numeric_cast<int>(m_ColumnsIndex.size()) &&
            m_ColumnsIndex.size() == m_RowIndex.size() &&
            m_RowIndex.size() == m_Pivoted.size() &&
            (m_Output.empty() || boost::numeric_cast<int>(m_Output.size()) == m_Size))
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
    for (auto index = 0; index < m_Size; ++index)
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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_Pivoted[m_CurrentColumn] = true;
#include STSTEM_WARNING_POP

    // ������ʹA[col][col]������ת�
    SwapRows();

    // �����е����С�
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
    m_RowIndex[index] = m_CurrentRow;
    m_ColumnsIndex[index] = m_CurrentColumn;
#include STSTEM_WARNING_POP

    // �����У��Ա���������1
    ScaleRow();

    // �����������е�������λ�á�
    ZeroOutPivotColumnLocations();
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::ScaleRow()
{
    auto inverse = Math::GetValue(1) / m_Inverse(m_CurrentColumn, m_CurrentColumn);

    m_Inverse(m_CurrentColumn, m_CurrentColumn) = Math::GetValue(1);
    for (auto index = 0; index < m_Size; index++)
    {
        m_Inverse(m_CurrentColumn, index) *= inverse;
    }

    if (!m_Output.empty())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Output[m_CurrentColumn] *= inverse;
#include STSTEM_WARNING_POP
    }
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::SwapRows()
{
    if (m_CurrentRow != m_CurrentColumn)
    {
        m_Inverse.SwapRows(m_CurrentRow, m_CurrentColumn);

        if (!m_Output.empty())
        {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
            std::swap(m_Output[m_CurrentColumn], m_Output[m_CurrentRow]);
#include STSTEM_WARNING_POP
        }
    }
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::CalculateCurrentMaxValue()
{
    m_CurrentMaxValue = Math::GetValue(0);

    for (auto outerIndex = 0; outerIndex < m_Size; ++outerIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        if (!m_Pivoted[outerIndex])
        {
            for (auto innerIndex = 0; innerIndex < m_Size; ++innerIndex)
            {
                if (!m_Pivoted[innerIndex])
                {
                    auto absValue = Math::FAbs(m_Inverse(outerIndex, innerIndex));
                    if (m_CurrentMaxValue < absValue)
                    {
                        m_CurrentMaxValue = absValue;
                        m_CurrentRow = outerIndex;
                        m_CurrentColumn = innerIndex;
                    }
                }
            }
        }
#include STSTEM_WARNING_POP
    }

    if (m_CurrentMaxValue <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�����ǲ�����ġ�"s));
    }
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>::ZeroOutPivotColumnLocations()
{
    for (auto outerIndex = 0; outerIndex < m_Size; ++outerIndex)
    {
        if (outerIndex != m_CurrentColumn)
        {
            ZeroOutPivotColumnLocations(outerIndex);
        }
    }
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>::ZeroOutPivotColumnLocations(int outerIndex)
{
    auto save = m_Inverse(outerIndex, m_CurrentColumn);
    m_Inverse(outerIndex, m_CurrentColumn) = Math::GetValue(0);
    for (int innerIndex = 0; innerIndex < m_Size; ++innerIndex)
    {
        m_Inverse(outerIndex, innerIndex) -= m_Inverse(m_CurrentColumn, innerIndex) * save;
    }

    if (!m_Output.empty())
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        m_Output[outerIndex] -= m_Output[m_CurrentColumn] * save;
#include STSTEM_WARNING_POP
    }
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>::Rearrangement()
{
    // ��������ʹA[][]�洢��ԭʼ������档
    for (auto outerIndex = m_Size - 1; 0 <= outerIndex; --outerIndex)
    {
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
        auto swapRowIndex = m_RowIndex[outerIndex];
        auto swapColumnsIndex = m_ColumnsIndex[outerIndex];
#include STSTEM_WARNING_POP

        if (swapRowIndex != swapColumnsIndex)
        {
            for (auto innerIndex = 0; innerIndex < m_Size; ++innerIndex)
            {
                std::swap(m_Inverse(innerIndex, swapRowIndex), m_Inverse(innerIndex, swapColumnsIndex));
            }
        }
    }
}

template <typename Real>
typename const Mathematics::LinearSystemInverse<Real>::VariableMatrix Mathematics::LinearSystemInverse<Real>::GetInverse() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Inverse;
}

template <typename Real>
typename const Mathematics::LinearSystemInverse<Real>::RealContainer Mathematics::LinearSystemInverse<Real>::GetResult() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;

    return m_Output;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H
