// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 09:19)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_BANDED_DETAIL_H

#include "SolveBanded.h"
#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"  
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/BandedMatrixDetail.h"

template <typename Real>
Mathematics::SolveBanded<Real>
	::SolveBanded(const BandedMatrix& matrix, const Real* inputVector, Real zeroTolerance)
	: m_ZeroTolerance{ zeroTolerance }, m_Matrix{ matrix }, m_Output{ inputVector,inputVector + matrix.GetSize() }
{
	Solve();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
void Mathematics::SolveBanded<Real>
	::Solve()
{
	auto size = m_Matrix.GetSize();

	// 正向消除.
	for (auto row = 0; row < size; ++row)
	{
		ForwardEliminate(row);
	}

	// 反向消除。
	for (auto row = size - 2; 0 <= row; --row)
	{
		auto columnMin = row + 1;
		auto columnMax = columnMin + m_Matrix.GetUpperBandsNumber();
		if (size < columnMax)
		{
			columnMax = size;
		}

		for (auto column = columnMin; column < columnMax; ++column)
		{
			m_Output[row] -= m_Matrix(row, column) * m_Output[column];
		}
	}
}

template <typename Real>
void Mathematics::SolveBanded<Real>
	::ForwardEliminate(int reduceRow)
{
	// 枢轴必须按顺序进行且非零。
	auto diag = m_Matrix(reduceRow, reduceRow);
	if (Math<Real>::FAbs(diag) <= m_ZeroTolerance)
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

	m_Output[reduceRow] /= diag;

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
		m_Matrix(row, reduceRow) = Math<Real>::GetValue(0);
		for (auto column = columnMin; column < columnMax; ++column)
		{
			m_Matrix(row, column) -= mult * m_Matrix(reduceRow, column);
		}
		m_Output[row] -= mult * m_Output[reduceRow];
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SolveBanded<Real>
	::IsValid() const noexcept
{
	if (!m_Output.empty() && Math<Real>::GetValue(0) <= m_ZeroTolerance)
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
typename const Mathematics::SolveBanded<Real>::OutputConstIterator	Mathematics::SolveBanded<Real>
	::GetBegin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return OutputConstIterator{ m_Output.begin() };
}

template <typename Real>
typename const Mathematics::SolveBanded<Real>::OutputConstIterator	Mathematics::SolveBanded<Real>
	::GetEnd() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return OutputConstIterator{ m_Output.end() };
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SOLVE_SYMMETRIC_CONJUGATE_GRADIENT_DETAIL_H
