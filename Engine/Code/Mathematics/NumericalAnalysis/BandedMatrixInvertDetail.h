// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/20 13:32)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_DETAIL_H

#include "BandedMatrixInvert.h"
#include "Mathematics/Base/MathDetail.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"  
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::BandedMatrixInvert<Real>
	::BandedMatrixInvert(const BandedMatrix& matrix, Real zeroTolerance)
	: m_ZeroTolerance{ zeroTolerance }, m_Matrix{ matrix }, m_Output{ m_Matrix.GetSize(), m_Matrix.GetSize() }
{
	Solve();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::BandedMatrixInvert<Real>
	::Solve()
{
	auto size = m_Matrix.GetSize();

	for (auto row = 0; row < size; ++row)
	{
		for (auto col = 0; col < size; ++col)
		{
			if (row != col)
			{
				m_Output(row, col) = Math::GetValue(0);
			}
			else
			{
				m_Output(row, row) = Math::GetValue(1);
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
void Mathematics::BandedMatrixInvert<Real>
	::ForwardEliminate(int reduceRow)
{
	// 枢轴必须按顺序进行且非零。
	auto diag = m_Matrix(reduceRow, reduceRow);
	if (Math::FAbs(diag) <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("支点必须非零！"));
	}

	m_Matrix(reduceRow, reduceRow) = Math::GetValue(1);

	// 行相乘使对角线项为1一致
	auto columnMin = reduceRow + 1;
	auto columnMax = columnMin + m_Matrix.GetUpperBandsNumber();
	if (m_Matrix.GetSize() < columnMax)
	{
		columnMax = m_Matrix.GetSize();
	}

	for (auto column = columnMin; column < columnMax; ++column)
	{
		m_Matrix(reduceRow, column) /= diag;
	}

	for (auto column = 0; column <= reduceRow; ++column)
	{
		m_Output(reduceRow, column) /= diag;
	}

	// 减少剩余行。
	auto rowMin = reduceRow + 1;
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
		for (auto column = 0; column <= reduceRow; ++column)
		{
			m_Output(row, column) -= mult * m_Output(reduceRow, column);
		}
	}
}

template <typename Real>
void Mathematics::BandedMatrixInvert<Real>
	::BackwardEliminate(int reduceRow)
{
	auto rowMax = reduceRow - 1;
	auto rowMin = reduceRow - m_Matrix.GetUpperBandsNumber();
	if (rowMin < 0)
	{
		rowMin = 0;
	}

	for (auto row = rowMax; rowMin <= row; --row)
	{
		auto mult = m_Matrix(row, reduceRow);
		m_Matrix(row, reduceRow) = Math::GetValue(0);
		for (auto column = 0; column < m_Output.GetColumnsNumber(); ++column)
		{
			m_Output(row, column) -= mult * m_Output(reduceRow, column);
		}
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrixInvert<Real>
	::IsValid() const noexcept
{
	if (Math::GetValue(0) <= m_ZeroTolerance)
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
typename const Mathematics::BandedMatrixInvert<Real>::VariableMatrix Mathematics::BandedMatrixInvert<Real>
	::GetInvert() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Output;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_BANDED_MATRIX_INVERT_DETAIL_H
