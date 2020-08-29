// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 14:38)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H

#include "LinearSystemInverse.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"

template <typename Real>
Mathematics::LinearSystemInverse<Real>
	::LinearSystemInverse(const VariableMatrix& matrix, Real zeroTolerance, const Real* inputVector)
	:m_ZeroTolerance{ zeroTolerance }, m_Inverse{ matrix }, m_Size{ m_Inverse.GetRowsNumber() }, m_ColumnsIndex(m_Size), m_RowIndex(m_Size),
	 m_Pivoted(m_Size, false), m_CurrentRow{ 0 }, m_CurrentColumn{ 0 }, m_CurrentMaxValue{}, m_OutputVector(inputVector != nullptr ? m_Size : 0)
{
	CopyInputVector(inputVector);
	Inverse();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::LinearSystemInverse<Real>
	::IsValid() const noexcept
{
	if (Math::GetValue(0) <= m_ZeroTolerance && m_Inverse.GetRowsNumber() == m_Inverse.GetColumnsNumber() && static_cast<size_t>(m_Size) == m_ColumnsIndex.size() &&
		m_ColumnsIndex.size() == m_RowIndex.size() && m_RowIndex.size() == m_Pivoted.size() && (m_OutputVector.empty() || m_OutputVector.size() == static_cast<size_t>(m_Size)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::CopyInputVector(const Real* inputVector)
{
	if (inputVector != nullptr)
	{
		for (auto i = 0; i < m_Size; ++i)
		{
			m_OutputVector[i] = inputVector[i];
		}
	}
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::Inverse()
{
	// 消除了完全旋转。
	for (auto index = 0; index < m_Size; ++index)
	{
		Inverse(index);
	}

	Rearrangement();
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::Inverse(int index)
{
	// 搜索矩阵（不含枢转行）的最大绝对值项。
	CalculateCurrentMaxValue();

	m_Pivoted[m_CurrentColumn] = true;

	// 交换行使A[col][col]包含枢转项。
	SwapRows();

	// 跟踪行的排列。
	m_RowIndex[index] = m_CurrentRow;
	m_ColumnsIndex[index] = m_CurrentColumn;

	// 缩放行，以便枢轴项是1
	ScaleRow();

	// 清零在其他行的枢轴列位置。
	ZeroOutPivotColumnLocations();
}


template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::ScaleRow()
{
	auto inverse = static_cast<Real>(1) / m_Inverse(m_CurrentColumn, m_CurrentColumn);

	m_Inverse(m_CurrentColumn, m_CurrentColumn) = static_cast<Real>(1);
	for (auto index = 0; index < m_Size; index++)
	{
		m_Inverse(m_CurrentColumn, index) *= inverse;
	}

	if (!m_OutputVector.empty())
	{
		m_OutputVector[m_CurrentColumn] *= inverse;
	}
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::SwapRows()
{
	if (m_CurrentRow != m_CurrentColumn)
	{
		m_Inverse.SwapRows(m_CurrentRow, m_CurrentColumn);

		if (!m_OutputVector.empty())
		{
			std::swap(m_OutputVector[m_CurrentColumn], m_OutputVector[m_CurrentRow]);
		}
	}
}

template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::CalculateCurrentMaxValue()
{
	m_CurrentMaxValue = Math::GetValue(0);

	for (auto outerIndex = 0; outerIndex < m_Size; ++outerIndex)
	{
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
	}

	if (m_CurrentMaxValue <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("矩阵是不可逆的。"));
	}
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::ZeroOutPivotColumnLocations()
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
void Mathematics::LinearSystemInverse<Real>
::ZeroOutPivotColumnLocations(int outerIndex)
{
	auto save = m_Inverse(outerIndex, m_CurrentColumn);
	m_Inverse(outerIndex, m_CurrentColumn) = Math::GetValue(0);
	for (int innerIndex = 0; innerIndex < m_Size; ++innerIndex)
	{
		m_Inverse(outerIndex, innerIndex) -= m_Inverse(m_CurrentColumn, innerIndex) * save;
	}

	if (!m_OutputVector.empty())
	{
		m_OutputVector[outerIndex] -= m_OutputVector[m_CurrentColumn] * save;
	}
}

// private
template <typename Real>
void Mathematics::LinearSystemInverse<Real>
	::Rearrangement()
{
	// 重排序列使A[][]存储该原始矩阵的逆。
	for (auto outerIndex = m_Size - 1; 0 <= outerIndex; --outerIndex)
	{
		auto swapRowIndex = m_RowIndex[outerIndex];
		auto swapColumnsIndex = m_ColumnsIndex[outerIndex];

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
typename const Mathematics::LinearSystemInverse<Real>::VariableMatrix Mathematics::LinearSystemInverse<Real>
	::GetInverse() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Inverse;
}

template <typename Real>
typename const Mathematics::LinearSystemInverse<Real>::OutputConstIterator Mathematics::LinearSystemInverse<Real>
	::GetBegin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return OutputConstIterator{ m_OutputVector.begin() };
}

template <typename Real>
typename const Mathematics::LinearSystemInverse<Real>::OutputConstIterator Mathematics::LinearSystemInverse<Real>
	::GetEnd() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return OutputConstIterator{ m_OutputVector.end() };
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_INVERSE_DETAIL_H
